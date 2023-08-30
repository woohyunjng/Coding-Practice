#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A, B, res = 0, X;
    cin >> N;

    int depth[N + 1] = {}, parent[N + 1][16] = {};
    vector<int> arr[N + 1];
    bool checked[N + 1] = {};

    stack<int> st;
    st.push(1);
    checked[1] = true;

    for (int i = 0 ; i < N - 1 ; i ++) {
        cin >> A >> B;
        arr[A].push_back(B);
        arr[B].push_back(A);
    }

    while (!st.empty()) {
        X = st.top();
        st.pop();

        for (int i : arr[X]) {
            if (!checked[i]) {
                checked[i] = true;
                st.push(i);

                depth[i] = depth[X] + 1;
                parent[i][0] = X;

                for (int j = 1 ; 1 << j <= N ; j ++) {
                    parent[i][j] = parent[parent[i][j - 1]][j - 1];
                }
            }
        }
    }

    A = -1;
    cin >> M;
    while (M --) {
        cin >> X;
        if (A == -1) {
            A = X;
            res += depth[X];
            continue;
        }

        B = A;
        A = X;
        int first_depth = depth[B] + depth[X];

        if (depth[X] < depth[B]) {
            swap(X, B);
        }

        int diff = depth[X] - depth[B], i = 0;
        while (diff) {
            if (diff % 2) {
                X = parent[X][i];
            }
            diff /= 2;
            i ++;
        }

        for (int i = 15 ; i >= 0 ; i --) {
            if (parent[X][i] != parent[B][i]) {
                X = parent[X][i];
                B = parent[B][i];
            }
        }
        if (X != B) {
            X = parent[X][0];
        }

        res += first_depth - depth[X] * 2;
    }


    cout << res;
}
