#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int maximumCandies(vector<int>& candies, long long k) {
            int summ=accumulate(candies.begin(),candies.end(),0);
            if(summ<k)return 0;
            
        }
    };