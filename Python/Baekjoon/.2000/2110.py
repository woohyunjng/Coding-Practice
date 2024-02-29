from sys import stdin

N, C = map(int, stdin.readline().rstrip().split())
arr = []

for i in range(N):
    arr.append(int(input()))
arr = list(sorted(arr))

dis = []
for i in range(1, N):
    dis.append(arr[i] - arr[i - 1])

st, en = 0, arr[N - 1] - arr[0]
res = 0

while st <= en:
    mid = (st + en) // 2
    val = 1
    k = 0
    for i in dis:
        if k + i >= mid:
            k = 0
            val += 1
        else:
            k += i

    if val < C:
        en = mid - 1
    else:
        res = max(res, mid)
        st = mid + 1

print(res)
