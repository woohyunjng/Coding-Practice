// 모든 간선 한번씩 지남
// 필요충분조건 -> 모든 정점의 차수가 짝수

// C[X] -> 간선 개수

void dfs(int node) {
    int X;
    while (!adj[node].empty()) {
        X = adj[node].back();
        if (C[X] > 0)
            C[X]--, dfs(U[X] ^ V[X] ^ node);
        else
            adj[node].pop_back();
    }
    ans.push_back(node);
}
