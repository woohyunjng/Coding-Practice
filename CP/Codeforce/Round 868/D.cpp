#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int X[MAX], C[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, K, before_val, before_length, A, B;
    string res;
    char cur, Y;
    bool flag;

    vector<pr> arr;

    cin >> T;

    while (T--) {
        cin >> N >> K;
        res = "abc", flag = true;
        arr.clear();

        for (int i = 1; i <= K; i++)
            cin >> X[i];
        for (int i = 1; i <= K; i++)
            cin >> C[i];

        if (X[1] == 3) {
            if (C[1] != 3) {
                cout << "NO\n";
                continue;
            }

            for (int i = 2; i <= K; i++)
                arr.push_back({X[i], C[i]});
        } else
            for (int i = 1; i <= K; i++)
                arr.push_back({X[i], C[i]});

        before_val = 3, before_length = 3, cur = 'd', Y = 'c';
        for (pr i : arr) {
            A = i.first, B = i.second;
            if (A - before_length < B - before_val) {
                flag = false;
                break;
            }

            res = res + string(B - before_val, cur);
            cur++;

            for (int j = 0; j < A - (before_length + B - before_val); j++) {
                if (Y == 'a')
                    Y = 'b';
                else if (Y == 'b')
                    Y = 'c';
                else
                    Y = 'a';
                res += Y;
            }

            before_length = A, before_val = B;
        }

        if (flag) {
            cout << "YES\n";
            cout << res << '\n';
        } else
            cout << "NO\n";
    }

    return 0;
}