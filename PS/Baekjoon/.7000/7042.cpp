#include <bits/stdc++.h>
#define int long long

#define MAX 300000
#define MAX_B 510
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;

int L, W, board[MAX_B][MAX_B], in_degree[MAX], out_degree[MAX];
pr go[2] = {{1, 0}, {0, 1}};

vector<int> arr[MAX], rvt_arr[MAX], scc[MAX];
stack<int> st;
bool checked[MAX];
int scc_num = 0, scc_id[MAX];

int get(int X, int Y) { return (X - 1) * W + Y; }

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

    int X, Y, in = 0, out = 0;

    cin >> W >> L;

    for (int i = 1; i <= L; i++)
        for (int j = 1; j <= W; j++)
            cin >> board[i][j];

    for (int i = 1; i <= L; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = 0; k < 2; k++) {
                X = i + go[k].first, Y = j + go[k].second;
                if (X < 1 || X > L || Y < 1 || Y > W)
                    continue;

                if (board[i][j] >= board[X][Y])
                    arr[get(i, j)].push_back(get(X, Y)), rvt_arr[get(X, Y)].push_back(get(i, j));
                if (board[i][j] <= board[X][Y])
                    arr[get(X, Y)].push_back(get(i, j)), rvt_arr[get(i, j)].push_back(get(X, Y));
            }
        }
    }

    kosaraju(L * W);

    for (int i = 1; i <= L * W; i++) {
        for (int j : arr[i]) {
            if (scc_id[i] != scc_id[j]) {
                out_degree[scc_id[i]]++;
                in_degree[scc_id[j]]++;
            }
        }
    }

    for (int i = 0; i < scc_num; i++) {
        if (!in_degree[i])
            in++;
        if (!out_degree[i])
            out++;
    }

    cout << (scc_num == 1 ? 0 : max(in, out));

    return 0;
}