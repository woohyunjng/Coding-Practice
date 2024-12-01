#include <bits/stdc++.h>
#define int long long

#define MAX 1100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int subst(int A, int B, int N) { return A * (N + 3) + B; }
pr to_pair(int K, int N) { return {K / (N + 3), K % (N + 3)}; }

pr go[4] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int parent[MAX * MAX], C[MAX][MAX];
bool safe[MAX * MAX];

int find(int K) { return parent[K] == K ? K : find(parent[K]); }

void uni(int A, int B) {
    A = find(A), B = find(B);
    if (A > B)
        swap(A, B);
    parent[B] = A;
    safe[A] = safe[A] && safe[B];
}

void solve() {
    int N, M, X, Y, res = 0;
    bool flag;
    string S;

    vector<pr> arr;

    cin >> N >> M;

    for (int i = 0; i <= N + 1; i++)
        for (int j = 0; j <= M + 1; j++)
            parent[subst(i, j, M)] = subst(i, j, M), safe[subst(i, j, M)] = i >= 1 && i <= N && j >= 1 && j <= M;

    for (int i = 1; i <= N; i++) {
        cin >> S;
        for (int j = 1; j <= M; j++) {
            if (S[j - 1] == 'R')
                uni(subst(i, j, M), subst(i, j + 1, M));
            else if (S[j - 1] == 'D')
                uni(subst(i, j, M), subst(i + 1, j, M));
            else if (S[j - 1] == 'L')
                uni(subst(i, j, M), subst(i, j - 1, M));
            else if (S[j - 1] == 'U') {
                uni(subst(i, j, M), subst(i - 1, j, M));
            } else
                arr.push_back({i, j});
        }
    }

    for (pr i : arr) {
        flag = true;
        for (pr j : go) {
            X = i.first + j.first, Y = i.second + j.second;
            if (safe[find(subst(X, Y, M))]) {
                uni(subst(i.first, i.second, M), subst(X, Y, M)), flag = false;
                break;
            }
        }
        if (flag)
            safe[find(subst(i.first, i.second, M))] = false;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            res += safe[find(subst(i, j, M))];
        }
    }
    cout << res << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}