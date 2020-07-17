vector<int> g[1000];
bool used[1000];
int tin[1000], fup[1000];
int timer = 0;
void dfs(int v, int p) {
    used[v] = true;
    fup[v] = tin[v] = timer++;
    for (auto i : g[v]) {
        if (i == p) continue;
        if (used[i]) fup[v] = min(tin[i], fup[v]);
        else {
            dfs(i, v);
            fup[v] = min(fup[v], fup[i]);
            if (fup[i] > tin[v])
                cout << v  << ' ' << i  << '\n';

        }
    }
}
