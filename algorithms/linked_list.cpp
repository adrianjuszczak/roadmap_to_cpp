#include <iostream>
using ul = unsigned long;

template <typename T>
struct Node {
    Node<T> *next;
    T value;
};

template <typename T>
class LinkedList {
public:
    LinkedList() : head{nullptr} {}
    ~LinkedList();
    // TODO deep-copy
    // TODO mv semantics
    void push_back(T value);
    void print_all_values();
    void remove_if_value_exist(T value);
    void cleanAllocatedMemory();
    static ul nodeCounter;

private:
    Node<T> *head;
    Node<T> *temp;
};

template <typename T>
ul LinkedList<T>::nodeCounter = 0;

template <typename T>
LinkedList<T>::~LinkedList() {
    cleanAllocatedMemory();
    std::cout << "DTOR - cleaned.\n";
}

template <typename T>
void LinkedList<T>::push_back(T value) {
    if (head == nullptr) {
        nodeCounter++;
        head = new Node<T>;
        head->value = value;
        head->next = nullptr;
    } else {
        temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node<T>;
        nodeCounter++;
        temp->next->next = nullptr;
        temp->next->value = value;
        std::cout << "elements on stack: " << nodeCounter << "\n";
    }
}

template <typename T>
void LinkedList<T>::print_all_values() {
    temp = head;
    while (temp)
    {
        std::cout << temp->value << ", ";
        temp = temp->next;
    }
    std::cout << "\n";
}

template <typename T>
void LinkedList<T>::remove_if_value_exist(T value) {
    if (head->value == value)
    {
        nodeCounter--;
        delete head;
        return;
    }
    else
    {
        temp = head;

        while (temp->next)
        {
            if (temp->next->value == value)
            {
                Node<T> *node_to_remove = temp->next;
                temp->next = temp->next->next;
                nodeCounter--;
                delete node_to_remove;
            }
            temp = temp->next;
        }
    }
}

template <typename T>
void LinkedList<T>::cleanAllocatedMemory() {
    std::cout << "Numbers of elements to be removed: " << nodeCounter << "\n";
    while (head)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main()
{
    {
        LinkedList<int> list;
        list.push_back(10);
        list.push_back(11);
        list.push_back(12);
        list.print_all_values();
        // list.remove_if_value_exist(11);
        list.print_all_values();
    }
}