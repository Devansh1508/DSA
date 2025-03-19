#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isSafe(int i,int j,int m,int n){
            return i>=0 && i<m && j>=0 && j<n;
        }

        vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};

        void dfs(vector<vector<int>>& grid,int i,int j){
            if(!isSafe(i,j,grid.size(),grid[0].size()) || grid[i][j]==0)return;
            grid[i][j]=0;
            for(auto dir:dirs){
                int nx=i+dir[0],ny=j+dir[1];
                dfs(grid,nx,ny);
            }
        }

        int numEnclaves(vector<vector<int>>& grid) {
            int m=grid.size(),n=grid[0].size();
            for(int i=0;i<m;i++){
                if(grid[i][0]==1)dfs(grid,i,0);
                if(grid[i][n-1]==1)dfs(grid,i,n-1);
            }
            for(int i=0;i<n;i++){
                if(grid[0][i]==1)dfs(grid,0,i);
                if(grid[m-1][i]==1)dfs(grid,m-1,i);
            }

            int ans=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]==1){
                        ans++;
                    }
                }
            }

            return ans;
        }
    };