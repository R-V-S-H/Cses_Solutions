#include <bits/stdc++.h>
using namespace std;
/*The number of factors of a number are (1+Xi)*(1+Xi+1)*(1+Xi+2).... Xi is the count of ith prime factor.Basic Combinatorics*/
void solve() {
     int n;
     cin>>n;
     long long ans =1;
     for(int x=2;x*x<=n;x++){
       int temp =1;
      while(n%x == 0)
      {
          temp++;
          n/=x;
      }
      
      ans = ans * (long long)temp;
     }
     if(n>1){ans=ans*2;} // for the last prime factor 
     cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
     cin >> t;
    while (t--) solve();
    return 0;
}
