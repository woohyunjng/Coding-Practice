#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int arr[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, X, Y;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    sort(arr + 1, arr + N + 1);
    for (int i = 1; i <= N; i++)
        sm[i] = sm[i - 1] + arr[i];

    while (Q--) {
        cin >> A >> B;
        if (A > B)
            cout << 0 << ' ' << 0 << '\n';
        else {
            X = upper_bound(arr + 1, arr + N + 1, B) - arr - 1;
            Y = lower_bound(arr + 1, arr + N + 1, A) - arr - 1;
            cout << X - Y << ' ' << sm[X] - sm[Y] << '\n';
        }
    }

    return 0;
}