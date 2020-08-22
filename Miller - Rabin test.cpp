#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define y1 y3278
#define sz(v) ll(v.size())
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
template <class T> using Pair_indexed_set = tree <T, null_type, less <T>, rb_tree_tag, tree_order_statistics_node_update>;
const long long INF = 2000000000000000000;
const long long Maxll = 9223372036854775807;
const long long MOD = 1000000000000037;
const ll MOD2 = 1100000009;
const ll inf = 1000000000;
const long long q0 = 31;
const ll differ = 'a' - 'A';
mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
template <class T>
istream& operator >> (istream &in, vector <T> &a) {
    for (T &i: a) in >> i;
    return in;
}
template <class T>
ostream& operator << (ostream &out, vector <T> &a) {
    for (T &i: a) out << i << ' ';
    out << '\n';
    return out;
}
template <class T>
ostream& operator << (ostream &out, set <T> &a) {
    out << a.size() << '\n';
    for (T i: a) out << i  << ' ';
    return out;
}

/// Actual code starts here
ll  n, m;

ll binpow(ll a, ll p, ll mod) {
    ll res = 1;
    while (p > 0) {
        if (p & 1 == 1) res = __int128(res) *__int128(a) % mod;
        a = __int128(a) *__int128(a) % mod;
        p >>= 1;
    }
    return res;
}

bool test(ll d) {
    if (d == 2 || d == 3) return true;
    if (d == 1 || d % 2 == 0) return false;
    ll t = d - 1;
    ll s = 0;
    while (t & 1 == 0) {
        t >>= 1;
        s++;
    }
    for (ll ii = 0;ii < 50;ii++) {
        ll r = max(2LL,(ll)rnd() % (d - 2));
        ll x = binpow(r, t, d);
        if (x == 1 || x == d - 1) continue;
        for (int i = 1;i < s;i++) {
            x = __int128 (x) *__int128 (x) % d;
            if (x == 1) return false;
            if (x == d - 1) break;
        }
        if (x != d - 1) return false;
    }
    return true;
}

void VOLK() {
    cin >> n;
    cout << test(n);
}
signed main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    //cin >> t;
    while (t--)
        VOLK();
}
