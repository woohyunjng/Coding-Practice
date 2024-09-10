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