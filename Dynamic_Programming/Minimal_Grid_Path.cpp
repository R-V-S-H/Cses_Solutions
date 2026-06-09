#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
    int n;
    cin>>n;
    vector<vector<char>>c(n,vector<char>(n));
    for(int i =0;i<n;i++)
      for(int j =0;j<n;j++)
         cin>>c[i][j];
   vector<vector<string>>dp(n,vector<string>(n,""));
    dp[0][0] = c[0][0];
    for(int i =0;i<n;i++)
      for(int j =0;j<n;j++)  
       {
         if(i == 0 && j == 0)continue;
           if(j>=1 && i<1)
            {dp[i][j] = dp[i][j-1]+c[i][j];continue;}
           if(j<1 && i>=1)
            {dp[i][j] =dp[i-1][j]+c[i][j];continue;}
         dp[i][j] = ((dp[i-1][j]<dp[i][j-1])?dp[i-1][j]:dp[i][j-1])+c[i][j];
       } 
       cout<<dp[n-1][n-1];
} 
