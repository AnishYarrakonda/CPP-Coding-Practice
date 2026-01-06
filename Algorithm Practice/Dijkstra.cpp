#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;
typedef long long ll;

// basic dijkstra function that returns distance array of all node distances from node S
vector<ll> dijkstra(int N, vector<vector<pair<int,int>>> adj, int S) {
    // initialize Priority Queue and Distance Array
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    vector<ll> dist(N+1, 1e18); dist[S] = 0; pq.push({0, S});

    // while there are entries
    while (!pq.empty()) {
        // save the distance and node for the entry, then pop
        ll d = pq.top().first; int node = pq.top().second; pq.pop(); 
        
        if (d > dist[node]) continue;           // skip if outdated

        // traverse all adjacent nodes
        for (auto it : adj[node]) {
            // store the adj node and the edge weight
            int adjNode = it.first; int edgeWeight = it.second;
            ll newDist = d + edgeWeight;        // calculate the new distance

            // if the new distance is shorter than the current best distance to adjNode
            if (newDist < dist[adjNode]) {
                dist[adjNode] = newDist;        // update the best distance
                pq.push({newDist, adjNode});    // push a new entry
            }
        }
    }
    return dist;    // return the distance array once the priority queue is exhausted
}

int main() {
    int N, M; cin >> N >> M;
    vector<vector<pair<int,int>>> adj(N+1);
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int S; cin >> S;

    vector<ll> distanceArray = dijkstra(N, adj, S);
    
    cout << endl;
    for (int i = 1; i < N+1; i++) cout << distanceArray[i] << endl;

    return 0;
}