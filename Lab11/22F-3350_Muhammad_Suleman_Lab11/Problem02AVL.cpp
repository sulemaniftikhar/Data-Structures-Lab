#include <iostream>
#include <ctime>
#include <chrono>
#include <cstdlib>
#include <string>

using namespace std;
using namespace std::chrono;

struct Node
{
    string word;
    string definition;
    Node *left;
    Node *right;
    int height;

    Node() : word("\0"), definition("\0"), left(nullptr), right(nullptr), height(0) {}

    Node(string word, string definition)
        : word(word), definition(definition), left(nullptr), right(nullptr), height(0) {}
};

class AVLTree
{
public:
    Node *root;

private:
    void destroyTree(Node *node);
    Node *insert(Node *root, string word, string definition);
    Node *find(Node *root, string word);
    void inOrder(Node *root);
    void preorderorderPrint(Node *root);
    void postorderPrint(Node *root);
    Node *minValueNode(Node *root);
    Node *deleteNode(Node *root, string word);
    Node *rotateRight(Node *y);
    Node *rotateLeft(Node *x);
    int getHeight(Node *node);
    int getBalanceFactor(Node *node);

public:
    AVLTree() : root(nullptr) {}

    ~AVLTree()
    {
        destroyTree(root);
    }

    void insert(string word, string definition);
    Node *find(string word);
    void inOrder();
    void preorderorderPrint();
    void postorderPrint();
    void deleteNode(string word);
};

int main()
{
    AVLTree avlTree;

    auto start = chrono::high_resolution_clock::now();

    avlTree.insert("algorithm", "a step by step procedure for solving a problem");
    avlTree.insert("ADT", "user defined classes");
    avlTree.insert("recursion", "function calling itself in its definition");
    avlTree.insert("binary search", "a searching algorithm");

    avlTree.insert("abc", "a");
    avlTree.insert("bcd", "b");
    avlTree.insert("cde", "c");
    avlTree.insert("fdfd", "a");
    avlTree.insert("dsds", "b");
    avlTree.insert("cdsdde", "c");
    avlTree.insert("abcsds", "a");
    avlTree.insert("bcdsd", "b");
    avlTree.insert("cdedew", "c");

    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Execution time of insertion in AVL: " << duration.count() << " nanoseconds." << endl;

    cout << "Searching for \"algorithm\" (AVL Tree)" << endl;
    Node *result = avlTree.find("algorithm");
    if (result)
    {
        cout << "Word \"" << result->word << "\" Found" << endl;
        cout << "Definition of \"algorithm\": " << result->definition << endl;
    }
    else
    {
        cout << "Term not found in the dictionary" << endl;
    }
    cout << endl;

    cout << "Searching for stack:" << endl;
    result = avlTree.find("stack");
    if (result)
    {
        cout << "Word \"" << result->word << "\" Found" << endl;
        cout << "Definition of \"stack\": " << result->definition << endl;
    }
    else
    {
        cout << "Term not found in the dictionary" << endl;
    }
    cout << endl;

    cout << "Inorder traversal" << endl;
    avlTree.inOrder();
    cout << endl;

    cout << "Deleting \"variable\" from the dictionary" << endl;
    avlTree.deleteNode("variable");
    cout << endl;

    // cout << "Inorder traversal after deletion:" << endl;
    // avlTree.inOrder();
    // cout << endl;

    return 0;
}

void AVLTree::destroyTree(Node *node)
{
    if (node != nullptr)
    {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

Node *AVLTree::insert(Node *root, string word, string definition)
{
    if (root == nullptr)
    {
        Node *newNode = new Node(word, definition);
        return newNode;
    }

    if (word < root->word)
    {
        root->left = insert(root->left, word, definition);
    }
    else if (word > root->word)
    {
        root->right = insert(root->right, word, definition);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    // left left case
    if (balance > 1 && word < root->left->word)
        return rotateRight(root);

    // right right case
    if (balance < -1 && word > root->right->word)
        return rotateLeft(root);

    // left right case
    if (balance > 1 && word > root->left->word)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // right left case
    if (balance < -1 && word < root->right->word)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }
    return root;
}

Node *AVLTree::find(Node *root, string word)
{
    if (root == nullptr || root->word == word)
    {
        return root;
    }

    if (word < root->word)
    {
        return find(root->left, word);
    }
    else
    {
        return find(root->right, word);
    }
}

void AVLTree::inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    cout << "Word: " << root->word << endl;
    cout << "Definition: " << root->definition << endl;
    inOrder(root->right);
}

void AVLTree::preorderorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << "Word: " << root->word << endl;
    cout << "Definition: " << root->definition << endl;
    preorderorderPrint(root->left);
    preorderorderPrint(root->right);
}

void AVLTree::postorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    postorderPrint(root->left);
    postorderPrint(root->right);
    cout << "Word: " << root->word << endl;
    cout << "Definition: " << root->definition << endl;
}

Node *AVLTree::minValueNode(Node *root)
{
    while (root != nullptr && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *AVLTree::deleteNode(Node *root, string word)
{
    if (root == nullptr)
    {
        return root;
    }
    else if (word < root->word)
    {
        root->left = deleteNode(root->left, word);
    }
    else if (word > root->word)
    {
        root->right = deleteNode(root->right, word);
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
            root->word = temp->word;
            root->definition = temp->definition;
            root->right = deleteNode(root->right, temp->word);
        }
    }

    if (root == nullptr)
    {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    // left left case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
    {
        return rotateRight(root);
    }

    // left right case
    if (balance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // right right case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
    {
        return rotateLeft(root);
    }

    // right left case
    if (balance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void AVLTree::insert(string word, string definition)
{
    root = insert(root, word, definition);
}

Node *AVLTree::find(string word)
{
    return find(root, word);
}

void AVLTree::inOrder()
{
    inOrder(root);
}

void AVLTree::preorderorderPrint()
{
    preorderorderPrint(root);
}

void AVLTree::postorderPrint()
{
    postorderPrint(root);
}

void AVLTree::deleteNode(string word)
{
    root = deleteNode(root, word);
}

Node *AVLTree::rotateRight(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(getHeight(y->left), getHeight(y->right));
    x->height = 1 + max(getHeight(x->left), getHeight(x->right));

    return x;
}

Node *AVLTree::rotateLeft(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    y->height = 1 + max(getHeight(y->left), getHeight(y->right));

    return y;
}

int AVLTree::getHeight(Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }
    return node->height;
}

int AVLTree::getBalanceFactor(Node *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}