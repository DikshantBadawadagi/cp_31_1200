#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n), d(n);
    for (int &v : x) cin >> v;
    for (int i = 0; i < n; ++i) {
        cin >> y[i];
        d[i] = x[i] - y[i];
    }

    sort(d.begin(), d.end());

    int l = 0, r = n - 1, cnt = 0;
    while (l < r) {
        if (d[l] + d[r] <= 0) {
            cnt++;
            l++;
            r--;
        } else {
            r--;
        }
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
