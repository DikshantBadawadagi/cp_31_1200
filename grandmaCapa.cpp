#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// Try making s a palindrome by deleting only 'ch' from either side
int makePalindromeWithChar(const string &s, char ch) {
    int l = 0, r = s.size() - 1;
    int deletions = 0;

    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        }
        else if (s[l] == ch) {
            l++;
            deletions++;
        }
        else if (s[r] == ch) {
            r--;
            deletions++;
        }
        else {
            // Cannot make it palindrome with this ch
            return INT_MAX;
        }
    }

    return deletions;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Try all 26 characters
        int answer = INT_MAX;
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            int res = makePalindromeWithChar(s, ch);
            answer = min(answer, res);
        }

        if (answer == INT_MAX) {
            cout << -1 << '\n';
        } else {
            cout << answer << '\n';
        }
    }

    return 0;
}
