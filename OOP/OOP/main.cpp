#include "Meniu.h"

int main() {
    Meniu* meniu = Meniu::getInstanta();

    meniu->ruleaza();

    delete meniu;

    return 0;
}