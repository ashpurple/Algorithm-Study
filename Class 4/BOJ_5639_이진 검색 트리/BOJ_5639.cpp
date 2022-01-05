#include <iostream>
using namespace std;

int binaryTree[1000000][2];

void preOrder(int input, int root){
    if(root < input){
        if(binaryTree[root][1] == 0){
            binaryTree[root][1] = input;
            return;
        } else {
            preOrder(input, binaryTree[root][1]);
        }
    }
    else{
        if(binaryTree[root][0] == 0){
            binaryTree[root][0] = input;
            return;
        } else {
            preOrder(input, binaryTree[root][0]);
        }
    }
}

void postOrder(int root){
    if(binaryTree[root][0] != 0)
        postOrder(binaryTree[root][0]);
    if(binaryTree[root][1] != 0)
        postOrder(binaryTree[root][1]);
        cout << root << '\n';
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, root = -1;

    while(true){
        cin >> num; 
        if(cin.eof()) 
            break;
        if(root == -1) 
            root = num;
        else 
            preOrder(num, root);
    }
    postOrder(root);
}