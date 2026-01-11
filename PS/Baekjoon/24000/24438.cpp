#include <bits/stdc++.h>
using namespace std;

int query(string q);

char getc(int X) { return (char)('a' + X); }

string guess(int N, int S) {
    string ans = "", qus;

    int X = -1, Y = -1, Z, L, R;
    bool flag = false;

    vector<int> cnt(S, 0), arr;

    for (int i = 0; i < S; i++) {
        qus = "", arr.push_back(i);
        for (int j = 0; j < N; j++)
            qus.push_back(getc(i));
        cnt[i] = query(qus);
        if (Z > Y)
            X = i, Y = Z;
    }

    sort(arr.begin(), arr.end(), [&](int x, int y) { return cnt[x] > cnt[y]; });

    for (int i : arr) {
        if (!flag) {
            for (int j = 0; j < cnt[i]; j++)
                ans.push_back(getc(i));
            flag = true;
            continue;
        }

        L = 0, R = ans.size();
        for (int j = 0; j < cnt[i]; j++) {
            X = -1;
            for (int st = L, en = R, md; st <= en;) {
                md = st + en >> 1;
                qus = ans.substr(0, md);
                for (int k = 0; k <= j; k++)
                    qus += getc(i);
                Y = query(qus);
                if (Y >= md + 1 + j)
                    X = md, st = md + 1;
                else
                    en = md - 1;
            }
            ans = ans.substr(0, X) + getc(i) + ans.substr(X), R = X;
        }
    }

    return ans;
}
