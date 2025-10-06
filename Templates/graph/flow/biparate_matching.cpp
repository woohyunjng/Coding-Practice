// O(VE)

vector<int> adj[MAX];
int assign[MAX];
bool chk[MAX];

bool dfs(int node) {
    for (int i : adj[node]) {
        if (chk[i])
            continue;
        chk[i] = true;
        if (assign[i] == -1 || dfs(assign[i])) {
            assign[i] = node;
            return true;
        }
    }
    return false;
}

void init() {
    int res = 0;

    for (int i = 1; i <= N; i++) {
        fill(chk, chk + MAX, false);
        if (dfs(i))
            res++;
    }
}