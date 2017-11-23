// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BinaryTree.h"

//
class BinaryTree
{
public:
	BinaryTree(TreeNode * _root = nullptr)
	{
		root = _root;
	}

	void FreeTree(TreeNode * _root)
	{
		FreeTree(_root->left);
		FreeTree(_root->right);
		if (_root)
		{
			delete _root;
		}
	}

	bool AddLeftNode(TreeNode * _root, TreeNode * node)
	{
		if (PreOrderFind(root, _root))
		{
			if (_root->left == nullptr)
			{
				_root->left = node;
				return true;
			}
		}

		return false;
	}

	TreeNode * FindNode(const TreeNode * node)
	{
		
	}

	static bool PreOrderFind(const TreeNode * _root, const TreeNode * node)
	{
		if (_root == nullptr || node == nullptr)
		{
			return false;
		}

		if (_root == node)
		{
			return true;
		}

		if (PreOrderFind(_root->left, node) || PreOrderFind(_root->right, node))
		{
			return true;
		}

		return false;
	}

private:
	TreeNode * root;
};

static void CreateBTree(TreeNode ** root)
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

static void CreateBTree(TreeNode ** root, const char *& names)
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

static void PreOrderPrint(TreeNode * root)
{
	if (root)
	{
		printf("%c", root->name);
		PreOrderPrint(root->left);
		PreOrderPrint(root->right);
	}
}

static void InOrderPrint(TreeNode * root)
{
	if (root)
	{
		InOrderPrint(root->left);
		printf("%c", root->name);
		InOrderPrint(root->right);
	}
}

static void PostOrderPrint(TreeNode * root)
{
	if (root)
	{
		PostOrderPrint(root->left);
		PostOrderPrint(root->right);
		printf("%c", root->name);
	}
}

/*
			A
		 /     \
		B	    C
	   / \     / \
	  D   F   G   I
	     /     \
		E       H
*/

/*
		   A
		/     \
	   B	   C
	  / \     / \
	 F   D   G   I
	  \       \     
       E       H
*/

int main()
{
	TreeNode * pTree1 = nullptr;
	TreeNode * pTree2 = nullptr;
	TreeNode * pTree3 = nullptr;
	TreeNode * pTree4 = nullptr;
	const char * pStr1 = "ABD##FE###CG#H##I##";
	const char * pStr2 = "ABD##FE###CG#H##I##";
	const char * pStr3 = "ABD##FE###CG#H##X##";
	const char * pStr4 = "ABF#E##D##CG#H##I##";
	CreateBTree(&pTree1, pStr1);
	CreateBTree(&pTree2, pStr2);
	CreateBTree(&pTree3, pStr3);
	CreateBTree(&pTree4, pStr4);
	printf("1v2 = %d\n", IsEqual(pTree1, pTree2));
	printf("1v3 = %d\n", IsEqual(pTree1, pTree3));
	printf("1v4 = %d\n", IsEqual(pTree1, pTree4));
	printf("1vs4 = %d\n", IsEqualSymmetric(pTree1, pTree4));
	getchar();
    return 0;
}

