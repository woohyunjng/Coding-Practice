#include <bits/stdc++.h>
#define int long long

#define MAX 21
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool dp[MAX * 3][1 << MAX];

int rotate(int X, int N) {
    return (X >> 1) | ((X & 1) << (N - 1));
}

int string_to_int(string &s) {
    int ret = 0;
    for (int i = 0; i < s.size(); i++)
        ret = ret * 2 + s[i] - '0';
    return ret;
}

void print_binary(int X, int N) {
    for (int i = N - 1; i >= 0; i--)
        cout << (X >> i & 1);
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, X, Y;
    string A, B;

    cin >> T >> N;

    dp[0][0] = true;

    for (int i = 1; i <= 3 * N; i++) {
        for (int j = 0; j < (1 << N); j++) {
            X = 0;
            if (i <= N)
                X = (1 << i) - 1;
            else if (i <= 2 * N)
                X = (1 << (2 * N - i)) - 1;
            else
                X = (1 << (i - 2 * N)) - 1;

            for (int k = 0; k < N; k++) {
                dp[i][j] |= dp[i - 1][j ^ X];
                X = rotate(X, N);
            }
        }
    }

    while (T--) {
        cin >> A >> B;
        X = string_to_int(A), Y = string_to_int(B);
        print_binary(X, N);
        print_binary(Y, N);

        for (int i = 0; i <= 3 * N; i++) {
            if (dp[i][X]) {
                cout << i << '\n';
                break;
            }
            X ^= Y;
            Y = rotate(Y, N);
            print_binary(X, N);
            print_binary(Y, N);
        }
    }

    return 0;
}