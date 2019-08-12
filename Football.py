T = int(input())

while T:
    T -= 1
    N = int(input())
    
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    
    s = []
    for i in range(0,N):
        temp = (a[i]*20) - (b[i]*10)
        s.append(max(0,temp))
    
    print(max(s))
