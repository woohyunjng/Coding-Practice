#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, A, B, C;
    bool res;

    sm[1] = 1;

    cin >> N;

    for (int i = 2; i <= N + 1; i++) {
        cin >> A >> B >> C;

        if (A == 1)
            res = sm[C] - sm[B - 1] == (C - B + 1);
        else
            res = sm[C] - sm[B - 1] == 0;

        if (res) {
            cout << "Yes\n";
            sm[i] = sm[i - 1] + 1;
        } else {
            cout << "No\n";
            sm[i] = sm[i - 1];
        }
    }

    return 0;
}