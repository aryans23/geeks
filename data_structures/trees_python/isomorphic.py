#! /usr/bin/env python3

from amazingTree import Node
from amazingTree import printPostorder
from amazingTree import printInorder
from amazingTree import printPreorder
from amazingTree import isomorphic

n1 = Node(1)
n1.left = Node(2)
n1.right = Node(3)
n1.left.left = Node(4)
n1.left.right = Node(5)
n1.right.left = Node(6)
n1.left.right.left = Node(7)
n1.left.right.right = Node(8)
 
n2 = Node(1)
n2.left = Node(3)
n2.right = Node(2)
n2.right.left = Node(4)
n2.right.right = Node(5)
n2.left.right = Node(6)
n2.right.right.left = Node(8)
n2.right.right.right  = Node(7)

print("Preorder traversal of binary tree is: ",end="")
printPreorder(n1)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(n1)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(n1)
print("\n")

print("Preorder traversal of binary tree is: ",end="")
printPreorder(n2)

print("\nInorder traversal of binary tree is: ",end="")
printInorder(n2)

print("\nPostorder traversal of binary tree is: ",end="")
printPostorder(n2)
print("\n")

if isomorphic(n1,n2):
    print ("They're isomorphic")  
else:
    print("No")
