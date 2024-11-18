#include <iostream>
using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val)
        : value(val), left(nullptr), right(nullptr) {}
};

class IntBinaryTree
{
private:
    TreeNode *root;

    void destroySubTree(TreeNode *node)
    {
        if (node)
        {
            destroySubTree(node->left);
            destroySubTree(node->right);
            delete node;
        }
    }

    void deleteNode(int num, TreeNode *&nodePtr)
    {
        if (nodePtr == nullptr)
        {
            cout << num << " not found.\n";
        }
        else if (num < nodePtr->value)
        {
            deleteNode(num, nodePtr->left);
        }
        else if (num > nodePtr->value)
        {
            deleteNode(num, nodePtr->right);
        }
        else
        {
            makeDeletion(nodePtr);
        }
    }

    void makeDeletion(TreeNode *&nodePtr)
    {
        TreeNode *tempNodePtr;
        if (nodePtr->right == nullptr)
        {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->left;
            delete tempNodePtr;
        }
        else if (nodePtr->left == nullptr)
        {
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        }
        else
        {
            tempNodePtr = nodePtr->right;
            while (tempNodePtr->left)
            {
                tempNodePtr = tempNodePtr->left;
            }
            tempNodePtr->left = nodePtr->left;
            tempNodePtr = nodePtr;
            nodePtr = nodePtr->right;
            delete tempNodePtr;
        }
    }

    void displayInOrder(TreeNode *node)
    {
        if (node)
        {
            displayInOrder(node->left);
            cout << node->value << " ";
            displayInOrder(node->right);
        }
    }

    void displayPreOrder(TreeNode *node)
    {
        if (node)
        {
            cout << node->value << " ";
            displayPreOrder(node->left);
            displayPreOrder(node->right);
        }
    }

    void displayPostOrder(TreeNode *node)
    {
        if (node)
        {
            displayPostOrder(node->left);
            displayPostOrder(node->right);
            cout << node->value << " ";
        }
    }

public:
    IntBinaryTree()
        : root(nullptr) {}
    ~IntBinaryTree() { destroySubTree(root); }

    void insertNode(int num)
    {
        TreeNode *newNode = new TreeNode(num);
        if (!root)
        {
            root = newNode;
        }
        else
        {
            TreeNode *nodePtr = root;
            while (true)
            {
                if (num < nodePtr->value)
                {
                    if (nodePtr->left != nullptr)
                    {
                        nodePtr = nodePtr->left;
                    }
                    else
                    {
                        nodePtr->left = newNode;
                        break;
                    }
                }
                else if (num > nodePtr->value)
                {
                    if (nodePtr->right != nullptr)
                    {
                        nodePtr = nodePtr->right;
                    }
                    else
                    {
                        nodePtr->right = newNode;
                        break;
                    }
                }
                else
                {
                    cout << "Duplicate value found in tree.\n";
                    break;
                }
            }
        }
    }

    bool find(int num)
    {
        TreeNode *nodePtr = root;
        while (nodePtr)
        {
            if (nodePtr->value == num)
                return true;
            else if (num < nodePtr->value)
                nodePtr = nodePtr->left;
            else
                nodePtr = nodePtr->right;
        }
        return false;
    }

    void remove(int num)
    {
        deleteNode(num, root);
    }

    void showNodesInOrder()
    {
        displayInOrder(root);
        cout << endl;
    }

    void showNodesPreOrder()
    {
        displayPreOrder(root);
        cout << endl;
    }

    void showNodesPostOrder()
    {
        displayPostOrder(root);
        cout << endl;
    }
};

int main()
{
    IntBinaryTree tree;
    tree.insertNode(50);
    tree.insertNode(30);
    tree.insertNode(70);
    tree.insertNode(20);
    tree.insertNode(40);
    tree.insertNode(60);
    tree.insertNode(80);

    cout << "Inorder traversal: ";
    tree.showNodesInOrder();

    cout << "Preorder traversal: ";
    tree.showNodesPreOrder();

    cout << "Postorder traversal: ";
    tree.showNodesPostOrder();

    cout << "Removing 30...\n";
    tree.remove(30);
    cout << "Inorder traversal after removal: ";
    tree.showNodesInOrder();

    return 0;
}