#include <bits/stdc++.h>
#define int long long
#define MAX 1000

using namespace std;
typedef array<int, 3> tp;

bool virus[MAX], cur_virus[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, K, A, B, C;
    bool res = true;

    cin >> N >> M >> K;

    while (K--) {
        cin >> A;
        virus[A] = true;
    }

    vector<tp> logs;
    while (M--) {
        cin >> A >> B >> C;
        logs.push_back({A, B, C});
    }
    sort(logs.begin(), logs.end());

    for (int i = 1; i <= N; i++) {
        fill(cur_virus, cur_virus + N + 1, false);
        cur_virus[i] = true;

        for (tp j : logs) {
            if (cur_virus[j[1]])
                cur_virus[j[2]] = true;
        }

        res = true;
        for (int j = 1; j <= N; j++) {
            if (cur_virus[j] != virus[j]) {
                res = false;
                break;
            }
        }
        if (res) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}