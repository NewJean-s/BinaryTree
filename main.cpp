#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int newData) {
    struct Node* temp;
    
    temp = (struct Node*) malloc (sizeof(struct Node));
    temp->data = newData;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

struct Node* searchNode(struct Node* root, int key) {
    //Search for a node in the tree with a value matching the given key and return its pointer.
    //If there isn't, this function will return 'NULL'.
    struct Node* temp;
    temp = NULL;
    if (root != NULL) {
        if (root->data == key) {
            temp = root;
        } else {
            temp = searchNode(root->left, key);
            if (temp == NULL) {
                temp = searchNode(root->right, key);
            }
        }
    }
    return temp;
}

void preorder(struct Node* root) {
    //root → left → right
    if (root != NULL) {
        printf("%d → ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root) {
    //left → root → right
    if (root != NULL) {
        inorder(root->left);
        printf("%d → ", root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root) {
    //left → right → root
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d → ", root->data);
    }
}

int countNode(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

void addLeft(struct Node* root, int key, int newData) {
    //Add new data to the left of the key data in the tree.
    struct Node* temp;
    struct Node* keyNode;
    
    keyNode = searchNode(root, key);
    if (keyNode != NULL) {
        temp = createNode(newData);
        keyNode->left = temp;
    } else {
        printf("Tree doesn't have %d\n", key);
    }
}

void addRight(struct Node* root, int key, int newData) {
    //Add new data to the right of the key data in the tree.
    struct Node* temp;
    struct Node* keyNode;
    
    keyNode = searchNode(root, key);
    if (keyNode != NULL) {
        temp = createNode(newData);
        keyNode->right = temp;
    } else {
        printf("Tree doesn't have %d\n", key);
    }
}

int main() {
    struct Node* root;
    struct Node* temp;
    root = NULL;
    
    root = createNode(5);
    
    addLeft(root, 5, 3);
    addLeft(root, 3, 1);
    addRight(root, 1, 2);
    addRight(root, 3, 4);
    
    addRight(root, 5, 10);
    addLeft(root, 10, 7);
    addRight(root, 10, 12);
    addLeft(root, 12, 11);
    
    printf("<Tree:%d>\n",countNode(root));
    
    printf("preoder [");
    preorder(root);
    printf("END]\n");
    
    printf("inoder [");
    inorder(root);
    printf("END]\n");

    printf("postoder [");
    postorder(root);
    printf("END]\n");
}
