#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        unordered_map<string,int>mp;

    public:
        int solve(vector<int>& arr, int &target,int i,int sum){
            string key=to_string(i)+","+to_string(sum);
            if(mp.find(key)!=mp.end())return mp[key];
            if(sum==target)return 1; // i can be n and at that time correct solution possible
            if(i>=arr.size() || sum>target)return 0;

            if(arr[i]==0) return solve(arr,target,i+1,sum);
            int pick=solve(arr,target,i+1,sum+arr[i]);
            int notPick=solve(arr,target,i+1,sum);

            return mp[key]=pick+notPick;
        }

        int perfectSum(vector<int>& arr, int target) {
            // code here
            int count=0;
            for(int i=0;i<arr.size();i++){
                if(arr[i]==0)count++;
            }
            int ans= solve(arr,target,0,0);
            return ans*(1<<count);
        }
  };