
#include "object.h"
#include "tree.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
Tree::Tree(){

}

Tree::Tree(TreeNode* root) {
	this->root = root;
}

TreeNode* Tree::getRoot() {
	return this->root;
}
void Tree::setRoot(TreeNode* root) {
	this->root = root;
}


string Tree::toString()const{
	stringstream ss;	
	if (this->root != NULL) {
		ss << this->root->toString() << endl;
		// for (int i = 0; i < this->root->getChildCount(); i++) {
		// 	ss << this->root->getSon(i)->toString() << endl;
		// }
	}

	return ss.str();
}