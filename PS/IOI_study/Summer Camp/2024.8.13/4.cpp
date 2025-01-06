#include <bits/stdc++.h>
#define int long long

#define MAX 3100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
bool checked[MAX];
int depth[MAX], cnt[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B, res = INF;
    pr K;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    queue<pr> q;

    for (int i = 1; i <= N; i++) {
        fill(checked, checked + N + 1, false);
        fill(depth, depth + N + 1, 0);

        q.push({i, 0});
        checked[i] = true;
        depth[i] = 1;

        while (!q.empty()) {
            K = q.front(), q.pop();
            for (int j : arr[K.first]) {
                if (j == K.second)
                    continue;
                if (checked[j]) {
                    res = min(res, depth[K.first] + depth[j] - 1);
                    cnt[depth[K.first] + depth[j] - 1]++;
                    continue;
                }

                checked[j] = true;
                depth[j] = depth[K.first] + 1;
                q.push({j, K.first});
            }
        }
    }

    cout << cnt[res] / (2 * res);

    return 0;
}