# Graphs
A graph is a data structure that consists of the following two components: 
1. A finite set of vertices also called as nodes. 
2. A finite set of ordered pair of the form (u, v) called as edge.

#### Methods to store a graph
1. Adjacency Matrix : An adjacency matrix is a square matrix used to represent a finite graph. The elements of the matrix indicate whether pairs of vertices are adjacent not in the graph.
> **NOTE**
> * Element can be accessed in O(1) time.
> * Space complexity is O(N<sup>2</sup>) for N nodes.
> * Finding neighbous takes O(N) time for N nodes.

2. EdgeList : An edge list is a data structure used to represent a graph as a list of its edges.

3. AdjacencyList : Can be refered to as array of list where array index is the value of nodes of a graph and array elements consists of a list of all nodes connected to the corresponding array index. This can also be visualized as a hash map where graph node is the key and list of neighbours is the value.
> **NOTE**
> * All neighbours can be found in O(Length of list of neighbours) time
> * Memory efficient approach, O(E) memory for E edges.

4. Implicit Graph : 2D Matrix of binary values. Indices above, below, on right or on left of a given index with a value 1 will be considered connected if they hold 1 as a value.

* Maximum number of edges a graph can have : <sup>N</sup>C<sub>2</sub> = O(N<sup>2</sup>)
* Minimum number of edges a graph can have : 0
* Minimum number of edges a connected graph (tree) can have : N - 1