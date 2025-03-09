#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 1000000;

map<string, int> dict;

string query_no_dict(int X, int Y) {
    string S;
    X = min(MAX, max(0ll, X)), Y = min(MAX, max(0ll, Y));
    cout << X << ' ' << Y << '\n', cout.flush();
    getline(cin, S);
    if (*S.rbegin() == '!')
        exit(0);
    return S;
}

int query(int X, int Y) {
    string S = query_no_dict(X, Y);
    if (dict.find(S) == dict.end())
        dict[S] = 2; // 2 -> Further
    return dict[S];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string S;
    int K, ansX, ansY, stX, stY, enX, enY, mdX, mdY;

    dict[query_no_dict(0, 0)] = 0; // 0 -> At the same distance

    S = query_no_dict(1, 1);
    if (dict.find(S) != dict.end()) {
        S = query_no_dict(0, 1);
        S = query_no_dict(1, 0);
    }

    dict[S] = 1; // 1 -> Closer

    stX = stY = 0, enX = enY = MAX;

    for (int i = 0; i < 19; i++) {
        if (stX == enX && stY == enY)
            break;
        mdX = stX + enX >> 1, mdY = stY + enY >> 1;

        query(mdX, mdY);
        if (query(mdX + 1, mdY) == 1)
            stX = mdX + 1;
        else
            enX = mdX - 1;

        if (query(mdX + 1, mdY + 1) == 1)
            stY = mdY + 1;
        else
            enY = mdY - 1;
    }

    query(stX, stY), query(stX + 1, stY + 1);
    query(stX + 1, stY), query(stX, stY + 1);

    return 0;
}