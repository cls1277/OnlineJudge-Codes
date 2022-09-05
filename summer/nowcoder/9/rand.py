from cyaron import *
from random import randint

n = randint(1, 5)
print(n)
for i in range(n):
    # str = String.random((10, 20))
    str = String.random(1000, charset="yz")
    print(str)