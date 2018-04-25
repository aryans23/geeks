#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import isIdentical

root1 = Node(1)
root1.left = Node(2)
root1.right = Node(3)
root1.left.left = Node(4)
root1.left.right = Node(5)
print("Preorder traversal of binary tree 1 is: ",end="")
printPreorder(root1)
print("\n")

root2 = Node(1)
root2.left = Node(2)
root2.right = Node(3)
root2.left.left = Node(4)
root2.left.right = Node(5)
print("Preorder traversal of binary tree 2 is: ",end="")
printPreorder(root2)
print("\n")
 
if isIdentical(root1, root2):
    print("Both trees are identical")
else:
    print("Trees are not identical")

print("\n")
