#!/usr/bin/python2

while True:
    f = None
    try:
       f = open('/tmp/tmp_file.txt')
       data = f.readlines()
       print(data)
       exit()
    except Exception:
       e = 1
    finally:
       if f: f.close()
