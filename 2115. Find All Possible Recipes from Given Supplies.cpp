#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
            map<string,vector<string>>mp;
            int recSize=recipes.size(),ingSize=ingredients.size(),supSize=supplies.size();
            map<string,int>indeg;
            map<string,bool>sup;
            
            for(auto s:supplies)sup[s]=true;

            for(int i=0;i<ingSize;i++){
                for(auto ing:ingredients[i]){
                    mp[ing].push_back(recipes[i]);
                    indeg[recipes[i]]++;
                }
            }

            map<string,bool>vis;
            vector<string>ans;

            while(true){
                bool flag=false;
                for(auto it:indeg){
                    if(it.second==0 && !vis[it.first]){
                        for(auto connectedTo:mp[it.first]){
                            indeg[connectedTo]--;
                        }
                        vis[it.first]=true;
                        ans.push_back(it.first);
                        flag=true;
                    }
                }
                if(!flag)break;
            }

            return ans;

        }
    };