#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define y1 y3278
#define sz(v) int(v.size())
#define y2 y4368
#define y y4368232
#define x x43682322
#define ff first
#define ss second
#define pb push_back
#define all(a) a.begin(),a.end()
#define tm tm3278
#define left left3278
#define right right3278
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template<class T> using Pair_indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const long long INF = 2000000000000000000;
const long long Maxll = 9223372036854775807;
const long long MOD = 1000000000000037;
const int MOD2 = 1100000009;
const int inf = 1000000000;
const long long q0 = 31;
const int differ = 'a' - 'A';
const int logg = 20;

template<class T>
istream &operator>>(istream &in, vector<T> &a) {
    for (T &i: a) in >> i;
    return in;
}

template<class T>
ostream &operator<<(ostream &out, vector<T> &a) {
    for (T &i: a) out << i + 1 << ' ';
    out << '\n';
    return out;
}

template<class T>
ostream &operator<<(ostream &out, set<T> &a) {
    out << a.size() << '\n';
    for (T i: a) out << i << ' ';
    return out;
}

/// Actual code starts here
int t, n, m, k, timer;
vector<int> g[500005];
vector<pair<int, int>> tr;
int lvl[900005], fst[900005];

vector<int> el;

pair<int, int> comb(pair<int, int> x, pair<int, int> y) {
    if (x.ff <= y.ff)
        return x;
    else
        return y;
}

int left_son(int v) {
    return v * 2 + 1;
}

int right_son(int v) {
    return v * 2 + 2;
}

void relax(int v) {
    tr[v] = comb(tr[left_son(v)], tr[right_son(v)]);
}

void build(int v = 0, int L = 0, int R = sz(el)) {
    if (R - L == 1) {
        tr[v] = make_pair(lvl[el[L]], el[L]);
        return;
    }
    int M = L + (R - L) / 2;
    build(left_son(v), L, M);
    build(right_son(v), M, R);
    relax(v);
}

pair<int, int> get(int l, int r, int v = 0, int L = 0, int R = sz(el)) {
    if (l == L && r == R)
        return tr[v];
    int M = L + (R - L) / 2;
    pair<int, int> ans = make_pair(inf, 0);
    if (l < M)
        ans = comb(ans, get(l, min(r, M), left_son(v), L, M));
    if (r > M)
        ans = comb(ans, get(max(l, M), r, right_son(v), M, R));
    return ans;
}

void dfs(int v, int p, int height) {
    el.pb(v);
    fst[v] = sz(el) - 1;
    lvl[v] = height;
    for (auto i : g[v])
        if (i != p) {
            dfs(i, v, height + 1);
            el.pb(v);
        }
}


void VOLK() {
    cin >> n;
    vector<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        string str;
        int x, y;
        cin >> str >> x >> y;
        if (str == "ADD") {
            g[x - 1].pb(y - 1);
            g[y - 1].pb(x - 1);
        } else
            q.pb({x - 1, y - 1});
    }
    dfs(0, 0, 0);
    tr.resize(4 * sz(el) + 1);
    build();
    for (auto i : q)
        cout << get(min(fst[i.ff], fst[i.ss]), max(fst[i.ss], fst[i.ff]) + 1).ss + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    t = 1;
    //cin >> t;
    while (t--)
        VOLK();
}
