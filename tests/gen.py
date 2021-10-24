from sys import argv
from random import randint

cnt = int(argv[1])

print(cnt)
for i in range(cnt):
    kind = randint(1,3)
    n = {
        1: 3,
        2: 4,
        3: 6
    }[kind]
    row = [kind, randint(0,6)] + [randint(0,10000) for _ in range(n)]
    print(' '.join(str(i) for i in row))
