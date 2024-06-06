N = int(input())
w, m = 0, 0

for i in range(N):
    T, W, H, L = input().split()
    W, H, L = int(W), int(H), int(L)

    if T == "A":
        w += (W // 12) * (H // 12) * (L // 12) * 500 + 1000
        m += (W // 12) * (H // 12) * (L // 12) * 4000
    else:
        w += 6000

print(w)
print(m)
