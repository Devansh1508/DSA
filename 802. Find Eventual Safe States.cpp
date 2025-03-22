#include<bits/stdc++.h> 
using namespace std;
class Solution {
    public:
        vector<int>ans;
        bool isCycle(vector<vector<int>>& graph,vector<bool>&visited,vector<int>&isSafe,int state){
            if(isSafe[state]==2)return true;
            isSafe[state]=1;
            visited[state]=true;
            for(int neighbour=0;neighbour<graph[state].size();neighbour++){
                if(isSafe[state]!=2){
                    bool returnValue=isCycle(graph,visited,isSafe,neighbour);
                    if(returnValue){
                        isSafe[state]=2;
                        return true;
                    }
                }else{
                    return true;
                }
            }
            
            
            return  false;
        }
    
        vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
            int n=graph.size();
            vector<bool>visited(n,false);
            vector<int>isSafe(n,0);
    
            for(int i=0;i<n;i++){
                if(!isCycle(graph,visited,isSafe,i)){
                    ans.push_back(i);
                }
            }
    
            return ans;
        }
    };