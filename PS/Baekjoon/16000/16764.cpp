#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

map<vector<int>, int> cnt;
int A[MAX][5];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0;
    vector<int> temp;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 5; j++)
            cin >> A[i][j];
        sort(A[i], A[i] + 5);

        for (int j = 1; j <= 5; j++) {
            for (int k = 0; k < (1 << 5); k++) {
                temp.clear();
                if (__builtin_popcount(k) != j)
                    continue;

                for (int l = 0; l < 5; l++) {
                    if ((k & (1 << l)) == 0)
                        continue;
                    temp.push_back(A[i][l]);
                }

                res += cnt[temp] * ((j & 1) ? 1 : -1);
                cnt[temp]++;
            }
        }
    }

    cout << N * (N - 1) / 2 - res << '\n';

    return 0;
}