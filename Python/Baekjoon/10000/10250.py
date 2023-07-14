T = int(input())

for i in range(T):
    H, W, N = map(int, input().split())
    print(f"{(N - 1) % H + 1}{str((N - 1) // H + 1).zfill(2)}")
