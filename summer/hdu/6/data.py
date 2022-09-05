from cyaron import *
from random import randint

n = 4
io = IO("data.txt")
graph = Graph.tree(n)
io.input_writeln(1)
io.input_writeln(n)
io.input_writeln(graph.to_str(output=Edge.unweighted_edge)) 