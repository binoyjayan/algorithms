
/*

Implement an LRU-Cache in constant time and space

*/

using namespace std;

struct DoublyLinkedListNode {
  string key;
    int value;
    DoublyLinkedListNode *prev;
    DoublyLinkedListNode *next;
    
    DoublyLinkedListNode(string key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
    // Remove next and prev pointers of the current node and adjust neighbors
    void removeBindings() {
        if (this->prev != nullptr) {
            this->prev->next = this->next;
        }
        if (this->next != nullptr) {
            this->next->prev = this->prev;
        }
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
    
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    void setHeadTo(DoublyLinkedListNode *node) {
        if (this->head == node) {
            return;
        } else if(this->head == nullptr) {
            this->head = node;
            this->tail = node;
        } else if (this->head == this->tail) {
            this->tail->prev = node;
            this->head = node;
            this->head->next = this->tail;
        } else {
            if (this->tail == node) {
              this->removeTail();
            }
            node->removeBindings();
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
        }
    }
    
    void removeTail() {
        if (this->tail == nullptr) {
            return;
        }
        if (this->tail == this->head) {
            this->head = nullptr;
            this->tail = nullptr;
            return;
        }
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
  }
};

class LRUCache {
public:
  int maxSize;
    int currentSize;
    DoublyLinkedList listOfMostRecent;
  unordered_map<string, DoublyLinkedListNode *> cache;
    
  LRUCache(int maxSize) {
        this->maxSize = maxSize > 1 ? maxSize : 1;
        this->currentSize = 0;
        this->listOfMostRecent = DoublyLinkedList();
    }

    // O(1) time | O(1) space
  void insertKeyValuePair(string key, int value) {
    if (this->cache.find(key) == this->cache.end()) {
            if (this->currentSize == this->maxSize) {
                this->evictLeastRecent();
            } else {
                this->currentSize++;
            }
            this->cache[key] = new DoublyLinkedListNode(key, value);
        } else {
            this->replaceValueAtKey(key, value);
        }
        this->updateMostRecent(this->cache[key]);
  }

    // O(1) time | O(1) space
  int *getValueFromKey(string key) {
        if (this->cache.find(key) == this->cache.end())
      return nullptr;
        this->updateMostRecent(this->cache[key]);
        return &this->cache[key]->value;
  }

    // O(1) time | O(1) space
  string getMostRecentKey() {
    if (this->listOfMostRecent.head == nullptr) {
            return "";
        }
        return this->listOfMostRecent.head->key;
  }
    
    void evictLeastRecent() {
        string keyToRemove = this->listOfMostRecent.tail->key;
        this->listOfMostRecent.removeTail();
        this->cache.erase(keyToRemove);
    }
    
    void updateMostRecent(DoublyLinkedListNode *node) {
        this->listOfMostRecent.setHeadTo(node);
    }
    
    void replaceValueAtKey(string key, int value) {
        if (this->cache.find(key) == this->cache.end()) {
            return;
        }
        this->cache[key]->value = value;
    }
};



