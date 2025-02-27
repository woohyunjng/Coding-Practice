vector<int> arr[MAX];
int sz[MAX], C[MAX];
bool vst[MAX];

int get_size(int node, int par) {
    sz[node] = 1;
    for (int i : arr[node]) {
        if (i == par || vst[i])
            continue;
        sz[node] += get_size(i, node);
    }
    return sz[node];
}

int get_cent(int node, int par, int cap) {
    for (int i : arr[node]) {
        if (i == par || vst[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_cent(i, node, cap);
    }
    return node;
}

void dnc(int node) {
    int cent = get_cent(node, -1, get_sz(node, -1));
    vst[cent] = true;

    for (int i : arr[cent]) {
        if (vst[i])
            continue;
    }

    for (int i : arr[cent]) {
        if (vst[i])
            continue;
        dnc(i);
    }
}
