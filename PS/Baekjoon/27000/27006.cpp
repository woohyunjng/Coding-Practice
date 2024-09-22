#include <bits/stdc++.h>
#define int long long

#define MAX 410
#define MAX_H 40010
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

bool dp[MAX][MAX_H];
int H[MAX], A[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<int> arr;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> H[i] >> A[i] >> C[i];
        arr.push_back(i);
    }

    sort(arr.begin(), arr.end(), [&](int a, int b) {
        return A[a] < A[b];
    });

    dp[0][0] = true;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= C[arr[i - 1]]; j++) {
            for (int k = 0; k <= A[arr[i - 1]]; k++) {
                dp[i][k] = dp[i][k] || dp[i - 1][k];
                if (k - H[arr[i - 1]] * j >= 0 && dp[i - 1][k - H[arr[i - 1]] * j])
                    dp[i][k] = true;
            }
        }
    }

    for (int i = 40000; i >= 0; i--) {
        if (dp[N][i]) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}