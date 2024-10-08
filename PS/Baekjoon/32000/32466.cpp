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

    int T, N, X, Y;
    string A;
    cin >> T;

    while (T--) {
        cin >> N;

        X = 0, Y = 0;
        for (int i = 1; i <= N; i++) {
            cin >> A;
            if (i != 1) {
                if (A == "110" || A == "011")
                    X++;
                else if (A == "111")
                    Y++;
            }
        }

        cout << (((X & 1) | (Y & 1)) ? "Yesyes" : "Nono") << '\n';
    }

    return 0;
}