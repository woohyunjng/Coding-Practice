# 496/500

T = int(input())
for i in range(T):
    N, K = map(int, input().split())
    if N == K:
        res = [1 for j in range(N)]
    elif K == 1:
        res = range(1, N + 1)
    else:
        print(-1)
        continue
    print(" ".join(map(str, res)))
