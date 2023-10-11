/*******************************************************************************************

* Programmer: Seth Aguilar                                                                 *

* Class: CptS 223                                                                          *

* Programming Assignment: PA2                                                              *

* Date:   10/11/2023                                                                       *

* Description:  A program that applies an AVL tree data structure                          *

*******************************************************************************************/

#include "AVLTree.h"

int main() {
    std::vector<int> ascending, descending, randomOrder;

    // Create data sequences
    for (int i = 1; i <= 100; i += 2) {
        ascending.push_back(i);
        descending.insert(descending.begin(), i);
        randomOrder.push_back(i);
    }

    // Shuffle for random order
    std::shuffle(randomOrder.begin(), randomOrder.end(), std::mt19937{ std::random_device{}() });

    // Create AVL trees
    AVLTree<int> treeAsc, treeDesc, treeRand;
    for (int num : ascending) {
        treeAsc.insert(num);
    }
    for (int num : descending) {
        treeDesc.insert(num);
    }
    for (int num : randomOrder) {
        treeRand.insert(num);
    }

    // Print heights
    std::cout << "Height of treeAsc: " << treeAsc.height() << std::endl;
    std::cout << "Height of treeDesc: " << treeDesc.height() << std::endl;
    std::cout << "Height of treeRand: " << treeRand.height() << std::endl;

    // Validate trees
    std::cout << "Validation of treeAsc: " << treeAsc.validate() << std::endl;
    std::cout << "Validation of treeDesc: " << treeDesc.validate() << std::endl;
    std::cout << "Validation of treeRand: " << treeRand.validate() << std::endl;

    // Check contains function
    for (int i = 1; i <= 100; i++) {
        bool expected = i % 2 == 1;
        if (treeAsc.contains(i) != expected || treeDesc.contains(i) != expected || treeRand.contains(i) != expected) {
            std::cout << "My AVL tree implementation is wrong" << std::endl;
            break;
        }
    }
    return 0;
}