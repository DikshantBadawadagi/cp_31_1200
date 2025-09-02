#include <bits/stdc++.h>
using namespace std;

// Get the indices of the top 3 maximum values in the array
vector<int> get_best3(const vector<int>& a) {
    int mx1 = -1, mx2 = -1, mx3 = -1;
    for (int i = 0; i < a.size(); ++i) {
        if (mx1 == -1 || a[i] > a[mx1]) {
            mx3 = mx2;
            mx2 = mx1;
            mx1 = i;
        } else if (mx2 == -1 || a[i] > a[mx2]) {
            mx3 = mx2;
            mx2 = i;
        } else if (mx3 == -1 || a[i] > a[mx3]) {
            mx3 = i;
        }
    }
    return {mx1, mx2, mx3};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n), b(n), c(n);
        for (int &x : a) cin >> x;
        for (int &x : b) cin >> x;
        for (int &x : c) cin >> x;

        vector<int> topA = get_best3(a);
        vector<int> topB = get_best3(b);
        vector<int> topC = get_best3(c);

        int ans = 0;

        for (int i : topA) {
            for (int j : topB) {
                for (int k : topC) {
                    if (i != j && i != k && j != k) {
                        ans = max(ans, a[i] + b[j] + c[k]);
                    }
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
