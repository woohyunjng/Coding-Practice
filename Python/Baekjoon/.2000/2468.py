from collections import deque

N = int(input())
arr, mx_height = [], -1

for i in range(N):
    arr.append(list(map(int, input().split())))
    mx_height = max(mx_height, max(arr[-1]))

mx = -1
for a in range(mx_height):
    res = 0
    checked = [[False for j in range(N)] for i in range(N)]

    for b in range(N):
        for c in range(N):
            if not checked[b][c] and arr[b][c] > a:
                checked[b][c] = True
                q = deque([(b, c)])
                res += 1

                while len(q):
                    d, e = q.pop()
                    go = [(d + 1, e), (d - 1, e), (d, e + 1), (d, e - 1)]

                    for f, g in go:
                        if f >= N or f < 0 or g >= N or g < 0:
                            continue
                        if arr[f][g] <= a or checked[f][g]:
                            continue

                        q.append((f, g))
                        checked[f][g] = True
    
    mx = max(mx, res)

print(mx)
