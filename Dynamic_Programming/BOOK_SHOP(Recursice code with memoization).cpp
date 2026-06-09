#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int knapsack(vector<int>&price,vector<int>&pages,int n,int x)
{
   
     if(n == -1 || x == 0)  // base case if we run out of items or capacity of our knapsack becomes zero
       return 0;
      if(dp[n][x] !=-1)return dp[n][x]; // pruning repetetive computation
      
          if(price[n-1]>x)  // checking our capacity against the book we want to pick
            return dp[n][x] = knapsack(price,pages,n-1,x);
                
              return dp[n][x] = max(knapsack(price,pages,n-1,x),knapsack(price,pages,n-1,x-price[n-1])+pages[n-1]);  
            
    
   
     
  
} 
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
          dp.resize(n+1,vector<int>(x+1,-1));
       knapsack(price,pages,n,x);
       cout<<dp[n][x];
}

