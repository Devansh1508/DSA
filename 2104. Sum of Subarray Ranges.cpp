#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {
            stack<pair<int,int>>st;
            int n=nums.size();
            long long ans=0;
            for(int i=0;i<=n;i++){
                while(!st.empty() && (i==n || st.top().first>=nums[i])){
                    int mid=st.top().second;
                    st.pop();
                    int left=(st.empty())?-1:st.top().second;
                    ans-=(long long)nums[mid]*(i-mid)*(mid-left);
                }
                if(i<n)st.push({nums[i],i});
                else st.push({-1,n});
            }

            st.pop();
            for(int i=0;i<=n;i++){
                while(!st.empty() && (i==n || st.top().first<=nums[i])){
                    int mid=st.top().second; 
                    st.pop();
                    int left=(st.empty())?-1:st.top().second;
                    ans+=(long long)nums[mid]*(i-mid)*(mid-left);
                }
                if(i<n)st.push({nums[i],i});
                else st.push({-1,n});
            }
            return ans;
        }
    };