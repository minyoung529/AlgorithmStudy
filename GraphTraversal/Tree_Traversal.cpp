#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
	char value, left, right;
};

unordered_map<char, Node> nodes;

void preorder(char v);
void inorder(char v);
void postorder(char v);

int main()
{
	int len;
	nodes['A'] = { 'A', ' ', ' ' }; // root
	cin >> len;

	for (int i = 0; i < len; i++)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		if (left != '.')
		{
			nodes[parent].left = left;
		}

		if (right != '.')
		{
			nodes[parent].right = right;
		}
	}

	preorder('A'); cout << '\n';
	inorder('A'); cout << '\n';
	postorder('A'); cout << '\n';
}

void preorder(char v)
{
	cout << v;

	if (isalpha(nodes[v].left))
		preorder(nodes[v].left);

	if (isalpha(nodes[v].right))
		preorder(nodes[v].right);
}

void inorder(char v)
{
	if (isalpha(nodes[v].left))
		inorder(nodes[v].left);

	cout << v;

	if (isalpha(nodes[v].right))
		inorder(nodes[v].right);
}

void postorder(char v)
{
	if (isalpha(nodes[v].left))
		postorder(nodes[v].left);

	if (isalpha(nodes[v].right))
		postorder(nodes[v].right);

	cout << v;
}
