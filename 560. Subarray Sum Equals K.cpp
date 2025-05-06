#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int subarraySum(vector<int>& nums, int k) {
            int n=nums.size();
            int preSum=0;
            unordered_map<int,int>mp;
            mp[0]++;
            int ans=0;
            for(int i=0;i<n;i++){
                preSum=preSum+nums[i];
                if(mp.find(preSum-k)!=mp.end()){
                        ans+=mp[preSum-k];
                    }

                mp[preSum]++;
            }

            return ans;
        }
    };