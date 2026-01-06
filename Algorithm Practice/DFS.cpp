#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <unordered_set>
using namespace std;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef long long ll;

void recursiveDFS(int V, vector<vint>& adj, int currDist, vint& distanceArr, vector<bool>& visited) {    
    distanceArr[V] = currDist; visited[V] = true;
    for (int adjNode : adj[V]) {
        if (!visited[adjNode]) {
            recursiveDFS(adjNode, adj, currDist+1, distanceArr, visited);
        }
    }
}

void iterativeDFS(int V, vector<vint>& adj, vint& distanceArr, vector<bool>& visited) {
    stack<int> s; s.push(V); visited[V] = true; distanceArr[V] = 0;
    while (!s.empty()) {
        int V = s.top(); s.pop();
        for (int adjNode : adj[V]) {
            if (!visited[adjNode]) {
                visited[adjNode] = true;
                distanceArr[adjNode] = distanceArr[V] + 1;
                s.push(adjNode);
            }
        }
    }
}

int main() {
    int N, M; cin >> N >> M;
    vector<vint> adj(N+1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vint distanceArr1(N+1); vector<bool> visited1(N+1, false);
    recursiveDFS(1, adj, 0, distanceArr1, visited1);

    cout << endl;
    for (int i = 1; i < N+1; i++) {
        if (visited1[i]) cout << i << " : " << distanceArr1[i] << endl;
        else cout << i << " : " << -1 << endl;
    }

    vint distanceArr2(N+1); vector<bool> visited2(N+1, false);
    iterativeDFS(1, adj, distanceArr2, visited2);

    cout << endl;
    for (int i = 1; i < N+1; i++) {
        if (visited2[i]) cout << i << " : " << distanceArr2[i] << endl;
        else cout << i << " : " << -1 << endl;
    }
    return 0;
}