N, M = map(int, input().split())
T, S = map(int, input().split())

home = N + (N - 1) // 8 * S
read = M + (M - 1) // 8 * (S + 2 * T) + T

if home < read:
    print("Zip")
    print(home)
else:
    print("Dok")
    print(read)
