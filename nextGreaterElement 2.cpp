#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> nextGreaterElements(vector<int>& nums) {
            stack<int>st;
            int n=nums.size();
            vector<int>ans(2*n); 

            for(int i=0;i<n;i++){
                nums.push_back(nums[i]);
            }

            for(int i=2*n-1;i>=0;i--){
                if(st.empty()){
                    ans[i]=-1;
                    st.push(nums[i]);
                }
                else{
                    if(st.top()>nums[i]){ans[i]=st.top(); st.push(nums[i]);}
                    else {
                        while(!st.empty() && st.top()<=nums[i]){
                            st.pop();
                        }
                        if(st.empty()){
                            ans[i]=-1;
                        }
                        else {
                            ans[i]=st.top(); 
                        }

                        st.push(nums[i]);
                    }
                }
            }

            ans.erase(ans.begin() + n, ans.end());

            return ans;
        }
    };