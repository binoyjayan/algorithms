
/*

Merge two singly linked lists that are in sorted order.
The merge should happen in place.

*/

#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
    LinkedList *prev = nullptr;
  LinkedList *curr1 = headOne;
    LinkedList *curr2 = headTwo;
    
    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->value < curr2->value) {
            prev = curr1;
            curr1 = curr1->next;
        } else {
            // the final head is the first element of second list
            if (prev != nullptr)
                prev->next = curr2;
            prev = curr2;
            curr2 = curr2->next;
            prev->next = curr1;
        }
    }
    // If the first list is exhausted, append remaining items in second to first
  if (curr1 == nullptr)
        prev->next = curr2;
  return headOne->value < headTwo->value ? headOne : headTwo;
}

// Recursive solution


void mergeLinkedListsRec(LinkedList *p1, LinkedList *p2, LinkedList *prev) {
    if (p1 == nullptr) {
        prev->next = p2;
        return;
    }
    if (p2 == nullptr)
        return;
    
    if (p1->value < p2->value) {
        mergeLinkedListsRec(p1->next, p2, p1);
  } else {
        if (prev != nullptr) {
            prev->next = p2;
        }
        LinkedList *newP2 = p2->next;
        p2->next = p1;
        mergeLinkedListsRec(p1, newP2, p2);
    }
}

LinkedList *mergeLinkedListsRec(LinkedList *headOne, LinkedList *headTwo) {
    mergeLinkedListsRec(headOne, headTwo, nullptr);
  return headOne->value < headTwo->value ? headOne : headTwo;
}







