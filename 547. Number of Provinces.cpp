#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int ans=0;
            int n=isConnected.size();
            vector<bool>vis(n,false);
            
            
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    queue<int>q;
                    q.push(i);
                    vis[i]=true;
                    while (!q.empty()){
                        auto top=q.front();   q.pop();
                        for(int j=0;j<n;j++){
                            if(isConnected[top][j]==1 && !vis[j]){
                                q.push(j); vis[j]=true;
                            }
                        }
                    }
                    ans++;
                } 
            }
            return ans;
        }
    };