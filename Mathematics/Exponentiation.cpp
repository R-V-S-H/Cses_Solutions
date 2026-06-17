#include <bits/stdc++.h>
using namespace std;
#define MOD  1000000007LL
typedef long long ll;
ll mod_exp(ll a,ll b ){
        ll res =1;
        while(b>0)
        {
           
             if(b & 1)
              {
               res= ((res%MOD)*(a%MOD))%MOD;
              } 
             a = ((a%MOD)*(a%MOD))%MOD; 
             b>>=1;
        }
        return res%MOD;
  
}
void solve() {
  long long a,b;
  cin>>a>>b;
  if(a == b && a == 0)
     cout<<1;
  else
   cout<<mod_exp(a,b);
  
    cout<<"\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
