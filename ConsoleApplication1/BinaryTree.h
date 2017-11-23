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