#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 100;

int X[MAX], Y[MAX], A[MAX][MAX];

int calc(int x, int y) {
    if (abs(X[x] - X[y]) == abs(Y[x] - Y[y]))
        return 1;
    return 2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, K, ans, V;
    bool flag;
    string S;

    vector<int> arr = {1, 2, 3};

    cin >> T;
    while (T--) {
        K = 0, flag = true, ans = 2147483647;
        for (int i = 0; i < 8; i++) {
            cin >> S;
            for (int j = 0; j < 8; j++) {
                if (S[j] == 'T')
                    X[++K] = i, Y[K] = j;
                else if (S[j] == 'B')
                    X[0] = i, Y[0] = j;
            }
        }

        for (int i = 1; i <= 3; i++)
            flag &= (X[i] % 2 - Y[i] % 2 + 2) % 2 == (X[0] % 2 - Y[0] % 2 + 2) % 2;

        if (!flag) {
            cout << -1 << '\n';
            continue;
        }

        do {
            ans = min(ans, calc(0, arr[0]) + calc(arr[0], arr[1]) + calc(arr[1], arr[2]));
        } while (next_permutation(arr.begin(), arr.end()));

        cout << ans << '\n';
    }

    return 0;
}