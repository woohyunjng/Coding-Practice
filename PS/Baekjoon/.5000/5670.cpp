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
};

vector<string> arr;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, res = 0, cnt = 0, cur;
    string S;

    cout << fixed << setprecision(2);

    while (true) {
        cin >> N;
        if (cin.eof())
            break;

        res = 0;

        Trie trie(false);

        for (int i = 1; i <= N; i++) {
            cin >> S;
            arr.push_back(S);
            trie.insert(S);
        }

        for (string i : arr) {
            cnt = 1;
            cur = trie.trie[0].children[i[0] - 'a'];

            for (int j = 1; j < i.size(); j++) {
                if (trie.trie[cur].child_num > 1 || trie.trie[cur].output)
                    cnt++;

                cur = trie.trie[cur].children[i[j] - 'a'];
            }

            res += cnt;
        }

        cout << (double)res / N << '\n';

        arr.clear();
    }

    return 0;
}