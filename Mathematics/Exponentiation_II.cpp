#include <bits/stdc++.h>
/*This problem can be same as Exponentiation problem we solved from binary exponentiation the trick here is the Little Fermat's Theorem*/
using namespace std; 
#define MOD (1000000007LL-1)
#define M 1000000007LL
typedef long long ll;
ll ipow(ll a, ll b, ll c) {
  ll res = 1;
   if(b == c && c==0)
        return a;
   while(c>0)
   {
       if(c&1){
          res = ((res%MOD)*(b%MOD))%MOD;
       }
       b = ((b%MOD)*(b%MOD))%MOD;
       c>>=1;

   }
   if(res == 0)return 1;
   ll n_res=1;
   while(res>0)
   { 
       if(res &1)
       {
         n_res = ((n_res%M)*(a%M))%M;
       }
        a= ((a%M)*(a%M))%M;
          res>>=1;
   }
  return n_res;
}
void solve() {
  ll a,b,c;
  cin>>a>>b>>c;

   cout<<ipow(a,b,c)<<"\n";

}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1;
  cin >> t;
  while (t--)
    solve();
  return 0;
}
