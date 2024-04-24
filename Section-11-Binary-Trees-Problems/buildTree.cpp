#include<iostream>
#include<queue>
#include<vector>
#include<map>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            data = d;
            left = NULL;
            right = NULL;
        }
};

//Input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree(){
    int d;
    cin>>d;

    if(d==-1){
        return NULL;
    }

    node* n = new node(d);
    n->left = buildTree();
    n->right = buildTree();
    return n;
}

/* ToDo: Implement Level Order Traversal
Expected Output

1
2 3
4 5 6
7
*/

void levelOrderPrint(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            //insert a new null for next level
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
    return;
}

/*ToDo: Implement Level Order Build for tree*/

node* levelOrederBuild(){
    int d;
    cin>>d;
    node* root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* current = q.front();
        q.pop();
        int c1, c2;
        cin>>c1>>c2;
        if(c1!=-1){
            current->left = new node(c1);
            q.push(current->left);
        }
        if(c2!=-1){
            current->right = new node(c2);
            q.push(current->right);
        }
    }

    return root;
}

//Helper function: Height of the tree
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);

    return 1+max(h1,h2);
}

//Diameter
int diameter(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    //rec case
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1, max(D2,D3));
}

//--------Diameter Optimized-------//

class HDPair{
    public:
        int height;
        int diameter;
};

HDPair optDiameter(node* root){
    HDPair p;
    if(root==NULL){
        p.height = p.diameter = 0;
        return p;
    }

    //otherwise
    HDPair left = optDiameter(root->left);
    HDPair right = optDiameter(root->right);

    p.height = max(left.height, right.height)+1;

    int D1 = left.height + right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;

    p.diameter = max(D1, max(D2,D3));
    return p;
}

//Todo: Replace with Descendant Sum leaving leaf nodes intact

int replaceWithSum(node* root){
    //base case
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL and root->right==NULL){
        return root->data;
    }
    //recursive case
    int LS = replaceWithSum(root->left);
    int RS = replaceWithSum(root->right);

    int temp = root->data;
    root->data = LS + RS;
    return root->data + temp;
}

pair<int, bool> isHeightBalanced(node* root){
    pair<int, bool> p, left, right;
    if(root==NULL){
        p.first = 0;//height
        p.second = true;//balanced
        return p;
    }
    //rec case (postorder traversal)
    left = isHeightBalanced(root->left);
    right = isHeightBalanced(root->right);

    int height = max(left.first, right.first)+1;
    if(abs(left.first - right.first)<=1 and left.second and right.second){
        return make_pair(height, true);
    }
    return make_pair(height, false);
}

//------maxSubsetSum Function----------//

class Pair{
    public:
        int inc;
        int exc;
};

Pair maxSubsetSum(node* root){
    Pair p;
    if(root==NULL){
        p.inc = p.exc = 0;
        return p;
    }
    Pair left = maxSubsetSum(root->left);
    Pair right = maxSubsetSum(root->right);

    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc, left.exc) + max(right.exc, right.inc);
    return p;
}

void printAtLevelK(node* root, int k){
    if(root == NULL|| k < 0 ){
        return;
    }
    if(k==0){
        // if(root->data){
            cout<<root->data<<" ";
        // }
        return;
    }
    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);
    return;
}

int printNodesAtDistanceK(node* root, node* target, int k){
    //base case
    if(root==NULL){
        return -1;
    }
    //reach the target node
    if(root==target){
        printAtLevelK(root,k);
        return 0;
    }

    //other case
    int DL = printNodesAtDistanceK(root->left, target, k);
    if(DL!=-1){
        //2 cases
		// Print the current node
        if(DL+1==k){
            cout<<root->data<<" ";
        }else{
            // or print somenodes in the rightsubtree
            printAtLevelK(root->right,k-DL-2);
        }
        return 1+DL;
    }
    int DR = printNodesAtDistanceK(root->right,target,k);
    if(DR!=-1){
        //2 cases
		//print current node
        if(DR+1==k){
            cout<<root->data<<" ";
        }else{
            printAtLevelK(root->left,k-DR-2);
        }
        return 1+DR;
    }
    return -1;
}

//helper 
void traverseTree(node* root, int d, map<int, vector<int>> &m){
    if(root==NULL){
        return;
    }
    m[d].push_back(root->data);
    traverseTree(root->left,d-1,m);
    traverseTree(root->right,d+1,m);
    return;
}

void verticalOrderPrint(node* root){
    map<int, vector<int>> m;
    int d=0;
    traverseTree(root,d,m);

    for(auto p:m){
        int key = p.first;
        vector<int> line = p.second;
        for(auto data: line){
            cout<<data<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    // node* root = buildTree();
    // //node* root = levelOrederBuild();
    // replaceWithSum(root);
    // levelOrderPrint(root);
    //cout<<"Diameter is "<<diameter(root)<<endl;
    //cout<<"Opt Diameter is "<<optDiameter(root).diameter<<endl;

    // node* root = new node(1);
    // root->left = new node(2);
    // root->right = new node(3);
    // root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->right = new node(6);
    // root->left->right->left = new node(7);
    // root->left->right->right = new node(8);
    // //root->left->right->right->left = new node(9);
    // //root->left->right->right->right = new node(10);

    // pair<int, bool> p = isHeightBalanced(root);
    // if(p.second){
    //     cout<<"Yes, its height balanced";
    // }else{
    //     cout<<"Not a height balnced tree";
    // }


    // node* root = buildTree();
    // levelOrderPrint(root);
    // //Pair p = maxSubsetSum(root);
    // //cout<<"Max Sum: "<<max(p.inc, p.exc)<<endl;
    // printAtLevelK(root,2);


    // node* root = new node(1);
	// root->left = new node(2);
	// root->right = new node(3);
	// root->left->left = new node(4);
	// root->left->right = new node(5);
	// root->right->right = new node(6);
	// root->left->right->left = new node(7);
	// root->left->right->right = new node(8);
	// root->left->right->right->left = new node(9);
	// root->left->right->right->right = new node(10);

    // //Target Node 5
	// node* target = root->left->right;

    // int k = 2;	
	// printNodesAtDistanceK(root,target,k);
	// cout<<endl;

    node* root = new node(1);
	root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->right->left->right = new node(8);
    root->right->right->right = new node(9);

    verticalOrderPrint(root);

    return 0;
}