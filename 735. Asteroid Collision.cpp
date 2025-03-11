#include<bits/stdc++.h> 
using namespace std;

class Solution {
    public:
        bool willColloide(stack<int>&st,int incoming){
            return (st.top()<0 && incoming>0);
        }


        vector<int> asteroidCollision(vector<int>& asteroids) {
            stack<int>st;
            int n=asteroids.size();
            for(int i=n-1;i>=0;i--){
                if(st.empty())st.push(asteroids[i]);
                else{
                    if(willColloide(st,asteroids[i])){
                        bool flag=false;
                        while(!st.empty() && willColloide(st,asteroids[i])){
                            if(abs(st.top())<asteroids[i]){st.pop();}
                            else if(abs(st.top())==asteroids[i]){st.pop(); flag=true; break;}
                            else {flag=true; break;}
                        }
                        if(!flag)st.push(asteroids[i]);
                    }
                    else {st.push(asteroids[i]);}
                }
            }

            vector<int>ans;
            while(!st.empty()){
                ans.push_back(st.top()); st.pop();
            }
            return ans;
        }
    };