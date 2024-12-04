#include <iostream>
#include <algorithm>
using namespace std;

// Define the structure of a node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Define the Binary Search Tree class
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the BST
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) return new TreeNode(value);
        if (value < node->val)
            node->left = insert(node->left, value);
        else if (value > node->val)
            node->right = insert(node->right, value);
        return node;
    }

    // Helper function to find the minimum value in a subtree
    int findMin(TreeNode* node) {
        if (node == nullptr) throw runtime_error("Tree is empty");
        while (node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }

    // Helper function to find the maximum value in a subtree
    int findMax(TreeNode* node) {
        if (node == nullptr) throw runtime_error("Tree is empty");
        while (node->right != nullptr) {
            node = node->right;
        }
        return node->val;
    }

    // Helper function to check if the tree is balanced
    bool isBalanced(TreeNode* node) {
        if (node == nullptr) return true;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
    }

    // Helper function to calculate the height of the tree
    int calculateHeight(TreeNode* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Public method to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Public method to find the minimum value
    int findMin() {
        return findMin(root);
    }

    // Public method to find the maximum value
    int findMax() {
        return findMax(root);
    }

    // Public method to check if the tree is balanced
    bool isBalanced() {
        return isBalanced(root);
    }

    // Public method to calculate the height of the tree
    int calculateHeight() {
        return calculateHeight(root);
    }

    // Public method for in-order traversal (to verify the BST structure)
    void inOrderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->val << " ";
        inOrderTraversal(node->right);
    }

    void displayInOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

// Main function to test the BinarySearchTree class
int main() {
    BinarySearchTree bst;

    // Insert values into the BST
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(13);
    bst.insert(17);

    // Display the BST in in-order (should be sorted)
    cout << "In-order Traversal: ";
    bst.displayInOrder();

    // Find minimum and maximum values
    cout << "Minimum Value: " << bst.findMin() << endl;
    cout << "Maximum Value: " << bst.findMax() << endl;

    // Check if the tree is balanced
    cout << "Is the tree balanced? " << (bst.isBalanced() ? "Yes" : "No") << endl;

    // Calculate the height of the tree
    cout << "Height of the Tree: " << bst.calculateHeight() << endl;

    return 0;
}
