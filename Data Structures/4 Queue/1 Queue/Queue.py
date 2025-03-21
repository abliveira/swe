"""
    This program demonstrates the implementation of a queue using a list.

    The queue follows the FIFO (First In, First Out) principle, where elements are added at the rear 
    and removed from the front. This implementation provides basic queue operations like enqueue and dequeue.

    Primary operations:
    - Enqueue: Add an element to the rear of the queue.
    - Dequeue: Remove an element from the front of the queue.
    - Print: Display the contents of the queue.

    Note:
    - This version uses a list to implement the queue, which is a simple and intuitive approach but may not be the most efficient for larger queues due to the O(n) time complexity of the `pop(0)` operation.
    - Python provides built-in `queue` and `collections.deque` for more optimized and specialized queue implementations.
"""


class Queue:
    def __init__(self):
        self.items = []  # Initialize an empty list for the queue

    def is_empty(self):
        return len(self.items) == 0  # Check if the queue is empty

    def enqueue(self, item):
        self.items.append(item)  # Add item to the rear of the queue

    def dequeue(self):
        if self.is_empty():
            print("Queue is empty, cannot dequeue!")
            return None
        return self.items.pop(0)  # Remove and return the front item

    def print_queue(self):
        if self.is_empty():
            print("Queue is empty!")
        else:
            print(" -> ".join(map(str, self.items)))

# Example usage
q = Queue()

# Enqueue elements
q.enqueue('a')
q.enqueue('b')
q.enqueue('42')

print("Queue contents after enqueues:")
q.print_queue()

# Dequeue an element
q.dequeue()
print("Queue contents after dequeue:")
q.print_queue()
