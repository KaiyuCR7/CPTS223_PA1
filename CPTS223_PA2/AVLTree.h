#ifndef __AVLTree_H
#define __AVLTree_H

#include <ostream>
#include <algorithm>
#include <exception>

#include "AVLNode.h"

using namespace std;

template <typename T>
class AVLTree
{
private:
    AVLNode<T> * _root;

public:
    AVLTree() : _root(nullptr) {}

    bool empty() {
        if(_root == nullptr) return true;
        return false;
    }

    void add(const T & newVal) {
        add(newVal, _root);
    }

    int validate() {
        AVLNode<T> *Right = _root;
        AVLNode<T> *Left = _root;
        int rcount = 0;
        int lcount = 0;
        while(Right->right != nullptr) {
            rcount++;
            Right = Right->right;
        }
        while(Left->left != nullptr) {
            lcount++;
            Left = Left->left;
        }

        if (rcount == lcount) {
            return 1;
        }
        return 0;
    }

    int contains(const T & findVal) {
        AVLNode<T> *tmp = _root;
        while(tmp != nullptr){
            if(tmp->val == findVal) return 1;
            if(tmp->val > findVal) tmp = tmp->left;
            else tmp = tmp->right;
        }
        return 0;
    }

    int height() {
        if(_root == nullptr) return -1;
        return height(_root);
    }


private:
    int height( AVLNode<T> * t ) const
    {
        return t == nullptr ? -1 : t->height;
    }

    void deleteAllFrom(AVLNode<T> * t){
        if(t == nullptr){
            return;
        }
        deleteAllFrom(t->left);
        deleteAllFrom(t->right);
        delete t;
    }

    int countNodes(AVLNode<T> * & t){
        if(t == nullptr){
            return 0;
        }
        else{
            return countNodes(t->left) + countNodes(t->right) + 1;
        }
    }


    AVLNode<T>* add(const T & newVal, AVLNode<T> * & node) {
        if(node == nullptr){
            node = new AVLNode<T>(newVal);
            node->height = 0;

        }
        else if (newVal < node->val) {
            node->left = add(newVal, node->left);
            if (height(node->left) - height(node->right) == 2) {
                if (newVal < node->left->val) {
                    node = rightRotate(node);
                }
                else {
                    node = doubleRightRotate(node);
                }
            }
        }
        else if(newVal > node->val){
            node->right = add(newVal, node->right);
            if (height(node->right) - height(node->left) == 2) {
                if (newVal > node->right->val) {
                    node = leftRotate(node);
                }
                else {
                    node = doubleLeftRotate(node);
                }
            }
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        return node;
    }

    AVLNode<T> * rightRotate(AVLNode<T> * & root){
        AVLNode<T> * node1 = root->left;
        root->left = node1->right;
        node1->right = root;
        root->height = max(height(root->left), height(root->right)) +1;
        node1->height = max(height(node1->left), (root->height)) +1;
        return node1;
    }

    AVLNode<T> * leftRotate(AVLNode<T> * & root){
        AVLNode<T> * node1 = root->right;
        root->right = node1->left;
        node1->left = root;
        root->height = max(height(root->right), height(root->left)) +1;
        node1->height = max(height(node1->right), (root->height)) +1;
        return node1;
    }

    AVLNode<T> * doubleRightRotate(AVLNode<T> * & node){
        node->left = leftRotate(node->left);
        return rightRotate(node);
        
    }

    AVLNode<T> * doubleLeftRotate(AVLNode<T> * & node){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
};




#endif
