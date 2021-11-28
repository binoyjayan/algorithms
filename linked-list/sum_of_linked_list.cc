
/*

Given two linked lists of potentially unequal length, where each list
represents a non-negative integer where each node in the list is a digit
of that integer, and the first node in the list is the least significant
digit of the integer.

sample:

list1: 2 -> 4 -> 7 -> 1
list2: 9 -> 4 -> 5 

output:

1 -> 9 -> 2 -> 2

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
// Solution 1 - traverse lists individually
int getSum(LinkedList *ptr) {
    int num = 0;
    int multiplier = 1;
    while (ptr != nullptr) {
        num += multiplier * ptr->value;
        multiplier *= 10;
        ptr = ptr->next;
    }
    return num;
}
LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
    int num = getSum(linkedListOne) + getSum(linkedListTwo);
  LinkedList *head = new LinkedList(num % 10);
    num /= 10;
    LinkedList *prev = head;    
    while (num != 0) {
        LinkedList *node = new LinkedList(num % 10);
        prev->next = node;
        prev = node;
        num /= 10;
  }
    return head;
}
*/

/// Solution2: only one traversal
LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
    LinkedList *p1 = linkedListOne;
    LinkedList *p2 = linkedListTwo;
    // dummy node
    LinkedList *dummy = new LinkedList(0);
    LinkedList *curr = dummy;
    int carry = 0;

    while (p1 != nullptr || p2 != nullptr || carry != 0) {
        int val1 = p1 != nullptr ? p1->value : 0;
        int val2 = p2 != nullptr ? p2->value : 0;
        int sum = val1 + val2 + carry;
        int newVal = sum % 10;
        carry = sum / 10;
        // cout << "val1: " << val1 << ", val2: " << val2  << ", newVal: " << newVal << ", carry: " << carry << endl;
      LinkedList *node = new LinkedList(newVal);
        curr->next = node;
        curr = node;
        p1 = p1 != nullptr ? p1->next : nullptr;
        p2 = p2 != nullptr ? p2->next : nullptr;
    }

    return dummy->next;
}



