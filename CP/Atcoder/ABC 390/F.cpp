#include <bits/stdc++.h>
#define int long long

#define MAX 400000
using namespace std;

int A[MAX];
map<int, int> sm[MAX];
vector<int> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, val, X, Y, K;
    cin >> N;

    for (int i = 1; i <= N + 1; i++)
        arr[i].push_back(0);
    for (int i = 1; i <= N; i++)
        cin >> A[i], arr[A[i]].push_back(i);
    for (int i = 1; i <= N + 1; i++)
        arr[i].push_back(N + 1);

    for (int i = 1; i <= N; i++) {
        sm[i][0] = 0;
        for (int j = 1; j < arr[i].size(); j++) {
            X = arr[i][j] - arr[i][j - 1] - 1;
            sm[i][j] = sm[i][j - 1] + X * (X + 1) / 2;
        }
    }

    for (int i = 2; i <= N + 1; i++) {
        for (int j = 1; j < arr[i].size(); j++) {
            X = upper_bound(arr[i - 1].begin(), arr[i - 1].end(), arr[i][j - 1]) - arr[i - 1].begin();
            Y = lower_bound(arr[i - 1].begin(), arr[i - 1].end(), arr[i][j]) - arr[i - 1].begin() - 1;
            if (X > Y)
                continue;
            K = arr[i][j] - arr[i][j - 1] - 1;
            val = K * (K + 1) / 2 - (sm[i - 1][Y] - sm[i - 1][X]);
            K = arr[i][j] - arr[i - 1][Y] - 1, val -= K * (K + 1) / 2;
            K = arr[i - 1][X] - arr[i][j - 1] - 1, val -= K * (K + 1) / 2;

            res += val;
        }
    }

    cout << res << '\n';

    return 0;
}