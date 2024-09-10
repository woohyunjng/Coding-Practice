#include <bits/stdc++.h>
#define int long long

#define MAX 200100
#define MOD 1000000007
#define INF 0x7f7f7f7f7f7f7f7f
#define endl '\n'

using namespace std;
typedef pair<int, int> pr;
typedef array<int, 3> tp;

struct Node {
    int child_num = 0;
    bool output = false;
    unordered_map<int, int> children;

    Node() { children.clear(); }
};

class Trie {
  public:
    vector<Node> trie;
    bool is_large = true;

    Trie(bool il = true) : is_large(il) { trie.push_back(Node()); }

    ~Trie() { trie.clear(); }

    void insert(string &S) {
        int cur = 0, c;

        for (char ch : S) {
            if (!is_large)
                c = ch - 'a';
            else
                c = ch - 'A';

            if (trie[cur].children.find(c) == trie[cur].children.end()) {
                trie[cur].children[c] = trie.size();
                trie[cur].child_num++;
                trie.push_back(Node());
            }

            cur = trie[cur].children[c];
        }
        trie[cur].output = true;
    }

    int find(string &S) {
        int cur = 0, c;

        for (char ch : S) {
            if (!is_large)
                c = ch - 'a';
            else
                c = ch - 'A';

            if (trie[cur].children.find(c) == trie[cur].children.end())
                return -1;

            cur = trie[cur].children[c];
        }

        return cur;
    }

    vector<int> starts_with(string &S) {
        vector<int> res;
        int c, cur = 0, length = 0;

        for (char ch : S) {
            if (!is_large)
                c = ch - 'a';
            else
                c = ch - 'A';

            if (trie[cur].children.find(c) == trie[cur].children.end())
                break;

            cur = trie[cur].children[c];
            length++;
            if (trie[cur].output)
                res.push_back(length);
        }

        return res;
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int C, N, Q;
    string S, K;
    bool res;

    cin >> C >> N;

    Trie color(false);
    unordered_map<string, bool> team_name;
    vector<int> val;

    while (C--) {
        cin >> S;
        color.insert(S);
    }

    while (N--) {
        cin >> S;
        team_name[S] = true;
    }

    cin >> Q;
    while (Q--) {
        cin >> S;
        val = color.starts_with(S);

        res = false;

        for (int i : val) {
            K = S.substr(i, S.size() - 1);
            if (team_name.find(K) != team_name.end()) {
                res = true;
                break;
            }
        }

        cout << (res ? "Yes" : "No") << endl;
    }

    return 0;
}