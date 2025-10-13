// Using Option<Box<Node>> for ownership and nullable pointers.
type Link<T> = Option<Box<Node<T>>>;

// Generic Node struct
struct Node<T> {
    elem: T,
    next: Link<T>,
}

// Generic LinkedList struct
pub struct LinkedList<T> {
    head: Link<T>,
}

impl<T: std::cmp::PartialEq + std::fmt::Display> LinkedList<T> {
    pub fn new() -> Self {
        LinkedList { head: None }
    }

    // Insert at the beginning
    pub fn prepend(&mut self, elem: T) {
        let new_node = Box::new(Node {
            elem: elem,
            next: self.head.take(),
        });
        self.head = Some(new_node);
    }

    // Insert at the end
    pub fn append(&mut self, elem: T) {
        let new_node = Box::new(Node { elem, next: None });
        let mut current = &mut self.head;
        while let Some(node) = current {
            current = &mut node.next;
        }
        *current = Some(new_node);
    }

    // Remove a node
    pub fn remove(&mut self, elem: T) {
        let mut current = &mut self.head;
        loop {
            match current {
                None => {
                    println!("Element not found.");
                    break;
                }
                Some(node) if node.elem == elem => {
                    *current = node.next.take();
                    break;
                }
                Some(node) => {
                    current = &mut node.next;
                }
            }
        }
    }

    // Display the list
    pub fn display(&self) {
        let mut current = &self.head;
        while let Some(node) = current {
            print!("{} -> ", node.elem);
            current = &node.next;
        }
        println!("None");
    }
}

// Implement Drop trait to clean up memory
impl<T> Drop for LinkedList<T> {
    fn drop(&mut self) {
        let mut cur_link = self.head.take();
        while let Some(mut boxed_node) = cur_link {
            cur_link = boxed_node.next.take();
        }
    }
}
