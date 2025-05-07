    #include<bits/stdc++.h>
    using namespace std;

    class Solution {
        public:
            vector<int> majorityElement(vector<int>& nums) {
                int maj1=0,maj2=0,c1=0,c2=0,n=nums.size();
                vector<int>ans;

                for(auto num:nums){
                    if(maj1==num)c1++;
                    else if(maj2==num)c2++;
                    else if(c1==0){
                        maj1=num; c1=1;
                    }
                    else if(c2==0){
                        maj2=num; c2=1;
                    }
                    else {
                        c1--; c2--;
                    }
                }

                if(c1>0)c1=count(nums.begin(),nums.end(),maj1);
                if(c2>0)c2=count(nums.begin(),nums.end(),maj2);

                if(c1>n/3)ans.push_back(maj1);
                if(c2>n/3)ans.push_back(maj2);
                return ans;
            }
        };