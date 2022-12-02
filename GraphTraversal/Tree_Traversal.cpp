#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
	char value;
	Node* left;
	Node* right;
};

void preorder();
void inorder();
void postorder();

int main()
{
	int len;
	unordered_map<char, Node> nodes;
	nodes.insert({ 'A', {'A', nullptr, nullptr} }); // root
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		char parent, val1, val2;
		Node newNode;
		cin >> parent >> val1 >> val2;

		if (val1 != '.')
		{
			newNode = { val1, nullptr, nullptr };
			nodes[parent].left = &newNode;
		}

		if (val2 != '.')
		{
			newNode = { val2, nullptr, nullptr };
			nodes[parent].right = &newNode;
		}
	}

	preorder();
	inorder();
	postorder();
}

void preorder()
{

}

void inorder()
{
}

void postorder()
{
}
