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
    int child_num = 0, output = 0, parent, children[2] = {0, 0};
};

class Trie {
  public:
    vector<Node> trie;

    Trie() { trie.push_back(Node()); }
    ~Trie() { trie.clear(); }

    void insert(string &S) {
        int cur = 0, c;

        for (int i = 0; i < 30; i++) {
            c = S[i] - '0';

            if (trie[cur].children[c] == 0) {
                trie[cur].children[c] = trie.size();
                trie[cur].child_num++;

                trie.push_back(Node());
                trie.back().parent = cur;
            }

            cur = trie[cur].children[c];
        }
        trie[cur].output++;
    }

    void remove(string &S) {
        int cur = 0, X, c;

        for (int i = 0; i < 30; i++)
            cur = trie[cur].children[S[i] - '0'];

        if (--trie[cur].output == 0) {
            for (int i = 30 - 1; i >= 0; i--) {
                c = S[i] - '0';
                X = trie[cur].parent;

                trie[X].children[c] = 0;
                trie[X].child_num--;

                cur = X;

                if (trie[X].child_num || trie[X].output)
                    break;
            }
        }
    }
};

string to_binary(int X) {
    string res = string(30, '0');
    int K = 30;

    while (X) {
        res[--K] = X % 2 + '0';
        X /= 2;
    }

    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int M, A, B, res, cur, c;
    string K;

    Trie trie;
    K = to_binary(0);
    trie.insert(K);

    cin >> M;
    while (M--) {
        cin >> A >> B;
        K = to_binary(B);
        if (A == 1)
            trie.insert(K);
        else if (A == 2)
            trie.remove(K);
        else {
            res = 0, cur = 0;
            for (int i = 0; i < 30; i++) {
                c = K[i] - '0';

                if (trie.trie[cur].children[c ^ 1]) {
                    cur = trie.trie[cur].children[c ^ 1];
                    res = res << 1 | 1;
                } else {
                    cur = trie.trie[cur].children[c];
                    res = res << 1;
                }
            }

            cout << res << '\n';
        }
    }

    return 0;
}