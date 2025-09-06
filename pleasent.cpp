#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        unordered_map<int, int> pos;

        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            pos[a[i]] = i;
        }

        int cnt = 0;

        for (int i = 1; i <= n; ++i) {
            int ai = a[i];

            // We look for all y such that ai * y <= 2n
            for (int y = 1; y <= (2 * n) / ai; ++y) {
                int prod = ai * y;
                if (pos.find(y) != pos.end()) {
                    int j = pos[y];
                    if (j > i && i + j == prod) {
                        cnt++;
                    }
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
