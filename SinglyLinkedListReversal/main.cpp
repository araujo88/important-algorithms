#include <iostream>

template <typename T>
struct Node
{
    T val;
    Node *next = nullptr;

    Node(T val) : val(val) {}
};

template <typename T>
class SinglyLinkedList
{
private:
    Node<T> *root = nullptr;

public:
    SinglyLinkedList() : root(nullptr) {}

    void addNode(Node<T> *node)
    {
        if (this->root == nullptr)
        {
            this->root = node;
        }
        else
        {
            Node<T> *current_node = this->root;
            while (current_node->next != nullptr)
            {
                current_node = current_node->next;
            }
            current_node->next = node;
        }
    }

    void printList()
    {
        Node<T> *current_node = this->root;
        while (current_node != nullptr)
        {
            std::cout << current_node->val << std::endl;
            current_node = current_node->next;
        }
    }

    void reverse()
    {
        Node<T> *previous_node = nullptr;
        Node<T> *current_node = this->root;
        Node<T> *next_node = nullptr;

        while (current_node != nullptr)
        {
            // Save next node
            next_node = current_node->next;

            // Reverse current node's pointer
            current_node->next = previous_node;

            // Move pointers one position ahead.
            previous_node = current_node;
            current_node = next_node;
        }
        this->root = previous_node;
    }
    ~SinglyLinkedList() {}
};

int main()
{
    Node<int> *node1 = new Node<int>(1);
    Node<int> *node2 = new Node<int>(2);
    Node<int> *node3 = new Node<int>(3);

    SinglyLinkedList<int> linked_list = SinglyLinkedList<int>();

    linked_list.addNode(node1);
    linked_list.addNode(node2);
    linked_list.addNode(node3);

    linked_list.printList();
    linked_list.reverse();
    linked_list.printList();

    delete node1;
    delete node2;
    delete node3;

    return 0;
}