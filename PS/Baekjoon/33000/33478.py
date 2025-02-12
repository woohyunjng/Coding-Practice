for _ in range(int(input())):
    A, B, C = map(int, input().split())
    print(
        ((A + B + C) * (A + B - C) * (B + C - A) * (C + A - B)) ** 0.5
        / (4 * (A + B + C))
    )
