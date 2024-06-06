from sys import stdin

N, K, D = map(int, stdin.readline().rstrip().split())
mx = -1

arr = []
for i in range(N):
    M, d = map(int, stdin.readline().rstrip().split())
    lst = list(map(int, stdin.readline().rstrip().split()))
    arr.append([d, lst])
arr = list(sorted(arr))

i, j = 0, 0
algo = [0 for i in range(K + 1)]

while j < N:
    for k in arr[j][1]:
        algo[k] += 1

    while arr[j][0] - arr[i][0] > D:
        for k in arr[i][1]:
            algo[k] -= 1
        i += 1

    A, B = 0, 0
    for k in algo:
        if k == j - i + 1:
            A += 1
        if k:
            B += 1
    mx = max(mx, (B - A) * (j - i + 1))

    j += 1

print(mx)
