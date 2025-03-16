#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPossible(vector<int>& nums, int threshold,int divisor){
            int summ=0;
            for(auto x:nums){
                summ+=(x+divisor-1)/divisor;
            }
            return summ<=threshold;
        }

        int smallestDivisor(vector<int>& nums, int threshold) {
            int left=1;
            int right=*max_element(nums.begin(),nums.end());
            while(left<=right){
                int mid=left+(right-left)/2;
                if(isPossible(nums,threshold,mid))right=mid-1;
                else left=mid+1;
            }
            return left;
        }
    };