
/*
 * Function to remove k-th node from a singly linked list
 */

#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void removeKthNodeFromEnd(LinkedList *head, int k) {
    LinkedList *p1 = head, *p2 = head, *prev = nullptr;
    
    while(p2 != nullptr) {
        p2 = p2->next;
        if (--k == 0)
            break;
    }
    // special handling of head removal
    if (p2 == nullptr) {
        head->value = head->next->value;
        head->next = head->next->next;
    }
    
    while(p2 != nullptr) {
        prev = p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    if (prev)
      prev->next = p1->next;
}

