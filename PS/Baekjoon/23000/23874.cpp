#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int st[MAX], en[MAX], first[MAX][MAX], second[MAX][MAX];

int flag(int A, int B, int C, int D) {
    int res = 0;

    if (A > C && D > A && B > D)
        res = -1;
    else if (C > A && B > C && D > B)
        res = -1;
    else if (A > D)
        res = 1;
    else if (C > B)
        res = 2;
    else if (A < C && D < B)
        res = 3;
    else if (C < A && B < D)
        res = 4;

    return res;
}

bool comp(int A, int B, int C, int D) {
    if (A > D || B < C)
        return true;
    if ((A <= C && D <= B) || (C <= A && B <= D))
        return true;
    return false;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, K, X;
    bool res;
    cin >> T;

    fill(st, st + MAX, INF), fill(en, en + MAX, -INF);

    while (T--) {
        cin >> N >> M;
        res = true;

        for (int i = 1; i <= M; i++) {
            cin >> K;
            for (int j = 1; j <= K; j++) {
                cin >> X;
                st[X] = min(st[X], i), en[X] = max(en[X], i);
                if (first[i][X] == 0)
                    first[i][X] = j;
                else
                    second[i][X] = j;
            }
        }

        for (int i = 1; i <= M; i++) {
            for (int j = 1; j <= N; j++) {
                if (st[j] <= i && i <= en[j])
                    res = res && first[i][j] != 0;
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                X = 0;
                for (int k = max(st[i], st[j]); k <= min(en[i], en[j]); k++) {
                    if (X == 0)
                        X = flag(first[k][i], second[k][i], first[k][j], second[k][j]);
                    else
                        res = res && X == flag(first[k][i], second[k][i], first[k][j], second[k][j]);
                }
                res = res && X != -1;
                res = res && (X <= 2 || (X == 3 && st[i] <= st[j] && en[j] <= en[i]) || (X == 4 && st[j] <= st[i] && en[i] <= en[j]));
            }
        }

        cout << (res ? "YES" : "NO") << '\n';

        for (int i = 1; i <= N; i++) {
            st[i] = INF, en[i] = -INF;
            for (int j = 1; j <= M; j++)
                first[j][i] = second[j][i] = 0;
        }
    }

    return 0;
}