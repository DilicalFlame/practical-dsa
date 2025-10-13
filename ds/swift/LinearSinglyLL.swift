import Foundation

// Node class for the linked list. Classes are used because they are reference types,
// which is what we need for the 'next' reference.
public class Node<T> {
    var value: T
    var next: Node<T>?

    public init(value: T) {
        self.value = value
    }
}

// LinkedList class to manage the list operations.
// The generic type T must be Equatable to allow for searching and removing elements.
public class LinkedList<T: Equatable> {
    private var head: Node<T>?

    // Computed property to check if the list is empty
    public var isEmpty: Bool {
        return head == nil
    }

    // Function to insert a node at the end of the list
    public func append(value: T) {
        let newNode = Node(value: value)
        if let lastNode = last {
            lastNode.next = newNode
        } else {
            head = newNode
        }
    }

    // Function to insert a node at the beginning of the list
    public func prepend(value: T) {
        let newNode = Node(value: value)
        newNode.next = head
        head = newNode
    }

    // Helper property to get the last node in the list
    private var last: Node<T>? {
        guard var node = head else {
            return nil
        }
        while let next = node.next {
            node = next
        }
        return node
    }

    // Function to delete a node with a specific value
    public func remove(value: T) {
        if head?.value == value {
            head = head?.next
            return
        }

        var prev: Node<T>? = nil
        var current = head

        while current != nil && current?.value != value {
            prev = current
            current = current?.next
        }

        if current == nil {
            print("Element not found.")
            return
        }

        prev?.next = current?.next
    }

    // Function to display the linked list
    public func display() {
        var current = head
        var result = ""
        while let node = current {
            result += "\(node.value) -> "
            current = node.next
        }
        print(result + "nil")
    }
}
