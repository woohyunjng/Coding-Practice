#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 10001;
const int MOD = 1000000007;

int P[MAX], L[MAX], D[MAX], V[MAX];
vector<int> arr[MAX];

int fpow(int N, int K) {
    int res = 1;
    while (K) {
        if (K & 1)
            res = res * N % MOD;
        N = N * N % MOD, K >>= 1;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, X = 0, Y, ans = 0, ans_pos;
    vector<int> val;

    cin >> N >> A;
    for (int i = 1; i <= N; i++)
        cin >> P[i] >> L[i] >> D[i];
    X = max_element(L + 1, L + N + 1) - L;

    for (int i = P[X] - D[X] + 1, j = 0; i <= P[X] + D[X] - 1; i++, j++) {
        V[j] = i;
        for (int k = 1; k <= N; k++) {
            Y = L[k] - abs(P[k] - i) / D[k];
            if (Y < 0)
                continue;
            arr[j].push_back(Y);
        }
        sort(arr[j].rbegin(), arr[j].rend()), val.push_back(j);
    }

    sort(val.begin(), val.end(), [&](int x, int y) {
        for (int k = 0; k < min(arr[x].size(), arr[y].size()); k++) {
            if (arr[x][k] == arr[y][k])
                continue;
            return arr[x][k] < arr[y][k];
        }
        return arr[x].size() < arr[y].size();
    });

    ans_pos = val.back();
    for (int i : arr[ans_pos])
        ans += fpow(A, i), ans %= MOD;

    cout << ans << '\n'
         << V[ans_pos] << '\n';

    return 0;
}