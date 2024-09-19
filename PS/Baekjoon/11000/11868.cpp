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

    int N, res = 0, A;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A;
        res ^= A;
    }

    cout << (res == 0 ? "cubelover" : "koosaga");

    return 0;
}