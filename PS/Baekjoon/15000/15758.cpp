#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int in[MAX];
vector<int> adj[MAX], arr[MAX];
bool vst[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int N,
        M, K, X, st, en, mid, cnt, res;
    bool flag;
    queue<int> q;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> K;
        for (int j = 0; j < K; j++)
            cin >> X, arr[i].push_back(X);
    }

    st = 1, en = M;
    while (st <= en) {
        mid = st + en >> 1, X = 0;
        for (int i = 1; i <= N; i++)
            adj[i].clear(), in[i] = 0, vst[i] = false;

        for (int i = 1; i <= mid; i++) {
            for (int j = 0; j < arr[i].size(); j++)
                vst[arr[i][j]] = true;
            for (int j = 1; j < arr[i].size(); j++)
                adj[arr[i][j - 1]].push_back(arr[i][j]), in[arr[i][j]]++;
        }

        for (int i = 1; i <= N; i++) {
            if (!in[i] && vst[i])
                q.push(i);
            X += vst[i];
        }
        flag = !q.empty(), cnt = 0;

        while (!q.empty()) {
            K = q.front(), q.pop(), cnt++;
            for (int i : adj[K])
                if (!--in[i])
                    q.push(i);
        }

        flag = flag && cnt == X;
        if (flag)
            st = mid + 1, res = mid;
        else
            en = mid - 1;
    }

    for (int i = 1; i <= N; i++)
        adj[i].clear(), in[i] = 0;

    for (int i = 1; i <= res; i++)
        for (int j = 1; j < arr[i].size(); j++)
            adj[arr[i][j - 1]].push_back(arr[i][j]), in[arr[i][j]]++;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++)
        if (!in[i])
            pq.push(i);

    while (!pq.empty()) {
        K = pq.top(), pq.pop();
        cout << K << ' ';

        for (int i : adj[K])
            if (!--in[i])
                pq.push(i);
    }

    return 0;
}