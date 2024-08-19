class Manacher {
  public:
    string S, K;
    vector<int> rad;

    Manacher(string S) : S(S) {
        K = "#";
        for (char i : S) {
            K.push_back(i);
            K.push_back('#');
        }
        rad.resize(K.size());
    }

    void build() {
        int r = -1, c = -1;
        for (int i = 0; i < K.size(); i++) {
            if (i <= r)
                rad[i] = min(r - i, rad[2 * c - i]);
            while (i - rad[i] - 1 >= 0 && i + rad[i] + 1 < K.size() && K[i - rad[i] - 1] == K[i + rad[i] + 1])
                rad[i]++;
            if (r < i + rad[i]) {
                r = i + rad[i];
                c = i;
            }
        }
    }
};