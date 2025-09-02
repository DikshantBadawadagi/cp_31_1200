#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// LCM function
ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

// Sum of first k natural numbers
ll sum_first_k(ll k) {
    return k * (k + 1) / 2;
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        ll n, x, y;
        cin >> n >> x >> y;

        ll cnt_x = n / x;
        ll cnt_y = n / y;
        ll cnt_common = n / lcm(x, y);

        ll only_x = cnt_x - cnt_common;
        ll only_y = cnt_y - cnt_common;

        // Sum of last only_x numbers in range 1 to n
        ll sum_last_x = sum_first_k(n) - sum_first_k(n - only_x);
        // Sum of first only_y numbers
        ll sum_first_y = sum_first_k(only_y);

        cout << (sum_last_x - sum_first_y) << '\n';
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
