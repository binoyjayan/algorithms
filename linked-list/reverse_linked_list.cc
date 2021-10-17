/*
 * Reverse a Linked list
 */
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList *reverseLinkedList(LinkedList *head) {
  LinkedList *prev = nullptr, *curr = head;
    while (curr != nullptr) {
        LinkedList *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
  return prev;
}
