#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isSafe(int i,int j,int m,int n){
            return i>=0 && i<m && j>=0 && j<n;
        }

        vector<vector<int>>dirs={{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>>dir1={{0,1},{1,0}};

        void solve(vector<vector<char>>& board) {
            int m=board.size(),n=board[0].size();
            queue<pair<int,int>>q;

            for(int i=0;i<n;i++){
                if(board[0][i]=='O'){board[0][i]='$'; q.push({0,i});}
                if(board[m-1][i]=='O'){board[m-1][i]='$'; q.push({m-1,i});}
            }

            for(int i=0;i<m;i++){
                if(board[i][0]=='O'){board[i][0]='$'; q.push({i,0});}
                if(board[i][n-1]=='O'){board[i][n-1]='$'; q.push({i,n-1});}
            }
            
            while(!q.empty()){
                auto front=q.front(); q.pop();
                int x=front.first, y=front.second;
                for(auto dir:dirs){
                    int nx=x+dir[0], ny=y+dir[1];
                    if(isSafe(nx,ny,m,n) && board[nx][ny]=='O'){
                        board[nx][ny]='$';
                        q.push({nx,ny});
                    }
                }
            }
            
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]=='O')board[i][j]='X';
                    else if(board[i][j]=='$')board[i][j]='O';
                }
            }
        }
    };