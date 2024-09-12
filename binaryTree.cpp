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

void inOrderTraversal(node* root){
    if(root==NULL)return;
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(node* root){
    if(root==NULL)return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

void preOrderTraversal(node* root){
    if(root==NULL)return;
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main()
{
    node* root=buildTree(NULL);

    cout<<"level order traversal"<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"pre order traversal"<<endl;
    preOrderTraversal(root);

    cout<<endl<<"post order traversal"<<endl;
    postOrderTraversal(root);
    
    cout<<endl<<"in order traversal"<<endl;
    inOrderTraversal(root);
    return 0;
}