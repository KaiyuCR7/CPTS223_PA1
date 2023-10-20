#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include <algorithm>

#include "AVLNode.h"
#include "AVLTree.h"
int main( int argc, char* argv[] ) {
    std::vector<int> v1{};
    std::vector<int> v2{};
    std::vector<int> v3{};
    AVLTree<int> tree1;
    AVLTree<int> tree2;
    AVLTree<int> tree3;
    int num = 1;
    int num2 = 99;
    for (int i = 0; i < 50; i++)
    {
        v1.push_back(num);
        v3.push_back(num);
        num += 2;
        v2.push_back(num2);
        num2 -= 2;
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v3.begin(), v3.end(), g);
    
    for( auto v : v1) {
        tree1.add(v);
    }

    for( auto v : v2) {
        tree2.add(v);
    }

    for( auto v : v3) {
        tree3.add(v);
    }

    printf("Tree 1 Height: %d\n", tree1.height());
    printf("Tree 2 Height: %d\n", tree2.height());
    printf("Tree 3 Height: %d\n", tree3.height());
    printf("Tree 1 Validation: %d\n", tree1.validate());
    printf("Tree 2 Validation: %d\n", tree2.validate());
    printf("Tree 3 Validation: %d\n", tree3.validate());

    printf("Tree 1 contains test:\n");
    for (int i = 1; i < 100; i++)
    {
        printf("%d:%d ",i,tree1.contains(i));
    }
    printf("\nTree 2 contains test:\n");
    for (int i = 1; i < 100; i++)
    {
        printf("%d:%d ", i, tree2.contains(i));
    }
    printf("\nTree 3 contains test:\n");
    for (int i = 1; i < 100; i++)
    {
        printf("%d:%d ", i, tree3.contains(i));
    }
    return 0;
}
