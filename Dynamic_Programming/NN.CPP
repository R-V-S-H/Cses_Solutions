#include<bits/stdc++.h>
using namespace std;
int main()
{
     long long c = 0;
     long long ans=0;
    int n;
    string s;
     
    cin>>n>>s;
    vector<int>v;
    v.push_back(0);
    for(int  i =1;i<n;i++)
       { if(s[i-1]!=s[i])
          v.push_back(i);}
   v.push_back(n);
     int x = v.size();
    for(int  i =1;i<x-2;i++){
         c =0;
         if(s[v[i]-1] == s[v[i+1]])
         { 
            c = (v[i]-v[i-1])*(v[i+2]-v[i+1]);
             
          }
      ans+=c;
    }
   
    cout<<ans;
}

