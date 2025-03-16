#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findPeakElement(vector<int>& nums) {
            int left=0,right=nums.size()-1;
            int mid;
            while(left<=right){
                mid=left+(right-left)/2;
                if(mid+1<nums.size() && nums[mid]<nums[mid+1])left=mid+1;
                else if(mid-1>=0 && nums[mid]<nums[mid-1])right=mid-1;
                else return mid;
            }
            return mid;
        }
    };
