#include "Joi.h"
#include "Ioi.h"
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MAX = 10000;

vector<int> adj[MAX], st, val;
vector<vector<int>> arr;

int uf[MAX], parent[MAX], sz[MAX], R[MAX], G[MAX];
bool chk[MAX];

void dfs1(int node, int par) {
	sz[node] = 1, parent[node] = par;
	for (int i : adj[node]) {
		if (i == par)
			continue;
		dfs1(i, node), sz[node] += sz[i];
	}
}

void dfs3(int node, int par) {
	st.push_back(node), parent[node] = par;
	for (int i : adj[node]) {
		if (i == par || !chk[i])
			continue;
		dfs3(i, node);
	}
}

void dfs4(int node, int par) {
	val.push_back(node);
	for (int i : adj[node])
		if (i ^ par)
			dfs4(i, node);
}

void dfs2(int node, int par, int gr) {
	if (arr[gr].size() == 60 && sz[node] < 60) {
		for (int i : arr[gr])
			chk[i] = true;
		st.clear(), dfs3(par, node);
		for (int i : arr[gr])
			chk[i] = false;
		val.clear(), dfs4(node, par), arr.push_back({}), G[node] = arr.size();
		for (int i : val) {
			R[i] = R[st.back()], st.pop_back();
			G[i] = G[node], arr[G[node] - 1].push_back(i);
		}
		for (int i : st)
			arr[G[node] - 1].push_back(i);
	} else if (arr[gr].size() == 60)
		arr.push_back({}), dfs2(node, par, (int)arr.size() - 1);
	else {
		R[node] = arr[gr].size(), arr[gr].push_back(node), G[node] = gr + 1;
		for (int i : adj[node]) {
			if (i == par)
				continue;
			dfs2(i, node, gr);
		}
	}
}

int find(int X) { return X == uf[X] ? X : uf[X] = find(uf[X]); }
void uni(int X, int Y) {
    X = find(X), Y = find(Y);
    uf[X] = Y;
}

int Ioi(signed N, signed M, signed A[], signed B[], signed P, signed V, signed T) {
	int ans = 0, RT;

    for (int i = 0 ; i < N ; i ++)
        uf[i] = i;

    for (int i = 0 ; i < M ; i ++) {
        if (find(A[i]) == find(B[i]))
            continue;
        adj[A[i]].push_back(B[i]), adj[B[i]].push_back(A[i]);
        uni(A[i], B[i]);
    }

    for (int i = 0 ; i < N ; i ++) 
        sort(adj[i].begin(), adj[i].end());
    dfs1(0, -1), arr.push_back({}), dfs2(0, -1, 0);

	for (int i : arr[G[P] - 1]) 
		chk[i] = true;
	st.clear(), dfs3(P, -1);

	for (int i = 0 ; i < 60 ; i ++) {
		ans |= (int)V << R[P];
		if (i + 1 == 60)
			break;
		while (parent[st[i + 1]] != P)
			P = parent[P], V = Move(P);
		P = st[i + 1], V = Move(P);
	}

	for (int i = 0 ; i < N ; i ++)
		adj[i].clear(), chk[i] = false, R[i] = G[i] = 0;
    st.clear(), arr.clear();
	
	return ans;
}

void Joi(signed N, signed M, signed A[], signed B[], int X, signed T) {
    for (int i = 0 ; i < N ; i ++)
        uf[i] = i;

    for (int i = 0 ; i < M ; i ++) {
        if (find(A[i]) == find(B[i]))
            continue;
        adj[A[i]].push_back(B[i]), adj[B[i]].push_back(A[i]);
        uni(A[i], B[i]);
    }

    for (int i = 0 ; i < N ; i ++) 
        sort(adj[i].begin(), adj[i].end());
    dfs1(0, -1), arr.push_back({}), dfs2(0, -1, 0);

	for (int i = 0 ; i < N ; i ++)
		MessageBoard(i, (X >> R[i]) & 1);

	for (int i = 0 ; i < N ; i ++)
		adj[i].clear(), chk[i] = false, R[i] = G[i] = 0;
    st.clear(), arr.clear();
}