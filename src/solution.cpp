#include"../inc/solution.hpp"


TreeNode* Solution::buildTree(std::vector<int>& preorder, std::vector<int>& inorder)
{
    // constructing an unordered map of the inorder vector elements permits fast searches on line 21
    std::unordered_map<int,int> inorderMap;
    for(int i{0}; i<inorder.size(); ++i){ inorderMap[inorder[i]] = i; }  // each element of inorder is mapped to its vector index

    return RecursiveTreeBuilder(preorder, inorder, 0, inorder.size()-1, inorderMap);
}

TreeNode* Solution::RecursiveTreeBuilder(std::vector<int>& preorder, std::vector<int>& inorder, 
                                        int subtreeStartIdx, int subtreeEndIdx, std::unordered_map<int,int>& inorderMap)
{
    static int preorderIdx{0};  // iterate over preorder vector, each element treated as root of its own tree; static keyword ensures recursive calls don't reset
    TreeNode* node = new TreeNode(preorder[preorderIdx++]);  // construct a node, node->left/right default to nullptr

    if(subtreeStartIdx == subtreeEndIdx){ return node; }  // node has no children (is the root of an empty tree) --> return node

    int divisionIdx = inorderMap[node->val];  // index of current value in inorder acts as a divider between elements belonging to its left and right subtrees
    node->left = RecursiveTreeBuilder(preorder, inorder, subtreeStartIdx, divisionIdx-1, inorderMap);  // left subtree of current node
    node->right = RecursiveTreeBuilder(preorder, inorder, divisionIdx+1, subtreeEndIdx, inorderMap);  // right subtree of current node

    return node;  // return root of the constructed tree
}