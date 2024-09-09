#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

vector<int> arr[MAX], rvt_arr[MAX], scc[MAX];
stack<int> st;
bool checked[MAX];
int scc_num = 0, scc_id[MAX], res[MAX];

int oppose(int K) {
    return K & 1 ? K + 1 : K - 1;
}

void kosaraju_first_dfs(int K) {
    checked[K] = true;
    for (int i : arr[K]) {
        if (!checked[i])
            kosaraju_first_dfs(i);
    }
    st.push(K);
}

void kosaraju_second_dfs(int K) {
    checked[K] = true;
    for (int i : rvt_arr[K]) {
        if (!checked[i])
            kosaraju_second_dfs(i);
    }
    scc[scc_num].push_back(K);
    scc_id[K] = scc_num;
}

void kosaraju(int V) {
    int A;
    for (int i = 1; i <= V; i++) {
        if (!checked[i])
            kosaraju_first_dfs(i);
    }
    fill(checked, checked + V + 1, false);
    while (!st.empty()) {
        A = st.top();
        st.pop();
        if (!checked[A]) {
            kosaraju_second_dfs(A);
            scc_num++;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;
    cin >> N >> M;

    while (M--) {
        cin >> A >> B;
        A = A < 0 ? -A * 2 - 1 : A * 2;
        B = B < 0 ? -B * 2 - 1 : B * 2;

        arr[oppose(A)].push_back(B);
        arr[oppose(B)].push_back(A);
        rvt_arr[B].push_back(oppose(A));
        rvt_arr[A].push_back(oppose(B));
    }

    kosaraju(N * 2);

    for (int i = 1; i <= N; i++) {
        if (scc_id[i * 2] == scc_id[i * 2 - 1]) {
            cout << 0;
            return 0;
        }
    }

    cout << 1;

    return 0;
}