#include <bits/stdc++.h>
#include <array>
#define pb push_back
#define F first
#define S second
#define int long long
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

int mod=1e9+7;
void solve() {
    // Your solution code here
    int n;
    cin>>n;

    vi dp(n+1,0);

    dp[0]=1;
    rep(target,1,n+1){
        rep(i,1,7){
            // cout<<"hello";
            if(target-i>=0 && dp[target-i]>0){
                dp[target]=(dp[target]+dp[target-i])%mod;
            }
        }
    }
    // rep(i,0,n+1)cout<<dp[i]<<" ";
    cout<< dp[n];
}
int32_t main() {
    IOS
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}