#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        map<pair<int,int>,bool>dp;
        int n;

        bool solve(vector<int>& stones,int i,int k){
            if(i>=n)return false;
            if(i==n-1)return true;

            if(dp.find({i,k})!=dp.end())return dp[{i,k}];
            bool ans;
            for(int j=i+1;j<n;j++){
                if(stones[j]-stones[i]==k || stones[j]-stones[i]==k+1 || stones[j]-stones[i]==k-1)ans=solve(stones,j,stones[j]-stones[i]);
                else if(stones[j]-stones[i]>k+1)break;
                if(ans)return ans;
            }

            return dp[{i,k}]=false;
        }

        bool canCross(vector<int>& stones) {
            n=stones.size();
            if(stones[1]-stones[0]>1)return false;
            // int maxi=*max_element(stones.begin(),stones.end());
            // int mini=*min_element(stones.begin(),stones.end());
            // dp.resize(n,vector<int>(maxi-mini+1,-1));
            return solve(stones,1,1);
        }
    };