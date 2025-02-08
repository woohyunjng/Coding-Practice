#include <bits/stdc++.h>
#define int long long

#define MAX 2000000

using namespace std;
typedef array<int, 2> pr;

int A[MAX], val[MAX], comp[MAX][2], num[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, cnt, res = 0, Z;
    pr X;
    priority_queue<pr> pq;

    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> A[i];

    for (int i = 1; i <= N; i++) {
        val[i] = A[i], chk[i] = true;
        comp[i][0] = comp[i][1] = i, num[i] = i;
        pq.push({val[i], i});
    }
    cnt = N;

    while (K--) {
        while (!chk[pq.top()[1]])
            pq.pop();
        X = pq.top(), pq.pop(), cnt++, res += X[0];

        chk[X[1]] = false, val[cnt] = -X[0], chk[cnt] = true;
        comp[cnt][0] = comp[X[1]][0], comp[cnt][1] = comp[X[1]][1];

        Z = num[comp[X[1]][0] == 1 ? N : comp[X[1]][0] - 1], chk[Z] = false;
        val[cnt] += val[Z], comp[cnt][0] = comp[Z][0];
        num[comp[Z][0]] = cnt;

        Z = num[comp[X[1]][1] == N ? 1 : comp[X[1]][1] + 1], chk[Z] = false;
        val[cnt] += val[Z], comp[cnt][1] = comp[Z][1];
        num[comp[Z][1]] = cnt;

        pq.push({val[cnt], cnt});
    }

    cout << res << '\n';

    return 0;
}