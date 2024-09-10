#include <bits/stdc++.h>
#define int long long

#define MAX 30100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

class TwoSat {
  private:
    vector<vector<int>> arr, rvt_arr;
    vector<bool> checked;
    vector<int> scc_id;
    stack<int> st;
    int scc_num;

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
        scc_id[K] = scc_num;
    }

    void kosaraju(int V) {
        int A;
        for (int i = 1; i <= V; i++) {
            if (!checked[i])
                kosaraju_first_dfs(i);
        }

        fill(checked.begin(), checked.end(), false);
        while (!st.empty()) {
            A = st.top();
            st.pop();
            if (!checked[A]) {
                kosaraju_second_dfs(A);
                scc_num++;
            }
        }
    }

  public:
    int N;
    TwoSat(int n) : N(n), arr(n * 2 + 1), rvt_arr(n * 2 + 1), checked(n * 2 + 1), scc_id(n * 2 + 1), scc_num(0) {}

    int oppose(int K) { return K & 1 ? K + 1 : K - 1; }

    void add_clause(int A, int B) {
        A = A < 0 ? -A * 2 - 1 : A * 2;
        B = B < 0 ? -B * 2 - 1 : B * 2;

        arr[oppose(A)].push_back(B);
        arr[oppose(B)].push_back(A);
        rvt_arr[B].push_back(oppose(A));
        rvt_arr[A].push_back(oppose(B));
    }

    void add_true(int A) {
        A = A < 0 ? -A * 2 - 1 : A * 2;
        arr[oppose(A)].push_back(A);
        rvt_arr[A].push_back(oppose(A));
    }

    void run() { kosaraju(N * 2); }

    bool solve() {
        run();

        for (int i = 1; i <= N; i++) {
            if (scc_id[i * 2] == scc_id[i * 2 - 1])
                return false;
        }

        return true;
    }

    bool get_value(int A) { return scc_id[A * 2] > scc_id[A * 2 - 1]; }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, A, B;

    while (true) {
        cin >> N >> M;
        if (cin.eof())
            break;

        TwoSat ts(N);

        while (M--) {
            cin >> A >> B;
            ts.add_clause(A, B);
        }
        ts.add_true(1);

        cout << (ts.solve() ? "yes" : "no") << '\n';
    }

    return 0;
}