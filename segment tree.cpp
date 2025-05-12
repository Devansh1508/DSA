#include<bits/stdc++.h>
using namespace std;

class segmentTree{
    public:
        vector<int>tree;
        vector<int>arr;
        void build(int node,int start,int end){
            if(start==end){
                tree[node]=arr[start];
                return;
            }

            int mid=((end-start)/2)+start;
            build(2*node,start,mid);
            build(2*node+1,mid+1,end);
            tree[node]=tree[2*node]+tree[2*node+1];
        }

        int query(int node,int start,int end,int l,int r){
            if(r<start || end<l)return 0;
            if(start>=l && end<=r)return tree[node];

            int mid=((end-start)/2)+start;
            int leftSum=query(node,start,mid,l,r);
            int rightSum=query(node,mid+1,end,l,r);

            return leftSum+rightSum;
        }

};