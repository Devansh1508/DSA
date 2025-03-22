#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector <int>dp;
        int solve(int n){
            if(n<=0)return 0;
            if(n==1)return 1;
            if(n==2)return 2;

            if(dp[n]!=-1)return dp[n];

            int ans=0;
            ans=solve(n-1)+solve(n-2);
            return dp[n]=ans;
        }

        int climbStairs(int n) {
            dp.resize(n+1,-1);
            return solve(n);
        }
    };