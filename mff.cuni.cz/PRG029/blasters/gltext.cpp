#include "gltext.h"

#include "gl/glpng.h"
#include "gltools.h"

GLuint fonttextures[1];			// Storage For Our Font Texture
GLuint fontbase;				// Base Display List For The Font


void gltPrintf(const char *fmt, ...)// Klon printf() pro OpenGL
{
	char text[256];// Ukl�d� �et�zec

	va_list ap;// Pointer do argument� funkce
	if (fmt == NULL) { return; }// Byl p�ed�n text?
	va_start(ap, fmt);// Rozbor �et�zce
	vsprintf(text, fmt, ap);// Zam�n� symboly za konkr�tn� ��sla
	va_end(ap);// V�sledek je ulo�en v text
	gltPrint(text);
}

void gltPrint(const char *text)
{
	int set = 0;
	glBindTexture(GL_TEXTURE_2D, fonttextures[0]);		// Select Our Font Texture
	glPushAttrib(GL_LIST_BIT);// Ulo�� sou�asn� stav display list�
	glListBase(fontbase-32+(128*set));						// Choose The Font Set (0 or 1)
	glCallLists((GLsizei)strlen(text),GL_UNSIGNED_BYTE, text);// Write The Text To The Screen
	glPopAttrib();// Obnov� p�vodn� stav display list�*/
}

void gltPrint(const std::string &s)
{
    gltPrint(s.c_str());
}

void gltInitFonts()
{
	fonttextures[0] = loadtexture("gfx/Font.png");

	float	cx;											// Holds Our X Character Coord
	float	cy;											// Holds Our Y Character Coord
	fontbase=glGenLists(256);							// Creating 256 Display Lists
	glBindTexture(GL_TEXTURE_2D, fonttextures[0]);		// Select Our Font Texture
	for (int loop=0; loop<256; loop++)					// Loop Through All 256 Lists
	{
		cx=float(loop%16)/16.0f;						// X Position Of Current Character
		cy=float(loop/16)/16.0f;						// Y Position Of Current Character

		glNewList(fontbase+loop,GL_COMPILE);			// Start Building A List
			glBegin(GL_QUADS);							// Use A Quad For Each Character
				glTexCoord2f(cx,1-cy-0.0625f);			glVertex2f(0,0);		// Vertex Coord (Bottom Left)
				glTexCoord2f(cx+0.0625f,1-cy-0.0625f);	glVertex2f(0.10f,0);	// Vertex Coord (Bottom Right)
				glTexCoord2f(cx+0.0625f,1-cy);			glVertex2f(0.10f,0.14f);// Vertex Coord (Top Right)
				glTexCoord2f(cx,1-cy);					glVertex2f(0,0.14f);	// Vertex Coord (Top Left)
			glEnd();
			glTranslated(0.08,0,0);						// Move To The Right Of The Character
		glEndList();									// Done Building The Display List
	}													// Loop Until All 256 Are Built

}



void gltDeleteFonts()
{
	glDeleteLists(fontbase,256);							// Delete All 256 Display Lists
}