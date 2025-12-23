#include <iostream>
using namespace std;
#include "modules/DrugBST.h"
#include "modules/PatientQueue.h"

int main()
{
    DrugBST dr;
    PatientQueue pq;
    dr.addDrug("iboprofien");
    dr.addDrug("paracetamol");
    dr.displayDrugs();
}