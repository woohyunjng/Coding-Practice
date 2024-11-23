#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

int sm[MAX][3];

signed main() { /*
     ios_base::sync_with_stdio(false);
     cin.tie(0), cout.tie(0);*/

    int N, Q, L, R, st, en, md, res, X, Y;
    string S;

    vector<int> arr;

    cin >> N >> Q;
    cin >> S;

    for (int i = 1; i <= N; i++) {
        if (S[i - 1] == '/')
            arr.push_back(i);
        sm[i][1] = sm[i - 1][1] + (S[i - 1] == '1');
        sm[i][2] = sm[i - 1][2] + (S[i - 1] == '2');
    }

    while (Q--) {
        cin >> L >> R;

        st = lower_bound(arr.begin(), arr.end(), L) - arr.begin();
        en = upper_bound(arr.begin(), arr.end(), R) - arr.begin() - 1;

        res = 0;

        while (st <= en) {
            md = st + en >> 1;
            X = sm[arr[md] - 1][1] - sm[L - 1][1];
            Y = sm[R][2] - sm[arr[md]][2];

            res = max(res, min(X, Y) * 2 + 1);

            if (X < Y)
                st = md + 1;
            else
                en = md - 1;
        }

        cout << res << '\n';
    }

    return 0;
}