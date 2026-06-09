#include<bits/stdc++.h>
using namespace std;
vector<int> dp(10000000,-1);
int f(int k,vector<int> &v,int n)
{
    if(k<0) return 1e9;
   if(k == 0) return 0;
    if(dp[k]!=-1)
      return dp[k];
    int ans =1e9;
  for(int i =0;i<n;i++)
   {
       ans  =  min(ans,1+f(k-v[i],v,n));
                    
   } 
    return dp[k] =ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i =0;i<n;i++)
       cin>>v[i];
     
    f(k,v,n);
    int a = (dp[k]<1e9)?dp[k]:-1;
    cout<<a;
}