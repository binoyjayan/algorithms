
/*

Write a function to check if a singly linked list is a palindrome.
The funtion must not use an auxiliary data structure.

*/

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

/*
// Recursive solution
struct LinkedListInfo {
    bool outerNodeAreEqual;
    LinkedList *leftNodeToCompare;
    
    LinkedListInfo(bool outerEq, LinkedList *left) {
        outerNodeAreEqual = outerEq;
        leftNodeToCompare = left;
    }
};

LinkedListInfo isPalindrome(LinkedList *left, LinkedList *right) {
    if (right == nullptr) {
        return LinkedListInfo(true, left);
    }
    LinkedListInfo result = isPalindrome(left, right->next);
    LinkedList *leftNodeToCompare = result.leftNodeToCompare;
    bool outerNodeAreEqual = result.outerNodeAreEqual;
    bool recursiveEqual = outerNodeAreEqual && leftNodeToCompare->value == right->value;
    LinkedList *nextLeftNodeToCompare = leftNodeToCompare->next;
    return LinkedListInfo(recursiveEqual, nextLeftNodeToCompare);
}

bool linkedListPalindrome(LinkedList *head) {
  return isPalindrome(head, head).outerNodeAreEqual;
}
*/


// Iterative solution
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

bool linkedListPalindrome(LinkedList *head) {
  LinkedList *slow = head;
    LinkedList *fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    LinkedList *firstHalf = head;
    LinkedList *revSecHalf = reverseLinkedList(slow);
    
    while (revSecHalf != nullptr) {
        if (revSecHalf->value != firstHalf->value)
            return false;
        revSecHalf = revSecHalf->next;
        firstHalf = firstHalf->next;
    }
    return true;
}




