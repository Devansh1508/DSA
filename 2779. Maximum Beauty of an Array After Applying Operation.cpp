#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int maximumBeauty(vector<int>& nums, int k) {
            int minNum= *min_element(nums.begin(), nums.end());
            int mini=minNum-k;
            if(mini<0){
                mini=abs(mini);
                for(auto &num:nums){
                    num+=mini;
                }
            }
            int maxNum= *max_element(nums.begin(), nums.end());
            vector<int> prefix(maxNum+2+k, 0);
            for(auto num:nums){
                int start = num-k,end=num+1+k;
                prefix[start]++;
                prefix[end]--;
            }
            
            int maxBeauty,sum=0;   
            for(int i=0;i<prefix.size();i++) {
                sum+=prefix[i];
                maxBeauty = max(maxBeauty, sum);
            }
            return maxBeauty;
        }  
    };