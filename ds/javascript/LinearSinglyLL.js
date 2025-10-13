// Node class for the linked list
class Node {
    constructor(data) {
        this.data = data
        this.next = null
    }
}

// LinkedList class to manage the list operations
class LinkedList {
    constructor() {
        this.head = null
    }

    // Function to insert a node at the end of the list
    append(data) {
        const newNode = new Node(data)
        if (!this.head) {
            this.head = newNode
            return
        }
        let current = this.head
        while (current.next) {
            current = current.next
        }
        current.next = newNode
    }

    // Function to insert a node at the beginning of the list
    prepend(data) {
        const newNode = new Node(data)
        newNode.next = this.head
        this.head = newNode
    }

    // Function to delete a node with a specific value
    remove(data) {
        if (!this.head) {
            return
        }

        if (this.head.data === data) {
            this.head = this.head.next
            return
        }

        let current = this.head
        while (current.next && current.next.data !== data) {
            current = current.next
        }

        if (current.next === null) {
            console.log('Element not found.')
            return
        }

        current.next = current.next.next
    }

    // Function to display the linked list
    display() {
        let current = this.head
        const elements = []
        while (current) {
            elements.push(current.data)
            current = current.next
        }
        console.log(elements.join(' -> ') + ' -> null')
    }
}
