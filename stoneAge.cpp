#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    vector<int> lastUpdate(n, 0); // when was this element last updated
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long totalSum = 0;
    for (int i = 0; i < n; ++i) {
        totalSum += a[i];
    }

    int currentTime = 0; // used to track operation times
    int lastAllUpdateTime = 0; // last time we did a full array update
    long long baseValue = 0; // value after last type-2 update

    while (q--) {
        int t;
        cin >> t;
        currentTime++;

        if (t == 1) {
            int i;
            long long x;
            cin >> i >> x;
            --i; // convert to 0-based index

            long long oldValue;
            if (lastUpdate[i] < lastAllUpdateTime) {
                oldValue = baseValue;
            } else {
                oldValue = a[i];
            }

            totalSum = totalSum - oldValue + x;
            a[i] = x;
            lastUpdate[i] = currentTime;
        } else {
            long long x;
            cin >> x;

            baseValue = x;
            lastAllUpdateTime = currentTime;
            totalSum = x * n;
        }

        cout << totalSum << '\n';
    }

    return 0;
}
