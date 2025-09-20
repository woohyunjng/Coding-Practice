#include <bits/stdc++.h>
using namespace std;

const int MAX = 200003;

int A[MAX];

void solve() {
    int N, L = 1, C;
    string _S;
    bool ans = true, flag;

    vector<int> arr;

    cin >> N >> _S;
    if (_S[0] == '0')
        _S = "0" + _S;
    if (_S.back() == '0')
        _S = _S + "0";

    N = _S.size(), A[N + 1] = 1;
    for (int i = 1; i <= N; i++)
        A[i] = _S[i - 1] - '0';

    while (L <= N && ans) {
        while (L <= N && A[L] == 1)
            L++;
        if (L > N)
            break;

        C = 0, arr.clear();
        for (int i = L; i <= N; i++) {
            if (A[i] == 1 && A[i + 1] == 1) {
                arr.push_back(C), L = i + 2;
                break;
            } else if (A[i] == 1)
                arr.push_back(C), C = 0;
            else
                C++;
            if (i == N && C > 0)
                arr.push_back(C), L = N + 1;
        }

        if (arr.size() % 2 == 0)
            continue;
        else {
            flag = true;
            for (int i : arr)
                flag &= i == 1;
            ans &= !flag;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}