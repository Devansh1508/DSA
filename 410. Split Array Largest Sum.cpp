#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPossible(vector<int>& nums, int k,int target){
            int partition=1;
            long long summ=0;
            bool flag=false;
            for(auto x:nums){
                if(summ+x>target){
                    summ=x; partition++;
                }
                else summ+=x;
            }
            return partition<=k;
        }

        int splitArray(vector<int>& nums, int k) {
            int low=*max_element(nums.begin(),nums.end());
            int high=accumulate(nums.begin(),nums.end(),0);
            while(low<=high){
                int mid=low+(high-low)/2;
                if(isPossible(nums,k,mid))high=mid-1;
                else low=mid+1;
            }
            return low; 
        }
    };