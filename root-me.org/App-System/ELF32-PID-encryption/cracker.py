#/usr/bin/python2

import re
import subprocess
import os


# Notes: quite overcomplicated solution, ToDo: how to exec command (with same pid)?

def readfile(filename):
    with open(filename, 'rt') as f:
        data = f.readlines()
        return [x.strip().split(' ') for x in data]

def fillDict(hashData):
    result = {}
    for (k,v) in hashData:
        result[k] = v
        result[v] = k
    return result

def run(arg):
    try:
        result = subprocess.check_output(['./ch4',arg])
    except subprocess.CalledProcessError as e:
        if e.returncode >0:
            print(e.output)
            exit(e.returncode)
        return False

    return result.decode('ascii')

def parseOutput(cmdout, hashes):
    p = re.compile('=([$]1[$]awesome[$].*)phail')
    m = p.search(cmdout)
    if (m):
        h = m.group(1)
        if h in hashes:
            return int(hashes[h])
        else:
            print("Not found: "+h)
            return None
    else:
        return None

print('read hashes')
hashFile = readfile('hashes')
hashes = fillDict(hashFile)

pid = os.getpid()
inc = 2

print('start')

for i in range(20):

    pid = pid + inc

    h = hashes[str(pid)]
    print('running ['+str(pid)+'] ./ch4 ' + h)
    cmdoutput = run(h)
    cmdpid = parseOutput(cmdoutput, hashes)
    if not cmdpid:
        print('cmdout was: ' + cmdoutput)
        exit()
    print('pid was: ' + str(cmdpid))
    if (cmdpid < pid):
        inc = inc - 1
        print('inc decr to: ' + str(inc))
    if (cmdpid > pid):
        inc = inc + 1
        print('inc inc to: ' + str(inc))

    pid = cmdpid or pid

