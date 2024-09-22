#include <bits/stdc++.h>
#define int long long

#define MAX 10100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, S, res = 0, A;
    cin >> N >> S;

    for (int i = 1; i <= N; i++)
        cin >> arr[i][0] >> arr[i][1];

    for (int i = 1; i <= N; i++) {
        A = arr[i][0];
        for (int j = 1; j < i; j++)
            A = min(A, (i - j) * S + arr[j][0]);
        res += A * arr[i][1];
    }

    cout << res;

    return 0;
}