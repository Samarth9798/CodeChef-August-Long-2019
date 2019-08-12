#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;
const ll mod = 1e9+7;

string s;
char toggle(char c)
{
    if(c == '1')
        return '0';
    return '1';
}
bool solve(int l, int r)
{
	if(l > r) 
	{
		return true;
	}

	for(int i = l; i <= r; i++)
	{
		if(s[i] == '1')
		{
			bool left,right;
		    if(i-1 >= l) 
		        s[i-1] = toggle(s[i-1]);
			  
		    if(i+1 <= r)
		        s[i+1] = toggle(s[i+1]);
			    
			left = solve(l,i-1);
			right = solve(i+1,r);
			
			if(i-1 >= l) 
		        s[i-1] = toggle(s[i-1]);
			  
		    if(i+1 <= r)
		        s[i+1] = toggle(s[i+1]);
		    
		    if(left and right)
		        return true;
		    else
		        return false;
		}
	}
	return false;
}

int main()
{
    fast
 	
 	int T;
 	cin >> T;

 	while(T--)
 	{
 		cin >> s;

 		solve(0,s.length()-1) ? cout << "WIN\n" : cout << "LOSE\n";
 	}
}
