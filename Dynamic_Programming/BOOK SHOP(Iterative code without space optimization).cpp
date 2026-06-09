#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;

int main () {

         int n,x;
         cin>>n>>x;
          vector<int>pages(n),price(n) ;
         for(int i =0;i<n;i++)
          {
            cin>>price[i];
          }
          for(int i =0;i<n;i++)
          {
            cin>>pages[i];
          }
         vector<vector<int>>dp(n+1,vector<int>(x+1,0));
         //STATE: dp[i][j] maximum value that we can get using till i items while being allowed j capacity
         //TRANSITION : dp[i][j] = max(skipping the ith item ,choosing the ith item) , max(dp[i-1][j],dp[i-1][j-price[i-1]]])
        for(int i =1;i<=n;i++)
         {
           for(int j =0;j<=x;j++)
            {
               int pg  = pages[i-1]; // pages of the ith item cause of 0 based indexing
               int pr  = price[i-1]; // price of the ith item cause of 0 based indexing
               // now we make 2 choice skip or pick 
               int skip = dp[i-1][j];  
               int pick = (j>=pr)?(pg+dp[i-1][j-pr]):0; // if capacity of knapsack less then then item weight we want to pick then we pick nothing
               dp[i][j] = max(pick,skip); //TRANSITION
              
            }}
          cout<<dp[n][x];
}

