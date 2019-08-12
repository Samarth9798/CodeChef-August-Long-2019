T = int(input())

mod = 10**9 + 7

two = pow(2, mod-2, mod)

def find(n,s):
	res = 0

	check = set(s)
	if len(check) == 1:
	    check = list(check)
	    x = int(check[0])
	    temp = 0
	    for i in range(0,len(s)-1):
	        temp = ((temp*10)+x)%mod
	    res = (temp * (temp+1))%mod
	    res = (res * two)%mod
	    return int(res)
	    
	n -= 2
    
	dp = [0]*(len(s)+1)
	prev = 1
	ex = 0
	for i in range(len(s)-1,0,-1):
		temp = int(s[i])
		temp1 = pow(10,ex,mod)
		temp = (temp1*temp)%mod
		temp = (temp + prev)%mod 
		dp[i-1] = temp
		ex += 1
		prev = temp

	dp[len(s)-1] = 1

	for i in range(0,len(s)-1):
		x = int(s[i])

		p = 1
		if n > 0:
			p = pow(10,n,mod)

		no = (x*p)%mod
		temp = (no * (no - 1))%mod
		temp = (temp * two)%mod
		res = (res + temp)%mod

		if int(s[i]) < int(s[i+1]):
			temp = (no * p)%mod
			res = (res + temp)%mod
		elif int(s[i]) == int(s[i+1]):
			temp = (no * dp[i+1])%mod
			res = (res + temp)%mod

		n -= 1

	return int(res)

def brute_force(L,R):
    ans = 0
    for i in range(L, R+1):
        s = str(i)
        p = len(s)-1
        prev = '$'
        no = 0
        for j in range(0,len(s)):
            if s[j] != prev:
                x = int(s[j])
                temp = (x * pow(10,p,mod))%mod
                no = (no + temp)%mod
            p -= 1
            prev = s[j]
        ans = (ans + no)%mod
    print(int(ans))
    
def optimized(n1,L,n2,R):

	left = 0
	right = 0

	if n1 > 1:
		left = find(n1,str(L))
	if n2 > 1:
		right = find(n2,str(R))

	L = L%mod
	R = R%mod

	L = (L * (L + 1))%mod
	L = (L * two)%mod
	L = (L - left)%mod

	R = (R * (R + 1))%mod
	R = (R * two)%mod
	R = (R - right)%mod

	ans = (R - L)%mod
	print(ans)
	
while T:
	T -= 1

	n1,L = map(int,input().split())
	n2,R = map(int,input().split())

	if (R-L) <= 100005:
		brute_force(L,R)
		continue
	
	L -= 1
	optimized(n1,L,n2,R)
