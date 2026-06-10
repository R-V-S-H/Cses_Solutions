#include <bits/stdc++.h>
using namespace std;
//STATE dp[i][j] number of towers of height i+1(as i will be going from i=0 to n-1)whose to layer is j =0 -->split or j =1 -->joined 
//TRANSITION dp[i][0] = 4*dp[i-1][0]+1*dp[i-1][1] number of cases when top layer is split and accounting for all the cases for bottom layers when it is also split 4 cases and when it is joined 1 cases
//Similarly for dp[i][1] = 1*dp[i-1][j]+2*dp[i-1][j]  number of cases when top layer is joined and accounting for all the cases for bottom layers when it is also split 1 cases and when it is joined 2 cases
 const int MOD = 1e9+7;
 const int MAXM =1e6+1;
 long long split[MAXM],joined[MAXM];
void solve() {
       int n;
       cin>>n;

     cout<<(split[n-1]+joined[n-1])%MOD<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    split[0]=1,joined[0]=1;
  for(int i =1;i<MAXM;i++)
        {
              split[i] = (4*split[i-1]+1*joined[i-1])%MOD;
             
              joined[i] = (1*split[i-1]+2*joined[i-1])%MOD;
              

        }
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
