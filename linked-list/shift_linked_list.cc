
/*

Shift a singly linked list right by k steps

Sample input:
head: 0-> 1 -> 2 -> 3 -> 4 ->5
k =2 

sample output:

4 -> 5 -> 0 -> 1 -> 2 -> 3

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

LinkedList *shiftLinkedList(LinkedList *head, int k) {
    if (!head)
        return nullptr;
    LinkedList *prev = nullptr, *curr = head;
    
    int shift;
    int n = 0;
    
    while (curr != nullptr) {
        prev = curr;
        curr = curr->next;
        n++;
    }
    // convert to a circular linked list by making tail point to head
    if (prev)
        prev->next = head;
    
    // Find out how much to shift to reach new tail
    if (k < 0)
        shift = abs(k) % n + 1;
    else
        shift = n - k % n + 1;
    
    // Do the actual shift
    curr = head;
    while (--shift > 0) {
        prev = curr;
        curr = curr->next;
    }
    // curr is now the new head and prev is now the new tail
    // mark next pointer of tail
    prev->next = nullptr;
    // return new head
    return curr;
}


