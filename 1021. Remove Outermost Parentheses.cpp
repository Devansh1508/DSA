#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char>st;
        int left=0,right=0;
        int i=0;
        for(auto c:s){
            if(c=='(')left++;
            else right++;

            if(left==right){
                string temp=s.substr(i+1,i+left+right-1);
                ans+=temp;
                i=left+right;
                left=right=0;
            }
        }

        return ans;
    }
};

