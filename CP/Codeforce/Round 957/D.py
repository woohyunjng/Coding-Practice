from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, M, K = map(int, input().rstrip().split())
    S = "A" + input().rstrip()

    res = True
    i = 0
    while True:
        cur = S[i]
        if cur == "A" or cur == "L":
            if i + M > N:
                break
            for j in range(i + 1, min(N + 1, i + M + 1)):
                if S[j] == "L":
                    i = j
                    break
            else:
                for j in range(i + M, i, -1):
                    if S[j] == "W":
                        i = j
                        break
                else:
                    res = False
                    break
        else:
            if K:
                K -= 1
                i += 1
                if i == N + 1:
                    break
                if S[i] == "C":
                    res = False
                    break
            else:
                res = False
                break

    print("YES" if res else "NO")
