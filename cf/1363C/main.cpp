#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif

void solve() {
    int n, x;
    cin >> n >> x;
    --x;

    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        g[v].push_back(u);
        g[u].push_back(v);
    }

    if (g[x].size() < 2) {
        cout << "Ayush\n";
        return;
    }

    if (n % 2 == 0) {
        cout << "Ayush\n";
    }
    else {
        cout << "Ashish\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
