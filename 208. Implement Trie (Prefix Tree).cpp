#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode*child[26];
    bool isEnd;
    TrieNode(){
        isEnd=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        auto temp=root;
        for(char c:word){
            if(!temp->child[c-'a']){
                temp->child[c-'a']=new TrieNode();
                temp=temp->child[c-'a'];
            }
            else temp=temp->child[c-'a'];
        }
        temp->isEnd=true;
    }
    
    bool search(string word) {
        auto temp=root;
        for(char c:word){
            if(!temp->child[c-'a']){
                return false;
            }
            else temp=temp->child[c-'a'];
        }
        if(word=="app")cout<<temp->isEnd;
        if(temp->isEnd==true)return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        auto temp=root;
        for(char c:prefix){
            if(!temp->child[c-'a']){
                return false;
            }
            else temp=temp->child[c-'a'];
        }
        return true;
    }
};
