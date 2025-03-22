#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void solve(TreeNode* root, stack<int>&st){
            if(!root)return;
            st.push(root->val);
            solve(root->left,st);
            solve(root->right,st);
        }

        vector<int> postorderTraversal(TreeNode* root) {
            stack<int>st;
            solve(root,st);
            vector<int>ans;
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
            return ans;
        }


    };


    class Solution {
        public:
            vector<int> inorderTraversal(TreeNode* root) {
                if(!root)return {};
                stack<TreeNode*>st;
                st.push(root);
                vector<int>ans;
                TreeNode*current;
                while (!st.empty())
                {
                    while(!current){
                        current=current->left;
                        if(!current)st.push(current);
                    }
                    current=st.top(); st.pop();
                    ans.push_back(current->val);
                    st.push(current->right);
                    current=current->right;
                }

                return ans;
            }
        };