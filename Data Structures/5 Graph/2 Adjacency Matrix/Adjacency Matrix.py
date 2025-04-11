"""
Adjacency Matrix Representation of an Undirected Graph

Key Differences from C++/Java Versions:
- Python uses lists for fixed-size 2D arrays (representing the adjacency matrix) instead of `vector` or `int[][]`.
- The graph’s number of vertices must be predefined at the time of creation, and cannot be dynamically adjusted after that.
- Unlike C++/Java, Python does not require manual memory management. The matrix is automatically managed by Python's garbage collector.
- No need for explicit memory allocation or deallocation (i.e., no need to manually allocate arrays or use `new`/`delete` in C++ or `new` in Java).
- Python's lists automatically grow/shrink, but in the case of the adjacency matrix, the size is fixed once initialized.

Efficient for dense graphs: O(1) add, O(1) remove, O(n²) display.
"""

class AdjacencyMatrix:
    def __init__(self, n):
        """
        Constructor: Initializes an n x n matrix with all elements set to 0
        """
        self.n = n  # Number of vertices
        self.matrix = [[0 for _ in range(n)] for _ in range(n)]  # 2D list for adjacency matrix

    def add_edge(self, orig, dest):
        """
        Add an edge between two vertices (undirected)
        """
        if orig < 1 or dest < 1 or orig > self.n or dest > self.n:
            print(f"Invalid edge: ({orig}, {dest})")
        else:
            self.matrix[orig - 1][dest - 1] = 1 # Adjust for 0-based indexing
            self.matrix[dest - 1][orig - 1] = 1 # Adjust for 0-based indexing and add the reverse edge for undirected graph

    def remove_edge(self, orig, dest):
        """
        Remove an edge between two vertices (undirected)
        """
        if orig < 1 or dest < 1 or orig > self.n or dest > self.n:
            print(f"Invalid edge removal: ({orig}, {dest})")
        else:
            self.matrix[orig - 1][dest - 1] = 0 # Adjust for 0-based indexing
            self.matrix[dest - 1][orig - 1] = 0 # Adjust for 0-based indexing and add the reverse edge for undirected graph

    def display(self):
        """
        Display the adjacency matrix
        """
        for row in self.matrix:
            print("  ".join(map(str, row)))

if __name__ == "__main__":
    G = AdjacencyMatrix(4)  # Create a graph with 4 vertices

    # Add undirected edges to form a small connected graph
    G.add_edge(1, 2)
    G.add_edge(1, 3)
    G.add_edge(2, 4)
    G.add_edge(3, 4)

    print("\nInitial Graph Structure:")
    G.display()

    # Remove the edge between 1 and 3
    G.remove_edge(1, 3)

    print("\nAfter Removing Edge (1, 3):")
    G.display()
