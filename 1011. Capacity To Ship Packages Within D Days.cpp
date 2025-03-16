#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPossible(vector<int>& weights, int days,int capacity){
            int ans=1,i=0,n=weights.size();
            int temp=0;
            while(i<n){
                    if(temp+weights[i]>capacity){
                        temp=0; ans++;
                    }
                    temp+=weights[i]; i++;
            }
            return ans<=days;
        }

        int shipWithinDays(vector<int>& weights, int days) {
            int high=accumulate(weights.begin(),weights.end(),0);
            int low=*max_element(weights.begin(), weights.end());;

            while(low<=high){
                int mid=low+(high-low)/2;
                if(isPossible(weights,days,mid))high=mid-1;
                else low=mid+1;
            }
            return low;
        }
    };