N = int(input())
res = []

checked = [[False for j in range(N + 1)] for i in range(N + 1)]
parent = [0 for i in range(N + 1)]

nt = 1
while True:
    k = nt
    if len(res) == N - 1:
        break

    print("maze", flush=True)
    nt = int(input())

    if checked[k][nt]:
        if parent[k] != nt:
            print(f"gaji {k}", flush=True)
            input()
            print(f"gaji {parent[k]}", flush=True)
            input()
        nt = parent[k]
        continue

    checked[k][nt] = True
    checked[nt][k] = True
    parent[nt] = k

    res.append((k, nt))

print("answer", flush=True)
for i in res:
    print(*i, flush=True)
exit()
