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

void solve() {
    // Your solution code here
    int n,target;
    cin>>n>>target;
    vi coins;
    rep(i,0,n){
        int t;
        cin>>t;
        coins.pb(t);
    }

    sort(all(coins));
    vi dp(target+1,INT_MAX);

    dp[0]=0;
    rep(t,1,target+1){
        for(auto coin:coins){
            if(t-coin>=0){
                dp[t]=min(dp[t],dp[t-coin]+1);
            }
        }
    }

    // rep(i,0,target+1)cout<<dp[i];
    if(dp[target]==INT_MAX){
        cout<<-1<<endl;
        return;
    }
    cout<<dp[target];
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