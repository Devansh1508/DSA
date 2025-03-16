#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isPossible(vector<int>& bloomDay, int days,int m,int k){
            int n=bloomDay.size(),ans=0,i=0;
            while(i<n){
                int pair=0;
                while(i<n && bloomDay[i]<=days){
                    pair++; i++;
                }
                // if(days==9)cout<<"pair "<<pair<<endl;
                ans+=pair/k; i++;
            }
            return ans>=m;
        }

        int minDays(vector<int>& bloomDay, int m, int k) {
            int n=bloomDay.size();
            if(n<(long long)m*k)return -1;
            int left=*min_element(bloomDay.begin(),bloomDay.end());
            int maxi=*max_element(bloomDay.begin(),bloomDay.end());
            int right=maxi;
            if(n==m*k)return maxi;

            while(left<=right){
                int mid=left+(right-left)/2;
                // cout<<left<<" "<<right<<endl;
                if(isPossible(bloomDay,mid,m,k))right=mid-1;
                else left=mid+1;
            }

            return left>maxi?maxi:left;
        }
    };