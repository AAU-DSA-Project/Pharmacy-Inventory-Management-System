#include <iostream>
using namespace std;
#include "modules/DrugBST.h"
#include "modules/PatientQueue.h"

int main()
{
    DrugBST dr;
    PatientQueue pq;
    // Added drugs
    dr.addDrug("iboprofien", 01, 10, "01-01-2026");
    dr.addDrug("paracetamol", 02, 20, "01-02-2026");
    dr.displayDrugs();

    // patients added
    pq.enqueue(1, "Alice");
    pq.enqueue(2, "Bob");
    pq.display();

    // Export current data to files
    dr.exportToFile("drugs.csv");
    pq.exportToFile("patients.csv");
}