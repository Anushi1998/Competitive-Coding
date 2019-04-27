import bisect as b
N = 100010
mod = 1000000000000000003

def SUM_MOD(a, b):
    Result = a + b
    Result = Result%mod
    if Result<0:
        return Result+mod
    return Result

def MUL_MOD(a, b):
    Result = a * b
    Result = Result%mod
    if Result<0:
        return Result+mod
    return Result

def HASH(a):
    cnt=0
    for i in a:
        cnt=SUM_MOD(MUL_MOD(cnt,26),ord(i)-ord('a'))
    return cnt

Pow26 = []
Pow26.append(1)
for i in range(1,N):
    Pow26.append(MUL_MOD(Pow26[i-1],26))


n=int(input())
m=int(input())
inp=[]
Hash=[]
for i in range(n):
    s=input()
    inp.append(s)
    Hash.append(HASH(s))

Hash.sort()
cnt=0
for j in range(n):
    s=inp[j]
    hell=HASH(s)
    
    for i in range(m):
        # print(hell,end=' ')
        d=ord(s[m-1-i])-ord('a')
        hell=SUM_MOD(hell,-MUL_MOD(d,Pow26[i]))
        letter=25
        while letter:
            letter=letter-1
            d=d+1
            d=d%26
            x=SUM_MOD(hell,MUL_MOD(d,Pow26[i]))
            diff=b.bisect_right(Hash,x)-b.bisect_left(Hash,x)
            cnt=cnt+diff
            # print(x,diff,end=' ')
        # print()
        hell=SUM_MOD(hell,MUL_MOD(ord(s[m-1-i])-ord('a'),Pow26[i]))
    

cnt=cnt//2
print(cnt)

