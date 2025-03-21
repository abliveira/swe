import queue

"""
    Demonstrates the usage of the `queue.Queue` class in Python.

    - Follows the FIFO (First In, First Out) principle, optimized for thread-safe queue operations.
    - Provides essential operations: put (enqueue), get (dequeue), empty, and size.
    - Uses `queue.Queue` to ensure safe data exchange in multithreaded applications.

    Thread Safety:
    - `queue.Queue` is designed with thread-safety in mind. It uses locking mechanisms to prevent data corruption in concurrent environments.
    - `queue.Queue` provides methods like `put()`, `get()`, and `qsize()` for interaction in a thread-safe manner, but lacks the flexibility of operations at both ends like `deque` does.

    Basic Operations:
    - **Put**: `put(item)` - Adds an element to the rear of the queue (FIFO).
    - **Get**: `get()` - Removes and returns the front element of the queue (FIFO).
    - **Empty**: `empty()` - Returns `True` if the queue is empty.
    - **Size**: `qsize()` - Returns the approximate size of the queue.
    - **Peek**: `queue.queue[0]` (Not directly supported, but can be accessed if needed).
"""

# Create a thread-safe queue using queue.Queue
q = queue.Queue()

# Enqueue elements
q.put('a')
q.put('b')
q.put('42')

print("Queue after enqueues:")
print(list(q.queue))  # Display the queue contents

# Dequeue an element
q.get()
print("Queue after dequeue:")
print(list(q.queue))  # Display the queue contents

# Check if the queue is empty
print("Is the queue empty?", q.empty())
