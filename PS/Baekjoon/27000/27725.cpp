#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, K, X;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> P[i];
    cin >> K;

    for (int i = 1; i <= N; i++) {
        X = K;
        while (X) {
            res += X / P[i];
            X /= P[i];
        }
    }

    cout << res;

    return 0;
}