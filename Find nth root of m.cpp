#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      int nthRoot(int n, int m) {
          // Code here.
          long long low=1,high=m;
          if(n==1)return m;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(pow(mid,n)<=m)low=mid+1;
            else high=mid-1;
        }
        // cout<<low<<" "<<high<<endl;
        return (pow(high,n)!=m)?-1:high;
      }
  };