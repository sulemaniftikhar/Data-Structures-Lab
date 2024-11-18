#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
        : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
public:
    Node *root;

private:
    Node *copyTree(const Node *srcNode)
    {
        if (srcNode == nullptr)
        {
            return nullptr;
        }
        Node *newNode = new Node(srcNode->data);
        newNode->left = copyTree(srcNode->left);
        newNode->right = copyTree(srcNode->right);
        return newNode;
    }

    void destroyTree(Node *node)
    {
        if (node != nullptr)
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    bool isBSTUtil(Node *node, int min_val, int max_val)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (node->data <= min_val || node->data >= max_val)
        {
            return false;
        }
        return isBSTUtil(node->left, min_val, node->data) && isBSTUtil(node->right, node->data, max_val);
    }

    Node *insert(Node *root, int data)
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

    Node *find(Node *root, int key)
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

    void InorderPrint(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        InorderPrint(root->left);
        cout << root->data << " ";
        InorderPrint(root->right);
    }

    void preorderorderPrint(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->data << " ";
        preorderorderPrint(root->left);
        preorderorderPrint(root->right);
    }

    void postorderPrint(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        postorderPrint(root->left);
        postorderPrint(root->right);
        cout << root->data << " ";
    }

    int nodeCount(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + nodeCount(root->left) + nodeCount(root->right);
    }

    int leafCount(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        return leafCount(root->left) + leafCount(root->right);
    }

public:
    BinarySearchTree()
        : root(nullptr) {}

    BinarySearchTree(const BinarySearchTree &other)
    {
        root = copyTree(other.root);
    }

    ~BinarySearchTree()
    {
        destroyTree(root);
    }

    bool isBST()
    {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
    void insert(int data)
    {
        root = insert(root, data);
    }

    Node *find(int key)
    {
        return find(root, key);
    }

    void InorderPrint()
    {
        InorderPrint(root);
    }

    void preorderorderPrint()
    {
        preorderorderPrint(root);
    }

    void postorderPrint()
    {
        postorderPrint(root);
    }

    int length()
    {
        return nodeCount(root);
    }

    int leafCount()
    {
        return leafCount(root);
    }
};

int main()
{
    BinarySearchTree tree1;

    tree1.insert(500);
    tree1.insert(1000);
    tree1.insert(1);
    tree1.insert(600);
    tree1.insert(700);
    tree1.insert(10);
    tree1.insert(30);
    tree1.insert(9000);
    tree1.insert(50000);
    tree1.insert(20);

    cout << "Printing data using recursive inorder traversal: ";
    tree1.InorderPrint();
    cout << endl;

    cout << "Using copy constructor to copy tree1 to tree2" << endl;
    BinarySearchTree tree2(tree1);

    cout << "Preorder Traversal: ";
    tree2.preorderorderPrint();
    cout << endl;

    cout << "Inorder Traversal: ";
    tree2.InorderPrint();
    cout << endl;

    cout << "Postorder Traversal: ";
    tree2.postorderPrint();
    cout << endl;

    cout << "SEARCH:" << endl;
    int arr[] = {1, 30, 50};
    for (int i = 0; i < 3; i++)
    {
        if (tree2.find(arr[i]))
        {
            cout << arr[i] << " exists in tree" << endl;
        }
        else
        {
            cout << arr[i] << " doesn't exists in tree" << endl;
        }
    }

    cout << "Tree nodes: " << tree1.length() << endl;
    cout << "Tree Leaf Nodes: " << tree1.leafCount() << endl;

    if (tree1.isBST())
    {
        cout << "Tree1 is BST" << endl;
    }
    else
    {
        cout << "Tree1 is NOT BST" << endl;
    }
    if (tree2.isBST())
    {
        cout << "Tree2 is BST" << endl;
    }
    else
    {
        cout << "Tree2 is NOT BST" << endl;
    }

    return 0;
}