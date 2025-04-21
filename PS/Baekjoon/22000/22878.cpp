#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000001;

int P[MAX], Q[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    vector<int> arr[4];
    int N, ans = 0, X[4] = {0, 0, 0, 0};

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> P[i];
    for (int i = 1; i <= N; i++)
        cin >> Q[i];

    for (int i = 1; i <= N; i++) {
        arr[0].push_back(P[i]), arr[1].push_back(Q[i]);
        arr[2].push_back(P[i] + Q[i]), arr[3].push_back(P[i] - Q[i]);
    }

    for (int i = 0; i < 4; i++)
        sort(arr[i].begin(), arr[i].end());

    for (int i = 0; i < N; i++) {
        ans += (arr[0][i] * i - X[0] + arr[1][i] * i - X[1]) * 2;
        ans -= arr[2][i] * i - X[2] + arr[3][i] * i - X[3];
        X[0] += arr[0][i], X[1] += arr[1][i], X[2] += arr[2][i], X[3] += arr[3][i];
    }

    cout << ans << '\n';

    return 0;
}