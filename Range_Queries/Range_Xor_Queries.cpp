#include <bits/stdc++.h>
using namespace std;

vector<int>v;
vector<int>segtree;
void build(int node,int left,int right)
{  
     if(left ==right)
       {segtree[node] =v[left];return;}

     int mid  = (left+right)/2;
    build(2*node,left,mid);
    build(2*node+1,mid+1,right);
   segtree[node] = (segtree[2*node]^segtree[2*node+1]);
} 
int query(int node,int left,int right,const int a,const int b)
{
     if(a<=left &&  b>=right)
      return segtree[node];
     if(a>right || b<left)
      return 0;
     int mid   = (left+right)/2;
    return (query(2*node, left, mid, a, b)^query(2*node+1, mid+1, right, a, b));  
}  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int n,m;
     cin>>n>>m;
     v.resize(n);
     for(int i=0;i<n;i++)
       cin>>v[i];

     int size =1;
      while (size<n) {
          size*=2;      
      }
      segtree.resize(2*size);
      build(1, 0,n-1);
      while(m--)
      {
        int a,b;
        cin>>a>>b;
        a--,b--;
        cout<<query(1,0,n-1,a,b)<<"\n";
      }
    return 0;
}
