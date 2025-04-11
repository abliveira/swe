import java.util.Arrays;

/*
 * Adjacency Matrix Representation of an Undirected Graph.
 *
 * Key differences from C++ version:
 * - Uses a 2D array for the adjacency matrix representation, where matrix[i][j] represents an edge between vertices i and j.
 * - No dynamic resizing needed, as the matrix is initialized once with fixed size.
 * - Edge removal and addition are direct assignments to matrix entries (O(1) time).
 * - Matrix values are initially set to 0, indicating no edges, and updated to 1 for edges.
 *
 * Efficient for dense graphs: O(1) add, O(1) remove, O(n²) display.
 */

class AdjacencyMatrix {

    private int n;          // Number of vertices
    private int[][] matrix;    // 2D array for adjacency matrix

    // Constructor: Initializes an n x n matrix with all elements set to 0
    public AdjacencyMatrix(int n) {
        this.n = n;
        matrix = new int[n][n]; // Initialize matrix with 0s
    }

    // Add an edge between two vertices (undirected)
    public void addEdge(int orig, int dest) {
        if (orig < 1 || dest < 1 || orig > n || dest > n) {
            System.out.println("Invalid edge: (" + orig + ", " + dest + ")");
        } else {
            matrix[orig - 1][dest - 1] = 1; // Adjust for 0-based indexing
            matrix[dest - 1][orig - 1] = 1; // Adjust for 0-based indexing and add the reverse edge for undirected graph
        }
    }

    // Remove an edge between two vertices (undirected)
    public void removeEdge(int orig, int dest) {
        if (orig < 1 || dest < 1 || orig > n || dest > n) {
            System.out.println("Invalid edge removal: (" + orig + ", " + dest + ")");
        } else {
            matrix[orig - 1][dest - 1] = 0; // Adjust for 0-based indexing
            matrix[dest - 1][orig - 1] = 0; // Adjust for 0-based indexing and add the reverse edge for undirected graph
        }
    }

    // Display the adjacency matrix
    public void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + "  ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        AdjacencyMatrix G = new AdjacencyMatrix(4);  // Create a graph with 4 vertices

        // Add undirected edges to form a small connected graph
        G.addEdge(1, 2);
        G.addEdge(1, 3);
        G.addEdge(2, 4);
        G.addEdge(3, 4);

        System.out.println("\nInitial Graph Structure:");
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

        System.out.println("\nAfter Removing Edge (1, 3):");
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
    }
}
