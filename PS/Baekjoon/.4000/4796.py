i = 1

while True:
    L, P, V = map(int, input().split())
    if not L:
        break

    print(f"Case {i}: {V // P * L + min(L, V % P)}")
    i += 1
