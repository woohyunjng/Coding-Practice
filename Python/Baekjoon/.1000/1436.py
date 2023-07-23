N = int(input())
K = 1
cnt = 0

while True:
    if "666" in str(K):
        cnt += 1

    if cnt == N:
        print(K)
        break

    K += 1
