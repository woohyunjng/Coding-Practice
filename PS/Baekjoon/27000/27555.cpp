#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 1000000000000000000ll
#define endl '\n'

using namespace std;
typedef array<int, 4> tp;

vector<tp> nodes;
int alph[30];

void print(int n, int l, int r) {
    if (l > r)
        return;

    if (nodes[n][0] != -1) {
        cout << (char)(nodes[n][0] + 'a');
        return;
    }

    if (nodes[nodes[n][2]][1] < l)
        print(nodes[n][3], l - nodes[nodes[n][2]][1], r - nodes[nodes[n][2]][1]);
    else if (nodes[nodes[n][2]][1] >= l && nodes[nodes[n][2]][1] < r) {
        print(nodes[n][2], l, nodes[nodes[n][2]][1]);
        print(nodes[n][3], 1, r - nodes[nodes[n][2]][1]);
    } else
        print(nodes[n][2], l, r);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int L, R, N, X;

    char K;
    string S;

    vector<pair<char, string>> inp;

    for (char i = 'a'; i <= 'z'; i++) {
        nodes.push_back({i - 'a', 1, -1, -1});
        alph[i - 'a'] = i - 'a';
    }

    cin >> L >> R >> N;

    for (int i = 1; i <= N; i++) {
        cin >> K >> S;
        inp.push_back({K, S});
    }

    while (N--) {
        auto [K, S] = inp[N];

        if (S.size() == 1)
            nodes.push_back({-1, nodes[alph[S[0] - 'a']][1], alph[S[0] - 'a'], -1});
        else {
            nodes.push_back({-1, min(INF, nodes[alph[S[0] - 'a']][1] + nodes[alph[S[1] - 'a']][1]), alph[S[0] - 'a'], alph[S[1] - 'a']});
            for (int i = 2; i < S.size(); i++)
                nodes.push_back({-1, min(INF, nodes.back()[1] + nodes[alph[S[i] - 'a']][1]), (int)nodes.size() - 1, alph[S[i] - 'a']});
        }

        alph[K - 'a'] = (int)nodes.size() - 1;
    }

    print(alph['a' - 'a'], L, R);

    return 0;
}