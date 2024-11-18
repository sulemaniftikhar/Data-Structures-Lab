//#include <iostream>
//using namespace std;
//
//template<typename T>
//struct Node {
//    T data;
//    Node* left;
//    Node* right;
//
//    Node(T value) : data(value), left(nullptr), right(nullptr) {}
//};
//
//template<typename T>
//class BST {
//private:
//    Node<T>* root;
//
//    Node<T>* copyTree(const Node<T>* srcNode) {
//        if (srcNode == nullptr) {
//            return nullptr;
//        }
//
//        Node<T>* newNode = new Node<T>(srcNode->data);
//        newNode->left = copyTree(srcNode->left);
//        newNode->right = copyTree(srcNode->right);
//
//        return newNode;
//    }
//
//    void destroyTree(Node<T>* node) {
//        if (node != nullptr) {
//            destroyTree(node->left);
//            destroyTree(node->right);
//            delete node;
//        }
//    }
//
//    Node<T>* insert(Node<T>* root, T data) {
//        if (root == nullptr) {
//            Node<T>* newNode = new Node<T>(data);
//            return newNode;
//        }
//        if (data < root->data) {
//            root->left = insert(root->left, data);
//        }
//        else if (data > root->data) {
//            root->right = insert(root->right, data);
//        }
//        return root;
//    }
//
//public:
//    BST() : root(nullptr) {}
//
//    BST(const BST<T>& other) {
//        root = copyTree(other.root);
//    }
//
//    ~BST() {
//        destroyTree(root);
//    }
//
//    void insert(T data) {
//        root = insert(root, data);
//    }
//
//    bool search(T key) {
//        return (find(root, key) != nullptr);
//    }
//
//    void InorderPrint() {
//        InorderPrint(root);
//    }
//
//    void preorderorderPrint() {
//        preorderorderPrint(root);
//    }
//
//    void postorderPrint() {
//        postorderPrint(root);
//    }
//
//    int length() {
//        return length(root);
//    }
//
//    int leafCount() {
//        return leafCount(root);
//    }
//
//    Node<T>* searchRecursive(Node<T>* root, T key) {
//        if (root == nullptr || root->data == key) {
//            return root;
//        }
//        if (key < root->data) {
//            return searchRecursive(root->left, key);
//        }
//        else {
//            return searchRecursive(root->right, key);
//        }
//    }
//
//    BST<T> copy() {
//        return BST<T>(*this);
//    }
//
//private:
//    Node<T>* find(Node<T>* root, T key) {
//        if (root == nullptr || root->data == key) {
//            return root;
//        }
//        if (key < root->data) {
//            return find(root->left, key);
//        }
//        else {
//            return find(root->right, key);
//        }
//    }
//
//    void InorderPrint(Node<T>* root) {
//        if (root == nullptr) {
//            return;
//        }
//        InorderPrint(root->left);
//        cout << root->data << " ";
//        InorderPrint(root->right);
//    }
//
//    void preorderorderPrint(Node<T>* root) {
//        if (root == nullptr) {
//            return;
//        }
//        cout << root->data << " ";
//        preorderorderPrint(root->left);
//        preorderorderPrint(root->right);
//    }
//
//    void postorderPrint(Node<T>* root) {
//        if (root == nullptr) {
//            return;
//        }
//        postorderPrint(root->left);
//        postorderPrint(root->right);
//        cout << root->data << " ";
//    }
//
//    int length(Node<T>* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        return 1 + length(root->left) + length(root->right);
//    }
//
//    int leafCount(Node<T>* root) {
//        if (root == nullptr) {
//            return 0;
//        }
//        if (root->left == nullptr && root->right == nullptr) {
//            return 1;
//        }
//        return leafCount(root->left) + leafCount(root->right);
//    }
//};
//
//int main() {
//    int num;
//    BST<int> tree;
//
//    tree.insert(500);
//    tree.insert(1000);
//    tree.insert(1);
//    tree.insert(600);
//    tree.insert(700);
//    tree.insert(10);
//    tree.insert(30);
//    tree.insert(9000);
//    tree.insert(50000);
//    tree.insert(20);
//
//    cout << "Printing data using recursive inorder traversal: ";
//    tree.InorderPrint();
//    cout << endl;
//
//    cout << "COPY CONSTRUCTOR" << endl;
//    BST<int> tree1 = tree.copy();
//
//    cout << "Preorder Traversal:" << endl;
//    tree1.preorderorderPrint();
//    cout << endl;
//
//    cout << "Inorder Traversal:" << endl;
//    tree1.InorderPrint();
//    cout << endl;
//
//    cout << "Postorder Traversal:" << endl;
//    tree1.postorderPrint();
//    cout << endl;
//
//    cout << "SEARCH:" << endl;
//    cout << "Key 1 found in tree: " << tree1.search(1) << endl;
//    cout << "Key 30 found in tree: " << tree1.search(30) << endl;
//    cout << "Key 50 found in tree: " << tree1.search(50) << endl;
//
//    cout << "Tree Length: " << tree.length() << endl;
//    cout << "Tree Leaf Nodes: " << tree.leafCount() << endl;
//
//    cout << "Press Enter to exit...";
//    cin.get();
//    return 0;
//}
