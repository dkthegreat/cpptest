#pragma once

struct TreeNode
{
	TreeNode * left;
	TreeNode * right;
	char name;
};

//
bool IsEqual(TreeNode * t1, TreeNode * t2);

//
bool IsEqualSymmetric(TreeNode * t1, TreeNode * t2);

//
void CreateBTree(TreeNode ** root);

//
void CreateBTree(TreeNode ** root, const char *& names);

//
void PreOrderPrint(TreeNode * root);

//
void InOrderPrint(TreeNode * root);

//
void PostOrderPrint(TreeNode * root);

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