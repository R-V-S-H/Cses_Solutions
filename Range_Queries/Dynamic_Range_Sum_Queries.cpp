#include <bits/stdc++.h>
using namespace std;
vector<long long>seg;
vector<int>v;
void build(int node,int left,int right)
{
   if(left  == right)        // we reached at leaf
   { seg[node] = v[left];return;}  // assign the single array element
    
    int mid  = (left+right)/2;

     build(2*node,left,mid);
     build(2*node+1,mid+1,right);

   seg[node] = seg[2*node]+seg[2*node+1];
} 
long long query(int node,const int ql,const int qr,int node_l,int node_r)
{
      if(ql<=node_l && qr>=node_r)   // segment contained inside the query
        {return seg[node];}
      if(ql>node_r || qr<node_l)
        return 0;
      int mid  = (node_l+node_r)/2;
        return query(2*node, ql, qr,node_l,mid) +query(2*node+1,ql,qr,mid+1,node_r);
}
void update(int node,int left,int right,const int index,const int val)
{
           if(left == right)
           {
             seg[node] = val; return;
           }
           int mid  = (left+right)/2;

      if(index<=mid)
      {update(2*node,left,mid,index,val);}
      else 
      {update(2*node+1,mid+1,right,index,val);}
    seg[node] = seg[node*2]+seg[node*2+1];
}  
void solve() {
    int n,m;
    cin>>n>>m;
    int size =1;
    while(size<n)
    {
         size<<=1;
    }
     seg.resize(2*size);
     v.resize(n);
     for(int i =0;i<n;i++)
       cin>>v[i];
     build(1,0,n-1);
     while(m--)
     {
        int q,a,b;
        cin>>q>>a>>b;
        if(q ==1)
           {
              a--;
              update(1,0,n-1,a,b);
           }
        else{
           a--;b--;
            cout<<query(1,a,b,0,n-1)<<"\n";
         
         }
     }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}