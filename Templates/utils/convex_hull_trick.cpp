vector<tp> F;
int ftop = 0;

void insert(pr X) {
    tp K = {X.first, X.second, 0};
    while (!F.empty()) {
        K[2] = (F.back()[1] - K[1]) / (K[0] - F.back()[0]);
        if (F.back()[2] < K[2])
            break;
        F.pop_back();
        if (F.size() == ftop)
            --ftop;
    }
    F.push_back(K);
}

int query(int x) {
    while (ftop + 1 < F.size() && F[ftop + 1][2] < x)
        ++ftop;
    return F[ftop][0] * x + F[ftop][1];
}