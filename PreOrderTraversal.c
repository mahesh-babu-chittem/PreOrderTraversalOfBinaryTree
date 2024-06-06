#include <stdlib.h>

struct treeNode {
    int val;
    struct treeNode *left;
    struct treeNode *right;
};

void preorder(struct treeNode* root, int* result, int* index) {
    if (root == NULL)
        return;
    
    // Store the current node's value
    result[*index] = root->val;
    (*index)++;
    
    // Recursively traverse left subtree
    preorder(root->left, result, index);
    
    // Recursively traverse right subtree
    preorder(root->right, result, index);
}

int* preorderTraversal(struct treeNode* root, int* returnSize) {
    // Count the number of nodes in the tree
    int count = 0;
    void countNodes(struct treeNode* node) {
        if (node == NULL)
            return;
        count++;
        countNodes(node->left);
        countNodes(node->right);
    }
    countNodes(root);
    
    // Allocate memory for the result array
    int* result = (int*)malloc(count * sizeof(int));
    
    // Perform preorder traversal and store values in result array
    int index = 0;
    preorder(root, result, &index);
    
    // Set the return size
    *returnSize = count;
    
    return result;
}
