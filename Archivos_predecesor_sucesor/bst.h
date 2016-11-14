#ifndef BST
#define BST
#include <iostream>
#include <vector>

class BinarySearchTree
{
private:
    struct tree_node
    {
       tree_node* left;
       tree_node* right;
       tree_node* parent;
       int data;
    };
    tree_node* root;
    tree_node* min(tree_node* nodo);
    tree_node* max(tree_node* nodo);
    tree_node* primer_ancestro_derecho(tree_node* nodo);
    tree_node* primer_ancestro_izquierdo(tree_node* nodo);
    tree_node* busqueda(int data);
    tree_node* insertar(int data);
    int size;
    bool isEmpty();

public:
    BinarySearchTree(std::vector<int> datos, int n);
    void imprimir(tree_node* nodo);
    void imprimir();
    int sucesor(int data);
    int predecesor(int data);
    long int size_bytes();
};
#endif
