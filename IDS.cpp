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
vector<vector<pair<int,int>>>g; 
int goal;

bool DLS(int node,int depth,vi& path,ll cost, ll& finalCost) {
    path.push_back(node);

    if(node==goal){
        finalCost = cost;  
        return true;       
    }

    if(depth == 0){      
        path.pop_back();
        return false;
    }

    for(auto [child, w] : g[node]) {
        if(DLS(child, depth - 1, path, cost + w, finalCost))
            return true;
    }

    path.pop_back();  
    return false;
}

bool IDS(int start) {
    int maxDepth = 0;
    vector<int>path;
    long long finalCost = 0;

    while(true) {
        path.clear();
        if(DLS(start, maxDepth, path, 0, finalCost)){
            cout << "Goal found at depth " << maxDepth <<nl;
            cout << "Path: ";
            for(int x : path) cout << x << " ";
            cout <<nl;
            cout << "Total cost: " << finalCost <<nl;
            return true;
        }
        maxDepth++;
    }
    return false;
}

void shakil(){
    int nodes, edges;
    cout<< "Enter number of nodes and edges:\n";
    cin>>nodes>>edges;

    g.assign(nodes + 1, {}); 

    cout << "Enter edges (u v w):"<<nl;

    for(int i = 0; i < edges; i++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    int start;
    cout << "Enter start node:\n";
    cin >> start;

    cout << "Enter goal node:\n";
    cin >> goal;

    if(!IDS(start)) cout << "Goal not found"<<nl;

}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    shakil();
}
