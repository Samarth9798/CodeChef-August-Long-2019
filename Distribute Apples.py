T = int(input())

while T:
    T -= 1
    n,k = map(int,input().split())
    p = k*k
    if n%p == 0:
        print("NO")
    else:
        print("YES")
