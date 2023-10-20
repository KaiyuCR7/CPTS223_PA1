
#ifndef __AVLNODE_H
#define __AVLNODE_H

template <typename T>
class AVLNode
{
    public:
        T val;
        AVLNode * left;
        AVLNode * right;
        int height;

        static int nodeCount;

    AVLNode( const T & newVal, 
                AVLNode * newLeft, 
                AVLNode * newRight, 
                int h = 0 ) 
                    : val( newVal ), left(newLeft), right(newRight), height(h) 
                    {
                        nodeCount++;
                    }

    AVLNode( const T & newVal )
                    : val( newVal ), left(nullptr), right(nullptr), height(0)
                    {
                        nodeCount++;
                    }
    ~AVLNode()
    {
        nodeCount--;    
    }
};

template <typename T>
int AVLNode<T>::nodeCount = 0;

#endif
