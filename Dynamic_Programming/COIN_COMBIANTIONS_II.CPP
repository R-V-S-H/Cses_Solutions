#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;


int main () {

          int n,k;
          cin>>n>>k;
           vector<int> v(n);
          for(int i =0;i<n;i++)
           cin>>v[i];
        vector<int> dp(k+1,0);
        dp[0] =1;
        for(int i =0;i<n;i++)
        {
         
          for(int j = 1;j<=k;j++)
          {
              if(j-v[i]>=0)
                dp[j]=(dp[j]+dp[j-v[i]])%MOD; 

          }
        }
        cout<<dp[k];
}


   
    