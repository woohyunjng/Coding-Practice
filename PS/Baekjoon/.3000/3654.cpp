#include <bits/stdc++.h>

#define MAX 510
using namespace std;

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
};

int A[MAX][MAX], num[MAX][MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, M, cnt[2], X;
    vector<int> arr;
    bool res;
    string S;

    cin >> T;

    while (T--) {
        cin >> N >> M;
        cnt[0] = cnt[1] = 0, res = true, X = 0;

        for (int i = 1; i <= N; i++) {
            cin >> S;
            for (int j = 1; j <= M; j++) {
                if (S[j - 1] == '.')
                    A[i][j] = 0;
                else if (S[j - 1] == 'B')
                    A[i][j] = 1, cnt[0]++, num[i][j] = X++;
                else
                    A[i][j] = 2, cnt[1]++;
            }
        }
        res = cnt[0] * 2 == cnt[1];

        TwoSat two_sat(X * 4 + 4);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                if (A[i][j] == 1) {
                    if (1 < i && i < N && A[i - 1][j] == 2 && A[i + 1][j] == 2) {
                        two_sat.add_clause(num[i][j] * 4 + 1, num[i][j] * 4 + 3);
                        two_sat.add_clause(-num[i][j] * 4 - 1, -num[i][j] * 4 - 3);
                    } else if (1 < i && A[i - 1][j] == 2)
                        two_sat.add_true(num[i][j] * 4 + 1);
                    else if (i < N && A[i + 1][j] == 2)
                        two_sat.add_true(num[i][j] * 4 + 3);
                    else
                        res = false;

                    if (1 < j && j < M && A[i][j - 1] == 2 && A[i][j + 1] == 2) {
                        two_sat.add_clause(num[i][j] * 4 + 2, num[i][j] * 4 + 4);
                        two_sat.add_clause(-num[i][j] * 4 - 2, -num[i][j] * 4 - 4);
                    } else if (1 < j && A[i][j - 1] == 2)
                        two_sat.add_true(num[i][j] * 4 + 2);
                    else if (j < M && A[i][j + 1] == 2)
                        two_sat.add_true(num[i][j] * 4 + 4);
                    else
                        res = false;
                } else if (A[i][j] == 2) {
                    arr.clear();
                    if (1 < i && A[i - 1][j] == 1)
                        arr.push_back(num[i - 1][j] * 4 + 3);
                    if (i < N && A[i + 1][j] == 1)
                        arr.push_back(num[i + 1][j] * 4 + 1);
                    if (1 < j && A[i][j - 1] == 1)
                        arr.push_back(num[i][j - 1] * 4 + 4);
                    if (j < M && A[i][j + 1] == 1)
                        arr.push_back(num[i][j + 1] * 4 + 2);

                    if (arr.size() == 1)
                        two_sat.add_true(arr[0]);
                    else if (arr.size() == 2) {
                        two_sat.add_clause(-arr[0], -arr[1]);
                    } else if (arr.size() == 3) {
                        two_sat.add_clause(-arr[0], -arr[1]);
                        two_sat.add_clause(-arr[1], -arr[2]);
                        two_sat.add_clause(-arr[2], -arr[0]);
                    } else if (arr.size() == 4) {
                        two_sat.add_clause(-arr[0], -arr[1]);
                        two_sat.add_clause(-arr[0], -arr[2]);
                        two_sat.add_clause(-arr[0], -arr[3]);
                        two_sat.add_clause(-arr[1], -arr[2]);
                        two_sat.add_clause(-arr[1], -arr[3]);
                        two_sat.add_clause(-arr[2], -arr[3]);
                    }
                    res &= arr.size() >= 1;
                }
            }
        }

        res &= two_sat.solve();
        cout << (res ? "YES" : "NO") << '\n';
    }

    return 0;
}