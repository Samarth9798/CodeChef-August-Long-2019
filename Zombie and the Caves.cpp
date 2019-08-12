#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;

int main()
{
    fast
    
    int T;
    cin >> T;
    
    while(T--)
    {
        ll N;
        cin >> N;
        
        ll a[N+5];
        ll h[N+5];
        for(int i = 0; i < N; i++)
            cin >> a[i];
        for(int i = 0; i < N; i++)
            cin >> h[i];
            
        ll ans[N+5];
        memset(ans,0,sizeof(ans));
        
        for(int i = 0; i < N; i++)
        {
            ll l = i - a[i];
            if(l < 0)
                l = 0;
            ans[l] += 1;
            ll r = i + a[i];
            if(r > N-1)
                r = N-1;
            r = r + 1;
            ans[r] -= 1;
            
        }
        
        for(int i = 1; i < N; i++)
        {
            ans[i] = ans[i] + ans[i-1];
        }
        
        sort(ans,ans+N);
        sort(h,h+N);
        
        int f = 0;
        for(int i = 0; i < N; i++)
        {
            if(ans[i] != h[i])
            {
                f = 1;
                break;
            }
        }
        
        f == 1 ? cout << "NO\n" : cout << "YES\n";
    }
}
