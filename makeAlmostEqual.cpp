#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (auto &x : a) cin >> x;

        ll answer = -1;
        for (int j = 1; j <= 60; ++j) {
            ll k = 1LL << j;  // same as pow(2, j) but faster and avoids floating point
            set<ll> mods;
            for (auto x : a) {
                mods.insert(x % k);
            }
            if (mods.size() == 2) {
                answer = k;
                break;
            }
        }

        // fallback (in case we don’t find any, which shouldn’t happen)
        if (answer == -1) answer = 1e18;
        cout << answer << '\n';
    }

    return 0;
}
