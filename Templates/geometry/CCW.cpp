int CCW(pr A, pr B, pr C) { // A-B-C 양수 반시계 / 0 일직선 / 음수 시계
    int val = (B[0] - A[0]) * (C[1] - A[1]) - (C[0] - A[0]) * (B[1] - A[1]);
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}