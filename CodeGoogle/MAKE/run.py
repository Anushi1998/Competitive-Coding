#!/usr/bin/python
import subprocess
import sys

ok=0

subprocess.call(["make","Compile"])

cnt=0
type = sys.argv[1]

if type=='0':
    print("Running Tests...")
    while not ok:
        Wrong=open("..//TXT//Wrong.txt","w")
        Correct=open("..//TXT//Correct.txt","w")
        subprocess.call("..//OUT//Generator.out")
        Test=open("..//TXT//Test.txt","r")
        subprocess.call("..//OUT//Wrong.out",stdin=Test,stdout=Wrong)
        Test.close()
        Test=open("..//TXT//Test.txt","r")
        ok=subprocess.call("..//OUT//Correct.out",stdin=Test,stdout=Correct)
        Test.close()
        ok|=subprocess.call(["cmp","..//TXT//Correct.txt","..//TXT//Wrong.txt"])
        Wrong.close()
        Correct.close()
        cnt=cnt+1
        print(cnt)

else:
    print('Running Timed cases')
    while not ok:
        Wrong=open("..//TXT//Wrong.txt","w")
        subprocess.call("../OUT//Generator.out")
        Test=open("..//TXT//Test.txt","r")
        ok=subprocess.call("..//OUT//Wrong.out", stdin=Test, stdout=Wrong, timeout=0.5)
        Test.close()
        Wrong.close()
        cnt=cnt+1
        print(cnt)
