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

pair<vint,vector<bool>> BFS(int N, int S, vector<vint> adj) {
    queue<int> q; vector<bool> visisted(N+1, false); vint distanceArr(N+1);
    
    
    distanceArr[S] = 0; visisted[S] = true; q.push(S);
    int level = 1;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int node = q.front(); q.pop();
            for (int adjNode : adj[node]) {
                if (visisted[adjNode]) continue;
                distanceArr[adjNode] = level;
                visisted[adjNode] = true;
                q.push(adjNode);
            }
        }
        level++;
    }
    return {distanceArr, visisted};
}

int main() {
    int N, M; cin >> N >> M;
    vector<vint> adj(N+1);
    for (int i = 0; i < M; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    pair<vint, vector<bool>> x = BFS(N, 1, adj);
    vint distanceArr = x.first; vector<bool> visited = x.second;

    cout << endl;
    for (int i = 1; i < N+1; i++) {
        if (visited[i]) cout << i << " : " << distanceArr[i] << endl;
        else cout << i << " : " << -1 << endl;
    }

    return 0;
}