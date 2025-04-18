#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int solve(vector<int>& prices){
            int mini=prices[0];
            int maxProfit=0;
            for(int i=1;i<prices.size();i++){
                mini=min(mini,prices[i]);
                maxProfit=max(maxProfit,prices[i]-mini);
            }
            return maxProfit;
        }

        int maxProfit(vector<int>& prices) {
            return solve(prices);
        }
    };