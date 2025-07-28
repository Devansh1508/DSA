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
    map<int,int>dp;
    void solve(vi &nums,int i,int xxor){
        if(i>=nums.size()){
            dp[xxor]++;
            return;
        }

        solve(nums,i+1,xxor|nums[i]);
        solve(nums,i+1,xxor);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        solve(nums,0,0);
        int maxi=0,ans=0;
        for(auto it:dp){
            if(it.first>maxi){
                maxi=it.first;
                ans=it.second;
            }
        }
        
        return ans;
    }
};