#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int totalSum = accumulate(a.begin(), a.end(), 0);
    if (totalSum < s) {
        cout << -1 << '\n';
        return;
    }
    if (totalSum == s) {
        cout << 0 << '\n';
        return;
    }

    // Sliding window to find longest subarray with sum == s
    int l = 0, sum = 0, max_len = 0;
    for (int r = 0; r < n; ++r) {
        sum += a[r];
        while (sum > s) {
            sum -= a[l];
            ++l;
        }
        if (sum == s) {
            max_len = max(max_len, r - l + 1);
        }
    }

    cout << n - max_len << '\n';  // Number of deletions = total - max_subarray_length
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
