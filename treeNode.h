#pragma once

#include "object.h"
#include "varraylist.h"
#include <string>

class TreeNode : public Object{
    private:
        Object* data;
        string label;
        TreeNode* parent;
        int depth, index;
        VArrayList* children;

    public:
        TreeNode(string, TreeNode*);
        TreeNode(string);
        TreeNode(Object*,string);
        TreeNode(Object*, string, TreeNode*, int);
        int getDepth();
        void setDepth(int);
        Object* getData();
        void setValue(Object*);
        TreeNode* getParent();
        void setParent(TreeNode*);
        VArrayList* getChildren();
        void setChildren(VArrayList);
        TreeNode* getLeftSon();
        TreeNode* getRigthSon();
        TreeNode* getRigthBrother();     
        TreeNode* getLeftBrother();
        void addSon(TreeNode*);
        void setIndex(int);
        int getChildCount();
        int getIndex();
        TreeNode* getSon(int);
        string toString();
};