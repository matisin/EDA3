 #include "bst.h"
#include <iostream>
#include <vector>
using namespace std;

int BinarySearchTree::sucesor(int data)
{
    tree_node* dato = busqueda(data);
    tree_node* sucesor = NULL;
    if(dato)
    {
        if(dato->right)
        {
            sucesor = min(dato->right);
        }else
        {
            sucesor = primer_ancestro_izquierdo(dato);
        }
    }
    if(sucesor)
    {
        return sucesor->data;
    }else
    {
        return -1;
    }
}

int BinarySearchTree::predecesor(int data)
{
    tree_node* dato = busqueda(data);
    tree_node* predecesor = NULL;
    if(dato)
    {
        if(dato->left)
        {
            predecesor = max(dato->left);
        }else
        {
            predecesor = primer_ancestro_derecho(dato);
        }
    }
    if(predecesor)
    {
        return predecesor->data;
    }else
    {
        return -1;
    }
}

BinarySearchTree::tree_node* BinarySearchTree::min(tree_node* nodo)
{
    tree_node* curr;
    curr = nodo;
    while(curr->left)
    {
        curr = curr->left;
    }
    return curr;
}
BinarySearchTree::tree_node* BinarySearchTree::max(tree_node* nodo)
{
    tree_node* curr;
    curr = nodo;
    while(curr->right)
    {
        curr = curr->right;
    }
    return curr;
}
BinarySearchTree::tree_node* BinarySearchTree::primer_ancestro_derecho(tree_node* nodo)
{
    tree_node* curr;
    tree_node* curr_parent = NULL;
    curr = nodo;
    while(curr->parent)
    {
        curr_parent = curr->parent;
        if(curr_parent->right == curr){
            break;
        }
        curr = curr_parent;
        if(curr == root){
            curr_parent;
        }
    }
    return curr_parent;
}

BinarySearchTree::tree_node* BinarySearchTree::primer_ancestro_izquierdo(tree_node* nodo)
{
    tree_node* curr;
    tree_node* curr_parent;
    curr = nodo;
    while(curr->parent)
    {
        curr_parent = curr->parent;
        if(curr_parent->left == curr){
            break;
        }
        curr = curr_parent;
        if(curr == root){
            curr_parent = NULL;
        }
    }
    return curr_parent;
}

BinarySearchTree::BinarySearchTree(vector<int> datos, int n)
{
    root = NULL;
    for(int i = 0 ; i < n ; i++){
        BinarySearchTree::insertar(datos[i]);
    }
    size = n;
}

bool BinarySearchTree::isEmpty()
{
    return root==NULL;
}

BinarySearchTree::tree_node* BinarySearchTree::busqueda(int data)
{
    tree_node* curr;
    curr = root;
    while(curr)    {
        if(data == curr->data){
            return curr;
        }
        else if(data < curr->data){
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return curr;
}

BinarySearchTree::tree_node* BinarySearchTree::insertar(int data)
{
    tree_node* child = new tree_node;
    tree_node* parent;
    child->data = data;
    child->left = NULL;
    child->right = NULL;
    parent = NULL;

    // si esta vacio
    if(isEmpty()){
        root = child;
        root->parent = NULL;
    }
    else
    {
        //nodo actual, partimos con la raiz
        tree_node* curr;
        curr = root;
        while(curr)
        {
            parent = curr;
            if(child->data > curr->data){
                curr = curr->right;
            }
            else if(child->data < curr->data){
                curr = curr->left;
            }else{
                return curr;
            }
        }
        curr = parent;
        if(child->data < parent->data)parent->left = child;
        else parent->right = child;
        child->parent = parent;
    }
    return child;
}

void BinarySearchTree::imprimir(tree_node* nodo)
{
    if(nodo != NULL){
        imprimir(nodo->left);
        cout << nodo->data << endl;
        imprimir(nodo->right);
    }

}

void BinarySearchTree::imprimir()
{
    if(root != NULL){
        imprimir(root->left);
        cout << root->data << endl;
        imprimir(root->right);
    }

}

long int BinarySearchTree::size_bytes()
{
    return size * (sizeof(tree_node*) + sizeof(bool) + sizeof(int));
}
