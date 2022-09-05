from cyaron import *
from random import randint

n = 2000000
io = IO("data.txt")
graph = Graph.tree(n)
io.input_writeln(n)
io.input_writeln(graph.to_str(output=Edge.unweighted_edge)) 
for i in range(n):
    io.input_write(randint(0, n))