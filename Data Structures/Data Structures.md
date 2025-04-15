# Data Structures Comparison

Data structures are essential for organizing, storing, and managing data efficiently. The choice of the appropriate data structure depends on the problem at hand and its requirements in terms of time and space complexity.

### Explanations of Categories:
- **Linear**: Data structures where elements are arranged sequentially.
- **Tree-based**: Hierarchical data structures where elements are arranged in a tree structure. Many tree-based structures are inherently recursive, meaning each subtree is itself a smaller instance of the tree
- **Associative**: Data structures that store key-value pairs, allowing efficient lookups based on keys.
- **Network**: Used to model networks, relationships, or graphs.
- **Array-based**: A fixed or dynamic structure for storing data in a matrix or grid format.
- **Buffer**: Specialized data structures that manage memory buffers, often used in text editing.


## Comparison Table

| **Data Structure**       | **Category**            | **Use Case**                                      | **Time Complexity**                           | **Space Complexity**               | **Advantages**                                             | **Disadvantages**                                        |
|--------------------------|-------------------------|---------------------------------------------------|----------------------------------------------|------------------------------------|------------------------------------------------------------|----------------------------------------------------------|
| **Array**                | **Linear**              | Fixed-size, ordered collections of data           | **Access**: O(1), **Insert/Delete**: O(n)    | O(n)                               | Fast access by index, simple structure                    | Fixed size, inefficient insert/delete at the middle       |
| **Linked List**          | **Linear**              | Dynamic collections where insertions/deletions are frequent | **Access**: O(n), **Insert/Delete**: O(1)    | O(n)                               | Dynamic size, efficient insertions/deletions               | Slow access by index, uses more memory per element       |
| **Stack**                | **Linear**              | Last-in, first-out (LIFO) operations              | **Push/Pop**: O(1), **Access**: O(n)         | O(n)                               | Simple to implement, efficient for recursion/undo actions  | Limited to LIFO, slow access to non-top elements         |
| **Queue**                | **Linear**              | First-in, first-out (FIFO) operations             | **Enqueue/Dequeue**: O(1), **Access**: O(n)   | O(n)                               | Simple to implement, efficient for scheduling tasks       | Limited to FIFO, slow access to non-front elements       |
| **Hash Table**           | **Associative**         | Fast key-value pair storage                      | **Insert/Lookup/Delete**: O(1) on average, O(n) worst case | O(n)                               | Fast access, supports dynamic key-value associations      | Collisions, not ideal for ordered data                   |
| **Heap**                 | **Tree-based**          | Priority queues, sorting                         | **Insert**: O(log n), **Extract-Min/Max**: O(log n) | O(n)                               | Efficient for priority-based problems, supports heap sort | Not efficient for search or ordered access               |
| **Binary Tree**          | **Tree-based**          | Hierarchical data storage                        | **Insert/Search/Delete**: O(log n) in balanced, O(n) in unbalanced | O(n)                               | Hierarchical structure, fast insertion in balanced trees  | Unbalanced trees lead to poor performance                |
| **Binary Search Tree (BST)** | **Tree-based**          | Efficient searching, sorting                     | **Insert/Search/Delete**: O(log n) in balanced, O(n) in unbalanced | O(n)                               | Efficient search and sorted traversal in balanced trees    | Can become unbalanced, leading to poor performance       |
| **Red-Black Tree**       | **Tree-based**          | Self-balancing binary search tree                 | **Insert/Search/Delete**: O(log n)            | O(n)                               | Balances automatically, maintains good worst-case performance | Slightly slower than AVL trees due to balancing method   |
| **AVL Tree**             | **Tree-based**          | Self-balancing binary search tree                 | **Insert/Search/Delete**: O(log n)            | O(n)                               | Always balanced, faster lookups than Red-Black trees       | More complex balancing mechanism, slower insertions      |
| **Graph**                | **Network**             | Networks, relationships, paths, etc.              | **DFS/BFS**: O(V + E), **Dijkstra**: O(V^2)   | O(V + E)                           | Flexible, powerful for complex relationships              | Can be memory intensive, complex algorithms for traversal |
| **Matrix**               | **Array-based**         | 2D grid representation, graphs, image processing  | **Access**: O(1), **Insert/Delete**: O(n)     | O(n^2)                             | Efficient for operations on grids, adjacency matrices     | Space inefficient for sparse matrices                    |
| **Decision Tree**        | **Machine Learning**    | Classification, regression in machine learning    | **Build**: O(n log n), **Query**: O(log n)    | O(n)                               | Easy to interpret, handles both numeric and categorical data | Prone to overfitting, requires large amounts of data     |
| **Set**                  | **Associative**         | Unordered collection of unique elements           | **Insert/Remove/Search**: O(1) on average      | O(n)                               | Fast membership checks, no duplicates                      | No ordering, slower for large datasets with complex elements |
| **Map**                  | **Associative**         | Key-value pair collection, like a dictionary      | **Insert/Lookup/Delete**: O(log n)            | O(n)                               | Fast lookup and updates based on keys                      | Slower than hash tables for simple lookups               |
| **Hashing**              | **Associative**         | Mapping data to unique values                     | **Insert/Lookup/Delete**: O(1) on average     | O(n)                               | Very fast lookups, ideal for unique element identification | Collisions, not ideal for ordered data                   |
| **Gap Buffer**           | **Buffer**              | Efficient text editing (insertions/deletions)     | **Insert/Delete**: O(1) at the gap, O(n) otherwise | O(n)                               | Efficient for text manipulation, especially in editors     | Can become inefficient when gap is near the array end    |

# Learning List

**Popular types of Data Structures:**
- Array - OK
- Linked List - OK
- Stack - OK
- Queue - OK
- Binary Tree
- Binary Search Tree
- Heap
- Hashing
- Graph - OK
- Matrix
- Gap Buffer
- Hash Table
- AVL Tree
- Decision Tree
- Red-Black Tree
- Sets
- Maps

**Google SWE Data Structures**
- Arrays - OK
- Linked Lists - OK
- Stacks - OK
- Queues - OK
- Sets
- Maps
- Binary Trees
- Heaps
- Graphs - OK

# References

https://www.geeksforgeeks.org/data-structures/

Binary Tree

https://www.geeksforgeeks.org/introduction-to-tree-data-structure/?ref=lbp

https://www.geeksforgeeks.org/binary-tree-set-1-introduction/

