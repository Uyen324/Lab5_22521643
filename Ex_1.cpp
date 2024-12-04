#include <iostream>
using namespace std;

// Node structure for the binary tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    // Helper function to insert a value into the tree
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function to find the minimum value node in the tree
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Helper function to delete a value from the tree
    TreeNode* deleteNode(TreeNode* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->value) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->value) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with one child or no child
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor
            TreeNode* temp = findMin(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    // Helper function to search for a value in the tree
    bool search(TreeNode* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->value == value) {
            return true;
        } else if (value < node->value) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Helper function for in-order traversal
    void inOrder(TreeNode* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout << node->value << " ";
            inOrder(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Insert a value into the binary tree
    void insert(int value) {
        root = insert(root, value);
    }

    // Delete a value from the binary tree
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Search for a value in the binary tree
    bool search(int value) {
        return search(root, value);
    }

    // Display the tree (in-order traversal)
    void display() {
        inOrder(root);
        cout << endl;
    }
};

// Main function for testing
int main() {
    BinaryTree tree;

    // Insert values
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "In-order traversal: ";
    tree.display();

    // Search for values
    cout << "Search 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search 90: " << (tree.search(90) ? "Found" : "Not Found") << endl;

    // Delete a value
    cout << "Deleting 50..." << endl;
    tree.deleteValue(50);

    cout << "In-order traversal after deletion: ";
    tree.display();

    return 0;
}
