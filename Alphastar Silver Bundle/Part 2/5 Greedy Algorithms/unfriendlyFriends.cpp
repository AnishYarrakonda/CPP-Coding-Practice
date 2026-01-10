#include <bits/stdc++.h>
using namespace std;

// basic types
using ll = long long;
using db = double;
using str = string;

// generic templates
template<typename A, typename B> using p = pair<A,B>;               // Pair
template<typename T> using v = vector<T>;                           // 1D vector
template<typename T> using vv = vector<vector<T>>;                  // 2D vector
template<typename T> using uset = unordered_set<T>;                 // unordered set
template<typename K, typename V> using umap = unordered_map<K,V>;   // unordered map

// even shorter shorthands for data types dealing with int
using pi = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;

// macros
#define rep(i,a,b) for(int i = a; i < (b); i++)     // for loop
#define all(x) (x).begin(),(x).end()                // entire container

// debugging (print 1D and 2D vectors to console)
template<typename T> void prettyprint(const v<T>& vec) { for(auto &x : vec) cout << x << ' '; cout << '\n'; }
template<typename T> void prettyprint(const vv<T>& mat) { for(auto &row : mat) prettyprint(row); }
template<typename T> void prettyprintnewline(const v<T>& vec) { for(auto &x : vec) cout << x << '\n'; }

// Solution Code below

int main() {
    int N, K;
    cin >> N >> K;

    priority_queue<pi, v<pi>, greater<pi>> pq;

    rep(i,0,K) {
        int u, v;
        cin >> u >> v;

        pq.push({u,v});
        pq.push({v,u});
    }

    int ANS = 0;

    int start = 0;
    int meanest = 1e9;

    while (!pq.empty()) {

        auto [u, v] = pq.top();
        pq.pop();

        if (u == meanest) {
            start = u;
            meanest = 1e9;
            ANS++;
        }


    }

    cout << ANS << endl;


    return 0;
}