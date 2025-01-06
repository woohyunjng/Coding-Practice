#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

map<int, int> cnt;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int Q, A, B;
    cin >> Q;

    while (Q--) {
        cin >> A >> B;
        if (A == 1)
            cnt[B]++;
        else if (A == 2) {
            if (cnt[B])
                cnt[B]--;
        } else
            cout << cnt[B] << '\n';
    }

    return 0;
}