#include <bits/stdc++.h>
#define int long long
#define MAX 101

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool numericLessThan(const string &a, const string &b) {
    if (a.length() != b.length()) {
        return a.length() < b.length();
    }

    return a < b;
}

string dp_st[MAX], zero_dp_st[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for (int i = 2; i < MAX; i++) {
        if (i - 2 != 1) {
            if (zero_dp_st[i] == "" || numericLessThan("1" + zero_dp_st[i - 2], zero_dp_st[i])) {
                zero_dp_st[i] = "1" + zero_dp_st[i - 2];
                dp_st[i] = "1" + zero_dp_st[i - 2];
            }
        }
        if (i - 3 != 1 && i >= 3) {
            if (zero_dp_st[i] == "" || numericLessThan("7" + zero_dp_st[i - 3], zero_dp_st[i])) {
                zero_dp_st[i] = "7" + zero_dp_st[i - 3];
                dp_st[i] = "7" + zero_dp_st[i - 3];
            }
        }
        if (i - 4 != 1 && i >= 4) {
            if (zero_dp_st[i] == "" || numericLessThan("4" + zero_dp_st[i - 4], zero_dp_st[i])) {
                zero_dp_st[i] = "4" + zero_dp_st[i - 4];
                dp_st[i] = "4" + zero_dp_st[i - 4];
            }
        }
        if (i - 5 != 1 && i >= 5) {
            if (zero_dp_st[i] == "" || numericLessThan("2" + zero_dp_st[i - 5], zero_dp_st[i])) {
                zero_dp_st[i] = "2" + zero_dp_st[i - 5];
                dp_st[i] = "2" + zero_dp_st[i - 5];
            }
            if (zero_dp_st[i] == "" || numericLessThan("3" + zero_dp_st[i - 5], zero_dp_st[i])) {
                zero_dp_st[i] = "3" + zero_dp_st[i - 5];
                dp_st[i] = "3" + zero_dp_st[i - 5];
            }
            if (zero_dp_st[i] == "" || numericLessThan("5" + zero_dp_st[i - 5], zero_dp_st[i])) {
                zero_dp_st[i] = "5" + zero_dp_st[i - 5];
                dp_st[i] = "5" + zero_dp_st[i - 5];
            }
        }
        if (i - 6 != 1 && i >= 6) {
            if (zero_dp_st[i] == "" || numericLessThan("6" + zero_dp_st[i - 6], zero_dp_st[i])) {
                zero_dp_st[i] = "6" + zero_dp_st[i - 6];
                dp_st[i] = "6" + zero_dp_st[i - 6];
            }
            if (zero_dp_st[i] == "" || numericLessThan("9" + zero_dp_st[i - 6], zero_dp_st[i])) {
                zero_dp_st[i] = "9" + zero_dp_st[i - 6];
                dp_st[i] = "9" + zero_dp_st[i - 6];
            }
            if (zero_dp_st[i] == "" || numericLessThan("0" + zero_dp_st[i - 6], zero_dp_st[i])) {
                zero_dp_st[i] = "0" + zero_dp_st[i - 6];
            }
        }
        if (i - 7 != 1 && i >= 7) {
            if (zero_dp_st[i] == "" || numericLessThan("8" + zero_dp_st[i - 7], zero_dp_st[i])) {
                zero_dp_st[i] = "8" + zero_dp_st[i - 7];
                dp_st[i] = "8" + zero_dp_st[i - 7];
            }
        }
    }

    int T, N;
    string K;
    cin >> T;

    while (T--) {
        cin >> N;
        cout << dp_st[N] << ' ';
        K = "";
        if (N % 2) {
            K = "7";
            N -= 3;
        }
        while (N) {
            K += "1";
            N -= 2;
        }

        cout << K << "\n";
    }

    return 0;
}
