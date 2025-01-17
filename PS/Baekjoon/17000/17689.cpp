#include <bits/stdc++.h>
#define int long long

#define MAX 400100
#define INF 0x3f3f3f3f3f3f3f3f

using namespace std;
typedef array<int, 2> pr;

int A[MAX], comp[MAX][2], num[MAX];
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, K, cnt, res = 0, Z;
    pr X;
    priority_queue<pr> pq;

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i], chk[i] = true;
        comp[i][0] = comp[i][1] = i, num[i] = i;
        pq.push({A[i], i});
    }

    A[0] = A[N + 1] = -INF, chk[0] = chk[N + 1] = true;
    comp[0][0] = comp[0][1] = 0, comp[N + 1][0] = comp[N + 1][1] = N + 1;
    num[0] = 0, num[N + 1] = N + 1, pq.push({-INF, 0}), pq.push({-INF, N + 1});

    cnt = N + 2;

    for (int i = 1; i <= (N + 1) / 2; i++) {
        while (!chk[pq.top()[1]])
            pq.pop();
        X = pq.top(), pq.pop(), cnt++, res += X[0];

        chk[X[1]] = false, A[cnt] = -X[0], chk[cnt] = true;
        comp[cnt][0] = comp[X[1]][0], comp[cnt][1] = comp[X[1]][1];

        Z = num[comp[X[1]][0] - 1], chk[Z] = false;
        A[cnt] += A[Z], comp[cnt][0] = comp[Z][0];
        num[comp[Z][0]] = cnt;

        Z = num[comp[X[1]][1] + 1], chk[Z] = false;
        A[cnt] += A[Z], comp[cnt][1] = comp[Z][1];
        num[comp[Z][1]] = cnt;

        pq.push({A[cnt], cnt});

        cout << res << '\n';
    }

    return 0;
}