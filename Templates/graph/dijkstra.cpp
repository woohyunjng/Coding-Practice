int V;
vector<pr> arr[MAX];

vector<int> get_dis(int K) {
    vector<int> dis(V + 1, LLONG_MAX);
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    pq.push({0, K});
    dis[K] = 0;

    while (pq.size()) {
        pr p = pq.top(), pq.pop();

        if (dis[p.second] != p.first)
            continue;

        for (pr i : arr[p.second]) {
            if (i.first + p.first < dis[i.second]) {
                dis[i.second] = i.first + p.first;
                pq.push({dis[i.second], i.second});
            }
        }
    }

    return dis;
}