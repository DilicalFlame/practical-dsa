#include <iostream>

// Node structure for the linked list
struct Node
{
    int data;
    Node *next;

    // Constructor to initialize a node
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class to manage the list operations
class LinkedList
{
private:
    Node *head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor to free memory
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    // Function to insert a node at the end of the list
    void append(int data)
    {
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *last = head;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
    }

    // Function to insert a node at the beginning of the list
    void prepend(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to delete a node with a specific value
    void remove(int data)
    {
        if (head == nullptr)
            return;

        // If the head node itself holds the key
        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *current = head;
        while (current->next != nullptr && current->next->data != data)
        {
            current = current->next;
        }

        if (current->next == nullptr)
        {
            std::cout << "Element not found." << std::endl;
            return;
        }

        Node *temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Function to display the linked list
    void display()
    {
        Node *current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};
