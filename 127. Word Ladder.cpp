#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string>s(wordList.begin(),wordList.end());
            if(s.find(endWord)==s.end())return 0;
            
            queue<pair<string,int>>q;
            q.push({beginWord,1});
            while(!q.empty()){
                auto front=q.front(); q.pop();
                string str=front.first;
                int step=front.second;

                for(int i=0;i<str.size();i++){
                    string s1=str;
                    for(char ch='a';ch<='z';ch++){
                        str[i]=ch;
                        if(s.find(str)!=s.end()){
                            if(str==endWord)return step+1;
                            q.push({str,step+1});
                            s.erase(str);
                        }
                    }
                    str=s1;
                }
            }
            
            
            return 0;
        }
    };