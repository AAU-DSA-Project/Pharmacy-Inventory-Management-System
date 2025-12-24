#include "DrugBST.h"
#include <iostream>
#include <fstream>
using namespace std;

// Drug constructor
Drug::Drug(string n) : name(n), left(nullptr), right(nullptr) {}

// DrugBST constructor
DrugBST::DrugBST() : root(nullptr) {}

// Insert into BST
Drug *DrugBST::insert(Drug *node, string name)
{
    if (!node)
        return new Drug(name);
    if (name < node->name)
        node->left = insert(node->left, name);
    else if (name > node->name)
        node->right = insert(node->right, name);
    return node;
}

// Search in BST
bool DrugBST::search(Drug *node, string name)
{
    if (!node)
        return false;
    if (node->name == name)
        return true;
    if (name < node->name)
        return search(node->left, name);
    return search(node->right, name);
}

// In-order traversal
void DrugBST::inorder(Drug *node)
{
    if (!node)
        return;
    inorder(node->left);
    cout << node->name << endl;
    inorder(node->right);
}

// In-order traversal to file
void DrugBST::inorderToFile(Drug *node, ofstream &out)
{
    if (!node)
        return;
    inorderToFile(node->left, out);
    out << node->name << "\n";
    inorderToFile(node->right, out);
}

// Public methods
void DrugBST::addDrug(string name)
{
    root = insert(root, name);
}

void DrugBST::findDrug(string name)
{
    cout << "Searching for " << name << ": "
         << (search(root, name) ? "Found" : "Not Found") << endl;
}

void DrugBST::displayDrugs()
{
    cout << "Drug list (sorted):" << endl;
    inorder(root);
}

void DrugBST::exportToFile(const string &filename)
{
    ofstream out(filename);
    if (!out.is_open())
    {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }
    // Optional header for clarity
    out << "name" << "\n";
    inorderToFile(root, out);
    out.close();
    cout << "Drugs exported to: " << filename << endl;
}