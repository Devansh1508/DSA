#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    int n;

    int solve(vector<int>& height, int i) {
        if (i >= n - 1) return 0;  // Base Case: If at last stone, no more cost.
        
        if (dp[i] != -1) return dp[i];  // Use memoized result if available.
        
        // Cost of jumping to the next stone
        int ans = abs(height[i + 1] - height[i]) + solve(height, i + 1);
        
        // If two-step jump is possible, consider it
        if (i + 2 < n) {
            ans = min(ans, abs(height[i + 2] - height[i]) + solve(height, i + 2));
        }

        return dp[i] = ans;  // Store and return the result.
    }
    
    int solveIt(vector<int>& height){
        // if (i >= n - 1) return 0;  // Base Case: If at last stone, no more cost.
        
        // if (dp[i] != -1) return dp[i];  // Use memoized result if available.
        for(int i=1;i<n;i++){
            int ans = abs(height[i] - height[i-1])+dp[i-1];
            
            // If two-step jump is possible, consider it
            if (i-2>=0) {
                ans = min(ans, abs(height[i] - height[i-2])+dp[i-2]);
            }
            dp[i]=ans;
        }
        // Cost of jumping to the next stone

        return dp[n-1];
    }

    int minCost(vector<int>& height) {
        n = height.size();
        dp.resize(n);
        return solveIt(height);
    }
};