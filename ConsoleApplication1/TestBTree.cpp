#include "stdafx.h"
#include "TestBTree.h"
#include "BinaryTree.h"

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

void TestBinaryTree()
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
}
