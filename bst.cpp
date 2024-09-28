#include <bits/stdc++.h>
#include <array>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node (int val){
        this->data=val;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* insertIntoBST(Node*&root,int data){
    if(!root){
        root=new Node(data);
        return root;
    }
    if(data<root->data) root->left=insertIntoBST(root->left,data);
    else root->right=insertIntoBST(root->right,data);
    return root;
}

void takeInput(Node *&root){
    cout<<"enter the data"<<endl;
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cout<<"enter the data"<<endl;
        cin>>data;
    }
}

void levelOrderTraversal(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        auto node=q.front();
        q.pop();
        if(!node){
            cout<<endl;
            if(!q.empty())q.push(NULL);
            continue;
        }
        cout<<node->data<<" ";
        if(node->left)q.push(node->left);
        if(node->right)q.push(node->right);
    }
}

void deleteNode(Node*root,int val,Node*parent=NULL){
    parent=root;
    if(!root)return;
    if(root->data==val){
        while(root->left || root->right){
            parent=root;
            if(root->left){
                root->data=root->left->data;
                root=root->left;
            }
            else{
                root->data=root->right->data;
                root=root->right;
            }
        }
        if(parent->left==root)parent->left=NULL;
        else parent->right=NULL;
        delete root;
    }
    else if(root->data>val)deleteNode(root->left,val,parent);
    else deleteNode(root->right,val,parent);
}


int main()
{
    Node*root=NULL;
    takeInput(root);
    levelOrderTraversal(root);
    deleteNode(root,8);
    levelOrderTraversal(root);
    return 0;
}