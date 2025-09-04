#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<string> grid(n);
    for (string &row : grid) cin >> row;

    int res = 0;

    for (int i = 0; i < (n + 1) / 2; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            // 4 rotationally linked cells
            int a = grid[i][j] - '0';
            int b = grid[j][n - 1 - i] - '0';
            int c = grid[n - 1 - i][n - 1 - j] - '0';
            int d = grid[n - 1 - j][i] - '0';

            int ones = a + b + c + d;
            int zeros = 4 - ones;

            res += min(ones, zeros);
        }
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}
