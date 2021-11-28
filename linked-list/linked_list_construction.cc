
/*
 * Program to construct a doubly linked list
 */
using namespace std;

class Node {
public:
  int value;
  Node *prev;
  Node *next;

  Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
  Node *head;
  Node *tail;

  DoublyLinkedList() {
    head = nullptr;
    tail = nullptr;
  }

    // O(1) time | O(1) space
  void setHead(Node *node) {
        if (head == nullptr) {
            head = tail = node;
        } else {
            insertBefore(head, node);
        }
  }

    // O(1) time | O(1) space
  void setTail(Node *node) {
        if (tail == nullptr) {
            head = tail = node;
        } else {
            insertAfter(tail, node);
        }
  }

    // O(1) time | O(1) space
  void insertBefore(Node *node, Node *nodeToInsert) {
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->prev = node->prev;
        nodeToInsert->next = node;
        // deal with head
        if (node->prev == nullptr)
            head = nodeToInsert;
        else
            node->prev->next = nodeToInsert;
        node->prev = nodeToInsert;
  }

    // O(1) time | O(1) space
  void insertAfter(Node *node, Node *nodeToInsert) {
        if (nodeToInsert == head && nodeToInsert == tail)
            return;
        remove(nodeToInsert);
        nodeToInsert->next = node->next;
        nodeToInsert->prev = node;
        // deal with tail
        if (node->next == nullptr)
            tail = nodeToInsert;
        else
            node->next->prev = nodeToInsert;
        node->next = nodeToInsert;
  }

    // O(p) time | O(1) space
  void insertAtPosition(int position, Node *nodeToInsert) {
        if (position == 1) {
            setHead(nodeToInsert);
            return;
        }
        Node *node = head;
        int currPos = 1;
        while (node != nullptr && currPos != position) {
            node = node->next;
            currPos++;
        }
        if (node != nullptr) {
            insertBefore(node, nodeToInsert);
        } else {
            // reached end of linked list
            setTail(nodeToInsert);
        }
  }

    // O(n) time | O(1) space
  void removeNodesWithValue(int value) {
        Node *node = head;
        while (node != nullptr) {
            Node *to_remove = node;
            node = node->next;
            if (to_remove->value == value)
                remove(to_remove);
        }
  }

    // Remove the node's prev and next pointers and adjust surrounding nodes
    void removeNodeBindings(Node *node) {
        if (node->prev != nullptr) {
            node->prev->next = node->next;
        }
        if (node->next != nullptr) {
            node->next->prev = node->prev;
        }
        node->prev = nullptr;
        node->next = nullptr;
  }
    
    // O(1) time | O(1) space
  void remove(Node *node) {
        if (node == head) {
            head = head->next;
        }
        if (node == tail) {
            tail = tail->prev;
        }
        removeNodeBindings(node);
  }

    // O(n) time | O(1) space
  bool containsNodeWithValue(int value) {
        Node *node = head;
        while (node != nullptr && node->value != value) {
            node = node->next;
        }
    return node != nullptr;
  }
};


