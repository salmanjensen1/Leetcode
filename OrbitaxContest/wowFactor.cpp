#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        long long x;
        cin >> s >> x;
        int n = s.length();

        vector<long long> w_count_before(n + 1, 0);
        vector<long long> w_count_after(n + 1, 0);
        vector<long long> wow_count(n + 1, 0);

        // Counting 'w' from left to right
        for (int i = 1; i <= n; i++) {
            w_count_before[i] = w_count_before[i - 1] + (s[i - 1] == 'w');
        }

        // Counting 'w' from right to left
        for (int i = n - 1; i >= 0; i--) {
            w_count_after[i] = w_count_after[i + 1] + (s[i] == 'w');
        }

        // Counting "wow" subsequences using the 'o' positions
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'o') {
                wow_count[i] = w_count_before[i - 1] * w_count_after[i];
            }
        }

        long long current_count = 0;
        int start = -1, end = -1;

        for (int i = 0; i < n; i++) {
            current_count = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == 'o') {
                    current_count += w_count_before[j] * w_count_after[j + 1];
                }
                if (current_count == x) {
                    if (start == -1 || j - i > end - start) {
                        start = i;
                        end = j;
                    }
                    break;
                }
            }
        }

        if (start == -1) {
            cout << "-1" << endl;
        } else {
            cout << start + 1 << " " << end + 1 << endl;
        }
    }

    return 0;
}
