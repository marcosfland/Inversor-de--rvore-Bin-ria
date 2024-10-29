#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore binária
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Função para criar um novo nó
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para inverter a árvore binária
void invertTree(struct Node* root) {
    if (root == NULL) {
        return;
    }

    // Troca os nós filhos
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Inverte as subárvores esquerda e direita
    invertTree(root->left);
    invertTree(root->right);
}

// Função para imprimir a árvore em ordem (in-order)
void printInOrder(struct Node* node) {
    if (node == NULL) {
        return;
    }

    printInOrder(node->left);
    printf("%d ", node->data);
    printInOrder(node->right);
}

int main() {
    // Criação de uma árvore binária de exemplo
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    printf("Árvore original: ");
    printInOrder(root);
    printf("\n");

    // Inversão da árvore binária
    invertTree(root);

    printf("Árvore invertida: ");
    printInOrder(root);
    printf("\n");

    return 0;
}