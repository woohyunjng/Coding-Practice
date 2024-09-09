#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sz[MAX], parent[MAX][18], length[MAX][18];
bool checked[MAX];
vector<pr> arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> sz[i];

    for (int i = 1; i < N; i++) {
        cin >> A >> B >> C;
        arr[A].push_back({B, C});
        arr[B].push_back({A, C});
    }

    queue<int> q;
    q.push(1);
    checked[1] = true;

    while (!q.empty()) {
        A = q.front(), q.pop();

        for (pr i : arr[A]) {
            if (checked[i.first])
                continue;

            parent[i.first][0] = A;
            length[i.first][0] = i.second;
            checked[i.first] = true;
            q.push(i.first);

            for (int j = 1; j < 18; j++) {
                if (!parent[i.first][j - 1])
                    continue;
                parent[i.first][j] = parent[parent[i.first][j - 1]][j - 1];
                length[i.first][j] = length[i.first][j - 1] + length[parent[i.first][j - 1]][j - 1];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        A = i;
        for (int j = 17; j >= 0; j--) {
            if (!parent[A][j])
                continue;
            if (length[A][j] <= sz[i])
                sz[i] -= length[A][j], A = parent[A][j];
        }
        cout << A << '\n';
    }

    return 0;
}