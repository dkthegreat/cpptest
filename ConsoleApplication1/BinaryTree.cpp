#include "stdafx.h"
#include "BinaryTree.h"

//
void CreateBTree(TreeNode ** root)
{
	printf("please input root value:\n");
	char c = getchar();
	getchar(); // \n
	TreeNode * node = new TreeNode;
	node->left = nullptr;
	node->right = nullptr;
	node->name = c;
	*root = node;
	printf("create left for %c ? (y/n)\n", node->name);
	c = getchar();
	getchar(); // \n
	if (c == 'y')
	{
		CreateBTree(&node->left);
	}

	printf("create right for %c ? (y/n)\n", node->name);
	c = getchar();
	getchar(); // \n
	if (c == 'y')
	{
		CreateBTree(&node->right);
	}
}

//
void CreateBTree(TreeNode ** root, const char *& names)
{
	if (*names != '\0')
	{
		TreeNode * node = new TreeNode;
		node->left = nullptr;
		node->right = nullptr;
		node->name = names[0];
		*root = node;
		++names;
		if (names[0] != '#')
		{
			CreateBTree(&node->left, names);
		}
		else
		{
			++names;
		}

		if (names[0] != '#')
		{
			CreateBTree(&node->right, names);
		}
		else
		{
			++names;
		}
	}
}

//
void PreOrderPrint(TreeNode * root)
{
	if (root)
	{
		printf("%c", root->name);
		PreOrderPrint(root->left);
		PreOrderPrint(root->right);
	}
}

//
void InOrderPrint(TreeNode * root)
{
	if (root)
	{
		InOrderPrint(root->left);
		printf("%c", root->name);
		InOrderPrint(root->right);
	}
}

//
void PostOrderPrint(TreeNode * root)
{
	if (root)
	{
		PostOrderPrint(root->left);
		PostOrderPrint(root->right);
		printf("%c", root->name);
	}
}

//
bool IsEqual(TreeNode * t1, TreeNode * t2)
{
	if (t1 == nullptr && t2 == nullptr)
	{
		return true;
	}

	if (t1 == nullptr || t2 == nullptr)
	{
		return false;
	}

	if (t1->name != t2->name)
	{
		return false;
	}

	return IsEqual(t1->left, t2->left) && IsEqual(t1->right, t2->right);
}

//
bool IsEqualSymmetric(TreeNode * t1, TreeNode * t2)
{
	if (t1 == nullptr && t2 == nullptr)
	{
		return true;
	}

	if (t1 == nullptr || t2 == nullptr)
	{
		return false;
	}

	if (t1->name != t2->name)
	{
		return false;
	}

	return (IsEqualSymmetric(t1->left, t2->left) && IsEqualSymmetric(t1->right, t2->right))
		|| (IsEqualSymmetric(t1->left, t2->right) && IsEqualSymmetric(t1->right, t2->left));
}
