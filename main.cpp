#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow window;

    // import pre existing drugs
    window.dr.importFromFile("drugs.csv");
    window.pq.importFromFile("patients.csv");

    // Added drugs 
    window.dr.addDrug("Ibuprofen", 01, 10, "2026-01-01");
    window.dr.addDrug("Paracetamol", 02, 20, "2027-02-01");
    window.dr.addDrug("Cough Drops", 03, 13, "2024-01-01");

    // discarding expired drugs
    window.dr.discardExpiredFromCSV("drugs.csv");

    // patients added
    window.pq.enqueue(3, "Mary");
    window.pq.enqueue(4, "James");

    window.show();

    return app.exec();
}