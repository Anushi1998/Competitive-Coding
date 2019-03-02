for _ in range(int(input())):
    k,n=map(int,input().split())
    ok=0
    cnt=0
    for i in range(k):
        x,y=map(int,input().split())
        if x<=0 or x>=n-1:
            ok=1
        elif y<=0 or y>=n-1:
            ok=1
        else:
            cnt=cnt+1
    if cnt>3 or ok:
        print('yes')
    else:
        print('no')