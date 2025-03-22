#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<string >> ans;
        vector<string> backtrack(map<string,vector<string>>&parent,string &endWord,string &beginWord){
            if(endWord==beginWord){
                return endWord;
            }
            string str="";
            for(auto x:parent[endWord]){
                auto temp=backtrack(parent,x,beginWord);
                str+=temp+" ";
            }
            return str;

        }


        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string>s(wordList.begin(),wordList.end());
            if(s.find(endWord)==s.end())return ans;
            
            queue<string>q;
            map<string,vector<string>>parent;
            q.push(beginWord);
            bool flag=false;
            
            while(!q.empty() && !flag){
                int level=q.size();
                vector<string>toRemove;
                while(level--){
                    auto front=q.front(); q.pop();
                    string str=front;
    
                    for(int i=0;i<str.size();i++){
                        string s1=str;
                        for(char ch='a';ch<='z';ch++){
                            str[i]=ch;
                            if(s.find(str)!=s.end()){
                                if(str==endWord){
                                    flag=true;
                                    // parent[str].push_back(s1);
                                    parent[s1].push_back(str);
                                }
                                q.push(str);
                                toRemove.push_back(str);
                                parent[s1].push_back(str);
                            }
                            str=s1;
                        }
                    }
                    for(auto x:toRemove){
                        s.erase(x);
                    }
                }
            }


            
            
            return ans;
        }
    };