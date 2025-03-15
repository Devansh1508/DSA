#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            if(nums.size()==1)return nums[0];
            int left=0,right=nums.size()-1;
            while(left<=right){
                int mid=(left+right)/2;
                if(mid-1<0 && nums[mid]!=nums[mid+1])return nums[mid];
                else if(mid+1>=nums.size() && nums[mid]!=nums[mid-1])return nums[mid];
                else if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])return nums[mid];
                else if(mid>0 && ((nums[mid]==nums[mid-1] && (mid-1)%2==0) || (mid<nums.size()-1 && (nums[mid]==nums[mid+1] && (mid)%2==0))))left=mid+1;
                else right=mid-1;
            }
            return -1;
        }
    };