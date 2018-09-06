#include "logger.h"

#include <fstream>
//#include <ostream>
#include <windows.h>

using namespace std;

static ofstream loggerOutput;

const Logger* Logger::instance = NULL;

const Logger* Logger::getInstance()
{
	if (instance == NULL) {
		instance = new Logger();
	}//if
	return instance;
}

void Logger::log(const char *str) const
{
	loggerOutput << str << endl;
}

void Logger::log(const string &str) const
{
	loggerOutput << str << endl;
}

void Logger::log(const char *str, int i) const
{
	loggerOutput << str << " " << i << endl;
}

void Logger::log(const char *str, const char *str2) const
{
	loggerOutput << str << " " << str2 << endl;
}

void Logger::log(const char *str, const string str2) const
{
	loggerOutput << str << " " << str2 << endl;
}

void Logger::log(const char *str, double d) const
{
	loggerOutput << str << " " << d << endl;
}

void Logger::logf(const char *fmt, ...) const
{
	char text[512];// Ukl�d� �et�zec
	va_list ap;// Pointer do argument� funkce
	if (fmt == NULL) { return; }// Byl p�ed�n text?
	va_start(ap, fmt);// Rozbor �et�zce
	vsprintf(text, fmt, ap);// Zam�n� symboly za konkr�tn� ��sla
	va_end(ap);// V�sledek je ulo�en v text
	log(text);
}

Logger::~Logger()
{
	loggerOutput.close();
}

Logger::Logger()
{
    memset(&fpsCounter, 0, sizeof(fpsCounter));
    memset(&lastFPS, 0, sizeof(lastFPS));
    memset(&fpsStart, 0, sizeof(fpsStart));
    
	loggerOutput.open("log.txt", ios::out);
}

/*************************************************/

void Logger::updateFPS(int i) const
{
    if ((fpsStart[i] + 5000) < GetTickCount()) {
        lastFPS[i] = (fpsCounter[i]*1000) / (GetTickCount() - fpsStart[i]);
        fpsStart[i] = GetTickCount();
        fpsCounter[i] = 0;
    }//if
    fpsCounter[i]++;
}
int  Logger::getFPS(int i) const
{
    return lastFPS[i];
}

/*************************************************/

const Logger* logger = Logger::getInstance();

