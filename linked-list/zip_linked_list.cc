
/*

Write a function that zips a singly linked list in place.

Sample: 1 -> 2 -> 3 -> 4 -> 5 -> 6
Output: 1 -> 6 -> 2 -> 5 -> 3 -> 4 

*/

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *reverseLinkedList(LinkedList *head) {
    LinkedList *prev = nullptr;
    LinkedList *curr = head;
    while (curr != nullptr) {
        LinkedList *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


LinkedList *zipLinkedList(LinkedList *linkedList) {
  LinkedList *slow = linkedList;
    LinkedList *fast = linkedList;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }    

    LinkedList *firstHalf = linkedList;
    LinkedList *secondHalf = reverseLinkedList(slow);;
    
    while (secondHalf != nullptr && secondHalf->next != nullptr) {
        LinkedList *firstHalfNext = firstHalf->next;
        LinkedList *secondHalfNext = secondHalf->next;
        firstHalf->next = secondHalf;
        secondHalf->next = firstHalfNext;
        secondHalf = secondHalfNext;
        firstHalf = firstHalfNext;
    }
  
  return linkedList;
}


