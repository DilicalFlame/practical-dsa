// Node class for the linked list
class Node {
    int data;
    Node next;

    // Constructor to create a new node
    Node(int d) {
        data = d;
        next = null;
    }
}

// LinkedList class to manage the list operations
public class LinearSinglyLL {
    Node head; // Head of the list

    // Function to insert a node at the end of the list
    public void append(int data) {
        Node newNode = new Node(data);

        // If the Linked List is empty, then make the new node as head
        if (head == null) {
            head = newNode;
            return;
        }

        // Else traverse till the last node and insert the newNode there
        Node last = head;
        while (last.next != null) {
            last = last.next;
        }

        // Insert the newNode at last node
        last.next = newNode;
    }

    // Function to insert a node at the beginning of the list
    public void prepend(int data) {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Function to delete a node with a specific value
    public void remove(int key) {
        // Store head node
        Node temp = head, prev = null;

        // If head node itself holds the key to be deleted
        if (temp != null && temp.data == key) {
            head = temp.next; // Changed head
            return;
        }

        // Search for the key to be deleted, keep track of the
        // previous node as we need to change temp.next
        while (temp != null && temp.data != key) {
            prev = temp;
            temp = temp.next;
        }

        // If key was not present in linked list
        if (temp == null) {
            System.out.println("Element not found.");
            return;
        }

        // Unlink the node from linked list
        prev.next = temp.next;
    }

    // Function to display the linked list
    public void display() {
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.println("null");
    }
}
