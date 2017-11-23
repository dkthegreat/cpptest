#include "stdafx.h"
#include "BinaryTree.h"

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
