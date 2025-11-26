#include <iostream>
#include <climits>
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

// Utility function to check BST property
bool isBSTUtil(Node* root, int minVal, int maxVal) {
    if (root == nullptr) return true;

    if (root->data <= minVal || root->data >= maxVal) return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

// Main function to check if tree is BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {

    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->left = new Node(25);
    root->right->right = new Node(35);

    if (isBST(root))
        cout << "The given tree is a BST." << endl;
    else
        cout << "The given tree is NOT a BST." << endl;

    return 0;
}
