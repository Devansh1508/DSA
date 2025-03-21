#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int n,m;
    bool isSafe(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }

    set<string>unique;
    void dfs(vector<vector<int>>& grid,int i,int j,string& s,char ch){
        if(!isSafe(i,j) || grid[i][j]==0)return ;
        
        grid[i][j]=0;
        s+=ch;
        dfs(grid,i-1,j,s,'U');
        dfs(grid,i+1,j,s,'D');
        dfs(grid,i,j+1,s,'R');
        dfs(grid,i,j-1,s,'L');
        s+='B';
    }

      int countDistinctIslands(vector<vector<int>>& grid) {
          // code here
            n=grid.size(); m=grid[0].size();

          for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                string s;
                if(grid[i][j]==1){
                    dfs(grid,i,j,s,'S');
                    unique.insert(s);
                }
            }
          }
          return unique.size();
      }
  };
