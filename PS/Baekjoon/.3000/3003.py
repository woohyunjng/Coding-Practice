N_W = [1, 1, 2, 2, 2, 8]
N = list(map(int, input().split()))

for w, i in zip(N_W, N):
    print(w - i)
