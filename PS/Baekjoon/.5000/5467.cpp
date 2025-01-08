#include <bits/stdc++.h>
#define int long long

using namespace std;
typedef pair<int, int> pr;

struct Node {
    bool output = false;
    int length = 0;
    unordered_map<int, int> children;

    Node() { children.clear(); }
};

vector<Node> trie;
vector<char> ans;

int length_dfs(int K) {
    int res = 1;
    for (int i = 0; i < 26; i++) {
        if (trie[K].children.find(i) != trie[K].children.end())
            res = max(res, 1 + length_dfs(trie[K].children[i]));
    }
    return trie[K].length = res;
}

void dfs(int K) {
    if (trie[K].output)
        ans.push_back('P');

    vector<pr> children;

    for (int i = 0; i < 26; i++)
        if (trie[K].children.find(i) != trie[K].children.end())
            children.push_back({trie[trie[K].children[i]].length, i});

    sort(children.begin(), children.end());

    for (pr i : children) {
        ans.push_back(i.second + 'a');
        dfs(trie[K].children[i.second]);
        ans.push_back('-');
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, cur = 0, C;
    string S;

    cin >> N;

    trie.push_back(Node());
    while (N--) {
        cin >> S, cur = 0;
        for (char i : S) {
            C = i - 'a';
            if (trie[cur].children.find(C) == trie[cur].children.end())
                trie[cur].children[C] = trie.size(), trie.push_back(Node());
            cur = trie[cur].children[C];
        }
        trie[cur].output = true;
    }

    length_dfs(0);
    dfs(0);

    while (ans.back() == '-')
        ans.pop_back();

    cout << ans.size() << '\n';
    for (char i : ans)
        cout << i << '\n';

    return 0;
}