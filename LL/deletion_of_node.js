class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

class LinkedList {
  constructor() {
    this.head = null;
  }

  // Method to insert at the end
  insertAtEnd(data) {
    const newNode = new Node(data);

    // If the list is empty, make the new node the head
    if (this.head === null) {
      this.head = newNode;
      return;
    }

    // Traverse to the last node
    let current = this.head;
    while (current.next !== null) {
      current = current.next;
    }

    // Attach the new node at the end
    current.next = newNode;
  }

  // Method to print the linked list (for verification)
  printList() {
    let current = this.head;
    let list = "";
    while (current !== null) {
      list += current.data + " -> ";
      current = current.next;
    }
    console.log(list + "null");
  }
}

// Example usage
const ll = new LinkedList();
ll.insertAtEnd(10);
ll.insertAtEnd(20);
ll.insertAtEnd(30);
ll.printList(); // Output: 10 -> 20 -> 30 -> null
