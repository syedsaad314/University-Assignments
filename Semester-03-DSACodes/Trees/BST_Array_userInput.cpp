#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val) {
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int val) {
    if(root == NULL)
        return createNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    return root;
}

Node* search(Node* root, int key) {
    if(root == NULL)
        return NULL;

    if(root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Node* minValue(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if(root == NULL)
        return root;
    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if(root->left == NULL)
            return root->right;

        else if(root->right == NULL)
            return root->left;

        Node* temp = minValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    int n, val;
    cout << "Enter number of elements to insert: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "Enter element " << i+1 << ": ";
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder Traversal (Sorted Order): ";
    inorder(root);
    cout << endl;

    int key;
    cout << "\nEnter value to search: ";
    cin >> key;
    
    Node* result = search(root, key);
    if(result != NULL)
        cout << "Element " << key << " found in the BST.\n";
    else
        cout << "Element " << key << " not found in the BST.\n";

    cout << "\nEnter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);
    cout << "\nBST after deletion (Inorder Traversal): ";
    inorder(root);
    cout << endl;

    return 0;
}