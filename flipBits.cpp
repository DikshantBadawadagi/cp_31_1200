#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;

        vector<int> diff(n, 0);
        diff[0] = (s1[0] == '0') ? -1 : 1;

        for (int i = 1; i < n; i++) {
            if (s1[i] == '0') {
                diff[i] = diff[i - 1] - 1;
            } else {
                diff[i] = diff[i - 1] + 1;
            }
        }

        bool flag = true;
        int flip = 0;  

        for (int i = n - 1; i >= 0; i--) {
            char a = s1[i];
            char b = s2[i];

            if (flip % 2 == 1) {
                a = (a == '0' ? '1' : '0');
            }

            if (a != b) {
                if (diff[i] != 0) {
                    flag = false;
                    break;
                }
                flip++;  
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
}
