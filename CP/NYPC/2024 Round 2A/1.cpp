#include <bits/stdc++.h>
#define int long long

#define MAX 500100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int U[MAX], D[MAX], res[MAX], sm[MAX][2];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, cur = 0;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> U[i];
    for (int i = 1; i <= N; i++)
        cin >> D[i];

    for (int i = N; i >= 1; i--) {
        if (D[i] != -1)
            sm[i][1] = sm[i + 1][1] + D[i];
        else
            sm[i][1] = sm[i + 1][1];
    }

    for (int i = 1; i <= N; i++) {
        if (U[i] != -1) {
            if (cur + U[i] <= sm[i + 1][1]) {
                res[i] = 1;
                cur += U[i];
            } else if (cur <= sm[i + 1][1]) {
                res[i] = 0;
            } else {
                res[i] = -1;
                cur -= D[i];
            }
        } else {
            if (cur <= sm[i + 1][1]) {
                res[i] = 0;
            } else {
                res[i] = -1;
                cur -= D[i];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        if (res[i] == 1)
            cout << "+";
        else if (res[i] == -1)
            cout << "-";
        else
            cout << "0";
    }

    return 0;
}