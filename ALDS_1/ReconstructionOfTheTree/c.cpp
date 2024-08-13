#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 40;
int n, pos;

int preorder[MAX];
int inorder[MAX];
vector<int> postorder;



void rec(int l, int r){
    if(l >= r) return;

    int root = preorder[pos]; pos++;
    
    int m;
    for (int i = 0; i < n; i++)
    {
        if(inorder[i] == root){
            m = i;
            break;
        }
    }


    rec(l, m);
    rec(m+1, r);

    postorder.push_back(root);
}


int main() {
    
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> preorder[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
    }
    

    pos = 0;
    rec(0, n);


    for (int i = 0; i < n; i++)
    {
        cout << postorder[i];
        if(i != n-1) {
            cout << " ";
        }    
    }

    cout << endl;
    
    return 0;
}