#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef array<int, 2> pr;

const int MAX = 31;

pr go[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int N, A[MAX][MAX];
bool vst[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, C, X, Y;
    vector<int> ans;
    string S;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> S;
        for (int j = 0; j < N; j++)
            A[i][j] = S[j] - '0';
    }

    queue<pr> q;
    pr K;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            if (vst[i][j] || A[i][j] == 0)
                continue;
            vst[i][j] = true, q.push({i, j}), C = 0;
            while (!q.empty()) {
                K = q.front(), q.pop(), C++;
                for (pr k : go) {
                    X = K[0] + k[0], Y = K[1] + k[1];
                    if (X < 0 || X >= N || Y < 0 || Y >= N || vst[X][Y] || A[X][Y] == 0)
                        continue;
                    vst[X][Y] = true, q.push({X, Y});
                }
            }
            ans.push_back(C);
        }

    sort(ans.begin(), ans.end());

    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << '\n';

    return 0;
}