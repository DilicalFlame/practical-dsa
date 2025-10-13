package main

import "fmt"

// Node represents a node in the linked list
type Node struct {
	data int
	next *Node
}

// LinkedList represents the linked list
type LinkedList struct {
	head *Node
}

// Append adds a node to the end of the list
func (ll *LinkedList) Append(data int) {
	newNode := &Node{data: data}
	if ll.head == nil {
		ll.head = newNode
		return
	}
	last := ll.head
	for last.next != nil {
		last = last.next
	}
	last.next = newNode
}

// Prepend adds a node to the beginning of the list
func (ll *LinkedList) Prepend(data int) {
	newNode := &Node{data: data}
	newNode.next = ll.head
	ll.head = newNode
}

// Remove deletes a node with a specific value
func (ll *LinkedList) Remove(data int) {
	if ll.head == nil {
		return
	}

	if ll.head.data == data {
		ll.head = ll.head.next
		return
	}

	current := ll.head
	for current.next != nil && current.next.data != data {
		current = current.next
	}

	if current.next == nil {
		fmt.Println("Element not found.")
		return
	}

	current.next = current.next.next
}

// Display prints the linked list
func (ll *LinkedList) Display() {
	current := ll.head
	for current != nil {
		fmt.Printf("%d -> ", current.data)
		current = current.next
	}
	fmt.Println("nil")
}
