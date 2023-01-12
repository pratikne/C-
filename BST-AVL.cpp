// Self Balancing Binary search tree - AVL Tree Implementation
// https://simplesnippets.tech/what-is-avl-tree-data-structure-all-avl-operations-with-full-code/

#include <iostream>

#define SPACE 10

using namespace std;

class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class AVLTree
{
public:
    TreeNode *root; //IMP

    AVLTree()
    {
        root = NULL;
    }

    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // Get Height
    int height(TreeNode *r)
    {
        if (r == NULL)
            return -1;
        else
        {
            /* compute the height of each subtree */
            int lheight = height(r->left);
            int rheight = height(r->right);

            /* use the larger one */
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }

    // Get Balance factor of node N = height(LST) - height(RST)
    int getBalanceFactor(TreeNode *node)
    {
        if (node == NULL)
            return -1;   //IMP
        return height(node->left) - height(node->right);
    }

    TreeNode *rightRotate(TreeNode *node)
    {   //       node
        //
        //    x
        //
        // new   T2

        TreeNode *x = node->left;
        TreeNode *T2 = x->right;

        // Perform rotation
        x->right = node;
        node->left = T2; // coz T2 is smaller than node

        return x;
    }

    TreeNode *leftRotate(TreeNode *node)
    {   //       node
        //
        //             y
        //
        //          T2    new
        TreeNode *y = node->right;
        TreeNode *T2 = y->left;

        // Perform rotation
        y->left = node;
        node->right = T2; // coz T2 is larger than node

        return y;
    }

    TreeNode *insert(TreeNode *root, TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value inserted successfully" << endl;
            return root;
        }

        if (new_node->value < root->value)
        {
            root->left = insert(root->left, new_node);
        }
        else if (new_node->value > root->value)
        {
            root->right = insert(root->right, new_node);
        }
        else
        {
            cout << "No duplicate values allowed!" << endl;
            return root;
        }

        int bf = getBalanceFactor(root);

        // Left Left Case - right rotation for root
        if (bf > 1 && new_node->value < root->left->value)
            return rightRotate(root);

        // Right Right Case - left rotation for root
        if (bf < -1 && new_node->value > root->right->value)
            return leftRotate(root);

        // Left Right Case - Left and then right rotation
        if (bf > 1 && new_node->value > root->left->value)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        // Right Left Case - right and then left rotation
        if (bf < -1 && new_node->value < root->right->value)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        /* return the (unchanged) node pointer */
        return root;
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        /* loop down to find the leftmost leaf */
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    TreeNode *maxValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        /* loop down to find the leftmost leaf */
        while (current->right != NULL)
        {
            current = current->right;
        }
        return current;
    }

    TreeNode *deleteNode(TreeNode *r, int v)
    {
        // base case
        if (r == NULL)
        {
            return NULL;
        }
        // If the key to be deleted is smaller than the root's key,
        // then it lies in left subtree
        else if (v < r->value)
        {
            r->left = deleteNode(r->left, v);
        }
        // If the key to be deleted is greater than the root's key,
        // then it lies in right subtree
        else if (v > r->value)
        {
            r->right = deleteNode(r->right, v);
        }
        // if key is same as root's key, then This is the node to be deleted
        else
        {
            // node with only one child or no child
            if (r->left == NULL && r->right == NULL)
            {
                TreeNode *temp = NULL;
                delete r;
                return temp;
            }
            else if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                // node with two children: Get the inorder successor (smallest in the right subtree)
                TreeNode *temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node
                r->value = temp->value;
                // Delete the inorder successor
                r->right = deleteNode(r->right, temp->value);
                // delete temp; //as temp is not dynamically allocated
                // return r;
                // deleteNode(r->right, temp->value);
            }
        }

        int bf = getBalanceFactor(r);
        // Left Left Imbalance/Case or Right rotation
        if (bf > 1 && getBalanceFactor(r->left) >= 0)
            return rightRotate(r);
        // Left Right Imbalance/Case or LR rotation
        else if (bf > 1 && getBalanceFactor(r->left) == -1)
        {
            r->left = leftRotate(r->left);
            return rightRotate(r);
        }
        // Right Right Imbalance/Case or Left rotation
        else if (bf < -1 && getBalanceFactor(r->right) <= 0)
            return leftRotate(r);
        // Right Left Imbalance/Case or RL rotation
        else if (bf < -1 && getBalanceFactor(r->right) == 1)
        {
            r->right = rightRotate(r->right);
            return leftRotate(r);
        }

        return r;
    }

    void print2D(TreeNode *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += SPACE;           // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
            cout << " ";                    // 5.1
        cout << r->value << "\n";           // 6
        print2D(r->left, space);            // Process left child  7
    }

    void printPreorder(TreeNode *r) //(current node, Left, Right)
    {
        if (r == NULL)
            return;
        /* first print data of node */
        cout << r->value << " ";
        /* then recur on left sutree */
        printPreorder(r->left);
        /* now recur on right subtree */
        printPreorder(r->right);
    }

    void printInorder(TreeNode *r) //  (Left, current node, Right)
    {
        if (r == NULL)
            return;
        /* first recur on left child */
        printInorder(r->left);
        /* then print the data of node */
        cout << r->value << " ";
        /* now recur on right child */
        printInorder(r->right);
    }

    void printPostorder(TreeNode *r) //(Left, Right, Root)
    {
        if (r == NULL)
            return;
        // first recur on left subtree
        printPostorder(r->left);
        // then recur on right subtree
        printPostorder(r->right);
        // now deal with the node
        cout << r->value << " ";
    }

    /* Print nodes at a given level */
    void printGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->value << " ";
        else // level > 0
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }

    void printLevelOrderBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
            printGivenLevel(r, i);
    }

    TreeNode *iterativeSearch(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (v == temp->value)
                {
                    return temp;
                }
                else if (v < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode *recursiveSearch(TreeNode *r, int val)
    {
        if (r == NULL || r->value == val)
            return r;

        else if (val < r->value)
            return recursiveSearch(r->left, val);

        else
            return recursiveSearch(r->right, val);
    }
};

int main()
{
    AVLTree obj;
    int option, val;

    do
    {
        cout << "---------------------------------------" << endl;
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal AVL Tree values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        // Node n1;
        TreeNode *new_node = new TreeNode(); // For global scope as Node is stored in Heap

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "AVL INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in AVL Tree: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insert(obj.root, new_node);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in AVL Tree: ";
            cin >> val;
            // new_node = obj.iterativeSearch(val);
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in AVL: ";
            cin >> val;
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                obj.root = obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "Print Level Order BFS: \n";
            obj.printLevelOrderBFS(obj.root);
            cout << endl;
            cout << "PRE-ORDER: ";
            obj.printPreorder(obj.root);
            cout << endl;
            cout << "IN-ORDER: ";
            obj.printInorder(obj.root);
            cout << endl;
            cout << "POST-ORDER: ";
            obj.printPostorder(obj.root);
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}