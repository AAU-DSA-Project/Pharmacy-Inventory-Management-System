#include "modules/DrugBST.h"
#include <iostream>
using namespace std;

int main(){

    DrugBST dr;
    // Added drugs
    dr.addDrug("iboprofien1", 01, 10, "2026-01-01");
    dr.addDrug("paracetamol1", 02, 20, "2026-02-01");
    dr.addDrug("cough drop", 03, 30, "2024-01-01");
    dr.displayDrugs();

    dr.discardExpiredDrugs();
}