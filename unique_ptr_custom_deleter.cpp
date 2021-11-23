#include <iostream>
#include <memory>

// https://stackoverflow.com/questions/38486211/c11-using-unique-ptr-with-custom-deleter

typedef struct Node_ {
    int           value;
    struct Node_* next;
} Node;

auto deleteList = [](Node* p) {
    while(p) {
        std::cout << "Deleting : " << p->value << std::endl;
        Node* n = p->next;
        delete p;
        p = n;
    }
    return;
};

auto createList() {
    std::unique_ptr<Node, decltype(deleteList)> head(new Node, deleteList);

    Node* temp  = head.get();
    temp->value = 0;
    for(int i = 1; i < 8; i++) {
        if(temp->next == nullptr) {
            temp->next  = new Node();
            temp        = temp->next;
            temp->value = i;
            temp->next  = nullptr;
        }
    }
    return head;
}

int main() {
    std::unique_ptr<Node, decltype(deleteList)> node = createList();
}

/**
Deleting : 0
Deleting : 1
Deleting : 2
Deleting : 3
Deleting : 4
Deleting : 5
Deleting : 6
Deleting : 7
*/
