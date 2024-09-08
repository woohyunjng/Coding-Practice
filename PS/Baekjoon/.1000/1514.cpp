#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 5> ftp;

int N, dp[MAX][10][10][10], A[MAX], B[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    ftp K;
    int res = INF;

    cin >> N;

    cin >> S;
    for (int i = 1; i <= N; i++)
        A[i] = S[i - 1] - '0';
    cin >> S;
    for (int i = 1; i <= N; i++)
        B[i] = S[i - 1] - '0';

    fill(&dp[0][0][0][0], &dp[MAX][0][0][0], INF);

    priority_queue<ftp, vector<ftp>, greater<ftp>> pq;
    pq.push({0, 1, A[1], A[2], A[3]});
    dp[1][A[1]][A[2]][A[3]] = 0;

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        if (dp[K[1]][K[2]][K[3]][K[4]] < K[0])
            continue;

        if (K[1] > N) {
            res = min(res, K[0]);
            continue;
        }

        if (K[1] == 2 && K[2] == 5 && K[3] == 6 && K[4] == 5)
            cout << K[0] << "heung\n";

        if (K[2] == B[K[1]] && K[0] < dp[K[1] + 1][K[3]][K[4]][A[K[1] + 3]]) {
            dp[K[1] + 1][K[3]][K[4]][A[K[1] + 3]] = K[0];
            pq.push({K[0], K[1] + 1, K[3], K[4], A[K[1] + 3]});
        }

        for (int i = -3; i <= 3; i++) {
            if (!i)
                continue;

            if (dp[K[1]][(K[2] + i + 10) % 10][(K[3] + i + 10) % 10][(K[4] + i + 10) % 10] > K[0] + 1) {
                dp[K[1]][(K[2] + i + 10) % 10][(K[3] + i + 10) % 10][(K[4] + i + 10) % 10] = K[0] + 1;
                pq.push({K[0] + 1, K[1], (K[2] + i + 10) % 10, (K[3] + i + 10) % 10, (K[4] + i + 10) % 10});
            }
            if (dp[K[1]][(K[2] + i + 10) % 10][(K[3] + i + 10) % 10][K[4]] > K[0] + 1) {
                dp[K[1]][(K[2] + i + 10) % 10][(K[3] + i + 10) % 10][K[4]] = K[0] + 1;
                pq.push({K[0] + 1, K[1], (K[2] + i + 10) % 10, (K[3] + i + 10) % 10, K[4]});
            }
            if (dp[K[1]][(K[2] + i + 10) % 10][K[3]][K[4]] > K[0] + 1) {
                dp[K[1]][(K[2] + i + 10) % 10][K[3]][K[4]] = K[0] + 1;
                pq.push({K[0] + 1, K[1], (K[2] + i + 10) % 10, K[3], K[4]});
            }
        }
    }

    cout << res << endl;

    return 0;
}