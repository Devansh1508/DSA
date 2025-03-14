#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool solve(vector<int>& nums, int target,int low,int high){
            while(low<=high){
                int mid=low+(high-low)/2;
                if(nums[mid]==target)return true;
                if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                    low++;high--;
                    continue;
                }

                if(nums[mid]>=nums[low]){
                    if(nums[mid]>target && nums[low]<=target)high=mid-1;
                    else low=mid+1;
                }
                else {
                    if(nums[mid]<target && nums[high]>=target)low=mid+1;
                    else high=mid-1;
                }
            }
            return false;
        }
        bool search(vector<int>& nums, int target) {
            int low=0,high=nums.size()-1;
            return solve(nums,target,low,high);
        }
    };