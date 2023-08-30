#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, K, A, B, C, D, E, diff, j;
    cin >> N;

    vector<pair<int, int>> arr[N + 1];
    bool checked[N + 1] = {};

    for (int i = 0 ; i < N - 1 ; i ++) {
        cin >> A >> B >> C;
        arr[A].push_back(make_pair(B, C));
        arr[B].push_back(make_pair(A, C));
    }

    stack<int> st;
    pair<int, pair<int, int>> parent[N + 1][18] = { make_pair(0, make_pair(1000001, -1)) };
    int depth[N + 1] = {};

    st.push(1);
    checked[1] = true;

    while (!st.empty()) {
        int x = st.top();
        st.pop();

        for (pair<int, int> i : arr[x]) {
            if (checked[i.first])
                continue;

            parent[i.first][0] = make_pair(x, make_pair(i.second, i.second));
            checked[i.first] = true;
            depth[i.first] = depth[x] + 1;

            for (int j = 1 ; 1 << j <= N ; j ++) {
                if (!parent[i.first][j - 1].first)
                    break;

                parent[i.first][j] = make_pair(
                    parent[parent[i.first][j - 1].first][j - 1].first,
                    make_pair(
                        min(parent[parent[i.first][j - 1].first][j - 1].second.first, parent[i.first][j - 1].second.first),
                        max(parent[parent[i.first][j - 1].first][j - 1].second.second, parent[i.first][j - 1].second.second)
                    )
                );
            }

            st.push(i.first);
        }
    }

    cin >> K;
    while (K--) {
        int res1 = 1000001, res2 = -1;

        cin >> D >> E;
        if (depth[D] < depth[E]) {
            C = E;
            E = D;
            D = C;
        }

        diff = depth[D] - depth[E];
        int i = 0;

        while (diff) {
            if (diff % 2) {
                res1 = min(res1, parent[D][i].second.first);
                res2 = max(res2, parent[D][i].second.second);
                D = parent[D][i].first;
            }
            i ++;
            diff /= 2;
        }

        for (int i = 17 ; i >= 0 ; i --) {
            if (parent[D][i].first != parent[E][i].first) {
                res1 = min(res1, parent[D][i].second.first);
                res1 = min(res1, parent[E][i].second.first);

                res2 = max(res2, parent[D][i].second.second);
                res2 = max(res2, parent[E][i].second.second);

                D = parent[D][i].first;
                E = parent[E][i].first;
            }
        }

        if (D != E) {
            res1 = min(res1, parent[D][0].second.first);
            res1 = min(res1, parent[E][0].second.first);

            res2 = max(res2, parent[D][0].second.second);
            res2 = max(res2, parent[E][0].second.second);
        }

        cout << res1 << ' ' << res2 << '\n';
    }
}

