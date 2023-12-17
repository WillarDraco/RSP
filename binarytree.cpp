#include <iostream>

struct node {
       int key;
       int count;
       node* parent;
       node* left;
       node* right;
};

node* search_tree(node *current, int key) {
    if (current == NULL) {
        return NULL;
    }

    if (current->key == key) {
        return current;
    }
    
    if (key < current->key) {
        return search_tree(current->left, key);
    } else {
        return search_tree(current->right, key);
    }
}

node* find_min(node* current) {
    node* min;

    if (current == NULL) {
        return NULL;
    }

    min = current;
    while (min->left != NULL) {
        min = min->left;
    }

    return min;
}

node* find_max(node* current) {
    node* max;

    if (current == NULL) {
        return NULL;
    }

    max = current;
    while (max->right != NULL) {
        max = max->right;
    }
    
    return max;
}

void traverse(node* root) {
    if (root != NULL) {
        traverse(root->left);
        std::cout << root->key << " ";
        traverse(root->right);
    }
}

node* newNode(int key) {
    node* temp = new node;
    temp->key = key;
    temp->count = 1;
    temp->left = temp->right = NULL;
    return temp;
}

node* insert(node* root, int key) {
    if (root == NULL) {
        return newNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    } else if (key == root->key) {
        root->count += 1;
    }

    return root;
}

int main(void) {
    node* root = NULL;
    root = insert(root, 50);
 
    // Inserting value 30
    insert(root, 30);
 
    // Inserting value 20
    insert(root, 20);
 
    // Inserting value 40
    insert(root, 40);
 
    // Inserting value 70
    insert(root, 70);
 
    // Inserting value 60
    insert(root, 60);
 
    // Inserting value 80
    insert(root, 80);
 
    // Print the BST
    traverse(root);
    
}