from cyaron import *

tree = Graph.tree(20001)

test_data = IO(file_prefix="tree", data_id=1)
test_data.input_writeln("20001")
test_data.input_writeln(tree.to_str(output=Edge.unweighted_edge))
# test_data.input_writeln(tree)