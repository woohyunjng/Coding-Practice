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

    int N, A, B, cur_A = 0, cur_B = 0;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A >> B;
        cur_A += A, cur_B += B;
        cout << cur_A - cur_B << '\n';
    }

    return 0;
}