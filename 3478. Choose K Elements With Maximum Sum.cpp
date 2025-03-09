#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
            vector<pair<int,int>> arr1;
            int n=nums1.size();
            for(int i=0;i<n;i++){
                arr1.push_back({nums1[i],i});
            }
            sort(arr1.begin(),arr1.end());
            priority_queue<int,vector<int>,greater<int>> pq;
            long long sumOfPQ=0;
            vector<int>pending;

            vector<long long> ans(n);
            for(int i=0;i<n;i++){
                int idx=arr1[i].second;
                // int val=arr1[i].first;

                if(i>0 && arr1[i-1].first==arr1[i].first){
                    // sumOfPQ=updateSum(pq);
                    ans[idx]=ans[arr1[i-1].second];
                    pending.push_back(idx);
                    continue;
                }

                
                    for(auto x:pending){
                        if(pq.size()<k){pq.push(nums2[x]); sumOfPQ+=nums2[x];}
                        else if(pq.top()<nums2[x]){
                            sumOfPQ-=pq.top();
                            pq.pop();
                            sumOfPQ+=nums2[x];
                            pq.push(nums2[x]);
                        }
                    }
                

                pending.clear();
                ans[idx]=sumOfPQ;
                pending.push_back(idx);
            }
            return ans;
        }
    };
