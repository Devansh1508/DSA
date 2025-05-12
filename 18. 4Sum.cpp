#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            set<vector<int>> s;

            for (int x = 0; x < n - 3; x++) {
                for (int i = x + 1; i < n - 2; i++) {
                    int k = n - 1, j = i + 1;
                    while (j < k) {
                        long long sum = 1LL * nums[j] + nums[k] + nums[i] + nums[x]; // Use long long
                        if (target < sum) k--;
                        else if (target > sum) j++;
                        else {
                            vector<int> temp = {nums[x], nums[i], nums[j], nums[k]};
                            s.insert(temp);
                            j++;
                            k--;
                        }
                    }
                }
            }

            for (auto v : s) {
                ans.push_back(v);
            }

            return ans;
        }
};