#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=nums1.size()-1;
        int s1=nums1.size(),s2=nums2.size();
        int k=s2-1,j=s1-s2-1;

        while(i>=0){
            if(j>=0 && k>=0 && nums1[j]<=nums2[k]){
                nums1[i]=nums2[k];
                k--;
            }
            else if(j>=0 && k>=0 && nums1[j]>nums2[k]){
                nums1[i]=nums1[j];
                j--;
            }
            i--;
        }

        while(k>=0){
            nums1[i]=nums2[k];
            k--;
            i--;
        }
    }
};

