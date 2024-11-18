#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node()
        : data(-1), left(nullptr), right(nullptr) {}

    Node(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    Node *root;

private:
    void destroyTree(Node *node);
    Node *insert(Node *root, int data);
    Node *find(Node *root, int key);
    void InorderPrint(Node *root);
    void preorderorderPrint(Node *root);
    void postorderPrint(Node *root);
    Node *minValueNode(Node *root);
    Node *deleteNode(Node *root, int value);
    Node *createMinBST(int arr[], int start, int end);
    int max(int a, int b);
    int getHeight(Node *root);

public:
    BinarySearchTree()
        : root(nullptr) {}

    ~BinarySearchTree()
    {
        destroyTree(root);
    }

    void insert(int data);
    Node *find(int key);
    void inOrder();
    void preorderorderPrint();
    void postorderPrint();
    void createMinimumBST(int arr[], int size);
    void deleteNode(int value);
    int height();
};

int main()
{
    BinarySearchTree tree1;

    int sortedArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int size = 15;

    for (int i = 0; i < size; i++)
    {
        tree1.insert(sortedArray[i]);
    }
    cout << "Normal BST using sorted array" << endl;
    cout << "Traversing inorder" << endl;
    tree1.inOrder();
    cout << endl;
    cout << "Height: " << tree1.height() << endl;

    BinarySearchTree tree2;
    tree2.createMinimumBST(sortedArray, size);

    cout << "Minimun height BST using sorted array" << endl;
    cout << "Traversing inorder" << endl;
    tree2.inOrder();
    cout << endl;
    cout << "Height: " << tree2.height() << endl;

    return 0;
}

void BinarySearchTree::destroyTree(Node *node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

Node *BinarySearchTree::insert(Node *root, int data)
{
    if (root == nullptr)
    {
        Node *newNode = new Node(data);
        return newNode;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *BinarySearchTree::find(Node *root, int key)
{
    if (root == nullptr || root->data == key)
    {
        return root;
    }
    if (key < root->data)
    {
        return find(root->left, key);
    }
    else
    {
        return find(root->right, key);
    }
}

void BinarySearchTree::InorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    InorderPrint(root->left);
    cout << root->data << " ";
    InorderPrint(root->right);
}

void BinarySearchTree::preorderorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << root->data << " ";
    preorderorderPrint(root->left);
    preorderorderPrint(root->right);
}

void BinarySearchTree::postorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << root->data << " ";
}

Node *BinarySearchTree::minValueNode(Node *root)
{
    while (root != nullptr && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *BinarySearchTree::deleteNode(Node *root, int value)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

Node *BinarySearchTree::createMinBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return nullptr;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);

    root->left = createMinBST(arr, start, mid - 1);
    root->right = createMinBST(arr, mid + 1, end);

    return root;
}

int BinarySearchTree::max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}

int BinarySearchTree::getHeight(Node *root)
{
    if (root == nullptr)
    {
        return -1;
    }
    return max(getHeight(root->left), getHeight(root->right)) + 1;
}

void BinarySearchTree::insert(int data)
{
    root = insert(root, data);
}

Node *BinarySearchTree::find(int key)
{
    return find(root, key);
}

void BinarySearchTree::inOrder()
{
    InorderPrint(root);
}

void BinarySearchTree::preorderorderPrint()
{
    preorderorderPrint(root);
}

void BinarySearchTree::postorderPrint()
{
    postorderPrint(root);
}

void BinarySearchTree::createMinimumBST(int arr[], int size)
{
    root = createMinBST(arr, 0, size - 1);
}

void BinarySearchTree::deleteNode(int value)
{
    root = deleteNode(root, value);
}

int BinarySearchTree::height()
{
    return getHeight(root);
}