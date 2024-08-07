#include <bits/stdc++.h>
#define int long long
#define MAX 500100
#define INF 0x7f7f7f7f7f7f7f7f
#define MOD 1000000007

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int P[MAX], sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, Q, A, B, C;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        sm[i] = sm[i - 1] + P[i];
    }

    while (Q--) {
        cin >> A >> B >> C;
    }

    return 0;
}