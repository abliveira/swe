"""
Adjacency List Representation of an Undirected Graph

Key Differences from C++/Java Versions:
- Python uses dictionaries (`dict`) for dynamic vertex management,
  making it easier to support sparse graphs and flexible vertex IDs.
- No need to predefine the number of vertices—nodes are created on demand.
- List operations like removal are built-in and concise (`list.remove()`).
- Exception handling (e.g., `try-except`) replaces manual bounds checks.

Efficient for sparse graphs: O(1) add, O(n) remove, O(n + e) display.
"""

class AdjacencyList:
    def __init__(self):
        # Dictionary maps each vertex to a list of its adjacent vertices
        self.graph = {}

    def add_edge(self, u, v):
        # Adds an undirected edge between u and v
        self.graph.setdefault(u, []).append(v)  # If 'u' is not a key in the dictionary, insert it with value []; then append 'v' to the list at key 'u'.
        self.graph.setdefault(v, []).append(u) # Same as above

    def remove_edge(self, u, v):
        # Removes the edge between u and v, if it exists
        try:
            self.graph[u].remove(v)  # Removes the first occurrence of value 'v' from the list stored at key 'u' in the dictionary.
            self.graph[v].remove(u)  # Removes the first occurrence of value 'u' from the list stored at key 'v' in the dictionary.
        except (KeyError, ValueError):
            print(f"Edge ({u}, {v}) does not exist.")

    def display(self):
        for vertex in sorted(self.graph):
            neighbors = ' -> '.join(map(str, self.graph[vertex])) # Converts all neighbors of 'vertex' to strings and joins them with ' -> ' separator into a single string.
            print(f"{vertex} -> {neighbors}")

# Example usage
if __name__ == "__main__":
    G = AdjacencyList()

    # Add edges
    G.add_edge(1, 2)
    G.add_edge(1, 3)
    G.add_edge(2, 4)
    G.add_edge(3, 4)

    print("\nInitial Graph:")
    G.display()

    # Remove an edge
    G.remove_edge(1, 3)

    print("\nAfter Removing Edge (1, 3):")
    G.display()
