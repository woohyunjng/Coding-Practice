#include <bits/stdc++.h>
#define int long long
#define MAX 200100

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool arr[4][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, res, X, Y;
    char K;
    cin >> T;

    while (T--) {
        cin >> N;
        for (int i = 1; i <= 2; i++) {
            for (int j = 1; j <= N; j++) {
                cin >> K;
                if (K == '.')
                    arr[i][j] = true;
                else
                    arr[i][j] = false;
            }
        }

        res = 0;
        for (int i = 1; i <= 2; i++) {
            for (int j = 2; j < N; j++) {
                if (!arr[i][j])
                    continue;
                if (i == 1) {
                    if (arr[i + 1][j] && !arr[i + 1][j - 1] && !arr[i + 1][j + 1] && arr[i][j - 1] && arr[i][j + 1])
                        res++;
                } else {
                    if (arr[i - 1][j] && !arr[i - 1][j - 1] && !arr[i - 1][j + 1] && arr[i][j - 1] && arr[i][j + 1])
                        res++;
                }
            }
        }
        cout << res << '\n';
    }

    return 0;
}