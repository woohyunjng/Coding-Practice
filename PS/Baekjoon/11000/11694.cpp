#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X = 0, Y = 0, A;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A;
        X ^= A, Y |= X > 1;
    }

    cout << ((X > 0) ^ Y ? "cubelover" : "koosaga");

    return 0;
}