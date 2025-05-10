#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 200001;
const int INF = 0x3f3f3f3f3f3f3f3f;

int A[MAX], S[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, ans = -INF, ansP1 = -1, ansP2 = -1, V, X = -INF;
    deque<pr> dq;

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i], S[i] = S[i - 1] + A[i];

    for (int i = 1; i <= min(N, K + 1); i++) {
        while (!dq.empty() && dq.back()[0] < S[i])
            dq.pop_back();
        dq.push_back({S[i], i});
    }
    ans = dq.front()[0], ansP1 = 1, ansP2 = dq.front()[1];

    for (int i = 2; i <= N; i++) {
        while (!dq.empty() && dq.front()[1] < i)
            dq.pop_front();
        if (i + K <= N) {
            while (!dq.empty() && dq.back()[0] < S[i + K])
                dq.pop_back();
            dq.push_back({S[i + K], i + K});
        }

        if (dq.front()[0] - S[i - 1] > ans)
            ans = dq.front()[0] - S[i - 1], ansP1 = i, ansP2 = dq.front()[1];
    }

    ans = ans * 2 - S[N];
    if (-S[N] > ans && N > 1)
        ans = -S[N], ansP1 = 2, ansP2 = 1;

    cout << ans << '\n';
    cout << ansP1 << ' ' << ansP2 << '\n';

    return 0;
}