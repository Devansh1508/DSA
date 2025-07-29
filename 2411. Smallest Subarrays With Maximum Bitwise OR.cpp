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

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vi ans(n),bits(31);
        rev(i,n-1,-1){
            int temp=nums[i];
            int j=0;
            while(temp>0){
                if(temp & 1)bits[j]=i;
                j++;
                temp=temp>>1;
            }
            j=0;
            rep(k,0,31){j=max(bits[k],j);}
            ans[i]=j-i+1;
        }
        return ans;
    }
};