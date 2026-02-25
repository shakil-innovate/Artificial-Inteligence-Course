#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define pb push_back
#define vl vector<ll>
#define all(v) v.begin(),v.end()
#define f first
#define se second
const ll INF = 1e18;

void shakil(){
  ll v=6,edge=8;
  vector<vector<pair<ll,ll>>>adj(v+1);
  adj[1].pb({2,4});
  adj[1].pb({3,2});
  adj[2].pb({4,5});
  adj[3].pb({4,8});
  adj[3].pb({5,10});
  adj[4].pb({6,6});
  adj[5].pb({6,3});
  adj[2].pb({5,7});

  ll start=1,end=6;

  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>pq;
  pq.push({0,start});
  vl dist(v+1,INF);
  dist[start]=0;

  vl parent(v+1,-1);
  ll expand=0;

  while(!pq.empty()){
    auto [cost,node]=pq.top();  pq.pop();
    if(dist[node]<cost)continue;
    if(node==end)break;

    // cout<<"node:"<<node<<nl;
    expand++;

    for(auto [child,w]:adj[node]){
        if(cost+w<dist[child]){
            dist[child]=w+cost;
            pq.push({dist[child],child});
            parent[child]=node;
        }
    }
  }

//   for(ll i=1;i<=v;i++)cout<<"i:"<<i<<" dist:"<<dist[i]<<nl;

  cout<<"optimal_path:";
  ll u=end;
  vl path;

  while(u!=-1){
    path.pb(u);
    u=parent[u];
  }
  reverse(all(path));

  for(auto it:path)cout<<it<<" ";cout<<nl;

  cout<<dist[end]<<nl;

  cout<<"expanded node:"<<expand<<nl;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll tt=1;
    while(tt--){
        shakil();
    }
}
