N, W = map(int, input().split())
arr = []

for i in range(N):
    S = input()
    K = ["" for j in range(7 * W)]
    mx = 10000000000000000000000000000000000

    start, use_freeze = 1e9, 0
    streek, last_freeze = 0, 0

    for j in range(7):
        line = list(input())
        for k in range(W):
            K[7 * k + j] = line[k]
    hash = 7 * W

    for i in range(hash):
        if K[i] == "O":
            streek += 1
            last_freeze = 0
            if start == 1e9:
                start = i
                use_freeze = 0
        elif K[i] == "F":
            use_freeze += 1
            last_freeze += 1
        else:
            streek = 0
            use_freeze = 0
            last_freeze = 0
            start = 1e9

        ims = [streek, use_freeze - last_freeze, start, K.count("X")]
        mx = min(mx, ims[3] + ims[2] * hash + ims[1] * hash**2 + (hash - ims[0]) * hash**3)

    arr.append((mx, S))

arr = list(sorted(arr))
bef = -1
num = 0

for i in range(N):
    if arr[i][0] != bef:
        num += 1
    print(f"{num}. {arr[i][1]}")
    bef = arr[i][0]
