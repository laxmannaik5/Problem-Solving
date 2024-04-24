#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int key;
        Node* left;
        Node* right;

        Node(int key){
            this->key = key;
            left = right = NULL;
        }
};

Node* insert(Node* root, int key){
    //base case
    if(root==NULL){
        return new Node(key);
    }
    //rec case
    if(key<root->key){
        root->left = insert(root->left,key);
    }else{
        root->right = insert(root->right,key);
    }
    return root;
}

void printInOrder(Node* root){
    if(root==NULL){
        return;
    }
    printInOrder(root->left);
    cout<<root->key<<" ,";
    printInOrder(root->right);
}

void search(Node* root, int key){
    if(root==NULL){
        cout<<"Key is not present in BST"<<endl;
        return;
    }
    if(root->key==key){
        cout<<"Yes, key is present in BST"<<endl;
        return;
    }
    if(key>root->key){
        search(root->right,key);
    }else{
        search(root->left,key);
    }
    //return;
}

Node* sortedArrayToMinHeightBST(vector<int> &arr, int s, int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e)/2;
    Node* root = new Node(arr[mid]);
    root->left = sortedArrayToMinHeightBST(arr,s,mid-1);
    root->right = sortedArrayToMinHeightBST(arr,mid+1,e);
    return root;
}

int findClosestInBST(Node* root, int target){
    int closest;
    int diff = INT_MAX;

    Node* temp = root;

    while(temp!=NULL){
        int closest_diff = abs(temp->key - target);
        if(closest_diff == 0){
            return temp->key;
        }
        if(closest_diff < diff){
            closest = temp->key;
            closest_diff = diff;
        }
        //right or left
        if(temp->key > target){
            temp = temp->left;
        }else{
            temp = temp->right;
        }
    }
    return closest;
}

//-----------BST To Sorted Linked List------------//
class LinkedList{
    public:
        Node* head;
        Node* tail;
};

LinkedList tree2LL(Node* root){
    LinkedList l;
    //base case
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }
    // 4 cases
    if(root->left == NULL and root->right == NULL){
        l.head = l.tail = root;
    }else if(root->left!=NULL and root->right==NULL){
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;

        l.head = leftLL.head;
        l.tail = root;
    }else if(root->left == NULL and root->right != NULL){
        LinkedList rightLL = tree2LL(root->right);
        root->left = rightLL.head;

        l.head = root;
        l.tail = rightLL.tail;
    }else{
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        leftLL.tail->right = root;
        root->right = rightLL.head;

        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
    return l;
}

//-----------next Inorder Successor-------------//

Node* inorderSucc(Node* root, Node* target){
    //If right subtree exist
    if(target->right!=NULL){
        Node* temp = target->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
    //otherwise
    Node* temp = root;
    Node* succ = NULL;
    while(temp!=NULL){
        if(temp->key > target->key){
            succ = temp;
            temp = temp->left;
        }else if(temp->key < target->key){
            temp = temp->right;
        }else{
            break;
        }
    }
    return succ;
}

int main(){
    // Node* root = NULL;
    // int arr[] = {8,3,10,1,6,14,4,7,13};
    // for(auto x:arr){
    //     root = insert(root,x);
    // }
    // printInOrder(root);
    // cout<<endl;
    // // search(root,13);

    // // cout<<findClosestInBST(root,12)<<endl;

    // LinkedList l = tree2LL(root);
    // Node* temp = l.head;
    // while(temp!=NULL){
    //     cout<<temp->key<<"-->";
    //     temp = temp->right;
    // }

    // vector<int> arr{1,2,3,4,5,6,7};
    // Node* root = sortedArrayToMinHeightBST(arr,0,6);
    // printInOrder(root);


    Node * root = NULL;
	root = insert(root,8);
	root = insert(root,3);
	root = insert(root,10);
	root = insert(root,1);
	root = insert(root,6);
	root = insert(root,14);
	root = insert(root,4);
	root = insert(root,7);
	root = insert(root,13);

	//Test our Code
	Node* t1 = root->left->right->right;
	Node* t2 = root->right;

	cout<<"Inorder succ of 7 is" << inorderSucc(root,t1)->key <<endl;
	cout<<"Inorder succ of 10 is" << inorderSucc(root,t2)->key <<endl;

    return 0;
}