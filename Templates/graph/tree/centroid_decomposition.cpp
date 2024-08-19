vector<int> arr[MAX];
int sz[MAX], C[MAX];
bool checked[MAX];

int get_size(int node, int parent) {
    sz[node] = 1;
    for (int i : arr[node]) {
        if (i == parent || checked[i])
            continue;
        sz[node] += get_size(i, node);
    }
    return sz[node];
}

int get_centroid(int node, int parent, int cap) {
    for (int i : arr[node]) {
        if (i == parent || checked[i])
            continue;
        if (sz[i] * 2 > cap)
            return get_centroid(i, node, cap);
    }
    return node;
}

int get_res(int node, int parent) {
    // 분할 정복
}

int divide_and_conquer(int node) {
    get_size(node, -1);
    int res = LLONG_MAX, cent = get_centroid(node, -1, sz[node]);
    checked[cent] = true;

    for (int i : arr[cent]) {
        if (checked[i])
            continue;
    }

    for (int i : arr[cent]) {
        if (checked[i])
            continue;
        res = min(res, divide_and_conquer(i));
    }
    return res;
}
