    #include<bits/stdc++.h>
    using namespace std;

    class Solution {
        public:
            bool isVowel(string &word,int i){
                return word[i]=='a' || word[i]=='e' || word[i]=='o' || word[i]=='i' || word[i]=='u';
            }

            bool validString(int& consonantCount,int& k,map<char,int>&mp){
                return consonantCount==k && mp.size()==5;
            }

            long long solve(string &word, int k){
                int left=0,right=0;
                int n=word.size();
                map<char,int>mp;
                int consonantCount=0;
                long long ans=0;
                while(right<n){
                    if(isVowel(word,right)){
                        mp[word[right]]++;
                    }
                    else {
                        consonantCount++;
                    }
                    
                    while(mp.size()==5 && consonantCount>=k){
                        ans+=n-right;
                        if(isVowel(word,left)){
                            mp[word[left]]--;
                            if(mp[word[left]]==0)mp.erase(word[left]);
                        }
                        else consonantCount++;
                        left++;
                    }

                    if(mp.size()<5 && consonantCount>k){
                        while(consonantCount>k){
                            
                        }
                    }

                    right++;
                }
                return ans;
            }

            long long countOfSubstrings(string word, int k) {
                long long t1=solve(word,k);
                long long t2=solve(word,k+1);
                return t1-t2;

                // return solve(word,k);
            }
        };


