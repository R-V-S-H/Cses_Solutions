#include <bits/stdc++.h>

using namespace std;
vector<int>segtree;
vector<int>v;
void build(int node,int left,int right)
{
    if(left == right)
    {
       segtree[node] = v[left]; // leaf node (segment of 1 element)
          return;
    }
    int mid = (left+right)/2;
    build(2*node,left,mid);
    build(2*node+1,mid+1,right);
   
    segtree[node] = min(segtree[2*node],segtree[2*node+1]);

} 
void update(int node,int left,int right,const int index,const int val)
{
      if(left == right)
      {
          segtree[node] = val;
          return;
      }
      int mid  = (left+right)/2;
      if(index<=mid)
      {update(2*node,left,mid,index,val);}
      else 
      {update(2*node+1,mid+1,right,index,val);}
      
       segtree[node] = min(segtree[2*node],segtree[2*node+1]);
}  
int query(int node,const int a,const int b,int left,int right)
{
        if(a<=left && b>=right)
        {return segtree[node];}
        if(a>right || b<left)
          return  INT_MAX;
         int mid  = (left+right)/2;
        return min(query(2*node,a,b,left,mid),query(2*node+1,a,b,mid+1,right));    
        
} 



int main()
{ 
    int n,q;
    cin>>n>>q;
    v.resize(n);
    int size =1;
    while(size<n){size*=2;}
    segtree.resize(2*size); 
    for(int i =0;i<n;i++)
    {
        cin>>v[i];
    } 
       build(1,0,n-1);
     while(q--)
     {
        int op,a,b;
        cin>>op>>a>>b;
          if(op==2){
          a--,b--;
           cout<<query(1,a,b,0,n-1)<<"\n";
          }
          else {
             a--;
             update(1, 0, n-1, a, b);
          }
         
     }
}

