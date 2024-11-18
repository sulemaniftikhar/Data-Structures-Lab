#include <iostream>
#include <string>

using namespace std;

struct TreeNode
{
	int productID;
	string name;
	char category;
	int price;
	float bill;
	string personName;
	int CNIC;

	TreeNode *left;
	TreeNode *right;

	TreeNode(int productID, string name, char category, int price, float bill, string personName, int CNIC)
		: productID(productID), name(name), category(category), price(price), bill(bill), personName(personName), CNIC(CNIC), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
	TreeNode *root;

	void destroyTree(TreeNode *node)
	{
		if (node != nullptr)
		{
			destroyTree(node->left);
			destroyTree(node->right);
			delete node;
		}
	}

	TreeNode *insert(TreeNode *root, int productID, string name, char category, int price, float bill, string personName, int CNIC)
	{
		if (root == nullptr)
		{
			TreeNode *newNode = new TreeNode(productID, name, category, price, bill, personName, CNIC);
			return newNode;
		}
		if (price < root->price)
		{
			root->left = insert(root->left, productID, name, category, price, bill, personName, CNIC);
		}
		else if (price > root->price)
		{
			root->right = insert(root->right, productID, name, category, price, bill, personName, CNIC);
		}
		return root;
	}

	TreeNode *find(TreeNode *root, int key)
	{
		if (root == nullptr || root->productID == key)
		{
			return root;
		}
		if (key < root->productID)
		{
			return find(root->left, key);
		}
		else
		{
			return find(root->right, key);
		}
	}

	void calculateBill(TreeNode *root, float &totalBill)
	{
		if (root != nullptr)
		{
			calculateBill(root->left, totalBill);
			totalBill += root->bill;
			calculateBill(root->right, totalBill);
		}
	}

	void print(TreeNode *root)
	{
		if (root != nullptr)
		{
			print(root->left);
			cout << "Product ID: " << root->productID << ", Name: " << root->name << ", Category: " << root->category << ", Price: " << root->price << endl;
			print(root->right);
		}
	}

public:
	BinarySearchTree()
		: root(nullptr) {}

	~BinarySearchTree()
	{
		destroyTree(root);
	}

	void insert(int productID, string name, char category, int price, float bill, string personName, int CNIC)
	{
		root = insert(root, productID, name, category, price, bill, personName, CNIC);
	}

	TreeNode *find(int key)
	{
		return find(root, key);
	}

	float calculateBill()
	{
		float totalBill = 0.0;
		calculateBill(root, totalBill);
		return totalBill;
	}

	void printItemsPurchased()
	{
		if (root == nullptr)
		{
			cout << "No items purchased yet" << endl;
		}
		else
		{
			cout << "Purchased Items:" << endl;
			print(root);
		}
	}
};

int main()
{
	BinarySearchTree eTree;
	BinarySearchTree vTree;

	eTree.insert(1234, "Laptop", 'E', 1500, 1500, "Suleman", 123456);
	eTree.insert(5678, "Smartphone", 'E', 1000, 1000, "Adnam", 987654);
	eTree.insert(9012, "Headphones", 'E', 500, 500, "Waleed", 246810);

	vTree.insert(3456, "Car", 'V', 50000, 50000, "Abdullah", 135792);
	vTree.insert(7890, "Bike", 'V', 2000, 2000, "Usama", 468135);


	float totalBill = eTree.calculateBill() + vTree.calculateBill();
	cout << "Total Bill: " << totalBill << endl;

	eTree.printItemsPurchased();
	vTree.printItemsPurchased();


	system("pause");
	return 0;
}