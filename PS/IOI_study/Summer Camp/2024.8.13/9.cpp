#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX];
int res[MAX], vst[MAX], cnt;

int dfs(int K, bool root) {
    int ret = ++cnt, X = 0, Y;
    vst[K] = ret;

    for (int i : arr[K]) {
        if (vst[i]) {
            ret = min(ret, vst[i]);
            continue;
        }
        X++;
        Y = dfs(i, false);
        if (!root && Y >= vst[K])
            res[K] = 1;
        ret = min(ret, Y);
    }

    if (root && X > 1)
        res[K] = 1;
    return ret;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    for (int i = 1; i <= N; i++) {
        if (!vst[i])
            dfs(i, true);
    }

    for (int i = 1; i <= N; i++)
        cout << res[i];

    return 0;
}