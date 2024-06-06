from collections import defaultdict, deque

K, N = map(int, input().split())
checked = defaultdict(bool)

arr = deque([(0, 1, K)])
res = []

while len(res) < N:
    a = arr.popleft()
    pos = [
        (K * (a[1] + a[2]) - a[0], a[1], a[2]),
        (a[0], K * (a[0] + a[2]) - a[1], a[2]),
        (a[0], a[1], K * (a[0] + a[1]) - a[2]),
    ]

    for i, j, k in pos:
        if i <= 0 or j <= 0 or k <= 0:
            continue

        arr.append((i, j, k))
        if not checked[i] and not checked[j] and not checked[k]:
            checked[i], checked[j], checked[k] = True, True, True
            res.append((i, j, k))

for i, j, k in res:
    print(i, j, k)
