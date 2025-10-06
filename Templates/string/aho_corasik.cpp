struct Node {
    int children[26], pi = 0;
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

void build() {
    queue<int> q;
    int X, C, P;

    for (int i = 0; i < 26; i++) {
        C = trie[0].children[i];
        if (C == -1)
            trie[0].children[i] = 0;
        else
            trie[C].pi = 0, q.push(C);
    }

    while (!q.empty()) {
        X = q.front(), q.pop();

        for (int i = 0; i < 26; i++) {
            C = trie[X].children[i];
            if (C == -1)
                continue;

            P = trie[X].pi;
            while (trie[P].children[i] == -1)
                P = trie[P].pi;

            P = trie[P].children[i], trie[C].pi = P;
            if (trie[P].output)
                trie[C].output = true;
            q.push(C);
        }
    }
}

bool query(string S) {
    int X = 0, C;
    bool res = false;

    for (char i : S) {
        C = i - 'a';
        while (trie[X].children[C] == -1)
            X = trie[X].pi;
        X = trie[X].children[C];
        res = res || trie[X].output;
    }

    return res;
}