#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int mySqrt(int x) {
            long long low=1,high=x;
            while(low<=high){
                float mid=low+(high-low)/2;
                auto midSq=mid*mid;
                if(midSq<x)low=(int)mid+1;
                else high=(int)mid-1;
            }
            return (low*low>x)?low-1:low;
        }
    };