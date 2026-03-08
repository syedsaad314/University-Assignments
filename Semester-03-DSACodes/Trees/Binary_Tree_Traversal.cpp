#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int val)
{
    Node* newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node*& root, int val)
{
    if(root == NULL)
    {
        root = createNode(val);
        return;
    }

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while(front < rear)
    {
        Node* temp = queue[front++];

        if(temp->left == NULL)
        {
            temp->left = createNode(val);
            return;
        }
        else
            queue[rear++] = temp->left;

        if(temp->right == NULL)
        {
            temp->right = createNode(val);
            return;
        }
        else
            queue[rear++] = temp->right;
    }
}

void inorder(Node* root)
{
    if(root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root)
{
    if(root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root)
{
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{


    Node* root = NULL;

    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cout << "Enter node " << i+1 << ": ";
        cin >> val;
        insert(root, val);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}