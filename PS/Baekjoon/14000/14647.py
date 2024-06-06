N, M = map(int, input().split())
row = [0 for i in range(N)]
col = [0 for j in range(M)]
sm = 0

for i in range(N):
    line = input().split()
    for j in range(M):
        nine = line[j].count("9")
        row[i] += nine
        col[j] += nine
        sm += nine

print(sm - max(max(row), max(col)))
