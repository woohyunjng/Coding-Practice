from collections import deque

N, K = map(int, input().split())
q = deque([[K, 0]])
checked = [False for i in range(100001)]

if N == K:
    print(0)
else:
    checked[K] = True
    while len(q):
        A = q.popleft()
        arr = [A[0] + 1, A[0] - 1]
        if not A[0] % 2:
            arr.append(A[0] // 2)

        if N in arr:
            print(A[1] + 1)
            break

        for i in arr:
            if i < 1 or i >= 100001:
                continue

            if not checked[i]:
                q.append([i, A[1] + 1])
                checked[i] = True
