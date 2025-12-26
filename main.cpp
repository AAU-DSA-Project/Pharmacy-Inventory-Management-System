#include <iostream>
using namespace std;
#include "modules/DrugBST.h"
#include "modules/PatientQueue.h"

int main()
{
    DrugBST dr;
    PatientQueue pq;
    // import pre existing drugs
    dr.importFromFile("drugs.csv");

    // Added drugs
    dr.addDrug("iboprofien1", 01, 10, "01-01-2026");
    dr.addDrug("paracetamol1", 02, 20, "01-02-2026");
    dr.displayDrugs();

    // patients added
    pq.enqueue(1, "Alice");
    pq.enqueue(2, "Bob");
    pq.display();

    // Export current data to files
    dr.exportToFile("drugs.csv");
    pq.exportToFile("patients.csv");
}