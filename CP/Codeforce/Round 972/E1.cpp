#include <bits/stdc++.h>
#define int long long

#define MAX 3100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][MAX];
bool checked[10], dp[MAX][MAX][10];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, L, N, M, A;
    vector<int> num;
    cin >> T;

    while (T--) {
        cin >> L >> N >> M;

        num.clear();
        fill(checked, checked + 10, false);

        for (int i = 1; i <= L; i++) {
            cin >> A;
            if (!checked[A]) {
                num.push_back(A);
                checked[A] = true;
            }
        }
        L = num.size();

        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                cin >> arr[i][j];

        for (int k = L - 1; k >= 0; k--) {
            for (int i = N; i >= 1; i--) {
                for (int j = M; j >= 1; j--) {
                    dp[i][j][k] = false;
                    if (i < N)
                        dp[i][j][k] = dp[i][j][k] || dp[i + 1][j][k];
                    if (j < M)
                        dp[i][j][k] = dp[i][j][k] || dp[i][j + 1][k];

                    dp[i][j][k] = dp[i][j][k] || (arr[i][j] == num[k] && (i == N || j == M || k == L - 1 || !dp[i + 1][j + 1][k + 1]));
                }
            }
        }

        cout << (dp[1][1][0] ? "T" : "N") << '\n';
    }

    return 0;
}