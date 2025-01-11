
/*
 * Given a head of a linked-list, whose nodes are in sorted order,
 * write a function to remove duplicates in the list in place.

 */

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  // Write your code here.
    if (!linkedList || !linkedList->next)
        return linkedList;
    LinkedList *prev = linkedList;
    LinkedList *curr = linkedList->next;

    while (curr) {
        if (curr->value == prev->value) {
            prev->next = curr->next;
        } else {
            prev = curr;
        }
        curr = curr->next;
    }
  return linkedList;
}
