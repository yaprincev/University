#include<iostream>
#include "Tree.h"
#include<string>
using namespace std;
TreeNode* Tree::addnode(int x, TreeNode* tree)
{
	if (tree == nullptr) {
		tree = new TreeNode();
		tree->value = x;
		tree->left = nullptr;
		tree->right = nullptr;
	}
	else if (x < tree->value)
		tree->left = addnode(x, tree->left);
	else
		tree->right = addnode(x, tree->right);
	return tree;
}

void Tree::treePrintPostfix(TreeNode* tree)
{
	if (tree != nullptr) {
		treePrintPostfix(tree->left);
		treePrintPostfix(tree->right);
		std::cout << tree->value;
	}
}

void Tree::treeInfixToString(TreeNode* tree)
{
	if (tree != nullptr) {
		treeInfixToString(tree->left);
		str = str + to_string(tree->value) + " ";
		treeInfixToString(tree->right);
	}
	
}


void Tree::treePrintInfix(TreeNode* tree)
{
	if (tree != nullptr) {
		treePrintInfix(tree->left);
		std::cout << tree->value;
		treePrintInfix(tree->right);
	}
}

void Tree::treePrintPrefix(TreeNode* tree)
{
	if (tree != nullptr) {
		std::cout << tree->value;
		treePrintPrefix(tree->left);
		treePrintPrefix(tree->right);
	}
}

void Tree::printCool(TreeNode* tree, int lvl)
{
	if (tree == nullptr)
		return;
	else {
		printCool(tree->left, ++lvl);
		for (int i = 0; i < lvl; i++) {
			std::cout << "    ";
			std::cout << tree->value << "\n";
			lvl--;
		}
	}
	printCool(tree->right, ++lvl);
}

void Tree::add(int x)
{
	root = addnode(x, root);
}

void Tree::freemem(TreeNode* tree)
{
	if (tree != nullptr) {
		freemem(tree->left);
		freemem(tree->right);
		delete tree;
	}
}

void Tree::print(PrintType type)
{
	switch (type) {
	case Postfix:
		treePrintPostfix(root);
		break;
	case Infix:
		treePrintInfix(root);
		break;
	case Prefix:
		treePrintPrefix(root);
		break;
	case Cool:
		std::cout << "Cool\n";
		printCool(root, 0);
		std::cout << "\n";
	default:
		break;
	}
}
int main() {
	string str;
	Tree tree(3);
	tree.add(5);
	tree.add(6);
	tree.add(6);
	tree.add(7);
	tree.add(8);
	tree.add(3);
	tree.add(3);
	tree.treeInfixToString(tree.root); 
	cout << tree.str << endl;



	int num, n = (tree.str.length() + 1) / 2;
	int* arr = new int[n];
	
	for (int i = 0; i < n; i++) {
		arr[i] = stoi(tree.str.substr(0, 1));
		tree.str.erase(0, 2);
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	int temp = 0, tempCount, count = 1;
	int popular = arr[0];


	for (int i = 0; i < n; i++) {
		
		tempCount = 0;
		temp = arr[i];
		tempCount++;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] == temp) {
				tempCount++;
				if (tempCount > count) {
					popular = temp;
					count = tempCount;
				}
			}
		}
	}
	cout << endl;
	cout << popular;
	return 0;
}