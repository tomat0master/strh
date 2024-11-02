#include <iostream>
#include "BinarySearchTree.h" 

void testBinarySearchTree() {
    BinarySearchTree<int> bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    std::cout << "Initial Tree:" << std::endl;
    bst.printTree();
	bst.printTree1();

	BinarySearchTree<int> bst1 = bst;
    bst1.remove(10);
    std::cout << "Tree after removing 10:" << std::endl;
    bst1.printTree();
	bst1.printTree1();

	BinarySearchTree<int> bst2 = bst;
    bst2.remove(5);
    std::cout << "Tree after removing 5:" << std::endl;
    bst2.printTree();
	bst2.printTree1();

	BinarySearchTree<int> bst3 = bst;
	bst3.remove(3);
    std::cout << "Tree after removing 3:" << std::endl;
    bst3.printTree();
	bst3.printTree1();

	BinarySearchTree<int> bst4 = bst;
	bst4.remove(12);
    std::cout << "Tree after removing 12 :" << std::endl;
    bst4.printTree();
	bst4.printTree1();

	bst3.remove(5);
	std::cout << "Tree after removing 3 and 5:" << std::endl;
    bst3.printTree();
	bst3.printTree1();

	bst.remove(11);
	std::cout << "Tree after removing 11:" << std::endl;
    bst.printTree();
	bst.printTree1();


}

int main() {
    testBinarySearchTree();
    return 0;
}