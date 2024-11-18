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

    Node()
        : word("\0"), definition("\0"), left(nullptr), right(nullptr) {}

    Node(string word, string definition)
        : word(word), definition(definition), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
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

public:
    BinarySearchTree()
        : root(nullptr) {}

    ~BinarySearchTree()
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
    BinarySearchTree BST;

    auto start = chrono::high_resolution_clock::now();

    BST.insert("algorithm", "a step by step procedure for solving a problem");
    BST.insert("ADT", "user defined classes");
    BST.insert("recursion", "function calling itself in its definition");
    BST.insert("binary search", "a searching algorithm");

    BST.insert("abc", "a");
    BST.insert("bcd", "b");
    BST.insert("cde", "c");
    BST.insert("fdfd", "a");
    BST.insert("dsds", "b");
    BST.insert("cdsdde", "c");
    BST.insert("abcsds", "a");
    BST.insert("bcdsd", "b");
    BST.insert("cdedew", "c");

    auto end = chrono::high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Execution time of insertion in BST: " << duration.count() << " nanoseconds." << endl;

    cout << "Searching for \"algorithm\" (BST Tree)" << endl;
    Node *result = BST.find("algorithm");
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
    result = BST.find("stack");
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
    BST.inOrder();
    cout << endl;

    cout << "Deleting \"variable\" from the dictionary" << endl;
    BST.deleteNode("variable");
    cout << endl;

    // cout << "Inorder traversal after deletion:" << endl;
    // BST.inOrder();
    // cout << endl;

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

Node *BinarySearchTree::insert(Node *root, string word, string definition)
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
    return root;
}

Node *BinarySearchTree::find(Node *root, string word)
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

void BinarySearchTree::inOrder(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    inOrder(root->left);
    cout << "Word: " << root->word << endl;
    cout << "Defination: " << root->definition << endl;
    inOrder(root->right);
}

void BinarySearchTree::preorderorderPrint(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    cout << "Word: " << root->word << endl;
    cout << "Defination: " << root->definition << endl;
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
    cout << "Word: " << root->word << endl;
    cout << "Defination: " << root->definition << endl;
}

Node *BinarySearchTree::minValueNode(Node *root)
{
    while (root != nullptr && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *BinarySearchTree::deleteNode(Node *root, string word)
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
    return root;
}

void BinarySearchTree::insert(string word, string definition)
{
    root = insert(root, word, definition);
}

Node *BinarySearchTree::find(string word)
{
    return find(root, word);
}

void BinarySearchTree::inOrder()
{
    inOrder(root);
}

void BinarySearchTree::preorderorderPrint()
{
    preorderorderPrint(root);
}

void BinarySearchTree::postorderPrint()
{
    postorderPrint(root);
}

void BinarySearchTree::deleteNode(string word)
{
    root = deleteNode(root, word);
}