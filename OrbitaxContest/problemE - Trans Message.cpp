#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;

bool incrementBinaryString(string &s) {
    int n = s.size();
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            s[i] = '1';
            for (int j = i + 1; j < n; ++j) {
                s[j] = '0';
            }
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        string S;
        cin >> N >> K >> S;

        unordered_set<string> substrings;

        for (int i = 0; i <= N - K; ++i) {
            substrings.insert(S.substr(i, K));
        }

        string candidate(K, '0');
        bool found = false;

        do {
            if (substrings.find(candidate) == substrings.end()) {
                cout << candidate << endl;
                found = true;
                break;
            }
        } while (incrementBinaryString(candidate));

        if (!found) {
            cout << "-1" << endl;
        }
    }

    return 0;
}
