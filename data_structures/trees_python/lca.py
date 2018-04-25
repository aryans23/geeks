#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import lca

root = Node(20)
root.left = Node(8)
root.right = Node(22)
root.left.left = Node(4)
root.left.right = Node(12)
root.left.right.left = Node(10)
root.left.right.right = Node(14)
 
print("Preorder traversal of binary tree is: ",end="")
printPreorder(root)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(root)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(root)
print("\n")

n1 = 10 ; n2 = 14
t = lca(root, n1, n2)
print("LCA of %d and %d is %d" %(n1, n2, t.val))
 
n1 = 14 ; n2 = 8
t = lca(root, n1, n2)
print("LCA of %d and %d is %d" %(n1, n2 , t.val))
 
n1 = 10 ; n2 = 22
t = lca(root, n1, n2)
print("LCA of %d and %d is %d" %(n1, n2, t.val))
