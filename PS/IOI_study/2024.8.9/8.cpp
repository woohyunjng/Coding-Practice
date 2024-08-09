#include <bits/stdc++.h>
#define int long long

#define MAX 50100
#define MAX_VAL 1001000
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;

map<vector<int>, int> arr[6];
int val[6];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, A, K = 1, j;
    vector<int> X;

    cin >> N;
    res = N * (N - 1) / 2;

    for (int i = 1; i <= N; i++) {
        for (j = 0; j < 5; j++)
            cin >> val[j];
        sort(val, val + 5);

        for (int k = 1; k < (1 << 5); k++) {
            X.clear();
            for (int l = 0; l < 5; l++) {
                if (k & (1 << l))
                    X.push_back(val[l]);
            }

            A = X.size();
            if (A & 1)
                res -= arr[A][X];
            else
                res += arr[A][X];
            arr[A][X]++;
        }
    }

    cout << res;

    return 0;
}