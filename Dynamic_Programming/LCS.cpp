#include<bits/stdc++.h>
using namespace std;
 
 
int main()
{
   //freeopen("knights.in","r",stdin);
 
 //  freeopen("knights.out","w",stdout);
    int n,m;
    cin>>n>>m;
     vector<int>s_1(n);
     vector<int>s_2(m);
     for(int i =0;i<n;i++)cin>>s_1[i];
      for(int i =0;i<m;i++)cin>>s_2[i];
   vector<vector<int>> dp(n+1,vector<int>(m+1,0));
vector<vector<string>> dp_c(n+1,vector<string>(m+1,""));
      for(int  i =1;i<=n;i++)
      {
          for(int j = 1;j<=m;j++)
          {
                if(s_1[i-1] == s_2[j-1])
                   {  dp[i][j] = 1+dp[i-1][j-1];
                      dp_c[i][j] = dp_c[i-1][j-1]+to_string(s_1[i-1])+" ";
                    }
                else
                {
                  dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                  dp_c[i][j] = ((dp_c[i-1][j].length()>dp_c[i][j-1].length())?dp_c[i-1][j]:dp_c[i][j-1]);
                }
          }
      }
     cout<<dp[n][m]<<"\n";
    cout<<dp_c[n][m];
   
} 
