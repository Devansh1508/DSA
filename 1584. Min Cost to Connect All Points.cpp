#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int dist(int x1,int y1,int x2,int y2){
            return abs(x1-x2)+abs(y1-y2);
        }
    
        struct custom{
            int wt;
            pair<int,int> p1;
            pair<int,int> p2;
        };
    
        int minCostConnectPoints(vector<vector<int>>& points) {
            int m=points.size(),n=points[0].size();
            priority_queue<custom,vector<custom>,greater<custom>>pq;
    
            for(int i=0;i<m;i++){
                for(int j=i+1;j<n;j++){
                    int x1=points[i][0],y1=points[i][1];
                    int x2=points[j][0],y2=points[j][1];
                    pair<int,int>p1={x1,y1};
                    pair<int,int>p2={x2,y2};
                    int wt=dist(x1,y1,x2,y2);
                    custom temp={wt,p1,p2};
                    pq.push(temp);
                }
            }

            
        }
    };