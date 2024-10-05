#include <bits/stdc++.h>
#define int long long

#define MAX 10
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

pr arr[MAX][2], go[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, T, X, Y, A, B;
    long double res = INF, val;

    vector<int> vec;
    cin >> N >> S >> T;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0].first >> arr[i][0].second >> arr[i][1].first >> arr[i][1].second;
        vec.push_back(i);
    }

    do {
        for (int i = 0; i < (1 << N); i++) {
            for (int j = 1; j <= N; j++) {
                if (i & (1 << (j - 1))) {
                    go[j][0] = arr[j][1];
                    go[j][1] = arr[j][0];
                } else {
                    go[j][0] = arr[j][0];
                    go[j][1] = arr[j][1];
                }
            }

            X = 0, Y = 0, val = 0;
            for (int j = 1; j <= N; j++) {
                A = go[vec[j - 1]][0].first, B = go[vec[j - 1]][0].second;
                val += sqrt((X - A) * (X - A) + (Y - B) * (Y - B)) / S;
                X = go[vec[j - 1]][1].first, Y = go[vec[j - 1]][1].second;
                val += sqrt((X - A) * (X - A) + (Y - B) * (Y - B)) / T;
            }
            res = min(res, val);
        }
    } while (next_permutation(vec.begin(), vec.end()));

    cout << fixed << setprecision(6) << res << endl;

    return 0;
}