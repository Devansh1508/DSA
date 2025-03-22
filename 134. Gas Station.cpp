#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int totalGas=accumulate(gas.begin(),gas.end(),0);
            int totalCost=accumulate(cost.begin(),cost.end(),0);
            if(totalGas<totalCost)return -1;
            
            int n=gas.size();
            vector<int>temp(n);
            for(int i=0;i<n;i++){
                temp[i]=gas[i]-cost[i];
            }

            int sum=0,ind=0;
            for(int i=0;i<n;i++){
                sum+=temp[i];
                if(sum<0){
                    sum=0;
                    ind=i+1;
                }
            }
            return ind;
        }
    };

  
  