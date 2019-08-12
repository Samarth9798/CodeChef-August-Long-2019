#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
typedef long long int ll;
const ll mod = 1e9+7;

int main()
{
    fast
 	
   	ll T;
   	cin >> T;

   	while(T--)
   	{
   		ll n;
   		cin >> n;

   		double k[n+5];
   		for(ll i = 0; i < n; i++)
   			cin >> k[i];

   		double c[n+5];
   		for(ll i = 0; i < n; i++)
   			cin >> c[i];

   		double x[n+5];
   		double Kn = k[n-1];
   		double Cn = c[n-1];
   		double Xn = 0.0;

   		//formula: temp1 += (ci*ki)/Kn, from 1 to n-1
   		//         temp2 += (Kn*Cn)/ki, from 1 to n-1
   		//         temp3 += (Kn/ki),    from 1 to n
   		double temp1,temp2,temp3;
   		temp1 = temp2 = temp3 = 0.0; 
   		for(ll i = 0; i < n-1; i++)
   		{
   			temp1 = temp1 + (c[i] * k[i])/Kn;
   			temp2 = temp2 + (Kn * Cn)/k[i];
   			temp3 = temp3 + (Kn / k[i]);
   		}
   		temp3 = temp3 + (Kn/Kn);
   		Xn = (temp1 - temp2)/temp3;

   		//formula: Xi = (Kn/Ki)*(Kn/Ki)*(Xn + Cn) - Ci
   		for(ll i = 0; i < n; i++)
   		{
   			double temp = Kn/k[i];
   			temp = temp * temp;
   			temp = temp*(Xn + Cn);
   			temp = temp - c[i];

   			x[i] = temp;
   		}

   		int f = 0;
   		if(Xn+Cn < 0)
   			f = 1;

   		if(f == 0)
   		{
   			double F = 0.0;

   			for(ll i = 0; i < n; i++)
   			{
   				double temp = sqrt(x[i] + c[i]);
   				F = F + temp;
   			}

	   		cout << fixed << setprecision(10);
	   		cout << F << ' ';
	   		for(ll i = 0; i < n; i++)
	   			cout << x[i] << ' ';
	   		cout << endl;
   		}
   		else
   		{
   			cout << -1 << endl;
   		}
   	}
}
