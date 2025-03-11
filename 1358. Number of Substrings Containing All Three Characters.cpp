#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int numberOfSubstrings(string s) {
            int ans=0,n=s.size(),count=0;
            int left=0,right=0;
            map<int,int>mp;
            int &i=right;
            while(right<n){
                if(s[i]=='a'||s[i]=='b'||s[i]=='c')mp[s[i]-'a']++;
                // if(mp.size()==3)cout<<i<<endl;
                while(mp.size()==3){
                    ans+=n-right;
                    if(s[left]=='a'||s[left]=='b'||s[left]=='c')mp[s[left]-'a']--;
                    if(mp[s[left]-'a']==0)mp.erase(s[left]-'a');
                    left++;
                }
                // cout<<left<<" "<<right<<ans<<endl;
                right++;
            }

            return ans;
        }
    };