#include <iostream>
#include <vector>
using namespace std;

/*
    Adjacency Matrix Representation of a Graph

    Adjacency Matrix: A 2D array where rows and columns represent vertices, and values indicate edge existence (1 for an edge, 0 for no edge). Efficient for dense graphs but uses O(n²) space.

        Example Graph:
        
            (1) --- (2)
             |       |
             |       |
            (3) --- (4)

        Adjacency Matrix:
        
                1  2  3  4  
            1 [ 0, 1, 1, 0 ]
            2 [ 1, 0, 0, 1 ]
            3 [ 1, 0, 0, 1 ]
            4 [ 0, 1, 1, 0 ]

    Basic operations and Complexity:
        - Add Edge: O(1) — Connects two vertices with an edge.
        - Remove Edge: O(1) — Removes an existing edge between two vertices.
        - Initialize: O(n²) — Creates a 2D array with all elements initialized to zero.
        - Display: O(n²) — Prints the adjacency matrix.

    Differences from the adjacency list:
        - Stores edges in a 2D matrix instead of dynamic neighbor lists.
        - More space usage (O(n²)) but offers constant-time edge lookup.
        - Best for dense graphs or when quick edge existence check is needed.

    Advantages:
        - Simple and direct representation, making edge lookups O(1).
        - Suitable for dense graphs where the number of edges is close to n².
        - Easy to implement and understand for small to medium-sized graphs.

    Cons:
        - Memory inefficient for sparse graphs, as it requires O(n²) space.
        - Operations like inserting or deleting vertices require resizing the matrix.
        - Traversing all edges takes O(n²), even if only a few edges exist.

    Implementation:
        - The `AdjacencyMatrix` class manages the graph, allowing edge insertion, removal, and display of connections.
*/


class AdjacencyMatrix {

    private:
        int n;          // Number of vertices
        vector<vector<int>> matrix;  // 2D vector for adjacency matrix
    
    public:
        // Constructor: Initializes an n x n matrix with all elements set to 0
        AdjacencyMatrix(int n) {
            this->n = n;
            matrix.resize(n, vector<int>(n, 0)); // Resizes the outer vector to 'n' rows, each containing an inner vector of 'n' zeros, forming an n x n 2D matrix initialized to 0

        }
    
        // Add an edge between two vertices (undirected)
        void addEdge(int orig, int dest) {
            if (orig < 1 || dest < 1 || orig > n || dest > n) {
                cout << "Invalid edge: (" << orig << ", " << dest << ")\n";
            } else {
                matrix[orig - 1][dest - 1] = 1; // Adjust for 0-based indexing
                matrix[dest - 1][orig - 1] = 1; // Adjust for 0-based indexing and add the reverse edge for undirected graph
            }
        }

        // Remove an edge between two vertices (undirected)
        void removeEdge(int orig, int dest) {
            if (orig < 1 || dest < 1 || orig > n || dest > n) {
                cout << "Invalid edge removal: (" << orig << ", " << dest << ")\n";
            } else {
                matrix[orig - 1][dest - 1] = 0; // Adjust for 0-based indexing
                matrix[dest - 1][orig - 1] = 0; // Adjust for 0-based indexing and add the reverse edge for undirected graph
            }
        }

    
        // Display the adjacency matrix
        void display() const {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << matrix[i][j] << "  ";
                }
                cout << endl;
            }
        }
    };

int main() {
    AdjacencyMatrix G(4);  // Create a graph with 4 vertices

    // Add undirected edges to form a small connected graph
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 4);
    G.addEdge(3, 4);

    cout << "\nInitial Graph Structure:\n";
    G.display();

    /*
        Initial Graph:

        (1) --- (2)
         |       |
         |       |
        (3) --- (4)

        This is a typical example of a sparse, undirected graph.

        Matrix before edge removal:

            1 2 3 4
        1 [ 0 1 1 0 ]
        2 [ 1 0 0 1 ]
        3 [ 1 0 0 1 ]
        4 [ 0 1 1 0 ]
    */

    // Remove the edge between 1 and 3
    G.removeEdge(1, 3);

    cout << "\nAfter Removing Edge (1, 3):\n";
    G.display();

    /*
        After Removing Edge (1,3):

           (1) --- (2)
                    |
                    |
           (3) --- (4)

            1 2 3 4
        1 [ 0 1 0 0 ]
        2 [ 1 0 0 1 ]
        3 [ 0 0 0 1 ]
        4 [ 0 1 1 0 ]
    */

    return 0;
}
