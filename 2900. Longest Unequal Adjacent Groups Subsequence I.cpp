#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string>ans;
        bool flag;
        flag=groups[0]==0?true:false;
        ans.push_back(words[0]);
        for(int i=1;i<groups.size();i++){
            if(flag && groups[i]==1){
                flag=false; ans.push_back(words[i]);
               }
            else if(!flag && groups[i]==0){
                flag=true; ans.push_back(words[i]);
            }
        }

        return ans;
    }
};