#include <bits/stdc++.h>
using namespace std;

const int MAX = 201;

int X[MAX], T[MAX];

int query(string S) {
    int res;
    cout << "? " << S << '\n', cout.flush();
    cin >> res;
    return res;
}

void answer(string S) { cout << "! " << S << '\n', cout.flush(); }

signed main() {
    int N, K;
    string S, ans;

    cin >> N;

    for (int i = 0; i < N; i++)
        S += "()";
    K = query(S);

    for (int i = 0; i < N; i++) {
        S[i << 1] = '{', S[i << 1 | 1] = '}';
        X[i << 1] = query(S) - K;
        S[i << 1] = '(', S[i << 1 | 1] = ')';
    }

    S.clear(), S += '(';
    for (int i = 0; i + 1 < N; i++)
        S += "()";
    S += ')', K = query(S);

    for (int i = 0; i + 1 < N; i++) {
        S[i << 1 | 1] = '{', S[(i + 1) << 1] = '}';
        X[i << 1 | 1] = query(S) - K;
        S[i << 1 | 1] = '(', S[(i + 1) << 1] = ')';
    }

    T[0] = 1;
    for (int i = 0; i + 1 < (N << 1); i++) {
        if (abs(X[i]) == 1)
            T[i + 1] = T[i];
        else if (abs(X[i]) == 2)
            T[i + 1] = -1;
        else
            T[i + 1] = 1;
    }

    for (int i = 0; i < (N << 1); i++) {
        if (T[i] == 1)
            ans += X[i] > 0 ? '(' : '{';
        else
            ans += X[i - 1] > 0 ? ')' : '}';
    }

    answer(ans);

    return 0;
}