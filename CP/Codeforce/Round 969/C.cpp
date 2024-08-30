#include <bits/stdc++.h>
#define int long long

#define MAX 100100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int arr[MAX];
pr in[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T, N, A, B, X, res = INF;
    cin >> T;

    while (T--) {
        cin >> N >> A >> B;
        for (int i = 1; i <= N; i++)
            cin >> arr[i];

        sort(arr + 1, arr + N + 1);
        X = gcd(A, B);

        for (int i = 1; i < N; i++) {
            in[i].first = arr[i] + (arr[N] - arr[i]) / X * X;
            in[i].second = in[i].first + X;
        }
        in[N].first = in[N].second = arr[N];

        sort(in + 1, in + N);
        res = in[N].first - in[1].first;
        for (int i = 1; i < N; i++)
            res = min(res, abs(in[i].second - in[i + 1].first));

        cout << res << '\n';
    }

    return 0;
}