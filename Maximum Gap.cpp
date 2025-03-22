#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int maxSortedAdjacentDiff(vector<int>& arr) {
          // code here
          int maxi=*max_element(arr.begin(),arr.end());
          int mini=*min_element(arr.begin(),arr.end());

          vector<int>temp(maxi-mini+1,0);
          for(int i=0;i<arr.size();i++){
            temp[arr[i]-mini]++;
          }

          int ans=0,empty=0;
          for(int i=0;i<temp.size();i++){
            if(temp[i]==0)empty++;
            else empty=0;
            ans=max(ans,empty);
          }

          return ans+1;
      }
  };

  