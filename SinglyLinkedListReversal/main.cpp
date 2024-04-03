#include <iostream>
#include <memory>

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
    auto node1 = std::make_unique<Node<int>>(1);
    auto node2 = std::make_unique<Node<int>>(2);
    auto node3 = std::make_unique<Node<int>>(3);

    auto linked_list = SinglyLinkedList<int>();

    linked_list.addNode(node1.get());
    linked_list.addNode(node2.get());
    linked_list.addNode(node3.get());

    linked_list.printList();
    linked_list.reverse();
    linked_list.printList();

    return 0;
}