#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, a, diff, x, y, u, v, w, k;
    cin >> N;

    vector<pair<int, int>> arr[N + 1];
    bool checked[N + 1] = {};

    for (int i = 0 ; i < N - 1 ; i ++) {
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
        arr[v].push_back(make_pair(u, w));
    }

    stack<int> st;
    int parent[N + 1][19] = {}, depth[N + 1] = {};
    long long int length[N + 1] = {};

    st.push(1);
    checked[1] = true;

    while (!st.empty()) {
        a = st.top();
        st.pop();

        for (pair<int, int> i : arr[a]) {
            if (checked[i.first])
                continue;

            parent[i.first][0] = a;
            checked[i.first] = true;
            depth[i.first] = depth[a] + 1;
            length[i.first] = length[a] + (long long int)i.second;

            for (int j = 1 ; 1 << j <= N ; j ++) {
                if (!parent[i.first][j - 1])
                    break;
                parent[i.first][j] = parent[parent[i.first][j - 1]][j - 1];
            }

            st.push(i.first);
        }
    }

    cin >> M;
    while (M--) {
        cin >> a >> u >> v;
        if (depth[u] < depth[v]) {
            x = v;
            y = u;
        } else {
            x = u;
            y = v;
        }

        diff = depth[x] - depth[y];
        int i = 0;

        while (diff) {
            if (diff % 2)
                x = parent[x][i];
            i ++;
            diff /= 2;
        }

        for (int i = 18 ; i >= 0 ; i --) {
            if (parent[x][i] != parent[y][i]) {
                x = parent[x][i];
                y = parent[y][i];
            }
        }

        if (x != y)
            x = parent[x][0];

        if (a == 1) {
            cout << length[u] + length[v] - length[x] * 2 << '\n';
        } else {
            cin >> k;
            k -= 1;

            if (depth[u] - depth[x] >= k) {
                x = u;
            } else {
                k = depth[u] + depth[v] - depth[x] * 2 - k;
                x = v;
            }

            int i = 0;
            while (k) {
                if (k % 2) {
                    x = parent[x][i];
                }
                i ++;
                k /= 2;
            }
            cout << x << '\n';
        }
    }
}
