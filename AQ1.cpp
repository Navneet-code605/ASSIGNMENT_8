#include <iostream>
using namespace std;

// Define a node of the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Pre-order Traversal: Root → Left → Right
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";   //
    preorder(root->left);        // Traverse left subtree
    preorder(root->right);       // Traverse right subtree
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);         // Traverse left subtree
    cout << root->data << " ";   // Visit root
    inorder(root->right);        // Traverse right subtree
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);      
    postorder(root->right);      // Traverse right subtree
    cout << root->data << " ";   // Visit root
}

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Pre-order Traversal: ";
    preorder(root);
    cout << endl;

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Post-order Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}