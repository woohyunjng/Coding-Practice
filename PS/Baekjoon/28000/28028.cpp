#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int C[MAX], S[MAX], F[MAX], cnt[MAX], vst[MAX];

vector<int> adj[MAX], color[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, A, B;
    bool res;
    cin >> T;

    queue<int> q;

    while (T--) {
        cin >> N >> M;
        for (int i = 1; i <= N; i++)
            adj[i].clear(), color[i].clear();

        for (int i = 1; i <= N; i++)
            cin >> C[i];
        for (int i = 1; i <= N; i++)
            cin >> S[i];
        for (int i = 1; i <= N; i++)
            cin >> F[i];

        while (M--) {
            cin >> A >> B;
            adj[A].push_back(B), adj[B].push_back(A);
        }

        fill(cnt, cnt + N + 1, 0);
        fill(vst, vst + N + 1, 0);

        q.push(1);
        vst[1] = 1, cnt[S[1]]++;

        res = true;

        while (!q.empty()) {
            A = q.front(), q.pop();
            vst[A] = 1;

            if (++cnt[S[A]] == 1) {
                for (int i : color[S[A]]) {
                    if (!vst[i])
                        vst[i] = 1, q.push(i);
                }
                color[S[A]].clear();
            }

            for (int i : adj[A]) {
                if (vst[i])
                    continue;
                if (cnt[C[i]])
                    q.push(i);
                else
                    color[C[i]].push_back(i);
            }
        }

        fill(cnt, cnt + N + 1, 0);
        for (int i = 1; i <= N; i++)
            color[i].clear();

        q.push(1);
        vst[1] = 2, cnt[F[1]]++;

        while (!q.empty()) {
            A = q.front(), q.pop();
            vst[A] = 2;

            if (++cnt[F[A]] == 1) {
                for (int i : color[F[A]]) {
                    if (vst[i] == 1)
                        vst[i] = 2, q.push(i);
                }
                color[F[A]].clear();
            }

            for (int i : adj[A]) {
                if (vst[i] != 1)
                    continue;
                if (cnt[C[i]] || C[i] == F[i])
                    q.push(i);
                else
                    color[C[i]].push_back(i);
            }
        }

        for (int i = 1; i <= N; i++) {
            if (vst[i] == 0)
                res = res && (F[i] == S[i]);
            if (vst[i] == 1)
                res = false;
        }

        cout << (res ? "YES" : "NO") << '\n';
    }

    return 0;
}