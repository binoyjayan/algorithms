
/*

Write a function to swap adjacent nodes in a linked list.
For odd numbered list, leave the last node untouched.

Sample input  : 0 -> 1 -> 2 -> 3 -> 4 -> 5 
Sample output : 1 -> 0 -> 3 -> 2 -> 5 -> 4

*/

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

/*
// Solution that needs special handling for swapping head node

// O(n) time | o(n) space
LinkedList *nodeSwap(LinkedList *head) {
    LinkedList *next, *prev = nullptr;
    LinkedList *curr = head;

  while (curr && curr->next != nullptr) {
        next = curr->next;
        // special handling for swapping head node
        if (prev == nullptr) {
          curr->next = head;
            head->next = curr;
            head = next;
        } else {
            prev->next = next;
        }
        curr->next = next->next;
        next->next = curr;
        
        prev = curr;
        curr = curr->next;
    }
  return head;
}

*/

// Better solution:
// - Avoid special handling for head by using a dummy node
// - Avoid extra if check in while loop

LinkedList *nodeSwap(LinkedList *head) {
  LinkedList *dummy = new LinkedList(0);
    LinkedList *prev = dummy;
    LinkedList *curr = head;
    
    dummy->next = head;
  while (curr && curr->next != nullptr) {
        LinkedList *next = curr->next;
        
        // Core logic
        prev->next = next;
        curr->next = next->next;
        next->next = curr;

        prev = curr;
        curr = curr->next;
    }
  return dummy->next;
}





