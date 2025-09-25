#include <bits/stdc++.h>
using namespace std;

bool query(int X, vector<int> &S) {
    int res;

    cout << "? " << X << ' ' << S.size() << ' ';
    for (int i : S)
        cout << i << ' ';
    cout << '\n', cout.flush();

    cin >> res;
    return res;
}

void answer(int X) { cout << "! " << X << '\n', cout.flush(); }

int ans;

void dnc(vector<int> arr, vector<int> S, vector<int> T) { // arr : index, S : 수
    if (ans != -1)
        return;

    if (arr.size() <= 1) {
        if (!S.empty())
            ans = S[0];
        return;
    }

    int m = (int)arr.size() / 2;
    vector<int> l, r, lS, rS, lT, rT;

    for (int i = 0; i < m; i++)
        l.push_back(arr[i]);
    for (int i = m; i < arr.size(); i++)
        r.push_back(arr[i]);

    for (int i : S) {
        if (query(i, l)) {
            if (query(i, r)) {
                lT.push_back(i), rT.push_back(i);
                continue;
            }
            lS.push_back(i);
        } else
            rS.push_back(i);
    }

    for (int i : T) {
        if (query(i, l))
            lT.push_back(i);
        else
            rT.push_back(i);
    }

    if (l.size() != (lS.size() * 2 + lT.size()))
        dnc(l, lS, lT);
    else
        dnc(r, rS, rT);
}

void solve() {
    int N;
    vector<int> A, B;

    cin >> N, ans = -1;
    for (int i = 1; i < N * 2; i++)
        A.push_back(i);
    for (int i = 1; i <= N; i++)
        B.push_back(i);

    random_device rd;
    mt19937 rng(rd());

    shuffle(A.begin(), A.end(), rng), shuffle(B.begin(), B.end(), rng);

    dnc(A, B, {}), answer(ans);
}

signed main() {
    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}