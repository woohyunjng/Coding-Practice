from sys import stdin

input = stdin.readline
T = int(input())

for t in range(T):
    N, A, B = map(int, input().split())
    S = input().strip()

    x, y = 0, 0

    res = False

    for i in range(100):
        for j in range(N):
            if S[j] == "N":
                y += 1
            elif S[j] == "E":
                x += 1
            elif S[j] == "S":
                y -= 1
            else:
                x -= 1

            if x == A and y == B:
                res = True
                break

    print("YES" if res else "NO")
