# Node class for the linked list
class Node
  attr_accessor :data, :next_node

  def initialize(data, next_node = nil)
    @data = data
    @next_node = next_node
  end
end

# LinkedList class to manage the list operations
class LinkedList
  def initialize
    @head = nil
  end

  # Function to insert a node at the end of the list
  def append(data)
    if @head.nil?
      @head = Node.new(data)
    else
      current = @head
      current = current.next_node until current.next_node.nil?
      current.next_node = Node.new(data)
    end
  end

  # Function to insert a node at the beginning of the list
  def prepend(data)
    @head = Node.new(data, @head)
  end

  # Function to delete a node with a specific value
  def remove(data)
    if @head.nil?
      return
    end

    if @head.data == data
      @head = @head.next_node
      return
    end

    current = @head
    while current.next_node && current.next_node.data != data
        current = current.next_node
    end
    
    if current.next_node.nil?
        puts "Element not found."
        return
    end

    current.next_node = current.next_node.next_node
  end

  # Function to display the linked list
  def display
    current = @head
    elements = []
    while current
      elements << current.data
      current = current.next_node
    end
    puts elements.join(' -> ') + ' -> nil'
  end
end
