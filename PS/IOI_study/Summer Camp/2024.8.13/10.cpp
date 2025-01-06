#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<pr> arr[MAX];
int res[MAX], vst[MAX];

int dfs(int K, int before, int cnt) {
    int ret = cnt, X;
    vst[K] = cnt;

    for (pr i : arr[K]) {
        if (i.first == before)
            continue;
        if (vst[i.first]) {
            ret = min(ret, vst[i.first]);
            continue;
        }

        X = dfs(i.first, K, cnt + 1);
        if (X > vst[K])
            res[i.second] = 1;
        ret = min(ret, X);
    }
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> A >> B;
        arr[A].push_back({B, i});
        arr[B].push_back({A, i});
    }

    for (int i = 1; i <= N; i++) {
        if (!vst[i])
            dfs(i, 0, 1);
    }

    for (int i = 1; i <= M; i++)
        cout << res[i];

    return 0;
}