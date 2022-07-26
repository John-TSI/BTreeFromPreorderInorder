#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include<vector>
#include<unordered_map>
#include"node.hpp"


class Solution
{
    public:
        TreeNode* buildTree(std::vector<int>&, std::vector<int>&);
        TreeNode* RecursiveTreeBuilder(std::vector<int>&, std::vector<int>&, int, int, std::unordered_map<int,int>&);
};

#endif // SOLUTION_HPP