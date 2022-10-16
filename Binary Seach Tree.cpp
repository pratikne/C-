/** Binary Search TREE -> Atmost 2 child nodes for any node and data at left <= right 
 *  Traversal in O(n) time, O(n) space complexity
 *  Search = O(logn)
 *  Insert = O(logn)
 *  Remove = O(logn) - code pending
 **/

#include<bits/stdc++.h>
using namespace std;

class BstNode{
    int data;
    BstNode* left;
    BstNode* right;


    public:
    BstNode(){} //default const.

    BstNode(int data){ //para. const.
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }   

    BstNode* GetNewNode(int data){ //Function to create New Node in heap
        BstNode* node = new BstNode(data);
        return node;
    }

    BstNode* InsertinTree(BstNode* root, int data){ //Insert in BT
        if(root == NULL)
            root = GetNewNode(data);
        else if(data <= root->data)
            root->left = InsertinTree(root->left,data);
        else
            root->right = InsertinTree(root->right,data);
        
        return root;
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

    void InOrderPrint(BstNode* root){ //Print in Inorder ::: (left -> root -> right)
        if(root == NULL)
            return;
        
        InOrderPrint(root->left);
        cout<< root->data << '\t';
        InOrderPrint(root->right);

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

    int FindHeight(BstNode* root){ //edges from leaf node
        if(root == NULL)
            return -1;
        else
            return (max(FindHeight(root->left),FindHeight(root->right)) + 1); //{max(left,right)} + 1
    }

    int FindMin(BstNode* root){ //Find Minimum value  in BST - leftmost node
        if(root ==NULL)
            return -1; //Tree empty
        BstNode* curr = root;
        while(curr->left != NULL){
            curr = curr->left;
        }
        return curr->data;
    }

    int FindMax(BstNode* root){ //Find Maximum value  in BST - rightmost node
        if(root ==NULL)
            return -1; //Tree empty
        BstNode* curr = root;
        while(curr->right != NULL){
            curr = curr->right;
        }
        return curr->data;
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

    cout << "Height is " << b.FindHeight(root) << endl; 

    cout << b.IsBinarySearchTree(root, INT_MIN, INT_MAX) << endl;
    
    b.InOrderPrint(root);
    cout<<endl;
    b.PreOrderPrint(root);
    cout<<endl;
    b.PostOrderPrint(root);
    cout<<endl;

    if(b.SearchinTree(root,10))
        cout<< "Found";
    else 
        cout<< "Not Found"; 
    return 0;


}