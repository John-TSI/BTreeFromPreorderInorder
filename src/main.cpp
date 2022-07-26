// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include<iostream>
#include"../inc/solution.hpp"


void PrintPreorder(TreeNode* node)
{
    if(!node){ return; }
    std::cout << node->val << ' ';
	PrintPreorder(node->left);
    PrintPreorder(node->right);
}

void PrintInorder(TreeNode* node)
{
    if(!node){ return; }
    PrintInorder(node->left);
    std::cout << node->val << ' ';
    PrintInorder(node->right);
}

int main()
{
	std::vector<int> preorder{3,9,20,15,7}, inorder{9,3,15,20,7};
	Solution sol;
	TreeNode* root = sol.buildTree(preorder,inorder);

	// verify constructed tree by recovering the two traversals
	PrintPreorder(root);
	std::cout << '\n';
	PrintInorder(root);
	return 0;
}

/*
preorder traversal of a binary tree: 	1) visit the current node
                                        2) recursively visit the current node's left subtree
                                		3) recursively visit the current node's right subtree

inorder traversal of a binary tree: 	1) recursively visit the current node's left subtree
                                        2) visit the current node
                                		3) recursively visit the current node's right subtree
*/