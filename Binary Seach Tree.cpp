/** Binary Search TREE -> Atmost 2 child nodes for any node and data at left <= right 
 *  Left subtree of root contains nodes with lesser key than the root key
 *  Right subtree of root contains nodes with greater key than the root key
 * 
 *  Traversal in O(n) time, O(n) space complexity
 *  Average time complexity is logN, worst case is N is not balanced
 *  Search = O(logn)
 *  Insert = O(logn)
 *  Remove = O(logn) 
 **/

#include<bits/stdc++.h>
using namespace std;

class BstNode{
    public:

    int data;
    BstNode* left;
    BstNode* right;
    
    BstNode(){} //default const.

    BstNode(int data){ //para. const.
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    // ~BstNode(){
        
    //         delete left;
    //         delete right;
    //         // left = NULL;
    //         // right = NULL;
    //         cout << "Deleting " << data << endl;
        
    // }   

    BstNode* GetNewNode(int data){ //Function to create New Node in heap
        BstNode* node = new BstNode(data);
        return node;
    }

    BstNode* InsertinTree(BstNode* root, int data){ //Insert Node in BST
        if(root == NULL)
            root = GetNewNode(data);
        else if(data <= root->data)
            root->left = InsertinTree(root->left,data);
        else
            root->right = InsertinTree(root->right,data);
        
        return root;
    }

    BstNode *deleteNode(BstNode *r, int v) //Delete Node in BST
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
                BstNode *temp = NULL;
                delete r;
                return temp;
            }
            else if (r->left == NULL)
            {
                BstNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                BstNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                // node with two children: Get the inorder successor (smallest
                // in the right subtree)
                BstNode *temp = minValueNode(r->right);
                // Copy the inorder successor's content to this node
                r->value = temp->value;
                // Delete the inorder successor
                r->right = deleteNode(r->right, temp->value);
                // deleteNode(r->right, temp->value);
            }
        }

        return r;
    }

    bool SearchinTree(BstNode *root, int data){ //Search in BT
        if(root == NULL)
            return false;
        else if(root->data == data)
            return true;
        else if(data <= root->data)
            return SearchinTree(root->left,data);
        else
            return SearchinTree(root->right,data);
    }

    //Lowest Common Ancestor of 2 nodes n1 and n2
    BstNode* lowestCommonAncestor(BstNode* root, int n1, int n2){
        if(root == NULL)
            return NULL;

        if(root->data > n1 && root->data > n2){
            return lowestCommonAncestor(root->left, n1, n2);
        }
        if(root->data < n1 && root->data < n2){
            return lowestCommonAncestor(root->right, n1, n2);
        }
        return root; //one lies in LST and other in RST so common is root
    }

    // NOTE ::: Inorder traversal gives Sorted list in ascending order
    void InOrderPrint(BstNode* root){ //Print in Inorder ::: (left -> root -> right)
        if(root == NULL)
            return;
        
        InOrderPrint(root->left);
        cout<< root->data << '\t';
        InOrderPrint(root->right);

        // Below does traversal in descending order
        // InOrderPrint(root->right);
        // cout<< root->data << '\t';
        // InOrderPrint(root->left);

    }

    void PreOrderPrint(BstNode* root){ //Print in Preorder ::: (root -> left -> right)
        if(root == NULL)
            return;
        
        cout<< root->data << '\t';
        PreOrderPrint(root->left);
        PreOrderPrint(root->right);

    }

    void PostOrderPrint(BstNode* root){ //Print in Postorder ::: (left -> right -> root )
        if(root == NULL)
            return;
        
        PostOrderPrint(root->left);
        PostOrderPrint(root->right);
        cout<< root->data << '\t';

    }

    // BFS - Level Order Traversal
    void levelOrderPrint(BstNode* root){
        if(root == NULL)
            return;
        
        queue<BstNode*> treeq;
        treeq.push(root);

        while(!treeq.empty()){
            BstNode* curr = treeq.front();
            treeq.pop();
            cout << curr->data << "\t";

            if(curr->left != NULL)
                treeq.push(curr->left);
            if(curr->right != NULL)
                treeq.push(curr->right);
        }
        cout << endl;
    }

    // Total number of Nodes in BSt
    int countNode(BstNode* root){
        if(root == NULL){
            return 0;
        }

        return (1 + countNode(root->left) + countNode(root->right));
    }

    // Total number of leaf nodes in BST
    int LeafCount(BstNode* root){
        if(root == NULL)
            return 0;
        else if(root->left == NULL && root->right == NULL)
            return 1;
            
        return (LeafCount(root->left) + LeafCount(root->right));
    }

    // Total number of Full nodes in BST
    int FullNodeCount(BstNode* root){
        if(root == NULL)
            return 0;
        int count = 0;
        if(root->left && root->right)
            count++;  // will always return 1 if FULL, 0 if not.  ---->      [0,1]
        // count = count + FullNodeCount(root->left) + FullNodeCount(root->right);
        // return count;
        return count + FullNodeCount(root->left) + FullNodeCount(root->right);
    }

    bool IsBinarySearchTree(BstNode* root, int minvalue, int maxvalue){
        if(root == nullptr)
            return true;
        if(root->data > minvalue &&
           root->data < maxvalue &&
           IsBinarySearchTree(root->left, minvalue, root->data) && 
           IsBinarySearchTree(root->right, root->data, maxvalue))
                 return true;
        else
                 return false;

    }


    int FindHeight(BstNode* root){ //edges from leaf node  O(n) - time and space
    //Height = Max depth
        if(root == NULL)
            return -1; //IMP
        else
            return (1 + max(FindHeight(root->left),FindHeight(root->right))); // 1 + {max(left,right)}
    }

    // Find depth of node having value x from the root
    int FindDepth(BstNode* root, int x){
        // if(root == NULL)
        //     return -1;

        // int dist = -1;
        // if(root->data == x || (dist = FindDepth(root->left,x)) >= 0 || (dist = FindDepth(root->right,x)) > 0 ){
        //         return (dist + 1);
        //     }
        // return dist;
        BstNode* curr = root;
        int depth = 0;
        if(curr->data == x)
            return depth;
        while(curr->data != x){ //check for NULL also for curr
            if(x < curr->data)
                curr = curr->left;
            else if(x > curr->data)
                curr->curr->right;
            depth++;
        }
        return depth;
        
    }

    // Find Minimum value  in BST - leftmost node
    int FindMin(BstNode* root){ 
        if(root ==NULL)
            return INT_MAX; //Tree empty
        BstNode* curr = root;
        while(curr->left != NULL){
            curr = curr->left;
        }
        return curr->data;
    }

    // Find Maximum value  in BST - rightmost node
    int FindMax(BstNode* root){ 
        if(root ==NULL)
            return INT_MIN; //Tree empty
        BstNode* curr = root;
        while(curr->right != NULL){
            curr = curr->right;
        }
        return curr->data;
    }

    // Finds Sum total of all nodes in a tree - O(n),O(n)
    int FindSum(BstNode* root){
        if(root == NULL)
            return 0;
        return root->data + FindSum(root->left) + FindSum(root->right);
    }

    // Checks if tree1 and tree2 are identical or not
    bool AreIdentical(BstNode* root1, BstNode* root2){

        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL || root2 == NULL)
            return false;
        if(root1->data == root2->data && AreIdentical(root1->left,root2->left) && AreIdentical(root1->right,root2->right))
            return true;
        else
            return false;
    }

};

int main(){
    BstNode b; 
    BstNode* root = NULL;
    root = b.InsertinTree(root,13);
    root = b.InsertinTree(root,11);
    root = b.InsertinTree(root,14);
    root = b.InsertinTree(root,12);
    root = b.InsertinTree(root,10);

    cout << "Min value is " << b.FindMin(root) << endl;
    cout << "Max value is " << b.FindMax(root) << endl;
    cout << "Total Sum is " << b.FindSum(root) << endl;

    cout << "Height is " << b.FindHeight(root) << endl;
    cout << "Depth of Node having value " <<  11 << " is " << b.FindDepth(root,11) << endl;

    cout << b.IsBinarySearchTree(root, INT_MIN, INT_MAX) << endl;
    
    //Below is BFS(Breadth First search)
    cout << "[BFS]" << endl;
    b.levelOrderPrint(root);

    // All below are DFS (Depth First search)
    cout << "[DFS]" << endl;
    b.InOrderPrint(root); // left->root->right
    cout<<endl;
    b.PreOrderPrint(root); // root->left->right
    cout<<endl;
    b.PostOrderPrint(root); //left->right->root
    cout<<endl;

    if(b.SearchinTree(root,10))
        cout<< "Found";
    else 
        cout<< "Not Found"; 

    cout << endl << "Count of Leaf nodes : " << b.LeafCount(root) << endl;
    cout << "Full Nodes : " << b.FullNodeCount(root) << endl;
    cout << "Total Nodes : " << b.countNode(root) << endl;

    BstNode* lca = b.lowestCommonAncestor(root, 10, 12);
    cout << "LCA of 10 and 12 is " << lca->data << endl;


    delete root;
    return 0;


}



/**
 * Binary Tree - atmost 2 child per node(0/1/2)
 * ------------------------------------------------------------
 * Types
 * 1. Full (0 or 2 child per node, levels doesn't matter)
 * 2. Complete (all levels expect last are completely filled and all nodes pssible leaning to left)
 * 3. Perfect (All levels completely filled with 2 children each)
 * 4. Skewed (Left leaning or right leaning tree)
 * 5. Balanced (diff of height of LST and RST is not more than k(usually 1))
 * 
 * Binary Tree can be implemented as:
 * 1. Dynamic Nodes in memory (Eg : BST, AVL)
 * 2. Conventional array (Eg: Heap)
 * 
 * ------------------------------------------------------------
 * Max number of nodes at any level(from 0 to n):
 * 2 to the power of level number = 2^n
 * 
 * for level 0 -> 2^0 = 1
 * for level 1 -> 2^1 = 2
 * and so on...
 * ------------------------------------------------------------
 * Max number of height h:
 * 
 * (2^(h+1)) - 1
 * Eg: for hight 2, max node count is 7 as per formula which is true
 * -----------------------------------------------------------
 * 
 * 
 * 
 * 
 * 
 * 
 */