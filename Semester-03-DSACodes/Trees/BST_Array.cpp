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
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

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

    int arr[] = {50,30,70,20,40,60,80}; //initializing Array too

    for(int i=0;i<7;i++)
        root = insert(root, arr[i]);

    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;

    int key = 60;
    if(search(root,key))
        cout<<"Value Found"<<endl;
    else
        cout<<"Value Not Found"<<endl;
    root = deleteNode(root,30);
    cout<<"After Deletion: ";
    inorder(root);

    return 0;
}