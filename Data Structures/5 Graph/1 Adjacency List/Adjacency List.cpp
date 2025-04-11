#include <iostream>
#include <vector>

using namespace std;

/*
    Adjacency List Representation of a Graph

    A graph is a non-linear data structure used to model relationships between objects. It consists of vertices (nodes) connected by edges (links), which can be either directed or undirected.

    Representation:
        - Adjacency List: A collection of lists where each vertex stores its adjacent vertices. More memory-efficient for sparse graphs.

            Example Graph:
            
                (1) --- (2)
                 |       |
                 |       |
                (3) --- (4)

            Adjacency List:

                1 → 2 → 3  
                2 → 1 → 4  
                3 → 1 → 4  
                4 → 2 → 3  

    Basic operations and Complexity:
        - Add Edge: O(1) — Connects two vertices with an edge.
        - Remove Edge: O(n) — Removes an existing edge (requires searching the adjacency list).
        - Initialize: O(n) — Creates an empty list for each vertex.
        - Display: O(n + e) — Prints the adjacency list representation.

    Advantages:
        - Space-efficient for sparse graphs, requiring only O(n + e) memory.
        - Faster edge insertion and deletion compared to an adjacency matrix.
        - Supports efficient traversal algorithms like BFS and DFS.

    Cons:
        - Edge lookups take O(n) time in the worst case.
        - Not as cache-friendly as an adjacency matrix due to scattered memory allocation.
        - Slightly more complex implementation compared to the adjacency matrix.

    Implementation:
        - The `AdjacencyList` class manages the graph, allowing edge insertion, removal, and display of connections.
*/

class AdjacencyList {
    private:
        int n;  // Number of vertices
        vector<vector<int>> adjList; // Each index in adjList represents a vertex and stores a list of its neighbors

    public:
        // Constructor: Initializes the graph with 'n' vertices and empty adjacency lists
        AdjacencyList(int n) {
            this->n = n;
            adjList.resize(n); // Prepares an empty list for each vertex (1-indexed logically)
        }

        // Adds an undirected edge between two vertices
        void addEdge(int orig, int dest) {
            // Prevents adding edges with invalid vertex indices
            if (orig < 1 || dest < 1 || orig > n || dest > n) {
                cout << "Invalid edge: (" << orig << ", " << dest << ")\n";
            } else {
                // Since it's undirected, both vertices point to each other
                adjList[orig - 1].push_back(dest);
                adjList[dest - 1].push_back(orig); 
            }
        }

        // Removes an undirected edge by deleting entries from both adjacency lists
        void removeEdge(int orig, int dest) {
            if (orig < 1 || dest < 1 || orig > n || dest > n) {
                cout << "Invalid edge removal: (" << orig << ", " << dest << ")\n";
                return;
            }

            // Access both adjacency lists (for each direction of the undirected edge)
            // Note: `auto&` automatically deduces the type as `vector<int>&`.
            // Without `auto`, you'd write: `vector<int>& list1 = adjList[orig - 1];`
            auto& list1 = adjList[orig - 1];
            auto& list2 = adjList[dest - 1];

            // Remove 'dest' from orig's list (search and erase pattern)
            for (auto it = list1.begin(); it != list1.end();) {
                // If current value matches the one to remove
                if (*it == dest) {
                    // Erase returns an iterator to the next valid element after deletion
                    it = list1.erase(it);
                } else {
                    ++it;
                }
            }

            // Remove 'orig' from dest's list
            for (auto it = list2.begin(); it != list2.end();) {
                if (*it == orig) {
                    it = list2.erase(it);
                } else {
                    ++it;
                }
            }

            // Note: Worst-case O(n) time for edge removal in each list
        }

        // Displays the adjacency list of each vertex
        void display() const {
            for (int i = 0; i < n; i++) {
                cout << i + 1 << " -> ";  // Vertex number
                for (size_t j = 0; j < adjList[i].size(); j++) {
                    cout << adjList[i][j];
                    if (j < adjList[i].size() - 1) {
                        cout << " -> ";
                    }
                }
                cout << endl;
            }
        }
        
};

int main() {
    AdjacencyList G(4);  // Create a graph with 4 vertices

    // Add undirected edges to form a small connected graph
    G.addEdge(1, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 4);
    G.addEdge(3, 4);

    // Display the graph structure as an adjacency list
    cout << "\nGraph Structure:\n";
    G.display();

    /*
        Initial Graph:

           (1) --- (2)
            |       |
            |       |
           (3) --- (4)

        This is a typical example of a sparse, undirected graph.

        Adjacency List:

        1 → 2 → 3  
        2 → 1 → 4  
        3 → 1 → 4  
        4 → 2 → 3  
    */

    // Removes the link between vertices 1 and 3
    G.removeEdge(1, 3);

    /*
        After Removing Edge (1,3):

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

    // Display final graph structure as adjacency list
    cout << "\nGraph Structure:\n";
    G.display();

    return 0;
}
