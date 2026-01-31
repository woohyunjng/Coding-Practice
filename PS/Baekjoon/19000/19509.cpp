#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAX = 2001;

int S[MAX];
map<int, int> mp;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T, N, P, X;
    bool flag;

    random_device rd;
    mt19937 mt(rd());

    uniform_int_distribution<int> dis(1, 100000);

    cin >> T;
    while (T--) {
        cin >> N, P = N + 1;
        while (true) {
            flag = true;
            for (int i = 2; i * i <= P; i++)
                flag &= P % i != 0;
            if (!flag)
                P++;
            else
                break;
        }

        while (true) {
            flag = true, mp.clear(), X = dis(mt);
            for (int i = 1; i <= N; i++) {
                S[i] = 2 * (P - 1) * i + (i * (i + 1) / 2 * X) % P;
                flag &= S[i] - S[i - 1] <= 3 * (N + 6) && mp.find(S[i] - S[i - 1]) == mp.end();
                mp[S[i] - S[i - 1]] = i;
            }
            if (flag)
                break;
        }

        for (int i = 1; i <= N; i++)
            cout << S[i] - S[i - 1] << ' ';
        cout << '\n';
    }

    return 0;
}