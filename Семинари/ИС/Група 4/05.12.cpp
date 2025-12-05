
#include <iostream>
#include <vector>
class BinTree
{
private:

	struct Node
	{
		int data;
		BinTree* left;
		BinTree* right;

		Node(int d)
			:data(d), left(nullptr), right(nullptr)
		{
		}
	};

	Node* root;

public:
	void setRootData(int data)
	{
		if (!root)
		{
			root = new Node(data);
		}
		else {
			root->data = data;
		}
	}

	void setLeftTree(BinTree* leftTree)
	{
		root->left = leftTree;
	}

	void setRightTree(BinTree* rightTree)
	{
		root->right = rightTree;
	}
	int init(const std::vector<int*>& numbers, int index)
	{
		if (numbers.empty())  
			return 0;

		if (numbers[index] == nullptr)
			return index + 1;

		BinTree* leftTree = new BinTree();
		BinTree *rightTree = new BinTree();
		
		int rightIndex = leftTree->init(numbers, index + 1);
		rightTree->init(numbers, rightIndex + 1);

		
		this->setRootData(*numbers[0]);
		this->setLeftTree(leftTree);
		this->setRightTree(rightTree);
		
	}

	void print()
	{
		if (!root)
			return;

		std::cout << root->data;
		root->left->print();
		root->right->print();

	}

	bool pathExists(std::vector<int> path ,int index)
	{
		if (root->left == nullptr && root->right == nullptr) {
			return path.size() == 0;
		}
		if (root->data != path[index])
		{
			return false;
		}
		if (index >= path.size())
		{
			return false;
		}

		return root->left->pathExists(path, index + 1) || root->right->pathExists(path, index + 1);
	}

	bool containsSum(int sum, int res)
	{
		res += root->data;
		if (!root->left && !root->right)
		{
			return res == sum;
		}
		return root->left->containsSum(sum, res) || root->right->containsSum(sum, res);
	}

	int leavesCount() {
		if (!root->left && !root->right) return 1;

		return (root->left != nullptr ? root->left->leavesCount() : 0) + (root->right != nullptr ? root->right->leavesCount() : 0);


		int count = 0;
		if (root->left) {
			count += root->left->leavesCount();
		}
		if (root->right) {
			count += root->right->leavesCount();
		}
		return count;
	}

	bool isALeaf() {
		return !root->left && !root->right;
	}

	bool containsElement(int value) {
		if (root->data == value) return true;
		return root->left->containsElement(value) || root->right->containsElement(value);
	}

	int parent(int first, int second) {
		if ((root->left->containsElement(first) && root->right->containsElement(second)) ||
			(root->left->containsElement(first) && root->right->containsElement(second)))
			return root->data;
		if (root->left->containsElement(first) && root->left->containsElement(second))
			return root->left->parent(first, second);

		if (root->right->containsElement(first) && root->right->containsElement(second))
			return root->right->parent(first, second);
	}

	int getHeight() {

	}

	int diameter() {

	}
};

int main()
{
	int* petPointer = new int;
	int* onePointer = new int;

	*petPointer = 5;
	*onePointer = 1;

	std::vector<int*> numbers = { petPointer , onePointer, petPointer, nullptr, nullptr, petPointer, nullptr, nullptr, onePointer, petPointer, nullptr, nullptr, nullptr};


	BinTree bt;
	bt.init(numbers, 0);
	bt.print();
	
}
