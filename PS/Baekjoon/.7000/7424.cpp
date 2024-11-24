#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<string, string> pr;

int N;
vector<int> res;

string format(int N, int L) {
    string S = to_string(N);
    while (S.size() < L)
        S = '0' + S;
    return S;
}

void find(int K, int D) {
    if (K / D < 10) {
        res.push_back(K);
        return;
    }

    int M = K / D, R = K % D, X;
    for (int i = 0; i < min(10ll, (M + 1) / 2); i++) {
        X = M - i;
        if (X % 10 == i)
            find(X * D + R, D * 10);
        else if (X % 11 == 0)
            res.push_back((X / 11 * 10 + i) * D + R);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    find(N, 1);

    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());

    cout << res.size() << '\n';
    for (int i : res)
        cout << i << " + " << format(N - i, to_string(i).size() - 1) << " = " << N << '\n';

    return 0;
}