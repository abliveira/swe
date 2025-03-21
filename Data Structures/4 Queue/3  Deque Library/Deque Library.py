from collections import deque

"""
    Demonstrates the usage of `collections.deque` as a queue in Python.

    - While `deque` can be used for strict FIFO (First In, First Out) behavior, it also allows for flexible double-ended operations.
    - `deque` supports **both** FIFO and reverse (LIFO: Last In, First Out) operations efficiently, with O(1) time complexity for operations at both ends, unlike the `queue.Queue` library.

    Basic Operations:
    - **Append**: `append(item)` - Adds an element to the rear of the queue (FIFO).
    - **Popleft**: `popleft()` - Removes and returns the front element of the queue (FIFO).
    - **Appendleft**: `appendleft(item)` - Adds an element to the front of the queue (used for reverse or LIFO operations).
    - **Pop**: `pop()` - Removes and returns the last element of the queue (LIFO).
    - **Peek**: `queue[0]` - Peeks at the front element of the queue (FIFO).
    - **Back Peek**: `queue[-1]` - Peeks at the back element of the queue (LIFO).
"""


# Create a queue using deque
queue = deque()

# ----- Strict FIFO Queue Operations -----

queue.append("a")   # Enqueue (add to rear)
queue.append("b")
queue.append("42")

print("Queue after enqueues:", list(queue))  # ['a', 'b', '42']

print("Front Peek:", queue[0])  # Peek front (equivalent to front())

queue.popleft()  # Dequeue (remove from front)
print("Queue after dequeue:", list(queue))  # ['b', '42']

# ----- Reverse Operations -----

queue.appendleft("X")  # Enqueue at front
print("Queue after enqueue_front:", list(queue))  # ['X', 'b', '42']

print("Back Peek:", queue[-1])  # Peek back (equivalent to back())

queue.pop()  # Dequeue from back
print("Queue after dequeue_back:", list(queue))  # ['X', 'b']
