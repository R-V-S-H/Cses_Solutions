#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&price,vector<int>&pages,int n,int x){
   
     if(n == -1 || x == 0)  // base case if we run out of items or capacity of our knapsack becomes zero
       return 0;
     
          if(price[n-1]>x)
            return knapsack(price,pages,n-1,x);
                
                return max(knapsack(price,pages,n-1,x),knapsack(price,pages,n-1,x-price[n-1])+pages[n-1]);  
            
    
   
     
  
} 
int main () {

         int n,x;
         cin>>n>>x;
          vector<int>pages(n),price(n) ;
         for(int i =0;i<n;i++)
          {
            cin>>price[i];
          }
          for(int i =0;i<n;i++)
          {
            cin>>pages[i];
          }
          
       cout<<knapsack(price,pages,n,x);
}


   
