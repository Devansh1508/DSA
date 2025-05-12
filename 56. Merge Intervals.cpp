#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            int lower=intervals[i][0];
            int higher=intervals[i][1];
            int size=ans.size();
            if(ans[size-1][0]<=lower && ans[size-1][1]>=lower){
                if(ans[size-1][1]<higher)ans[size-1][1]=higher;
            }
            else ans.push_back(intervals[i]);
        }

        return ans;
    }
};