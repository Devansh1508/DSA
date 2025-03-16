#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool handle(vector<int>& arr, int k,int mid){
            int missing=arr[mid]-mid;
            return missing<=k;
        }

        int findKthPositive(vector<int>& arr, int k) {
            int low=0,high=arr.size()-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(handle(arr,k,mid))high=mid-1;
                else low=mid+1;
            }      
            return low>0?(arr[low-1]+(k-(arr[low-1]-low-1))):k;
        }
    };