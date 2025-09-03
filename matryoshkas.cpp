#include <iostream>
#include <vector>
#include <map>
using namespace std;

int solve(vector<int>& dolls) {
    map<int, int> freq;
    for (int size : dolls) {
        freq[size]++;
    }

    int sets = 0;
    while (!freq.empty()) {
        int current = freq.begin()->first; // smallest available size
        sets++;
        while (freq.count(current) && freq[current] > 0) {
            freq[current]--;
            if (freq[current] == 0) {
                freq.erase(current); // clean up to avoid re-processing
            }
            current++; // move to next size in the sequence
        }
    }
    return sets;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> dolls(n);
        for (int i = 0; i < n; ++i) {
            cin >> dolls[i];
        }

        cout << solve(dolls) << '\n';
    }

    return 0;
}
