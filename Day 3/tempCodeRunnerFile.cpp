// base case
    // if preindex is out of bounds
    // inorderstart exceeds inorderend
    if( preIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    // constuct the node for the element of preIndex
    int nodeVal = preOrder[preIndex];
    Node *root = new Node(nodeVal);

    // find the position of the preIndex element in inOrder array
    int pos = findIndex(inOrder, nodeVal, size);

    // update the index
    preIndex = preIndex + 1;

    // construct the left and right sub tree by bounding the inOder indices
    root -> left = bulidTreeFromPreOrderAndInOrder(preOrder, inOrder, preIndex, inOrderStart, pos-1, size);

    root -> right = bulidTreeFromPreOrderAndInOrder(preOrder, inOrder, preIndex, pos+1, inOrderEnd, size);

    // return the node
    return root;