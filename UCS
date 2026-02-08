#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define vl vector<ll>
#define pb push_back
#define f first
#define se second

ll INF=1e15;

struct cmp{
    bool operator()(const pair<ll,ll>&a, const pair<ll,ll>&b)const{
         return a.f > b.f; 
    }
};

void shakil(){
    cout<<"Enter node no. and Edge no:"<<nl;
    ll node,edge;   cin>>node>>edge;

    vector<vector<pair<ll,ll>>>g(node+1);
    for(ll i=0;i<edge;i++){
        ll u,v,w;     cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }

    cout<<"Enter start node and goal node:"<<nl;
    ll start,goal;  cin>>start>>goal;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,cmp>pq;

    vl dist(node+1,INF);
    // vector<bool>vis(node+1,0);

    pq.push({0,start});

    while(!pq.empty()){
        auto [cost,node]=pq.top();pq.pop();

        if(cost>dist[node])continue;

        if(node==goal)break;
        for(auto [child,w]:g[node]){
            if(dist[node]+w<dist[child]){
                dist[child]=dist[node]+w;
                pq.push({dist[child],child});
            }
        }
    }

    cout<<"shortest path is:"<<nl;
    cout<<dist[goal]<<nl;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    shakil();
}
