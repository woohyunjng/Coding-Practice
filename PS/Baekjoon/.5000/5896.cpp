#include <bits/stdc++.h>
#define int long long

#define MAX 50100
#define INF 0x2f2f2f2f2f2f2f2f

using namespace std;
typedef pair<int, int> pr;

int P[MAX], Cst[MAX];
bool chk[MAX], vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, M, X = 0, res = 0, cnt = 0;
    pr A, B, C;
    priority_queue<pr, vector<pr>, greater<pr>> pqP, pqC, pqX;

    cin >> N >> K >> M;
    for (int i = 1; i <= N; i++) {
        cin >> P[i] >> Cst[i];
        pqC.push({Cst[i], i});
    }

    while (K--) {
        A = pqC.top(), pqC.pop();
        cnt++, X += A.first;
        pqP.push({P[A.second] - Cst[A.second], A.second}), chk[A.second] = true;

        if (X > M) {
            cout << cnt - 1 << '\n';
            return 0;
        }
    }
    res = cnt;

    for (int i = 1; i <= N; i++) {
        if (!chk[i])
            pqX.push({P[i], i});
    }

    while (true) {
        A = B = C = {INF, 0};
        while (!pqC.empty() && chk[pqC.top().second])
            pqC.pop();
        while (!pqX.empty() && vst[pqX.top().second])
            pqX.pop();
        if (!pqP.empty() && !pqC.empty())
            A = pqP.top(), B = pqC.top();
        if (!pqX.empty())
            C = pqX.top();

        if (A.first + B.first <= C.first)
            pqP.pop(), pqC.pop(), pqP.push({P[B.second] - Cst[B.second], B.second}), cnt++, X += A.first + B.first, vst[B.second] = true;
        else
            pqX.pop(), cnt++, X += C.first, chk[C.second] = true;

        if (X > M)
            break;
        res = max(res, cnt);
    }

    cout << res << '\n';

    return 0;
}