#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k, x;
    cin >> n >> k >> x;

    vector<ll> a(n);
    for (ll &val : a) cin >> val;

    sort(a.begin(), a.end());

    // To store how many students are needed to fix each break
    vector<ll> patch_costs;

    for (ll i = 1; i < n; ++i) {
        ll diff = a[i] - a[i - 1];
        if (diff > x) {
            // Calculate how many insertions are needed
            ll required = (diff + x - 1) / x - 1;
            patch_costs.push_back(required);
        }
    }

    // Initial group count = number of breaks + 1
    ll groups = patch_costs.size() + 1;

    // Try to fix the cheapest breaks first
    sort(patch_costs.begin(), patch_costs.end());

    for (ll cost : patch_costs) {
        if (k >= cost) {
            k -= cost;
            groups--; // Merged a group
        } else {
            break;
        }
    }

    cout << groups << '\n';
    return 0;
}
