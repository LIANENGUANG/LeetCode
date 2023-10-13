#include "predefs.h"

// 二叉树节点的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//二叉搜索树（Binary Search Tree，简称BST）是一种特殊的二叉树数据结构，它满足以下性质：
//每个节点的键值都大于或等于其左子树中任意节点的键值。
//每个节点的键值都小于或等于其右子树中任意节点的键值。
//左右子树也分别为二叉搜索树。

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(const vector<int>& nums, int left, int right) {
        // 基本情况：如果左>右，则树为空 --- 递归终止条件
        if (left > right) {
            return nullptr;
        }

        // 找到中间索引
        int mid = left + (right - left) / 2;

        // 创建一个具有中间值的新节点
        TreeNode* node = new TreeNode(nums[mid]);

        // 递归构建左子树和右子树
        // 数组中间点左侧全部都在左子树
        // 数组中间点右侧全都都在右子树
        node->left = buildBST(nums, left, mid - 1);
        node->right = buildBST(nums, mid + 1, right);

        return node;
    }
};
