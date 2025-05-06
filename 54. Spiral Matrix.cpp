#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int m=matrix.size(),n=matrix[0].size();
            bool flag=false;
            vector<int>ans(m*n,0);

            int i=0,j=0;
            int idx=0,didx=0;
            vector<vector<int>>dirs={{0,1},{1,0},{0,-1},{-1,0}};
            while(idx<ans.size()){
                ans[idx]=matrix[i][j];
                matrix[i][j]=1e9;

                i+=dirs[didx][0];
                j+=dirs[didx][1];
                
                if(i<0 || j<0 || i>=m || j>=n || matrix[i][j]==1e9){
                    i-=dirs[didx][0];
                    j-=dirs[didx][1];

                    didx=(didx+1)%4;
                    
                    i+=dirs[didx][0];
                    j+=dirs[didx][1];
                }

                idx++;
            }

            return ans;
        }
    };