#include <bits/stdc++.h>
#define int long long
#define MAX 1000

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX], dp_1[MAX][MAX], dp_2[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int R, C, res = 0, K;
    string S;

    cin >> R >> C;

    for (int i = 1; i <= R; i++) {
        cin >> S;
        for (int j = 1; j <= C; j++)
            arr[i][j] = S[j - 1] - '0';
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (!arr[i][j]) {
                dp_1[i][j] = 0;
                continue;
            }
            dp_1[i][j] = dp_1[i - 1][j - 1] + 1;
        }
        for (int j = C; j >= 1; j--) {
            if (!arr[i][j]) {
                dp_2[i][j] = 0;
                continue;
            }
            dp_2[i][j] = dp_2[i - 1][j + 1] + 1;
        }
    }

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            K = min(dp_1[i][j], dp_2[i][j]);
            for (int k = 1; k <= K; k++) {
                if (dp_1[i - k + 1][j + k - 1] >= k && dp_2[i - k + 1][j - k + 1] >= k)
                    res = max(res, k);
            }
        }
    }

    cout << res;

    return 0;
}