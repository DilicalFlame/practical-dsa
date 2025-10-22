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

// Main program to demonstrate the linked list operations
class Program
{
    static void Main(string[] args)
    {
        LinkedList list = new LinkedList();

        Console.WriteLine("=== Linear Singly Linked List Demo ===\n");

        // Test append
        Console.WriteLine("Appending elements: 10, 20, 30");
        list.Append(10);
        list.Append(20);
        list.Append(30);
        Console.Write("List: ");
        list.Display();

        // Test prepend
        Console.WriteLine("\nPrepending element: 5");
        list.Prepend(5);
        Console.Write("List: ");
        list.Display();

        // Test remove
        Console.WriteLine("\nRemoving element: 20");
        list.Remove(20);
        Console.Write("List: ");
        list.Display();

        // Test removing non-existent element
        Console.WriteLine("\nTrying to remove non-existent element: 100");
        list.Remove(100);
        Console.Write("List: ");
        list.Display();

        Console.WriteLine("\nDone!");
    }
}
