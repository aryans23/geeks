#! /usr/bin/env python3

class Node:
    def __init__(self,key):
        self.left = None
        self.right = None
        self.val = key

def printInorder(root):
    if root:
        printInorder(root.left)
        print(root.val,end=" ")
        printInorder(root.right)

def printPreorder(root):
    if root:
        printPreorder(root.left)
        printPreorder(root.right)
        print(root.val,end=" ")

def printPostorder(root):
    if root:
        print(root.val,end=" ")
        printPostorder(root.left)
        printPostorder(root.right)

def size(root):
    if root is None:
        return 0;
    elif root:
        return (1 + size(root.left) + size(root.right))

def isIdentical(a,b):
    if a is None and b is None:
        return True
    elif a is not None and b is not None:
        return ((a.val == b.val) and
                (isIdentical(a.left,b.left)) and
                (isIdentical(a.right,b.right)))
    return False

def height(root):
    if root is None:
        return 0
    return (max(height(root.left),height(root.right)) + 1)

def mirror(root):
    if root is None:
        return None
    else:
        temp = mirror(root.left)
        root.left = mirror(root.right)
        root.right = temp
    
    return root

def rootToLeafPathUtil(root,path):
    path.append(root.val)
    if (root.left is None and root.right is None):
        print(path)
        path.pop()
        return
    if root.left is not None:
        rootToLeafPathUtil(root.left,path)
    if root.right is not None:
        rootToLeafPathUtil(root.right,path)

def rootToLeafPath(root):
    if root is None:
        return
    path = []
    rootToLeafPathUtil(root,path)

def lca(root,a,b):
    while root:
        if (root.val < a and root.val < b):
            root = root.right
        elif (root.val > a and root.val > b):
            root = root.left
        else:
            break
    return root

# Always use queue for O(n) worst time
def printLevelOrder(root):
    if root is None:
        return
    
    queue = []
    queue.append(root)
    while (queue):
        print(queue[0].val,end=" ")
        n = queue.pop(0)
        if (n.left is not None):
            queue.append(n.left)
        if (n.right is not None):
            queue.append(n.right)

def getLeafCount(root):
    if root is None:
        return 0
    if (root.left is None and root.right is None):
        return 1
    else:
        return getLeafCount(root.left) + getLeafCount(root.right)

def diameter(root):
    if root is None:
        return 0

    lheight = height(root.left)
    rheight = height(root.right)

    ldia = diameter(root.left)
    rdia = diameter(root.right)

    return max(ldia,rdia,1+lheight+rheight)

def hasPathSum(root,s):
    if root is None:
        return s is 0
    else:
        ans = False
        subSum = s - root.val
        if subSum is 0 and root.left is None and root.right is None:
            return True
        if root.left:
            ans = ans or hasPathSum(root.left,subSum)
        if root.right:
            ans = ans or hasPathSum(root.right,subSum)

        return ans

def getMaxWidth(root):
    if root is None:
        return 0
    
    q = []
    maxWidth = 0
    q.insert(0,root)

    while q:
        count = len(q)
        maxWidth = max(count,maxWidth)
        while count is not 0:
            temp = q[0]
            q.pop()
            count -= 1
            if temp.left:
                q.insert(0,temp.left)
            if temp.right:
                q.insert(0,temp.right)

    return maxWidth

def isFoldableUtil(n1,n2):
    if n1 is None and n2 is None:
        return True
    if n1 is None or n2 is None:
        return False

    return (isFoldableUtil(n1.left,n2.right) and
            isFoldableUtil(n1.right,n2.left))

def isFoldable(root):
    if root is None:
        return True
    return isFoldableUtil(root.left,root.right)

def ancestors(root,target):
    if root is None:
        return False
    if root.val is target:
        return True
    if (ancestors(root.left,target) or ancestors(root.right,target)):
        print(root.val)
        return True
    return False

def sumTree(root):
    ls = 0;
    rs = 0;
    
    if (root is None or (root.left is None and root.right is None)):
        return True
    
    if (sumTree(root.left) and sumTree(root.right)):
        if root.left is None:
            ls = 0
        elif root.left.left is None and root.left.right is None:
            ls = root.left.val
        else:
            ls = 2 * root.left.val

        if root.right is None:
            rs = 0
        elif root.right.left is None and root.right.right is None:
            rs = root.right.val
        else:
            rs = 2 * root.right.val
        
        return (ls + rs == root.val)

    return False

def areIdentical(T,S):
    if T is None and S is None:
        return True
    if T is None or S is None:
        return False
    return (T.val == S.val
            and areIdentical(T.left,S.left)
            and areIdentical(T.right,S.right))

def isSubTree(T,S):
    if S is None:
        return True
    if T is None:
        return False
    if areIdentical(T,S):
        return True
    return isSubTree(T.left,S) or isSubTree(T.left,S)

def isCompleteBT(root):
    if root is None:
        return True

    q = []
    flag = False  # flag is set when a non-Full node is seen
    q.append(root)

    while (len(q) > 0):
        temp = q[0]
        q.pop(0)

        if (temp.left):
            if flag is True:
                return False
            q.append(temp.left)
        else:
            flag = True

        if (temp.right):
            if flag is True:
                return False
            q.append(temp.right)
        else:
            flag = True

    return True

def printBoundaryLeft(root):
    if root is None:
        return
    
    while (root.left):
        print("%d" %(root.val),end=" ")
        root = root.left

    if (root.right):
        print("%d" %(root.val),end=" ")
        printBoundaryLeft(root.right)

def printBoundaryRight(root):
    if root is None:
        return
    
    if root.right:
        printBoundaryRight(root.right)
        print("%d" %(root.val),end=" ")

    if (root.left):
        printBoundaryRight(root.left)
        print("%d" %(root.val),end=" ")

def printLeaves(root):
    if root:
        printLeaves(root.left)
        if root.left is None and root.right is None:
            print("%d" %(root.val),end=" ")
        printLeaves(root.right)

def printBoundary(root):
    if root:
        print("%d" %(root.val),end=" ")
        printBoundaryLeft(root.left)
        printLeaves(root.left)
        printLeaves(root.right)
        printBoundaryRight(root.right)
        print()

def isomorphic(n1,n2):
    if n1 is None and n2 is None:
        return True
    if n1 is None or n2 is None:
        return False
    if n1.val != n2.val:
        return False
    return ((isomorphic(n1.left,n2.left) 
        and isomorphic(n1.right,n2.right)) or 
        (isomorphic(n1.left,n2.right) 
        and isomorphic(n1.right,n2.left)))

def leafAtSameLevelUtil(root,level):
    if root is None:
        return True

    if root.left is None and root.right is None:
        if leafAtSameLevel.leafLevel == 0:
            leafAtSameLevel.leafLevel = level
            return True

        return level == leafAtSameLevel.leafLevel

    return (leafAtSameLevelUtil(root.left,level+1) and 
            leafAtSameLevelUtil(root.right,level+1))

def leafAtSameLevel(root):
    level = 0
    leafAtSameLevel.leafLevel = 0
    return(leafAtSameLevelUtil(root,level))

def leftViewUtil(root,level,maxLev):
    if root is None:
        return

    if (maxLev[0] < level):
        print("%d\t" %(root.val),end="")
        maxLev[0] = level
    
    leftViewUtil(root.left,level+1,maxLev)
    leftViewUtil(root.right,level+1,maxLev)

def leftView(root):
    maxLev = [0]
    print("Left View:\t",end=" ")
    leftViewUtil(root,1,maxLev)
    print()

def prune(root,k):
    if root is None:
        return None
    
    k -= root.val
    if (k <= 0):
        return root

    root.left = prune(root.left,k)
    root.right = prune(root.right,k)

    if (root.left is None and root.right is None):
        return None
    else:
        return root

def nextRight(root,k):
    if root is None:
        return None

    qn = []
    ql = []
    level = 0

    qn.append(root)
    ql.append(level)

    while (len(qn) > 0):
        node = qn.pop(0)
        level = ql.pop(0)

        if (node.val == k):
            if (len(qn) == 0 or ql[0] != level):
                return None
            return qn[0]

        if node.left is not None:
            qn.append(node.left)
            ql.append(level+1)

        if node.right is not None:
            qn.append(node.right)
            ql.append(level+1)

    return None

