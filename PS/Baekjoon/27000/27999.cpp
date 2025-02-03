#include <bits/stdc++.h>
#define MAX 16000

using namespace std;
typedef array<int, 2> pr;

int A[MAX], B[MAX], val[MAX];
bool chk[MAX];
bitset<MAX> mask[MAX];

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    int N, M, S = 0, ans = -1, X;
    pr K;
    priority_queue<pr> pq;
    vector<int> arr;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i], S += A[i];
        pq.push({A[i], i});
    }

    for (int i = 1; i <= S; i++)
        for (int j = 1; j <= N; j++)
            val[i] += min(i, A[j]);

    cin >> M;
    for (int i = 1; i <= M; i++)
        cin >> B[i], chk[B[i]] = 1;

    vector<vector<bitset<MAX>>> dp(S + 1);
    dp[0] = vector<bitset<MAX>>(S + 1);
    for (int i = 0; i <= S; i++)
        dp[0][i][0] = 1;

    for (int i = 1; i <= S; i++)
        dp[i] = vector<bitset<MAX>>(S / i + 1);

    mask[0][0] = 1;
    for (int i = 1; i <= S; i++)
        mask[i] = mask[i - 1], mask[i][i] = 1;

    for (int i = 1; i <= S; i++) {
        for (int j = S / i; j >= 1; j--) {
            if (j < S / i)
                dp[i][j] = dp[i][j + 1];
            if (chk[j] && (i == 1 || j <= S / (i - 1)))
                dp[i][j] |= dp[i - 1][j] << j;
            dp[i][j] &= mask[val[i]];
        }
    }

    for (int i = 1; i <= S; i++)
        if (dp[i][1][S]) {
            ans = i;
            break;
        }

    cout << ans << '\n';
    if (ans == -1)
        return 0;

    for (int i = ans; i >= 1; i--) {
        for (int j = S / i; j >= 1; j--) {
            if (!dp[i][j][S])
                continue;
            X = j, S -= j;
            while (X--) {
                K = pq.top(), pq.pop();
                A[K[1]]--, arr.push_back(K[1]);
            }

            cout << arr.size() << ' ';
            for (int i : arr)
                cout << i << ' ', pq.push({A[i], i});
            cout << '\n';
            arr.clear();
            break;
        }
    }

    return 0;
}