#include<bits/stdc++.h>
using namespace std;
vector<int> dp(1000001,1e9);

int f(int n)
{
    
    if(dp[n]!=1e9)
        return dp[n];
    int i =n;
    int c_min = 1e9;
    while(i)
    {  
        int d = i%10;
         if(d != 0)
         c_min = min(c_min,f(n-d));
         i/=10;
    }
    return dp[n] = c_min+1;
}
int main()
{
   int n;
   cin>>n;
   for(int i =0;i<10;i++)dp[i] =1;
   f(n);
   cout<<dp[n];

}