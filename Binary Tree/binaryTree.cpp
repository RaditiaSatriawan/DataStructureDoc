#include <iostream>

using namespace std;

// Class to represent a node in the binary tree
class Node {
    public:
        int data;

        Node* left;
        Node* right;

        Node(){
            left = right = NULL;
        }
};

// Class to represent the binary tree
class BinaryTree {
    public:
        Node *root;

        // Constructor
        BinaryTree() {
            root = NULL;
        }

        // Recursive function to insert a node into the binary tree
        Node* insertRecursive(Node* currentRoot, int newData) {
            if (currentRoot == NULL) {
                Node *newNode = new Node();
                newNode->data = newData;
                return newNode;
            }

            if (newData < currentRoot->data) {
                currentRoot->left = insertRecursive(currentRoot->left, newData);
            } else if (newData > currentRoot->data) {
                currentRoot->right = insertRecursive(currentRoot->right, newData);
            }

            return currentRoot;
        }

        // Function to initialize that the currentRoot = Root
        void insert(int newData){
            root = insertRecursive(root, newData);
        }

        // Recursive function to do pre order recursive
        Node* preOrderRecursive(Node *currentRoot){
            if(currentRoot != NULL){
                cout << currentRoot->data << " ";
                preOrderRecursive(currentRoot->left);
                preOrderRecursive(currentRoot->right);
            }
        }

        // Function to initialize the root is current root
        void preOrderTraversal(){
            preOrderRecursive(root);
            cout << endl;
        }

        // Function to perform inorder traversal of the binary tree
        Node* inOrderRecursive(Node* node) {
            if (node != NULL) {
                inOrderRecursive(node->left);
                cout << node->data << " ";
                inOrderRecursive(node->right);
            }
        }

        // Function to perform inorder traversal of the binary tree (wrapper function)
        void inOrderTraversal() {
            inOrderRecursive(root);
            cout << endl;
        }

        // Recursive function to do post order recursive
        Node* postOrderRecursive(Node *currentNode){
            if(currentNode != NULL){
                postOrderRecursive(currentNode->left);
                postOrderRecursive(currentNode->right);
                cout << currentNode->data << " ";
            }
        }

        // Function to perform post order traversal of the binary tree (wrapper function)
        void postOrderTraversal(){
            postOrderRecursive(root);
            cout << endl;
        }
};

int main() {
    BinaryTree *bin1 = new BinaryTree;
    
    bin1->insert(6);
    bin1->insert(7);
    bin1->insert(4);
    bin1->insert(5);
    bin1->insert(8);
    bin1->insert(3);

    bin1->preOrderTraversal();
    bin1->inOrderTraversal();
    bin1->postOrderTraversal();


    return 0;
}
