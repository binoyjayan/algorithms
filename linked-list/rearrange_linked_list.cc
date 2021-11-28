
/*

Write a function that takes in a linked list and an integer k,
rearranges the list in place and returns the new head.

Rearranging the list around nodes with value k means moving
all nodes with a value smaller than k before all nodes with
value k and moving all nodes with a value greater than k
after all nodes with value k.

All moved nodes should maintain relative ordering when possible.

Sample input:
head: 3 -> 0 -> 5 -> 2 -> 1 -> 4
k = 3

sample output:

0 -> 2 -> 1 -> 3 -> 5 -> 4
*/

using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

void addTail(LinkedList **head, LinkedList **tail, LinkedList *node) {
    if (*head == nullptr) {
        *head = node;
        *tail = node;
    } else {
        LinkedList *prevTail = *tail;
        *tail = node;
        prevTail->next = node;
    }
    node->next = nullptr;
}

LinkedList *rearrangeLinkedList(LinkedList *head, int k) {
  LinkedList *ltHead = nullptr, *ltTail = nullptr;
    LinkedList *eqHead = nullptr, *gtTail = nullptr;
    LinkedList *gtHead = nullptr, *eqTail = nullptr;
    LinkedList *curr = head, *next = nullptr;

    // Add items to three linked lists depending on their value
    while (curr != nullptr) {
        next = curr->next;
        if (curr->value < k) {
            addTail(&ltHead, &ltTail, curr);
        } else if (curr->value > k) {
            addTail(&gtHead, &gtTail, curr);
        } else {
            addTail(&eqHead, &eqTail, curr);
        }
        curr = next;
    }
    
    // Join the three linked lists
    if (ltTail) {
        ltTail->next = eqHead == nullptr ? gtHead: eqHead;
    }    
    if (eqTail)
        eqTail->next = gtHead;
    
  return ltHead ? ltHead: eqHead ? eqHead: gtHead;
}


