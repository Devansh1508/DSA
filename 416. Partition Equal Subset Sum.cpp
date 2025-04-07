#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool solve(vector<int>&nums,int target,int i){
            if(i>=nums.size() || target<0)return false;
            if(target==0)return true;

            int include=solve(nums,target-nums[i],i+1);
            int exclude=solve(nums,target,i+1);

            return (include || exclude)?true:false;
        }

        bool canPartition(vector<int>& nums) {
            int sum=accumulate(nums.begin(),nums.end(),0);
            if(sum%2==1)return false;
            return solve(nums,sum/2,0);
        }
    };