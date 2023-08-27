#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, a, b, c, diff, j;
    cin >> N;

    vector<int> arr[N + 1];
    bool checked[N + 1] = {};

    for (int i = 0 ; i < N - 1 ; i ++) {
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }

    stack<int> st;
    int parent[N + 1][18] = {}, depth[N + 1] = {};

    st.push(1);
    checked[1] = true;

    while (!st.empty()) {
        a = st.top();
        st.pop();

        for (int i : arr[a]) {
            if (checked[i])
                continue;

            parent[i][0] = a;
            checked[i] = true;
            depth[i] = depth[a] + 1;

            for (int j = 1 ; 1 << j <= N ; j ++) {
                if (!parent[i][j - 1])
                    break;
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }

            st.push(i);
        }
    }

    cin >> M;
    for (int i = 0 ; i < M ; i ++) {
        cin >> a >> b;
        if (depth[a] < depth[b]) {
            c = b;
            b = a;
            a = c;
        }

        diff = depth[a] - depth[b];
        j = 0;

        while (diff) {
            if (diff % 2)
                a = parent[a][j];
            j ++;
            diff /= 2;
        }

        for (int j = 17 ; j >= 0 ; j --) {
            if (parent[a][j] != parent[b][j]) {
                a = parent[a][j];
                b = parent[b][j];
            }
        }
        if (a != b)
            a = parent[a][0];

        cout << a << '\n';
    }
}
