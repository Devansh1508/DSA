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
    // int len(int n){
    //     return n==0?0:32-__builtin_clz(n);
    // }
    int dp[32][2][32];

    int solve(string &s,int i,int tight,int count){
        if(i==s.size())return count;
        if(dp[i][tight][count]!=-1)return dp[i][tight][count];

        int ans=0;
        int limit=(tight==1)?(s[i]-'0'):9;
        for(int j=0;j<=limit;j++){
            int updCount=count+((j==1)?1:0);
            ans+=solve(s,i+1,(tight & (s[i]-'0'==j)),updCount);
        }

        return dp[i][tight][count]=ans;
    }

    int countDigitOne(int n) {
        // int l=len(n);
        string s=to_string(n);
        memset(dp,-1,sizeof(dp));
        // cout<<"hello";
        return solve(s,0,1,0);
    }
};