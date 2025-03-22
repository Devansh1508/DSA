#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool canFinish(int n, vector<vector<int>>& pre) {
            if(pre.size()==0)return true;
            vector<int>in(n,0);
            vector<vector<int>>adj(n);
            for(auto p:pre){
                int first=p[1],second=p[0];
                in[second]++;
                adj[first].push_back(second);
            }
    
            queue<int>q;
            for(int i=0;i<n;i++){
                if(in[i]==0)q.push(i);
            }
    
            int ans=0;
            while(!q.empty()){
                auto front=q.front(); q.pop();
                for(auto x:adj[front]){
                    in[x]--;
                    if(in[x]==0)q.push(x);
                }
                ans++;
            }
    
            return ans==n;
        }
    };