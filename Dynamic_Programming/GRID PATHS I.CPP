#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
vector<int> v;
vector<vector<int>>dp(10001,vector<int>(10001,-1));
int solve (int k ,int j){

  if(k == 0)return 1;
  if(j>=v.size() || v[j]>k)return 0;
  if(dp[k][j]!=-1)return dp[k][j];
  int a1 =0; 
  a1 = solve(k-v[j],j)+solve(k,j+1);
  return dp[k][j] = a1;  
} 
int main () {

          int n,k;
          cin>>n>>k;
           v.resize(n);
          for(int i =0;i<n;i++)
           cin>>v[i];
      solve(k,0);
        int sum =0;
       for(int i =0;i<n;i++)
          sum+=dp[k][i];
        cout<<sum-1;
}


   
    