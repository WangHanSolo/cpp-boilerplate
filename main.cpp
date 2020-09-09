#include <iostream>
#include <vector>

struct Node{
    Node(int id){
        children = std::vector<Node*>();
        this->id = id;
    }
    std::vector<Node*> children;
    int id;
};

/**
 * Util function to print a graph
 */
void traverse(Node* root){

    for(auto* node : root->children){
        traverse(node);
    }
    printf("%d\n", root->id);
}

/**
 * Util function to delete graph
 */
void delete_tree(Node* root){
    for (auto* node : root->children){
        delete_tree(node);
    }
    delete root;
}

Node* copy(Node* root){
    Node* root_cpy = new Node(root->id);
    for (auto* node : root->children){
        Node* twin = copy(node);
        root_cpy->children.push_back(twin);
    }

    return root_cpy;
}

int main(int argc, char* argv[]){

    // create test graph
    Node* root = new Node(0);
    Node* c1 = new Node(11);
    Node* c2 = new Node(12);
    Node* c3 = new Node(13);
    root->children.push_back(c1);
    root->children.push_back(c2);
    root->children.push_back(c3);
    Node* c11 = new Node(111);
    Node* c12 = new Node(112);
    Node* c13 = new Node(113);
    Node* c21 = new Node(121);
    Node* c31 = new Node(131);
    c1->children.push_back(c11);
    c1->children.push_back(c12);
    c1->children.push_back(c13);
    c2->children.push_back(c21);
    c3->children.push_back(c31);

    Node* twin = copy(root);
    traverse(root);
    printf("PRINTING COPY\n");
    traverse(twin);

    delete_tree(root);
    delete_tree(twin);
    

}
