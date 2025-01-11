
/*

Write a function to find a loop in the linked list.
The funtion should return the node from which the loop
originates in constant space.

*/

#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};


/*
              'x'
1 -> 2 -> 3 -> 4 -> 5 -> 6
               ^         |
               |         v
               9 <- 8 <- 7   'y'

T: Total nodes in linked list
x: Assume 'x' is the node where the tail merges back with the list
D: Distance from head to the node 'x'
P: Distance from node 'x' to node 'y'
R: Distance from node 'y' to node 'x'
Distance covered by slow pointer = D + P
Distance covered by fast pointer = 2(D + P) 
T = 2(D + P)  - P (total is P less than distance covered by fast pointer)
  = 2D + P
R = T       - (P + D)
  = 2D + P  - (P + D)   // substitute 'T'
    = D
So, R = D, thus after the pointers overlap at 'y', travel D more to reach 'x'
*/

// O(n) time O(1) space
LinkedList *findLoop(LinkedList *head) {
  LinkedList *slow = head->next;
    LinkedList *fast = head->next->next;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
  return slow;
}

