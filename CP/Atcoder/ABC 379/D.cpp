#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[MAX], arr[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, X, A, B = 0, C = 1, D = 1, res = 0;
    cin >> Q;

    while (Q--) {
        cin >> X;
        if (X == 1) {
            arr[C++] = B;
        } else if (X == 2) {
            cin >> A;
            B++;
            sm[B] = sm[B - 1] + A;
        } else {
            cin >> A;
            res = 0;
            while (D < C && sm[B] - sm[arr[D]] >= A)
                D++, res++;
            cout << res << '\n';
        }
    }

    return 0;
}