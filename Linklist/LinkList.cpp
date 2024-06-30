#include <iostream>
using namespace std ;
class List {
public:
    class Node {
    private:
        int node_value;
        Node* next_node;

    public:
        Node(int node_value = 0, Node* next_node = nullptr);
        int value() const;
        Node* next() const;
        void set_next(Node* next); // تابع setter اضافه شده
    };

    List();
    bool empty() const;
    int size() const;
    int front() const;
    Node* begin() const;
    Node* end() const;
    int count(int) const;
    void push_front(int);
    int pop_front();
    void push_EveryWhere(int);//Look like push every where becous of that i dont write thats function
    int erase(int);

private:
    Node* list_head;
};
//----------------------------------------------------------------------------------------------------------------------------------------
//این توابع در کلاس نود هستش
List::Node::Node(int e, Node* n) {
    node_value = e;
    next_node = n;
}

int List::Node::value() const {
    return node_value;
}

List::Node* List::Node::next() const {
    return next_node;
}

void List::Node::set_next(Node* next) { // تابع setter اضافه شده
    next_node = next;
}
//-----------------------------------------------------------------------------------------------------------------------------------------
List::List() {
    list_head = nullptr;
}

bool List::empty() const {
    return list_head == nullptr;
}

int List::size() const {
    int size = 0;
    for (Node* temp = list_head; temp != nullptr; temp = temp->next()) {
        size++;
    }
    return size;
}

List::Node* List::begin() const {
    return list_head;
}

List::Node* List::end() const {
    return nullptr;
}

int List::front() const {
    if (empty()) {
        throw runtime_error("List is empty");
    }
    return begin()->value();
}

void List::push_front(int n) {
    list_head = new Node(n, list_head);
}

int List::pop_front() {
    if (empty()) {
        throw runtime_error("List is empty");
    }
    Node* old_head = list_head;
    int value = old_head->value();
    list_head = old_head->next();
    delete old_head;
    return value;
}

void List::push_EveryWhere(int value) {
    int index = 0;
    int siz = size();
    Node* new_head = nullptr;
    Node* prev_node = nullptr;

    cout << "Your size is = " << siz << endl;
    cout << "Where do you want to insert the new node? (Enter an index): ";
    cin >> index;

    if (index < 0 || index > siz) {
        cout << "Invalid index. Insertion failed." << endl;
        return;
    }

    if (index == 0) {
        push_front(value);
        return;
    }

    for (Node* temp = list_head; temp != nullptr; temp = temp->next()) {
        if (index == siz) {
            new_head = new Node(value, temp);
            prev_node->set_next(new_head); // استفاده از تابع setter
            break;
        }
        prev_node = temp;
        siz--;
    }
}

int main() {
    List myList;

    if (myList.empty()) {
        cout << "The list is empty." << endl;
    }

    myList.push_front(10);
    myList.push_front(20);
    myList.push_front(30);
    myList.push_front(11);
    myList.push_front(55);
    if (!myList.empty()) {
        cout << "The list is not empty." << endl;
    }
    cout << "Size of your list: " << myList.size() << endl;
    cout << "Front element: " << myList.front() << endl;

    cout << "List elements: ";
    for (List::Node* node = myList.begin(); node != myList.end(); node = node->next()) {
        cout << node->value() << " ";
    }
    cout << endl;

    int poppedValue = myList.pop_front();
    cout << "Popped front element: " << poppedValue << endl;
    cout << "Front element after pop: " << myList.front() << endl;

    myList.push_EveryWhere(25);
    cout << "List elements: ";
    for (List::Node* node = myList.begin(); node != myList.end(); node = node->next()) {
        cout << node->value() << " ";
    }
    cout <<"\n";
}