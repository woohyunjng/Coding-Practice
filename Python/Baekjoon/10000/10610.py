N = list(map(int, input()))

if sum(N) % 3 or 0 not in N:
    print(-1)
else:
    N.remove(0)
    print(f"{''.join(sorted(map(str, N), reverse=True))}0")
