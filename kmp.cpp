#include <bits/stdc++.h>
#include <array>
#define pb push_back
#define F first
#define S second
// #define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair<int,int>
#define vvi vector<vector<int>>
#define vi vector<int>
#define vpii vector<pii>
#define vvpii vector<vector<pii>>
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define vc vector
#define L cout<<'\n';
#define E cerr<<'\n';
#define all(x) x.begin(),x.end()
#define rep(i,a,b) for (int i=a; i<b; ++i)
#define rev(i,a,b) for (int i=a; i>b; --i)
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define setpr(x) cout<<setprecision(x)<<fixed
#define sz size()
#define inpa(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define inpv(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define inps(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

using namespace std;

class Solution {
public:
    vi construct(string &s){
        int len=0,i=1;
        vi lps(s.sz,0);
        while(i<s.sz){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                // checking where the last matched character was found 
                if(len!=0){
                    len=lps[len-1];
                }else{
                    i++;
                }
            }
        }
        return lps;
    }

    bool kmp(string& s,string& p){
        int n=s.sz;
        vi lps=construct(p);

        int i=0,j=0;
        while(i<n){
            if(j==p.sz)return true;
            
            // simple matching 
            if(s[i]==p[j]){
                i++;
                j++;
            }else{
                // last time last matched letter kaha mila tha 
                if(j!=0){
                    j=lps[j-1];
                }
                // j==0 ---> j-1 is not a legal entry for vector 
                else{
                    i++;
                }
            }
        }
        cout<<j<<" "<<p.sz;
        if(j==p.sz)return true;
        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string s;
        int count=0;
        while(s.sz<b.sz){
            s+=a;
            count++;
        }
        // cout<<s;
        if(kmp(s,b))return count;
        s+=a;
        count++;
        if(kmp(s,b))return count;

        return -1;
    }
};