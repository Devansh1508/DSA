#include <bits/stdc++.h>
#include <array>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node * right;

    node(int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node * root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1)return NULL;
    cout<<"enter the value of left child "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter the value of right child "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void levelOrderTraversal(node*root){
    queue<node*> q; 
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        auto treeNode=q.front();
        q.pop();
        if(treeNode==NULL){
            cout<<endl; 
            if(!q.empty())q.push(NULL); continue;
        }

        cout<<treeNode->data<<" ";
        if(treeNode->left)q.push(treeNode->left); 
        if(treeNode->right)q.push(treeNode->right);
    }
}

int main()
{
    node* root=buildTree(NULL);
    levelOrderTraversal(root);
    return 0;
}