#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int i=0,j=0,k=0;
            int n=nums.size();
            sort(nums.begin(),nums.end());
            vector<vector<int>>ans;
            set<vector<int>>s;

            for(int i=0;i<n-2;i++){
                int val=-nums[i];
                k=n-1; j=i+1;
                while(j<k){
                    int sum=nums[j]+nums[k];
                    if(val<sum)k--;
                    else if(val>sum)j++;
                    else {
                        vector<int>temp;
                        temp={nums[i],nums[j],nums[k]};
                        
                        s.insert(temp);
                        j++; k--;
                    }
                }
            }

            for(auto v:s){
                ans.push_back(v);
            }

            return ans;
        }
    };