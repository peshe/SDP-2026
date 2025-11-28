
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
