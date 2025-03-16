#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool pilesFinished(vector<int>&piles,int h,int k){
            long long time=0;
            for(int i=0;i<piles.size();i++){
                time+=((long long)(piles[i]+k-1))/k;  //ceil
            }
            return time<=h;
        }

        int minEatingSpeed(vector<int>& piles, int h) {
            int maxElement=*max_element(piles.begin(),piles.end());
            int left=1,right=maxElement;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(pilesFinished(piles,h,mid))right=mid-1;
                else left=mid+1;
            }
            return left;
        }
    };