#include <bits/stdc++.h>
#define int long long
#define MAX 100100
#define MAX_LOG 18

using namespace std;
typedef pair<int, int> pr;

int N, parent[MAX][MAX_LOG], depth[MAX];
vector<int> arr[MAX];
bool checked[MAX];

void dfs(int K) {
    int A;
    stack<int> st;

    st.push(K);
    checked[K] = true;

    while (!st.empty()) {
        A = st.top();
        st.pop();

        for (int i : arr[A]) {
            if (checked[i])
                continue;
            parent[i][0] = A;
            checked[i] = true;
            depth[i] = depth[A] + 1;

            for (int j = 1; j < MAX_LOG; j++) {
                if (!parent[i][j - 1])
                    continue;
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }

            st.push(i);
        }
    }
}

int LCA(int A, int B) {
    if (depth[A] < depth[B])
        swap(A, B);

    int diff = depth[A] - depth[B];
    for (int i = 0; diff; i++) {
        if (diff & 1)
            A = parent[A][i];
        diff >>= 1;
    }

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parent[A][i] != parent[B][i])
            A = parent[A][i], B = parent[B][i];
    }
    if (A != B)
        A = parent[A][0];
    return A;
}

int get_dis(int A, int B) {
    int X = LCA(A, B);
    return depth[A] + depth[B] - 2 * depth[X];
}