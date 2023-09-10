chess = ""
for i in range(8):
    chess += input()

white = (
    chess.count("P")
    + chess.count("N") * 3
    + chess.count("B") * 3
    + chess.count("R") * 5
    + chess.count("Q") * 9
)

black = (
    chess.count("p")
    + chess.count("n") * 3
    + chess.count("b") * 3
    + chess.count("r") * 5
    + chess.count("q") * 9
)

print(white - black)
