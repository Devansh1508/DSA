#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<vector<int>>>dp;
        int solve(vector<int>& nums, int i, int k,int maxi) {
            if(k==0)return maxi;
            if(i>=nums.size() && k!=0)return -1;
            if(dp[i][k][maxi]!=-1)return dp[i][k][maxi];

            int robbed,notRobbed;
            if(maxi==INT_MAX){
                robbed=solve(nums,i+2,k-1,nums[i]);
            }
            else robbed=solve(nums,i+2,k-1,max(maxi,nums[i]));
            
            notRobbed=solve(nums,i+1,k,maxi);

            robbed=(robbed==-1)?INT_MAX:robbed;
            notRobbed=(notRobbed==-1)?INT_MAX:notRobbed;

            return dp[i][k][maxi]=min({robbed,notRobbed});
        }
        

        int minCapability(vector<int>& nums, int k) {
            dp.resize(nums.size(),vector<vector<int>>(2,vector<int>(nums.size(),-1)));
            return solve(nums,0,k,INT_MAX);
        }
    };