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
    int C, N; 
    cin >> C >> N;

    multiset<int> seniors;
    rep(i,0,C) {
        int time;
        cin >> time;
        seniors.insert(time);
    }
    multiset<pi> freshmen;
    rep(i,0,N) {
        int time1, time2;
        cin >> time1 >> time2;
        freshmen.insert({time1, time2});
    }

    int ans = 0;
    while (!(seniors.empty() || freshmen.empty())) {
        int time = *seniors.begin();
        pi fresh = *freshmen.begin();

        if (time < fresh.first) {
            seniors.erase(seniors.begin());
        } else if (time > fresh.second) {
            freshmen.erase(freshmen.begin());
        } else {
            seniors.erase(seniors.begin());
            freshmen.erase(freshmen.begin());
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}