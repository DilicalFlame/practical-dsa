// Node class for the linked list. Dart's null safety is used here.
class Node<T> {
  T data;
  Node<T>? next;

  Node(this.data);
}

// LinkedList class to manage the list operations.
class LinkedList<T> {
  Node<T>? head;

  bool get isEmpty => head == null;

  // Function to insert a node at the end of the list.
  void append(T data) {
    final newNode = Node(data);
    if (isEmpty) {
      head = newNode;
      return;
    }
    var current = head;
    while (current?.next != null) {
      current = current?.next;
    }
    current?.next = newNode;
  }

  // Function to insert a node at the beginning of the list.
  void prepend(T data) {
    final newNode = Node(data);
    newNode.next = head;
    head = newNode;
  }

  // Function to delete a node with a specific value.
  void remove(T data) {
    if (isEmpty) return;

    if (head?.data == data) {
      head = head?.next;
      return;
    }

    var current = head;
    while (current?.next != null && current?.next?.data != data) {
      current = current?.next;
    }

    if (current?.next == null) {
      print('Element not found.');
      return;
    }

    current?.next = current.next?.next;
  }

  // Function to display the linked list.
  void display() {
    var current = head;
    final elements = <T>[];
    while (current != null) {
      elements.add(current.data);
      current = current.next;
    }
    print(elements.join(' -> ') + ' -> null');
  }
}
