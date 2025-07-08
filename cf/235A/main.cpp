#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...) 0
#endif

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "1\n";
        return;
    }
    else if (n == 2) {
        cout << "2\n";
        return;
    }
    else if (n == 3) {
        cout << "6\n";
        return;
    }

    vector<int64_t> a(n);
    iota(a.begin(), a.end(), 1);

    int64_t ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, lcm(lcm(a[n - 1], a[n - 2]), a[i]));
        ans = max(ans, lcm(a[i], lcm(a[n - 2], a[n - 3])));
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--)
        solve();

    return 0;
}
