# Introduction:
# This program demonstrates the implementation and operations of a singly linked list in Python. 
# The linked list supports the following operations:
# - Add a node at the front of the list.
# - Add a node at the end of the list.
# - Check if the list is empty.
# - Search for a node by its value.
# - Delete a specific node by its value.
# - Delete the last node in the list.
# - Count the total number of nodes in the list.
# - Print all nodes in the list.
#
# Each function showcases a different aspect of linked list manipulation, highlighting its 
# dynamic nature and advantages over arrays for certain operations, such as insertion and deletion.
#
# The main function demonstrates the usage of these operations, including:
# - Initial checks for an empty list.
# - Adding nodes at both the front and end.
# - Searching for and deleting nodes by value.
# - Deleting the last node in the list.
# - Counting and printing nodes before and after operations.

class Node:
    """Class representing a single node in the linked list."""
    def __init__(self, data):
        self.data = data  # Data stored in the node
        self.next = None  # Pointer to the next node

class LinkedList:
    """Class representing a singly linked list."""
    def __init__(self):
        self.head = None  # Initialize the list as empty

    def is_empty(self):
        """Check if the list is empty."""
        return self.head is None

    def add_at_front(self, node):
        """Add a node at the front of the list."""
        node.next = self.head
        self.head = node

    def add_at_end(self, node):
        """Add a node at the end of the list."""
        if self.is_empty():
            self.head = node
            return
        last = self.get_last_node()
        last.next = node

    def get_last_node(self):
        """Retrieve the last node in the list."""
        current = self.head
        while current and current.next:
            current = current.next
        return current

    def search(self, value):
        """Search for a node by its value."""
        current = self.head
        while current:
            if current.data == value:
                return current
            current = current.next
        return None

    def delete_node(self, value):
        """Delete a node by its value."""
        if self.is_empty():
            return None

        current = self.head
        prev = None

        # If the node to delete is the head
        if current.data == value:
            self.head = current.next
            return current

        # Traverse to find the node to delete
        while current and current.data != value:
            prev = current
            current = current.next

        # If the node is found, bypass it in the list
        if current:
            prev.next = current.next
        return current

    def delete_from_end(self):
        """Delete the last node in the list."""
        if self.is_empty():
            return None

        current = self.head
        prev = None

        # If there's only one node
        if not current.next:
            self.head = None
            return current

        # Traverse to the second last node
        while current.next:
            prev = current
            current = current.next

        # Remove the last node
        prev.next = None
        return current

    def count_nodes(self):
        """Count the total number of nodes in the list."""
        count = 0
        current = self.head
        while current:
            count += 1
            current = current.next
        return count

    def print_list(self):
        """Print all nodes in the list."""
        if self.is_empty():
            print("List is empty!")
            return
        current = self.head
        while current:
            print(f"{current.data} -> ", end="")
            current = current.next
        print("NULL")  # Indicate the end of the list

# Main function to demonstrate usage of the linked list
if __name__ == "__main__":
    L = LinkedList()

    # Check if the list is initially empty
    if L.is_empty():
        print("The list is empty.")

    # Create some nodes
    n1 = Node(5)
    n2 = Node(8)
    n3 = Node(12)

    # Add nodes to the list
    L.add_at_front(n1)  # Add 5 at the front
    L.add_at_front(n2)  # Add 8 at the front
    L.add_at_end(n3)    # Add 12 at the end

    # Check again if the list is empty
    if not L.is_empty():
        print("The list is not empty.")

    # Print the list
    print("Current List: ", end="")
    L.print_list()

    # Count the nodes in the list
    print(f"Total nodes: {L.count_nodes()}")

    # Delete a node by value
    deleted = L.delete_node(8)
    if deleted:
        print(f"Deleted node with value: {deleted.data}")

    # Print the list after deletion
    print("List after deleting 8: ", end="")
    L.print_list()

    # Delete the last node
    deleted = L.delete_from_end()
    if deleted:
        print(f"Deleted last node with value: {deleted.data}")

    # Print the list after deleting the last node
    print("List after deleting the last node: ", end="")
    L.print_list()
