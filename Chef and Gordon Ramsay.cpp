#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds; 
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set; 

vector<int> adj[100005];
int vis[100005], per[3], root; 
ll S, L, small[100005], large[100005], si, ans, N, max_depth;
ordered_set s;

void depth_check(int x,int d)
{
    if(d > max_depth)
        max_depth = d;
    vis[x] = 1;
    for(int i = 0; i < adj[x].size(); i++)
        if(vis[adj[x][i]] == 0)
            depth_check(adj[x][i], d+1);
}

void not_tree(int x)
{
    vector<int> v;
    
    queue<int> q;
    q.push(x);
    
    while(!q.empty())
    {
        x = q.front();
        q.pop();
        if(vis[x] == 1)
            continue;
        vis[x] = 1;
        v.push_back(x);
        for(int i = 0; i < adj[x].size(); i++)
            q.push(adj[x][i]);
    }
    
    si = 0;
    x = v[v.size()-1];
    s.insert(x);
    for(int i = v.size()-2; i >= 0; i--)
    {
        int y = v[i];
        s.insert(y);
        S = s.order_of_key(y);
        L = s.size() - 1 - S;
        small[x] = S;
        large[x] = L;
        x = y;
    }
    s.clear();
}

void dfs(int x)
{
	vis[x] = 1;
	s.insert(x); 
	si++;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(vis[y] == 0)
		{
			int temp1, s1 = si;
			if(x == *s.rbegin())
			    temp1 = s1-1;
			else if(x == *s.begin())
			    temp1 = 0;
			else
			    temp1 = s.order_of_key(x);
			    
			dfs(y);
			
			int temp2, s2 = si;
			if(x == *s.rbegin())
			    temp2 = s2-1;
			else if(x == *s.begin())
			    temp2 = 0;
			else
			    temp2 = s.order_of_key(x);
			
			S = temp2 - temp1;
			L = (s2 - s1) - S;
			small[y] = S;
			large[y] = L;
		}
	}
}

void case1(int x, int p)
{
	vis[x] = 1;

	ll total = (N - x), temp = 0, total_small = 0,total_large = 0;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(y != p)
		{
			S = small[y];
			L = large[y];
			temp = temp + (S * (total - L));
			total_small += S;
			total_large += L;
		}
	}
	S = (x - 1) - total_small;
	L = (N - x) - total_large;
	temp = temp + (S * (total - L));

	ans = (ans + temp);

	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(vis[y] == 0)
			case1(y,x);
	}
}

void case2(int x, int p)
{
	vis[x] = 1;

    ll total = (x - 1), temp = 0, total_small = 0;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(y != p)
		{
			S = small[y];
			temp = temp + (S * (total - S));
			total_small += S;
		}
	}
	S = (x - 1) - total_small;
	temp = temp + (S * (total - S));

	ans = (ans + (temp/2));

	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(vis[y] == 0)
			case2(y,x);
	}
}

void case3(int x, int p)
{
	vis[x] = 1;

    ll total = (N - x), temp = 0, total_large = 0;
	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(y != p)
		{
			L = large[y];
			temp = temp + (L * (total - L));
			total_large += L;
		}
	}
	L = (N - x) - total_large;
	temp = temp + (L * (total - L));

	ans = (ans + (temp/2));

	for(int i = 0; i < adj[x].size(); i++)
	{
		int y = adj[x][i];
		if(vis[y] == 0)
			case3(y,x);
	}
}

void solve()
{
	ans = 0;
	memset(vis,0,sizeof(vis));
	if(per[1] == 2)
	{
		case1(root,root);
	}
	else if(per[1] == 3)
	{
		case2(root,root);
	}
	else if(per[1] == 1)
	{
		case3(root,root);
	}
	cout << ans << "\n";
}

void init()
{
	for(ll i = 0; i <= N; i++)
	{
		adj[i].clear();
		vis[i] = 0;
		small[i] = 0;
		large[i] = 0;
	}
}

int main()
{
    fast
 	
 	int T;
 	
 	cin >> T;

 	while(T--)
 	{
        cin >> N;
        
 		init();

 		cin >> per[0] >> per[1] >> per[2];

 		for(int i = 0; i < N-1; i++)
 		{
 			int x,y;
 			cin >> x >> y;
 			adj[x].push_back(y);
 			adj[y].push_back(x);
 		}
        
        root = N;
        for(int i = N; i >= 1; i--)
        {
            if(adj[i].size() == 1)
            {
                root = i;
                break;
            }
        }
        
        max_depth = 1;
        depth_check(root,1);
        
        if(max_depth == N)
        {
            memset(vis,0,sizeof(vis));
            not_tree(root);
        }
        else
        {
            si = 0;
            root = N;
            memset(vis,0,sizeof(vis));
            dfs(root);
            s.clear();
        }
 		solve();
 	}
}
