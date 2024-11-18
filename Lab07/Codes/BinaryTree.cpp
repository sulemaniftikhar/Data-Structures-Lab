#include <iostream>

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

// Binary tree class
class BinaryTree
{
private:
    Node *root;

    // Helper function to recursively insert a value into the tree
    Node *insertRecursive(Node *current, int value)
    {
        if (current == nullptr)
        {
            return new Node(value);
        }

        if (value < current->data)
        {
            current->left = insertRecursive(current->left, value);
        }
        else if (value > current->data)
        {
            current->right = insertRecursive(current->right, value);
        }

        return current;
    }

    // Helper function to recursively search for a value in the tree
    bool searchRecursive(Node *current, int value)
    {
        if (current == nullptr)
        {
            return false;
        }

        if (value == current->data)
        {
            return true;
        }

        if (value < current->data)
        {
            return searchRecursive(current->left, value);
        }
        else
        {
            return searchRecursive(current->right, value);
        }
    }

    // Helper function for pre-order traversal
    void preOrderRecursive(Node *node)
    {
        if (node == nullptr)
            return;

        std::cout << node->data << " ";
        preOrderRecursive(node->left);
        preOrderRecursive(node->right);
    }

    // Helper function for in-order traversal
    void inOrderRecursive(Node *node)
    {
        if (node == nullptr)
            return;

        inOrderRecursive(node->left);
        std::cout << node->data << " ";
        inOrderRecursive(node->right);
    }

    // Helper function for post-order traversal
    void postOrderRecursive(Node *node)
    {
        if (node == nullptr)
            return;

        postOrderRecursive(node->left);
        postOrderRecursive(node->right);
        std::cout << node->data << " ";
    }

public:
    BinaryTree() : root(nullptr) {}

    // Method to insert a value into the tree
    void insert(int value)
    {
        root = insertRecursive(root, value);
    }

    // Method to search for a value in the tree
    bool search(int value)
    {
        return searchRecursive(root, value);
    }

    // Method to perform pre-order traversal
    void preOrderTraversal()
    {
        preOrderRecursive(root);
        std::cout << std::endl;
    }

    // Method to perform in-order traversal
    void inOrderTraversal()
    {
        inOrderRecursive(root);
        std::cout << std::endl;
    }

    // Method to perform post-order traversal
    void postOrderTraversal()
    {
        postOrderRecursive(root);
        std::cout << std::endl;
    }
};

int main()
{
    BinaryTree tree;

    // Inserting some values into the tree
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(2);
    tree.insert(4);

    // Pre-order traversal
    std::cout << "Pre-order traversal: ";
    tree.preOrderTraversal();

    // In-order traversal
    std::cout << "In-order traversal: ";
    tree.inOrderTraversal();

    // Post-order traversal
    std::cout << "Post-order traversal: ";
    tree.postOrderTraversal();

    return 0;
}