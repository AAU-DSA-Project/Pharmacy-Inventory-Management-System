#ifndef DRUGBST_H
#define DRUGBST_H
#include <string>

#include <fstream>

using namespace std;

struct Drug
{
    int id;
    string name;
    Drug *left;
    Drug *right;
    int quantity;
    string catagory;
    string expiryDate;
    Drug(string n, int i, int quan, string expiry); // automatically initiallizes the res
};

class DrugBST
{
private:
    Drug *root;
    Drug *insert(Drug *node, string name, int id, int quantity, string expiry);
    Drug *deleteByName(Drug *node, const string& name);
    bool searchByName(Drug *node, string name);
    bool searchById(Drug *node, int id);
    void inorder(Drug *node);
    void inorderToFile(Drug *node, ofstream &out);
<<<<<<< HEAD
    int countNodes(Drug *node);//added
=======
    void clear(Drug *node);

>>>>>>> a4747e7551a9a98f33b7ea16730038613cf45bb8
public:
    DrugBST();
    void addDrug(string name, int id, int quantity, string expiryDate);
    void findDrugName(string name);
    void findDrugId(int id);
    void displayDrugs();
    void exportToFile(const string &filename);
<<<<<<< HEAD
    void importFromFile(const string &filename); 
    int getDrugTypeCount();//added
=======
    void importFromFile(const string &filename);
    void clearTree();
    void discardExpiredFromCSV(const string &filename);
>>>>>>> a4747e7551a9a98f33b7ea16730038613cf45bb8
};

#endif