void init(string S) {
    vector<int> K = {'#'}, rad; // rad[i] := i가 중심인 팰린드롬 반지름
    for (char i : S)
        K.push_back(i), K.push_back('#');
    rad.resize(K.size());

    int R = -1, C = -1;
    for (int i = 0; i < K.size(); i++) {
        if (i <= R)
            rad[i] = min(R - i, rad[2 * C - i]);
        while (i - rad[i] - 1 >= 0 && i + rad[i] + 1 < K.size() && K[i - rad[i] - 1] == K[i + rad[i] + 1])
            rad[i]++;
        if (R < i + rad[i])
            R = i + rad[i], C = i;
    }
}