#include <iostream>
#include <algorithm> // for max, min
using namespace std;

// Node definition
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// (a) Insert an element (no duplicates allowed)
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    // If val == root->data → do nothing (no duplicates allowed)
    return root;
}

// Helper: Find minimum node (used in deletion)
Node* findMin(Node* root) {
    while (root->left != nullptr) root = root->left;
    return root;
}

// (b) Delete an existing element
Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            // Two children: replace with inorder successor
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// (c) Maximum depth of BST
int maxDepth(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// (d) Minimum depth of BST
int minDepth(Node* root) {
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    if (root->left == nullptr) return 1 + minDepth(root->right);
    if (root->right == nullptr) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// In-order traversal (for testing)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    // Insert elements
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int v : values) root = insert(root, v);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    // Delete element
    root = deleteNode(root, 10);
    cout << "After deleting 10, In-order Traversal: ";
    inorder(root);
    cout << endl;

    // Depths
    cout << "Maximum Depth of BST: " << maxDepth(root) << endl;
    cout << "Minimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}
