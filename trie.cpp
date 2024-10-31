#include <bits/stdc++.h>
#include <array>
using namespace std;

class TrieNode{
    public:
    char data;
    TrieNode*children[26];
    bool isTerminal;

    TrieNode(int ch){
        data=ch;
        for(int i=0;i<26;i++)children[i]=NULL;
        isTerminal=false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie (){
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode*root, string word){
        if(word.length()==0){root->isTerminal=true; return;}
        TrieNode*child;
        int index=word[0]-'A';
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));

    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word){
        if(word.length()==0)return root->isTerminal;

        int index=word[0]-'A';
        TrieNode*child;

        if(root->children[index]){
            child=root->children[index];
        }else{return false;}

        return searchUtil(child,word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root,word);
    }

    void deleteUtil(TrieNode*root,string word){
        if(word.length()==0 && root->isTerminal){root->isTerminal=false; return;}
        else if (word.length()==0 && !root->isTerminal){return;}
        // considering word is present in the trie 
        int index=word[0]-'A';
        TrieNode*child;
        child=root->children[index];
        deleteUtil(child,word.substr(1));
    }

    void deleteWord(string Word){
        deleteUtil(root,Word);
    }
};

int main()
{
    Trie *t=new Trie();
    t->insertWord("HELLO");
    t->insertWord("TIME");
    t->insertWord("TIMY");

    cout<<"is it present "<<t->searchWord("HELLO")<<endl;
    cout<<"is it present "<<t->searchWord("TIM")<<endl;
    t->deleteWord("HELLO");
    cout<<"is it present "<<t->searchWord("HELLO")<<endl;
    
    return 0;
}