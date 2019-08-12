#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;
const ll mod = 1e9+7;

ll a[100005];
ll n;

void normal()
{
	ll ans = 0;
	for(int i = 0; i < n-1; i++)
	{
		ll temp = 0;
		map<ll,ll> m;
		for(int j = i; j >= 0; j--)
		{
			temp = (temp^a[j]);
			m[temp]++;
		}
		temp = 0;
		for(int j = i+1; j < n; j++)
		{
			temp = (temp^a[j]);
			if(m.count(temp))
			{
				ans = (ans + m[temp]);
			}
		}
	}
	cout << ans << endl;
}

void optimized()
{
	ll ans = 0;

	ll pre[n+5];
	pre[0] = a[0];
	for(ll i = 1; i < n; i++)
	{
		pre[i] = (pre[i-1] ^ a[i]);
	}

	map<ll,ll> first;
    unordered_map<ll,ll> total;
    unordered_map<ll,ll> cnt;
    
	for(ll i = 0; i < n; i++)
	{
		if(first.count(pre[i]))
		{
			ll temp = first[pre[i]];
			ll temp1 = cnt[pre[i]];
			ll diff = i - temp;
			temp = diff * temp1;
			temp = temp - total[pre[i]];
			
			ans = (ans + temp);
		}
		if(pre[i] == 0)
		{
			ans = (ans + i);
		}
		
		if(first.count(pre[i]))
		{
		    ll temp = first[pre[i]];
		    temp = (i+1) - temp;
		    cnt[pre[i]]++;
		    total[pre[i]] += temp;
		}
		else
		{
		    first[pre[i]] = (i+1);
		    cnt[pre[i]] = 1;
		    total[pre[i]] = 0;
		}
	}
	cout << ans << endl;
}

int main()
{
    fast
 	
    int T;

    cin >> T;

    while(T--)
    {
    	cin >> n;
    	
    	for(int i = 0; i < n; i++)
    		cin >> a[i];

    	if(n <= 1000)
    	{
    		normal();
    	}
    	else
    	{
    		optimized();
    	}
    }
}
