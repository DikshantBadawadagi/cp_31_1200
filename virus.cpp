#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int& x : a) cin >> x;

    sort(a.begin(), a.end());

    vector<int> gaps;

    // Compute gaps between infected houses (on a circle)
    for (int i = 0; i < m; ++i) {
        int curr = a[i];
        int next = a[(i + 1) % m];

        int gap = (next - curr - 1 + n) % n;
        if (gap > 0) gaps.push_back(gap);
    }

    sort(gaps.rbegin(), gaps.rend());  // Sort descending

    int saved = 0, time = 0;

    for (int g : gaps) {
        int remaining = g - 2 * time;

        if (remaining <= 0) continue;

        // We can save one house immediately (before spread)
        if (remaining == 1) {
            saved += 1;
            time += 1;
        } else {
            saved += remaining - 1;
            time += 2;
        }
    }

    cout << n - saved << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
