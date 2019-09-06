#include "print.hpp"
#include "binary_tree.hpp"
#include <iostream>

using lib::print;

int main(int argc, char *argv[]) {
	lib::BST<int> b;
	
	print(b.insert(3));
	print(b.insert(1));
	print(b.insert(2));
	print(b.insert(20));
	print(b.insert(1));

	b.inorder();
	

	// print (b);
}