N = int(input())
S = input()

print(
    min(
        [
            S.count("B"),
            S.count("E") // 2,
            S.count("I"),
            S.count("L"),
            S.count("N"),
            S.count("O"),
            S.count("R") // 2,
            S.count("S"),
            S.count("V"),
            S.count("Z"),
        ]
    )
)
