#include <bits/stdc++.h>
#define int long long

using namespace std;

int gt(char X) {
    if (X == 'A')
        return 0;
    if (X == 'C')
        return 1;
    if (X == 'G')
        return 2;
    return 3;
}

struct Node {
    int children[4];
    vector<int> output;

    Node() {
        output.clear();
        for (int i = 0; i < 4; i++)
            children[i] = -1;
    }
};

vector<Node> trie;

void dfs(int cur) {
    for (int i = 0; i < 4; i++) {
        if (trie[cur].children[i] == -1)
            continue;

        sort(trie[cur].output.begin(), trie[cur].output.end());
        dfs(trie[cur].children[i]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, cur, C, L, R, res;
    bool flag;
    string S, P, Q;
    vector<string> arr;

    cin >> N >> M;
    trie.push_back(Node());

    for (int i = 1; i <= N; i++)
        cin >> S, arr.push_back(S);
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++) {
        cur = 0, S = arr[i];
        reverse(S.begin(), S.end());

        for (char j : S) {
            C = gt(j);
            if (trie[cur].children[C] == -1)
                trie[cur].children[C] = trie.size(), trie.push_back(Node());
            cur = trie[cur].children[C];
            trie[cur].output.push_back(i);
        }
    }

    dfs(0);

    while (M--) {
        cin >> P >> Q, res = 0, flag = true;
        L = lower_bound(arr.begin(), arr.end(), P) - arr.begin();
        R = upper_bound(arr.begin(), arr.end(), P + "{") - arr.begin() - 1;

        cur = 0, reverse(Q.begin(), Q.end());
        for (char j : Q) {
            C = gt(j);
            if (trie[cur].children[C] == -1) {
                flag = false;
                break;
            }
            cur = trie[cur].children[C];
        }

        if (flag)
            res = upper_bound(trie[cur].output.begin(), trie[cur].output.end(), R) - lower_bound(trie[cur].output.begin(), trie[cur].output.end(), L);
        cout << res << '\n';
    }

    return 0;
}