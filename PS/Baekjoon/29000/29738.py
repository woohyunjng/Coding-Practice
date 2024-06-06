T = int(input())
for i in range(T):
    N = int(input())

    if N <= 25:
        res = "World Finals"
    elif N <= 1000:
        res = "Round 3"
    elif N <= 4500:
        res = "Round 2"
    else:
        res = "Round 1"

    print(f"Case #{i + 1}: {res}")
