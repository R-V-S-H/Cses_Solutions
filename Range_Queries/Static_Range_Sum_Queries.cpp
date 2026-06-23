#include <bits/stdc++.h>
using namespace std;
int main()
{ 
    int n,q;
    cin>>n>>q;
    vector<long long>v(n,0);
    vector<long long>prefix_sum(n+1,0);
    for(int i =0;i<n;i++)
    {
        cin>>v[i];
        prefix_sum[i+1] = prefix_sum[i]+v[i];
    }  
     while(q--)
     {
        int a,b;
        cin>>a>>b;
        cout<<prefix_sum[b]-prefix_sum[a-1]<<"\n";
     }
}
