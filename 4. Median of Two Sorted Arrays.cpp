#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int low=0,high=nums1.size()-1;
            int total=nums1.size()+nums2.size();
            total=total/2;
            while(low<=high){
                int mid=low+(high-low)/2;
                int remainingEle=total-mid-1;
                int idx=remainingEle-1;
                if(nums1[mid]>nums2[idx]){
                    if((nums1.size()+nums2.size())%2==0){
                        return (min(nums1[mid+1],nums2[idx+1])+max(nums1[mid],nums2[idx]))/2;
                    }
                    else{
                        return min(nums1[mid+1],nums2[idx+1]);
                    }
                }
                else if(nums1[mid]<nums2[idx])low=mid+1;
                else high=mid-1;
            }
            return -1;
        }
    };