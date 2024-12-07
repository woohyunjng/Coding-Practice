#include <bits/stdc++.h>
#define int long long

#define MAX 110
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, cur = 0, T, V, bef = 0;
    cin >> N;

    while (N--) {
        cin >> T >> V;
        cur -= T - bef, bef = T;
        cur = max(0ll, cur);
        cur += V;
    }

    cout << cur << '\n';

    return 0;
}