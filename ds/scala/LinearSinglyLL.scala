// Node class for the linked list (using case class for immutability benefits)
case class Node[T](var data: T, var next: Option[Node[T]] = None)

// LinkedList class to manage the list operations
class LinkedList[T] {
  var head: Option[Node[T]] = None

  // Function to insert a node at the end of the list
  def append(data: T): Unit = {
    val newNode = Some(Node(data))
    head match {
      case None => head = newNode
      case Some(node) =>
        var current = node
        while (current.next.isDefined) {
          current = current.next.get
        }
        current.next = newNode
    }
  }

  // Function to insert a node at the beginning of the list
  def prepend(data: T): Unit = {
    val newNode = Node(data)
    newNode.next = head
    head = Some(newNode)
  }

  // Function to delete a node with a specific value
  def remove(data: T): Unit = {
    head match {
        case None => println("List is empty.")
        case Some(node) if node.data == data => head = node.next
        case Some(node) =>
            var current = node
            while(current.next.isDefined && current.next.get.data != data) {
                current = current.next.get
            }
            if (current.next.isEmpty) {
                println("Element not found.")
            } else {
                current.next = current.next.get.next
            }
    }
  }

  // Function to display the linked list
  def display(): Unit = {
    var current = head
    while (current.isDefined) {
      print(s"${current.get.data} -> ")
      current = current.get.next
    }
    println("None")
  }
}
