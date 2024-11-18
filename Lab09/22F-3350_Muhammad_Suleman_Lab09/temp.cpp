#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node()
        : data(0), left(nullptr), right(nullptr) {}
    Node(int data)
        : data(data), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
    void printLevel(Node *root, int level)
    {
        if (root == nullptr)
        {
            return;
        }
        else if (level == 0)
        {
            cout << root->data << " ";
        }
        else
        {
            printLevel(root->left, level - 1);
            printLevel(root->right, level - 1);
        }
    }

    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        return b;
    }

public:
    Node *root;
    BinarySearchTree()
        : root(nullptr) {}

    int height(Node *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        else
        {
            return 1 + max(height(root->left), height(root->right));
        }
    }
    void insert(Node *&root, int data)
    {
        if (root == nullptr)
        {
            Node *newNode = new Node(data);
            root = newNode;
        }
        else if (data < root->data)
        {
            insert(root->left, data);
        }
        else if (data > root->data)
        {
            insert(root->right, data);
        }
        else
        {
            cout << "Duplicate not allowed" << endl;
        }
    }

    bool search(Node *root, int data)
    {
        if (root == nullptr)
        {
            cout << "Cannot search in empty tree" << endl;
            return false;
        }
        if (root->data == data)
        {
            return true;
        }
        if (data < root->data)
        {
            return search(root->left, data);
        }
        return search(root->right, data);
    }

    void BFS(Node *root)
    {
        int h = height(root);
        for (int i = 0; i <= h; i++)
        {
            printLevel(root, i);
        }
        cout << endl;
    }

    void preOrder(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    int findMin(Node *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root->data;
    }

    int findMax(Node *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        while (root->right != nullptr)
        {
            root = root->right;
        }
        return root->data;
    }

    int findMin2(Node *root)
    {
        if (root == nullptr)
        {
            return -1;
        }
        else if (root->left == nullptr)
        {
            return root->data;
        }
        return findMin2(root->left);
    }
};

int main()
{
    BinarySearchTree tree;
    tree.root = nullptr;

    tree.insert(tree.root, 500);
    tree.insert(tree.root, 1000);
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 600);
    tree.insert(tree.root, 700);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 9000);
    tree.insert(tree.root, 5000);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 15);

    cout << "Height: " << tree.height(tree.root) << endl;

    if (tree.search(tree.root, 1))
        cout << "1 found" << endl;
    else
        cout << "1 not found" << endl;

    tree.preOrder(tree.root);
    cout << endl;

    cout << tree.root->data << endl;
    cout << "MAX: " << tree.findMax(tree.root) << endl;
    cout << "MIN: " << tree.findMin(tree.root) << endl;
    cout << "MIN2: " << tree.findMin2(tree.root) << endl;

    tree.BFS(tree.root);

    return 0;
}