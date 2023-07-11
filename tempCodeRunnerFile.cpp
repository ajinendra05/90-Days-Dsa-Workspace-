void preorder(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->val << " ";
        preorder(node->left);
        preorder(node->right);
    }