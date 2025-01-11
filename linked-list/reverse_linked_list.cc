/*
 * Reverse a Linked list
 */
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

class ListNode {
public:
    int value;
    ListNode *next;

    ListNode(int value) {
        this->value = value;
        this->next = nullptr;
    }
};

ListNode* initialize_from_vec(std::vector<int> vec) {
    if (vec.size() == 0) return nullptr;
    ListNode *head = new ListNode(vec[0]);
    ListNode *current = head;
    for (int i = 1; i < vec.size(); i++) {
        ListNode *newNode = new ListNode(vec[i]);
        current->next = newNode;
        current = newNode;
    }
    return head;
}

// Function to print the linked list with formatting similar to vector
void printList(const std::string& s, ListNode *head) {
    std::cout << s << " [";
    ListNode *temp = head;
    while (temp != nullptr) {
        std::cout << std::setw(3) << temp->value;
        if (temp->next != nullptr) {
            std::cout << ", ";
        }
        temp = temp->next;
    }
    std::cout << "]" << std::endl;
}

ListNode *reverse_linked_list(ListNode *head) {
    ListNode *prev = nullptr, *curr = head;
    while (curr != nullptr) {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    ListNode *list1 = initialize_from_vec(vec);
    printList("Original list", list1);
    ListNode *reversed1 = reverse_linked_list(list1);
    printList("Reversed list", reversed1);
    return 0;
}
