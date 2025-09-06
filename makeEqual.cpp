#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;

        // Check if already good
        bool all_good = true;
        for (char ch : s) {
            if (ch != c) {
                all_good = false;
                break;
            }
        }

        if (all_good) {
            cout << 0 << '\n';
            continue;
        }

        // Try to find a valid x such that all positions divisible by x have s[i] == c
        int x = -1;
        for (int i = 1; i <= n; ++i) {
            bool ok = true;
            for (int j = i; j <= n; j += i) {
                if (s[j - 1] != c) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                x = i;
                break;
            }
        }

        if (x != -1) {
            cout << 1 << '\n';
            cout << x << '\n';
        } else {
            // fallback: two operations
            cout << 2 << '\n';
            cout << n << ' ' << n - 1 << '\n';
        }
    }

    return 0;
}
