#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1000001,-1);
int f(int k,vector<int>&v)
{
    if(k<0) return 0; // no path 
    if(k == 0)return 1; // last node
      if(dp[k]!=-1)return dp[k]; // memoization
      long long ans =0;
    for(auto i:v)
    {
        ans = (ans+f(k-i,v))%1000000007; 
    }
    return dp[k]=ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i =0;i<n;i++)
       cin>>v[i];
     
    f(k,v);
   cout<<dp[k]%1000000007;
}