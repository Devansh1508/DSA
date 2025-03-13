#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
            int l=0,r=nums.size()-1;
            if(!isDiffrenceMatPos(queries,nums,l,r))return -1;

            while(l<=r){
                int mid=r+(l-r)/2;
                if(isDiffrenceMatPos(queries,nums,l,mid))r=mid-1;
                else l=mid+1;
            }
            return l;
        }

        bool isDiffrenceMatPos(vector<vector<int>>& queries,vector<int>& nums,int l,int r){
            vector<int>pre(nums.size()+1);
            for(int i=0;i<=r;i++){
                int left=queries[i][0],right=queries[i][1],val=queries[i][2];
                pre[l]+=val; pre[right+1]-=val;
            }

            int summ=0;
            for(int i=0;i<nums.size();i++){
                summ+=pre[i];
                if(summ<nums[i])return false;
            }

            return true;
        }
    };