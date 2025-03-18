#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isSafe(int i,int j,int m,int n){
            return i>=0 && j>=0 && i<m && j<n;
        }
    
        vector<vector<int>>dirs={{1,0},{0,1}};
    
        int genIdx(int i,int j,int rows){
            return i*rows+j;
        }
    
        int getParent(vector<int>&parent,int x){
            if(parent[x]==x)return x;
            return getParent(parent,parent[x]);
        }
    
        void handle(vector<int>&parent,vector<int>&rank,int x,int y){
            int px=getParent(parent,x);
            int py=getParent(parent,y);
    
            if(rank[px]>rank[py]){
                parent[py]=px;
                rank[px]++;
            }
            else if(rank[px]<rank[py]){
                parent[px]=py;
                rank[py]++;
            }
            else{
                parent[px]=py;
                rank[py]++;
            }
        }
    
        int numIslands(vector<vector<char>>& grid) {
            int m=grid.size(),n=grid[0].size();
            vector<int>parent(m*n),rank(m*n,0);
            for(int i=0;i<m*n;i++)
                parent[i]=i;
    
            vector<vector<bool>>vis(m,vector<bool>(n,false));
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='1'){
                        for(auto dir:dirs){
                            int nx=i+dir[0],ny=j+dir[1];
                            int idnx=genIdx(nx,ny,n);
                            int idx=genIdx(i,j,n);
                            
                            if(isSafe(nx,ny,m,n) && grid[nx][ny]=='1')
                                handle(parent,rank,idnx,idx);
                        }
                    }
                }
            }
            unordered_set<int>s;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(grid[i][j]=='1')
                    s.insert(getParent(parent,genIdx(i,j,n)));
                }
            }
    
            return s.size();
        }
    };