#include <bits/stdc++.h>
using namespace std;

int calc(int X, int Y, char K) {
    if (K == '+')
        return X + Y;
    else if (K == '-')
        return X - Y;
    else if (K == '*')
        return X * Y;
    else if (K == '/')
        return X / Y;
    return 0;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, X, Y;
    string S;

    vector<int> num;
    vector<char> st;

    cin >> S, N = S.size();

    for (int i = 0; i < N; i++) {
        if (S[i] == '(')
            st.push_back('(');
        else if (S[i] == ')') {
            while (!st.empty() && st.back() != '(')
                X = num.back(), num.pop_back(), Y = num.back(), num.pop_back(), num.push_back(calc(Y, X, st.back())), st.pop_back();
            st.pop_back();
        } else if (S[i] == '+' || S[i] == '-') {
            while (!st.empty() && st.back() != '(')
                X = num.back(), num.pop_back(), Y = num.back(), num.pop_back(), num.push_back(calc(Y, X, st.back())), st.pop_back();
            st.push_back(S[i]);
        } else if (S[i] == '*' || S[i] == '/') {
            while (!st.empty() && (st.back() == '*' || st.back() == '/'))
                X = num.back(), num.pop_back(), Y = num.back(), num.pop_back(), num.push_back(calc(Y, X, st.back())), st.pop_back();
            st.push_back(S[i]);
        } else {
            X = S[i] - '0';
            while (i + 1 < N && S[i + 1] >= '0' && S[i + 1] <= '9')
                X = X * 10 + (S[++i] - '0');
            num.push_back(X);
        }
    }

    while (!st.empty())
        X = num.back(), num.pop_back(), Y = num.back(), num.pop_back(), num.push_back(calc(Y, X, st.back())), st.pop_back();

    cout << num.back() << '\n';

    return 0;
}