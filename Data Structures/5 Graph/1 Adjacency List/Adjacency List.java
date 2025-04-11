import java.util.ArrayList;
import java.util.List;

/*
 * Adjacency List Representation of an Undirected Graph.
 *
 * Key differences from C++ version:
 * - Uses `ArrayList` for dynamic and safe resizing of vertex lists.
 * - Edge removal uses `removeIf()` for cleaner logic.
 * - Vertex validation is factored into a helper for clarity.
 * - Adjacency lists are pre-initialized—no risk of null access.
 *
 * Efficient for sparse graphs: O(1) add, O(n) remove, O(n + e) display.
 */


 class AdjacencyList {
    private final int numVertices;                    // Total number of vertices
    private final List<List<Integer>> adjList;        // Adjacency list: vertex → list of neighbors

    /**
     * Constructs an empty graph with a given number of vertices.
     *
     * @param numVertices the number of vertices in the graph (1-based indexing assumed).
     */
    public AdjacencyList(int numVertices) {
        this.numVertices = numVertices;
        adjList = new ArrayList<>(numVertices);

        // Initialize an empty list for each vertex
        for (int i = 0; i < numVertices; i++) {
            adjList.add(new ArrayList<>());
        }
    }

    /**
     * Adds an undirected edge between two vertices.
     *
     * @param from the source vertex (1-based).
     * @param to   the destination vertex (1-based).
     */
    public void addEdge(int from, int to) {
        if (!isValidVertex(from) || !isValidVertex(to)) {
            System.out.printf("Invalid edge: (%d, %d)%n", from, to);
            return;
        }

        adjList.get(from - 1).add(to);
        adjList.get(to - 1).add(from);
    }

    /**
     * Removes an undirected edge between two vertices, if it exists.
     *
     * @param from the source vertex (1-based).
     * @param to   the destination vertex (1-based).
     */
    public void removeEdge(int from, int to) {
        if (!isValidVertex(from) || !isValidVertex(to)) {
            System.out.printf("Invalid edge removal: (%d, %d)%n", from, to);
            return;
        }

        adjList.get(from - 1).removeIf(v -> v == to);
        adjList.get(to - 1).removeIf(v -> v == from);
    }

    /**
     * Displays the graph's adjacency list in a readable format.
     */
    public void display() {
        for (int i = 0; i < numVertices; i++) {
            System.out.print((i + 1) + " -> ");
            List<Integer> neighbors = adjList.get(i);
            for (int j = 0; j < neighbors.size(); j++) {
                System.out.print(neighbors.get(j));
                if (j < neighbors.size() - 1) {
                    System.out.print(" -> ");
                }
            }
            System.out.println();
        }
    }

    /**
     * Checks if a vertex index is valid (1-based).
     */
    private boolean isValidVertex(int v) {
        return v >= 1 && v <= numVertices;
    }

    /**
     * Simple test for the graph.
     */
    public static void main(String[] args) {
        AdjacencyList graph = new AdjacencyList(4);

        // Add undirected edges
        graph.addEdge(1, 2);
        graph.addEdge(1, 3);
        graph.addEdge(2, 4);
        graph.addEdge(3, 4);

        System.out.println("\nInitial Graph Structure:");
        graph.display();

        /*
            Graph layout before removal:

               (1) --- (2)
                |       |
                |       |
               (3) --- (4)

            Adjacency List:
            1 → 2 → 3  
            2 → 1 → 4  
            3 → 1 → 4  
            4 → 2 → 3  
         */

        // Remove edge between vertex 1 and 3
        graph.removeEdge(1, 3);

        System.out.println("\nAfter Removing Edge (1, 3):");
        graph.display();

        /*
            Graph layout after removal:

               (1) --- (2)
                        |
                        |
               (3) --- (4)

            Adjacency List:
            1 → 2  
            2 → 1 → 4  
            3 → 4  
            4 → 2 → 3  
         */
    }
}
