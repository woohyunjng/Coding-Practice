#include <bits/stdc++.h>
using namespace std;

typedef array<int, 3> tp;

const int MAX = 101;

int P[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    vector<tp> ans;

    cin >> N;

    for (int i = 1; i <= N; i++)
        P[i][0] = P[i][1] = N - i + 1;

    for (int i = 1; i <= N; i++) {
        while (P[i][0] != i || P[i][1] != i) {
            for (int j = 1; j <= N; j++)
                if (P[j][0] < P[j][1])
                    swap(P[j][0], P[j][1]);
            for (int j = N; j > i; j--) {
                if (P[j][0] < P[j][1])
                    swap(P[j][0], P[j][1]);
                if (P[j][0] == i) {
                    ans.push_back({j - 1, P[j - 1][0], P[j][0]});
                    swap(P[j][0], P[j - 1][0]);
                } else if (P[j][1] == i) {
                    ans.push_back({j - 1, P[j - 1][0], P[j][1]});
                    swap(P[j][1], P[j - 1][0]);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
        assert(P[i][0] == i && P[i][1] == i);

    assert(ans.size() <= 0.7 * N * N);
    cout << ans.size() << '\n';
    for (tp i : ans)
        cout << i[0] << ' ' << i[1] << ' ' << i[2] << '\n';

    return 0;
}