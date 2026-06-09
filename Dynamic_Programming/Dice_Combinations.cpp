#include<bits/stdc++.h>
using namespace std;
long long dp[1000000];
int f(int n)
{
   if(n<0)return 0;
   if(n ==0)
     return 1;
   if(dp[n]!=0)
     return dp[n]%1000000007;
     
  for(int i =1;i<=6;i++)
    {dp[n] += f(n-i);}
    return dp[n]%1000000007;  
}
int main()
{
    int n ;
    cin>>n;
   
    f(n); 
     
    cout<<(dp[n])%1000000007;
 
}

