#include <bits/stdc++.h>
using namespace std;

const int MAX = 100001;

vector<int> V[26], arr;
string C = "sogan";
bool chk[MAX];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int N, X, ans = 0;
    bool flag;

    vector<int> arr, val;

    cin >> N >> S;

    for (int st = 1, en = N, md; st <= en;) {
        md = st + en >> 1, flag = true, arr.clear(), val.clear();
        fill(chk, chk + N, false);

        for (int i = 0; i < 26; i++)
            V[i].clear();
        for (int i = 0; i < N; i++)
            V[S[i] - 'a'].push_back(i);
        for (int i = 0; i < 26; i++)
            reverse(V[i].begin(), V[i].end());

        for (int i = 0; i < md; i++) {
            X = -1;
            for (char c : C) {
                while (!V[c - 'a'].empty() && V[c - 'a'].back() <= X)
                    V[c - 'a'].pop_back();
                if (V[c - 'a'].empty()) {
                    flag = false;
                    break;
                }
                X = V[c - 'a'].back(), V[c - 'a'].pop_back(), chk[X] = true;
            }
            if (!flag)
                break;
            arr.push_back(X);
        }

        if (flag) {
            for (int i = 0; i < N; i++)
                if (!chk[i] && S[i] == 'g')
                    val.push_back(i);
            reverse(val.begin(), val.end());

            for (int i = 0; i < md; i++) {
                while (!val.empty() && val.back() <= arr[i])
                    val.pop_back();
                if (val.empty()) {
                    flag = false;
                    break;
                }
                val.pop_back();
            }
        }

        if (flag)
            ans = md, st = md + 1;
        else
            en = md - 1;
    }

    cout << ans << '\n';

    return 0;
}
