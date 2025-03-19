#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isSafe(int i,int j,int m,int n){
            return i>=0 && i<m && j>=0 && j<n;
        }

        vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};

        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
            int m=image.size(),n=image[0].size();
            queue<pair<int,int>>q;
            q.push({sr,sc});
            int col=image[sr][sc];
            vector<vector<bool>>vis(m,vector<bool>(n,false));
            while(!q.empty()){
                auto front=q.front(); q.pop();
                int x=front.first,y=front.second;
                vis[x][y]=true;
                image[x][y]=color;
                for(auto dir:dirs){
                    int nx=x+dir[0];
                    int ny=y+dir[1];
                    if(isSafe(nx,ny,m,n) && image[nx][ny]==col && !vis[nx][ny]){
                        image[nx][ny]=color; vis[nx][ny]=true;
                        q.push({nx,ny});
                    }
                }
            }
            return image;
        }
    };