int parent[MAX], sz[MAX];

int find(int X) { return parent[X] == X ? X : find(parent[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    if (X == Y)
        return;
    if (sz[X] < sz[Y])
        swap(X, Y);
    rollback_st.push_back(Y);
    sz[X] += sz[Y], parent[Y] = X;
}

void rollback() {
    int K = rollback_st.back();
    rollback_st.pop_back();
    sz[parent[K]] -= sz[K], parent[K] = K;
}