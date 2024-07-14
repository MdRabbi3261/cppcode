#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define forn for (ll i = 0; i < n; ++i)
#define foro for (ll i = 1; i < n; ++i)
#define forne for (ll i = n - 1; i >= 0; --i)
#define MOD 1000000007
#define umap unordered_map
#define pb push_back
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define vc vector
#define rd ill()
ll ill();

void solve()
{
 int n;
 cin>>n;   
 vector<ll>v(n);
 ll mx=INT_MIN,mxin=0,mi=INT_MAX,miin=0;
 for(int i=0;i<n;i++)
 {
    cin>>v[i];
    if(v[i]>mx)
    {
       mx=v[i];
       mxin=i;
    }
    if(v[i]<mi)
    {
        mi=v[i];
        miin=i;
    }
 }   
 if(mx==mi)
 {
    cout<<0<<endl;
    return;
 }
 vector<pair<ll,ll>>ve;
 if(mi>0)
{
    for(int i=1;i<n;i++)
    {
        v[i]=v[i]+v[i-1];
        ve.push_back({i+1,i});
    }
}
else if(mx<0)
{
    for(int i=n-2;i>=0;i--)
   {
    v[i]=v[i]+v[i+1];
    ve.push_back({i+1,i+2});
   }
}
else 
{
    for(int i=1;i<n;i++)
   {
     if(v[i]<v[i-1])
     {
        while(v[i]<v[i-1])
        {
          v[i]+=mx;
          ve.push_back({i+1,mxin+1});
        }
        if(v[i]>mx)
        {
            mx=v[i];
            mxin=i;
        }
     }
   }
//    for(int i=1;i<n;i++)
//     {
//         v[i]=v[i]+v[i-1];
//         ve.push_back({i+1,i});
//     }
}
// for(auto &e:v)
// cout<<e<<" ";
// cout<<endl;
cout<<ve.size()<<endl;
for(int i=0;i<ve.size();i++)
{
    cout<<ve[i].first<<" "<<ve[i].second<<endl;
}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++)
        solve();
    return 0;
}
ll ill()
{
    ll x;
    cin >> x;
    return x;
}