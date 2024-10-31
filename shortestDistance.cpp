#include <bits/stdc++.h>
#include <array>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<pair<int,int>>> adjList;

    void addEdge(int u,int v,int wt){
        pair <int,int> p={v,wt};
        adjList[u].push_back(p);
    }

    void printAdj(){
        for (auto i:adjList){
            cout<<i.first<<"->";
            for(auto j:adjList[i.first]){
                cout<<"("<<j.first<<","<<j.second<<")";
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,2,2);
    g.addEdge(1,3,6);
    g.addEdge(2,3,7);
    g.addEdge(2,4,4);
    g.addEdge(2,5,2);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-2);

    g.printAdj();
    int N=6;
    // implementing topological sort 
    // kahn's algorithm 
    vector<bool>visited(N);
    stack<int>s;
    queue<int>q;
    vector<int>indegree(N,0);

    for(int i=0;i<N;i++){
        for(auto j:g.adjList[i]){
            indegree[j.first]++;
        }
    }

    for(int i=0;i<N;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        auto front=q.front();   q.pop();
        s.push(front);
        for(auto i:g.adjList[front]){
            indegree[i.first]--;
            if(indegree[i.first]==0){
                q.push(i.first);
            }
        }
    }

    vector<int>path;
    while(!s.empty()){
        path.push_back(s.top());
        s.pop();
    }

    reverse(path.begin(),path.end());

    // basic topologiacal sort done 
    // now we will implement shortest path algorithm
    vector<int>dist(N,INT_MAX);
    dist[1]=0;

    for(int i=1;i<path.size();i++){
        for(auto j:g.adjList[i]){
            if(dist[j.first]>dist[i]+j.second){
                dist[j.first]=dist[i]+j.second;
            }
        }
    }

    for(auto x:dist){
        cout<<x<<" ";
    }

    return 0;
}
