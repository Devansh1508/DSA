#include<bits/stdc++.h>
using namespace std; 

class Solution {
    public:
        bool isPos(vector<int>&temp,int i){
            return (temp[i]%2==0 && temp[i-1]%2==1) || (temp[i]%2==1 && temp[i-1]%2==0);
        }
    
        vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
            int n=nums.size();
            vector<bool>ans;
            vector<int>temp(n);
            for(int i=1;i<n;i++){
                if(isPos(nums,i))temp[i]=temp[i-1]+1;
                else temp[i]=temp[i-1];
            }
            // for (auto x:temp)cout<<x<<" ";
    
            for(auto q:queries){
                int l=q[0],r=q[1];
                if(r-l==temp[r]-temp[l])ans.push_back(true);
                else ans.push_back(false);
            }
    
            return ans;
        }
    };