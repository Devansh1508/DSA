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
    // logV ---> we will never have more than V enteries that will be valid for 
    // dist[]
    // O((V+E)log(V))
    bool solve(vc<vc<vc<int>>>& graph,vc<bool>&online,ll &k,int mid){
        int n=online.size();
        priority_queue<vl,vvl,greater<vl>>pq;
        pq.push({0,0});
        vl dist(n,LLONG_MAX);
        dist[0]=0;

        while(!pq.empty()){
            auto top=pq.top(); pq.pop();
            ll cost=top[0],curr=top[1];
            if(cost>dist[curr])continue;
            for(auto x:graph[curr]){
                int nxt=x[0],nxtCost=x[1];
                if(!online[nxt] || nxtCost<mid)continue;
                if(nxt==n-1){
                    dist[n-1]=min(dist[curr]+nxtCost,dist[n-1]);
                    if(dist[n-1]<=k)return true;
                    continue;
                }
                if(dist[nxt]>dist[curr]+nxtCost){
                    dist[nxt]=dist[curr]+nxtCost;
                    pq.push({dist[nxt],nxt});
                }
            }
        }

        return dist[n-1]<=k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        if(!online[0] || !online[n-1] || edges.size()==0)return -1;
        vc<vc<vc<int>>> graph(n);
        vi wt;
        for(auto e:edges){
            int a=e[0],b=e[1],c=e[2];
            graph[a].pb({b,c});
            wt.pb(c);
        }
        sort(all(wt));
        int low=0,high=wt.size()-1;
        int ans=-1;

        // O(logE*(O((V+E)*logV)))
        while(low<=high){
            int mid=(high-low)/2+low;
            if(solve(graph,online,k,wt[mid])){
                low=mid+1;
                ans=wt[mid];
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};