#include <bits/stdc++.h>
#define int long long

#define MAX 200
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[3][MAX], dis[MAX];
bool checked[MAX];

pr go[3] = {{0, 1}, {1, 0}, {-1, 0}};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, cnt = 0, K, A, B;
    string S;

    cin >> N;
    for (int i = 1; i <= 2; i++) {
        cin >> S;
        for (int j = 0; j < N; j++) {
            arr[i][j] = (S[j] == '#' ? 0 : 1);
            cnt += arr[i][j];
        }
    }

    queue<int> q;

    for (int i = 1; i <= 2; i++) {
        if (arr[i][0] == 1) {
            dis[(i - 1) * N + 0] = 1;
            q.push((i - 1) * N + 0);
            checked[(i - 1) * N + 0] = true;
        }
    }

    while (!q.empty()) {
        K = q.front(), q.pop();
        A = K / N + 1, B = K % N;

        if (B == N - 1) {
            cout << cnt - dis[K];
            break;
        }

        for (pr i : go) {
            if (A + i.first < 1 || A + i.first > 2 || B + i.second < 0 || B + i.second >= N)
                continue;
            if (arr[A + i.first][B + i.second] == 0 || checked[(A + i.first - 1) * N + B + i.second])
                continue;

            dis[(A + i.first - 1) * N + B + i.second] = dis[K] + 1;
            q.push((A + i.first - 1) * N + B + i.second);
            checked[(A + i.first - 1) * N + B + i.second] = true;
        }
    }

    return 0;
}