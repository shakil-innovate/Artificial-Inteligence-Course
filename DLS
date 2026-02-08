#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define vl vector<ll>
#define pb push_back
#define f first
#define se second
#define vi vector<int>

ll INF=1e15;

vector<vector<pair<int,int>>> g; 
int goal;

bool DLS(int node, int depth,vi& path,ll cost, ll& finalCost, vector<bool>& vis) {
    path.push_back(node);
    vis[node] = true;  

    if(node == goal){
        finalCost = cost;  
        return true;
    }

    if(depth == 0){  
        path.pop_back();
        vis[node] = false; 
        return false;
    }

    for(auto [child, w] : g[node]){
        if(!vis[child]){
            if(DLS(child, depth - 1, path, cost + w, finalCost, vis))
                return true; 
        }
    }

    path.pop_back();      
    vis[node] = false;   
    return false;
}

void shakil(){
    int nodes, edges;
    cout << "Enter number of nodes and edges:"<<nl;
    cin >> nodes >> edges;

    g.assign(nodes + 1, {});

    cout << "Enter edges (u v w):\n";
    for(int i = 0; i < edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); 
    }

    int start;
    cout << "Enter start node:"<<nl;
    cin >> start;

    cout << "Enter goal node:"<<nl;
    cin >> goal;

    vector<int> path;
    long long finalCost = 0;
    vector<bool> vis(nodes + 1, false);

    int depthLimit;
    cout << "Enter depth limit for DLS:"<<nl;
    cin >> depthLimit;

    if(DLS(start, depthLimit, path, 0, finalCost, vis)){
        cout << "Goal found within depth " << depthLimit <<nl;
        cout << "Path: ";
        for(int x : path) cout << x << " ";
        cout << "\nTotal cost: " << finalCost <<nl;
    } else {
        cout << "Goal not found within depth " << depthLimit <<nl;
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    shakil();
}
