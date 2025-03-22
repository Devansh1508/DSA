#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int>segmentTree;
        void build(int ind,int left,int right){
            if(left==right) {

            }
            int mid=left+right;
            mid/=2;

            build(2*ind+1,left,mid);
            build(2*ind+2,mid+1,right);
            segmentTree[ind]=max(segmentTree[2*ind+1],segmentTree[2*ind+2]);
        }

        int query(int ind,int low,int high,int l,int r){
            if(low>=l && high<=r)return segmentTree[ind];

            if(high<l || low>r)return INT_MIN;
            int mid=(low+high)/2;
            int left=query(2*ind+1,low,mid,l,r);
            int right=query(2*ind+2,mid,high,l,r);
            return max(left,right);
        }

        int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
            
        }
    };