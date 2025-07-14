//Except Tree
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char name;
    Node* left;
    Node* right;

    Node(char val) {
        name = val;
        left = right = NULL;
    }
};

// Build the family tree
Node* buildFamilyTree() {
    Node* M = new Node('M');
    Node* J = new Node('J');
    Node* S = new Node('S');
    Node* H = new Node('H');
    Node* L = new Node('L');
    Node* R = new Node('R');
    Node* U = new Node('U');
    Node* D = new Node('D');
    Node* I = new Node('I');
    Node* P = new Node('P');
    Node* Y = new Node('Y');

    M->left = J;
    M->right = S;

    J->left = H;
    J->right = L;

    H->left = D;
    H->right = I;

    S->left = R;
    S->right = U;

    R->left = P;
    U->right = Y;

    return M;
}

// a. Find Parent
void find_parent(Node* root, char name, Node* parent = NULL) {
    if (!root) return;

    if (root->name == name) {
        if (parent)
            cout << "The parent is: " << parent->name << endl;
        else
            cout << "No parent found (root node)" << endl;
        return;
    }

    find_parent(root->left, name, root);
    find_parent(root->right, name, root);
}

// b. Find Sibling
void find_siblings(Node* root, char name) {
    if (!root) return;

    if (root->left && root->right) {
        if (root->left->name == name) {
            cout << "The sibling is: " << root->right->name << endl;
            return;
        } else if (root->right->name == name) {
            cout << "The sibling is: " << root->left->name << endl;
            return;
        }
    }

    find_siblings(root->left, name);
    find_siblings(root->right, name);
}

// c. Find Grandparent
void find_grandparent(Node* root, char name, Node* parent = NULL, Node* grandparent = NULL) {
    if (!root) return;

    if (root->name == name) {
        if (grandparent)
            cout << "The grandparent is: " << grandparent->name << endl;
        else
            cout << "No grandparent found" << endl;
        return;
    }

    find_grandparent(root->left, name, root, parent);
    find_grandparent(root->right, name, root, parent);
}

// d. Get Descendants
void collect_descendants(Node* root, vector<char>& result) {
    if (!root) return;
    result.push_back(root->name);
    collect_descendants(root->left, result);
    collect_descendants(root->right, result);
}

bool get_descendants(Node* root, char name, vector<char>& result) {
    if (!root) return false;

    if (root->name == name) {
        if (root->left) collect_descendants(root->left, result);
        if (root->right) collect_descendants(root->right, result);
        return true;
    }

    return get_descendants(root->left, name, result) ||
           get_descendants(root->right, name, result);
}

// e. Count Total Members
int count_total_members(Node* root) {
    if (!root) return 0;
    return 1 + count_total_members(root->left) + count_total_members(root->right);
}

// f. Get Subtree Height
int get_height(Node* root) {
    if (!root) return 0;
    return 1 + max(get_height(root->left), get_height(root->right));
}

Node* find_node(Node* root, char name) {
    if (!root) return NULL;
    if (root->name == name) return root;

    Node* left = find_node(root->left, name);
    if (left) return left;

    return find_node(root->right, name);
}

int get_subtree_height(Node* root, char name) {
    Node* target = find_node(root, name);
    if (!target) return -1;
    return get_height(target);
}

// Main Function
int main() {
    Node* root = buildFamilyTree();

    cout << "a) Parent of 'Y': ";
    find_parent(root, 'Y');

    cout << "b) Sibling of 'H': ";
    find_siblings(root, 'H');

    cout << "c) Grandparent of 'Y': ";
    find_grandparent(root, 'Y');

    cout << "d) Descendants of 'S': ";
    vector<char> descendants;
    if (get_descendants(root, 'S', descendants)) {
        for (char ch : descendants) cout << ch << " ";
        cout << endl;
    } else {
        cout << "Node not found.\n";
    }

    cout << "e) Total members in tree: " << count_total_members(root) << endl;

    cout << "f) Height of subtree from 'J': " << get_subtree_height(root, 'J') << endl;

    return 0;
}
