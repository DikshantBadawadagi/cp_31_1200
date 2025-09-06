#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Store all substrings of length 1 to 3 in a set
        set<string> substrs;
        for (int len = 1; len <= 3; ++len) {
            for (int i = 0; i + len <= n; ++i) {
                substrs.insert(s.substr(i, len));
            }
        }

        // Try all possible strings in lexicographical order
        // First try 1-letter strings
        for (char c = 'a'; c <= 'z'; ++c) {
            string temp(1, c);
            if (!substrs.count(temp)) {
                cout << temp << '\n';
                goto next_case;
            }
        }

        // Then try 2-letter strings
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                string temp = {c1, c2};
                if (!substrs.count(temp)) {
                    cout << temp << '\n';
                    goto next_case;
                }
            }
        }

        // Then try 3-letter strings
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                for (char c3 = 'a'; c3 <= 'z'; ++c3) {
                    string temp = {c1, c2, c3};
                    if (!substrs.count(temp)) {
                        cout << temp << '\n';
                        goto next_case;
                    }
                }
            }
        }

    next_case:;
    }

    return 0;
}
