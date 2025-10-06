struct Node {
    int children[26];
    bool output = false;

    Node() { fill(children, children + 26, -1); }
};

vector<Node> trie;

void insert(string S) {
    int X = 0, C;
    for (char i : S) {
        C = i - 'a';
        if (trie[X].children[C] == -1)
            trie[X].children[C] = trie.size(), trie.push_back(Node());
        X = trie[X].children[C];
    }
    trie[X].output = true;
}

int find(string S) {
    int X = 0, C;
    for (char i : S) {
        C = i - 'a';
        if (trie[X].children[C] == -1)
            return -1;
        X = trie[X].children[C];
    }
    return X;
}