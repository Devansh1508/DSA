#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        map<bool,int>mp;
        int n;
        vector<bool>vis;
        vector<int>color;
        bool solve(vector<vector<int>>& graph,int node,bool flag){
            color[node]=mp[flag];
            vis[node]=true;
            for(int i=0;i<graph[node].size();i++){
                if(!vis[graph[node][i]]){
                    // vis[graph[node][i]]=true;
                    // color[graph[node][i]]=mp[flag];
                    bool ans=solve(graph,graph[node][i],!flag);
                    if(!ans)return ans;
                }
                else if(mp[flag]==color[graph[node][i]]){
                    return false;
                }
            }

            return true;
        }

        bool isBipartite(vector<vector<int>>& graph) {
            mp[false]=0;
            mp[true]=1;
            n=graph.size();
            vis.resize(n,false);
            color.resize(n,0);

            for(int i=0;i<n;i++){
                if(!vis[i] && !solve(graph,i,false)){
                    return false;
                }
            }

            return true;
        }
    };
