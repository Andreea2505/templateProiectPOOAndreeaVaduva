#include "Meniu.h"
#include "Exceptii.h"
#include <iostream>

int main() {
    try {
        Meniu* meniu = Meniu::getInstanta();
        meniu->ruleaza();
    }
    catch (const UserInputError& e) {
        std::cout << "Eroare: " << e.what() << "\n";
    }
    catch (const std::exception& e) {
        std::cout << "Exceptie standard: " << e.what() << "\n";
    }
    catch (...) {
        std::cout << "Eroare necunoscuta!\n";
    }

    return 0;
}
