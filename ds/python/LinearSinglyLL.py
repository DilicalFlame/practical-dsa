# Node class for the linked list
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# LinkedList class to manage the list operations
class LinkedList:
    def __init__(self):
        self.head = None

    # Function to insert a node at the end of the list
    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node

    # Function to insert a node at the beginning of the list
    def prepend(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    # Function to delete a node with a specific value
    def remove(self, data):
        if not self.head:
            return

        # If the head node itself holds the key
        if self.head.data == data:
            self.head = self.head.next
            return

        current_node = self.head
        while current_node.next and current_node.next.data != data:
            current_node = current_node.next
        
        if current_node.next is None:
            print("Element not found.")
            return

        current_node.next = current_node.next.next
    
    # Function to display the linked list
    def display(self):
        elements = []
        current_node = self.head
        while current_node:
            elements.append(str(current_node.data))
            current_node = current_node.next
        print(" -> ".join(elements) + " -> None")

# Main part to demonstrate LinkedList functionality
if __name__ == "__main__":
    llist = LinkedList()
    llist.append(10)
    llist.append(20)
    llist.append(30)
    print("List after appending 10, 20, 30:")
    llist.display()

    llist.prepend(5)
    print("List after prepending 5:")
    llist.display()
    
    llist.remove(20)
    print("List after removing 20:")
    llist.display()

    llist.remove(5)
    print("List after removing 5:")
    llist.display()

    llist.remove(40) # Element not in the list
