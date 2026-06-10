#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n,sum=0;
  cin>>n;
  vector<int>coins(n);
  for(int i =0;i<n;i++)
  {cin>>coins[i];sum+=coins[i];}
    vector<vector<bool>>dp(sum+1,vector<bool>(n,0));
    fill(dp[0].begin(),dp[0].end(),true);
    for(int i =1;i<=sum;i++){

      for(int j =0;j<n;j++){
         int r_sum = i-coins[j];bool  f =false;
         if(r_sum>0)
            for(int k =j+1;k<n;k++)
            {
              f = f || dp[r_sum][k];
              if(f)break;
            }
        if(r_sum == 0)
          f= true;
         dp[i][j] =f;

      }
 } 
    int x=0;
    for(int i =1;i<=sum;i++){
      for(int j =0;j<n;j++)
        if(dp[i][j]){x++;break;}
    }
       cout<<x<<"\n";
    for(int i =1;i<=sum;i++){
      for(int j =0;j<n;j++)
        if(dp[i][j]){cout<<i<<" ";break;}
    }
}
