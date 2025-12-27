#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 5001;

int V[MAX], dp[MAX][2];

int calc(vector<int> arr) {
    int N = arr.size(), S = 0, ans = 0;
    if (N == 1)
        return arr[0];

    for (int i : arr)
        S += i;
    dp[0][0] = arr[0], dp[0][1] = arr[1];
    for (int i = 2; i + 1 < N; i += 2) {
        dp[i][0] = min(dp[i - 2][0] + max(arr[i - 1], arr[i]), dp[i - 2][1] + max(arr[i - 2], arr[i]));
        dp[i][1] = min(dp[i - 2][0] + max(arr[i - 1], arr[i + 1]), dp[i - 2][1] + max(arr[i - 2], arr[i + 1]));
    }
    ans = min(dp[N - 3][0] + max(arr[N - 2], arr[N - 1]), dp[N - 3][1] + max(arr[N - 3], arr[N - 1]));
    return ans * 2 - S;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, ans, L, R;
    bool flag;
    vector<int> arr;

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> V[i];

    if (N % 2 == 0) {
        ans = 0;
        for (int i = 0; i < N; i++) {
            rotate(V, V + 1, V + N), S = 0, arr.clear();
            L = 1, R = N - 1, flag = true;
            while (L <= R) {
                arr.push_back(V[flag ? L : R]);
                L += flag, R -= !flag, flag = !flag;
            }
            S = calc(arr) - V[0];
            ans = max(ans, S);
        }
        cout << (ans == 0 ? "Sphere" : "Lulu") << '\n';
        if (ans != 0)
            cout << ans << '\n';
    } else {
        ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 0; i < N; i++) {
            rotate(V, V + 1, V + N), S = V[0];
            L = 1, R = N - 1;
            while (L < R)
                S += abs(V[L++] - V[R--]);
            ans = min(ans, S);
        }
        cout << (ans == 0 ? "Sphere" : "Terra") << '\n';
        if (ans != 0)
            cout << ans << '\n';
    }

    return 0;
}