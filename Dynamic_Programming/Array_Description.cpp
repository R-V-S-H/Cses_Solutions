#include <bits/stdc++.h>
using namespace std;
//STATE: DP[i][j] # of arrays till the ith index using j element
//TRANSITION:DP[i][j] = DP[i-1][j]+DP[i-1][j+1]+DP[i-1][j-1]
//base case DP[i][0] = 0 as   0<m<=100
//final ans  = summation(DP[n-1][j]) j =1 to m
int MOD  = 1e9+7;
int main()
{
   int n,m;
   cin>>n>>m;
   vector<int>v(n);
   for(int i =0;i<n;i++)
     cin>>v[i];
    vector<vector<int>>dp(n,vector<int>(m+1,0));
     if(v[0] == 0)
       for(int i=1;i<=m;i++)dp[0][i] =1;
     else
      dp[0][v[0]]=1;
    for(int i =1;i<n;i++){
      if(v[i] == 0)
      for(int j=1;j<=m;j++){
         {
             dp[i][j] = dp[i-1][j]%MOD;

             if(j>1)dp[i][j]=(dp[i][j]+dp[i-1][j-1])%MOD;       
             if(j<m)dp[i][j]=(dp[i][j]+dp[i-1][j+1])%MOD;       
         }
         }
      else
      {
        dp[i][v[i]]=dp[i-1][v[i]]%MOD;
        if(v[i]>1)dp[i][v[i]] =(dp[i][v[i]]+dp[i-1][v[i]-1])%MOD;
        if(v[i]<m)dp[i][v[i]]=(dp[i][v[i]]+dp[i-1][v[i]+1])%MOD;
     }
    }
    int ans =0;
       for(int i =1;i<=m;i++)
         ans=(ans+dp[n-1][i])%MOD;
       cout<<ans;
}
