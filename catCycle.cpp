#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k;
        cin >> n >> k;
        k--; // convert to 0-based index
        long long floor = n / 2;
        long long res = (k + (n % 2) * (k / floor)) % n + 1;
        cout << res << '\n';
    }
    return 0;
}
