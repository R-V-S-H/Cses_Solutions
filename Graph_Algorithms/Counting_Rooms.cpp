#include <bits/stdc++.h>
using namespace std;
vector<bool>visited;
void dfs(vector<vector<int>>&adj,int start_node)
{
     if(visited[start_node])return;
      visited[start_node] =true;
      for(auto u:adj[start_node])
      {
           dfs(adj,u);
      }



} 
void solve() {
     int n,m;
     cin>>n>>m;
     vector<vector<int>>adj(n*m+1);
     vector<vector<char>>v(n,vector<char>(m));
     for(int i=0;i<n;i++ )
       for(int j =0;j<m;j++)
       {
          cin>>v[i][j];
    
        }  
      visited.resize(n*m+1,true);
     for(int i=0;i<n;i++ )
       for(int j =0;j<m;j++)
       {
          if(v[i][j] =='.')
           {
               visited[i*m+j] =false;
               int di[] ={-1,1,0,0};
                        
               int dj[] ={0,0,1,-1};
               for(int k=0;k<4;k++)
                  {
                      int x = i+di[k];
                      int y = j+dj[k];
                      if(x>=0 && x<n && y<m && y>=0 && v[x][y] == '.')
                      { adj[i*m+j].push_back(x*m+y);
                        adj[x+y].push_back(i+j);
                        
                      }
                            
                  }
           }      
        
       }
      int rooms =0;
         for(int i=0;i<n;i++ )
       for(int j =0;j<m;j++)
            {
                    if(v[i][j] == '.' && visited[i*m+j] ==false)
                    {
                       rooms++;
                       dfs(adj,i*m+j);
                           
                    }
            }
         cout<<rooms;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
