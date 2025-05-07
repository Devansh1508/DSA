#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int maxLen(vector<int>& arr) {
          // code here
          int sum=0;
          map<int,vector<int>>mp;
          int i=0;
          for(auto num:arr){
            sum+=num;
            mp[sum].push_back(i);
            i++;
          }
        mp[0].push_back(-1);
          int ans=0;
          for(auto it:mp){
            vector<int>v=it.second;
            int maxi=*max_element(v.begin(),v.end());
            int mini=*min_element(v.begin(),v.end());
            int len=maxi-mini;
            ans=max(ans,len);
          }

          return ans;
      }
  };