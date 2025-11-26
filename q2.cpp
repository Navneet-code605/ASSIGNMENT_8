#include <iostream>
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

// Insert function
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root;
}

// (a) Search Recursive
Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key) return root;
    if (key < root->data) return searchRecursive(root->left, key);
    return searchRecursive(root->right, key);
}

// (a) Search Non-Recursive
Node* searchIterative(Node* root, int key) {
    while (root != nullptr) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

// (b) Maximum element
Node* findMax(Node* root) {
    while (root && root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// (c) Minimum element
Node* findMin(Node* root) {
    while (root && root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// (d) In-order successor
Node* inorderSuccessor(Node* root, Node* target) {
    if (target->right != nullptr) {
        return findMin(target->right);
    }
    Node* succ = nullptr;
    while (root != nullptr) {
        if (target->data < root->data) {
            succ = root;
            root = root->left;
        } else if (target->data > root->data) {
            root = root->right;
        } else break;
    }
    return succ;
}

// (e) In-order predecessor
Node* inorderPredecessor(Node* root, Node* target) {
    if (target->left != nullptr) {
        return findMax(target->left);
    }
    Node* pred = nullptr;
    while (root != nullptr) {
        if (target->data > root->data) {
            pred = root;
            root = root->right;
        } else if (target->data < root->data) {
            root = root->left;
        } else break;
    }
    return pred;
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
    int values[] = {20, 10, 30, 5, 15, 25, 35};
    for (int v : values) root = insert(root, v);

    cout << "In-order Traversal: ";
    inorder(root);
    cout << endl;

    // Search
    int key = 15;
    Node* res = searchRecursive(root, key);
    cout << "Recursive Search for " << key << ": " 
         << (res ? "Found" : "Not Found") << endl;

    res = searchIterative(root, key);
    cout << "Iterative Search for " << key << ": " 
         << (res ? "Found" : "Not Found") << endl;

    // Max & Min
    cout << "Maximum element: " << findMax(root)->data << endl;
    cout << "Minimum element: " << findMin(root)->data << endl;

    // Successor & Predecessor
    Node* target = searchRecursive(root, 20);
    Node* succ = inorderSuccessor(root, target);
    Node* pred = inorderPredecessor(root, target);

    cout << "In-order Successor of " << target->data << ": " 
         << (succ ? to_string(succ->data) : "None") << endl;
    cout << "In-order Predecessor of " << target->data << ": " 
         << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}
