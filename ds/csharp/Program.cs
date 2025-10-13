using System;

// Node class for the linked list
public class Node
{
    public int data;
    public Node next;

    public Node(int d)
    {
        data = d;
        next = null;
    }
}

// LinkedList class to manage the list operations
public class LinkedList
{
    public Node head;

    // Function to insert a node at the end of the list
    public void Append(int data)
    {
        Node newNode = new Node(data);
        if (head == null)
        {
            head = newNode;
            return;
        }
        Node last = head;
        while (last.next != null)
        {
            last = last.next;
        }
        last.next = newNode;
    }

    // Function to insert a node at the beginning of the list
    public void Prepend(int data)
    {
        Node newNode = new Node(data);
        newNode.next = head;
        head = newNode;
    }

    // Function to delete a node with a specific value
    public void Remove(int key)
    {
        Node temp = head, prev = null;

        if (temp != null && temp.data == key)
        {
            head = temp.next;
            return;
        }

        while (temp != null && temp.data != key)
        {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null)
        {
            Console.WriteLine("Element not found.");
            return;
        }

        prev.next = temp.next;
    }

    // Function to display the linked list
    public void Display()
    {
        Node current = head;
        while (current != null)
        {
            Console.Write(current.data + " -> ");
            current = current.next;
        }
        Console.WriteLine("null");
    }
}
