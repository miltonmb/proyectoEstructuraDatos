#include "object.h"
#include "varraylist.h"
#include "treeNode.h"
#include <sstream>
#include <string>
#include <iostream>
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define BLUE    "\033[34m"      /* Blue */
#define CLEAR "\033[2J"  // clear screen escape code 
using namespace std;
/*Arbol compuesto por una VArrayList, una lista de tamaño variable*/
TreeNode::TreeNode(Object* data, string label, TreeNode* parent, int depth):data(data), label(label), parent(parent), depth(depth){
    children = new VArrayList(5);
}
TreeNode::TreeNode(Object* data, string label):data(data), label(label), parent(NULL), index(0), depth(0){
    children = new VArrayList(5);
}
TreeNode::TreeNode(string label):data(NULL), label(label), parent(NULL), index(0), depth(0){
    children = new VArrayList(5); 
}
TreeNode::TreeNode(string label, TreeNode* parent):data(NULL), label(label), parent(parent), index(0), depth(0){
    children = new VArrayList(5); 
}

Object* TreeNode::getData() {
    return this->data; 
}
/*Devuelve el hijo, que en este caso seria una lista*/
VArrayList* TreeNode::getChildren() {
    return this->children;    
}
/*Devuelve el hijo izquierdo de un nodo*/
TreeNode* TreeNode::getLeftSon() {
    if (this->children->size() == 0) {
        return NULL;
    }
    return static_cast<TreeNode*> (this->children->get(0));
}
/*Devuelve el hijo derecho de un nodo*/
TreeNode* TreeNode::getRigthSon() {
    if (this->children->size() == 0) {
        return NULL;
    }
    return static_cast<TreeNode*> (this->children->last());

}
/*Devuelve el hermano derecho de un nodo*/
TreeNode* TreeNode::getRigthBrother() {
    int rightIndex = this->index + 1;
    if (rightIndex > this->parent->getChildCount()) {
        return NULL;
    }
    return static_cast<TreeNode*> (this->parent->children->get(rightIndex));
}   
/*Devuelve el hermano izquierdo de un nodo*/  
TreeNode* TreeNode::getLeftBrother() {
    int rightIndex = this->index - 1;
    if (rightIndex < 0) {
        return NULL;
    }
    return static_cast<TreeNode*> (this->parent->children->get(rightIndex));
}
/*Se agrega un hijo a un nodo*/
void TreeNode::addSon(TreeNode* newSon) {
    newSon->setIndex(this->getChildCount());
    newSon->setParent(this);
    newSon->depth = this->depth + 1;
    this->children->insert(newSon, this->children->size());
}
/*Devuelve la cantidad de hijos*/
int TreeNode::getChildCount() {
    return this->children->size();
}
/*Devuelve el indice del nodo*/
int TreeNode::getIndex() {
    return this->index;
}

/*Devuelve la profundidad del nodo*/
int TreeNode::getDepth() {
    if (this->parent == NULL)
        return 0;
    return this->parent->getDepth() + 1;
}

/*Setea el indice al nodo*/
void TreeNode::setIndex(int index) {
    this->index = index;
}

/*Setea el padre al nodo*/
void TreeNode::setParent(TreeNode* parent) {
    this->parent = parent;
}
/*Obtiene un hijo del nodo*/
TreeNode* TreeNode::getSon(int pos) {
    return static_cast<TreeNode*> (this->children->get(pos));
}


string TreeNode::toString(){
    stringstream ss;
    TreeNode* temp = this->parent;
    for (int i = 0; i < this->getDepth(); i++) {
        if (i == this->getDepth() - 1) {
            ss <<GREEN<< "|====="<<RESET;
        } else {
            ss <<GREEN <<"|\t"<<RESET;
        }
    }

    ss <<RED<<"> "<<RESET << this->data->toString()<< endl;
    for (int i = 0; i < this->getChildCount(); i++) {
        ss << this->getSon(i)->toString();
    }
    return ss.str();
}