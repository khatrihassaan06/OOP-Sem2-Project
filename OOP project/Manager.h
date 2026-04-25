#ifndef MANAGER_H
#define MANAGER_H
#include <vector>
#include <string>
#include "BaseProduct.h"

class Manager {
private:
    std::vector<BaseProduct*> catalog; // Requirement: Dynamic Memory pointers
public:
    ~Manager(); // Requirement: Proper use of delete
    void addProduct(BaseProduct* p);
    void displayAll() const; // Ensure 'const' is here
    void deleteProduct(int id);
    void saveData(); // Requirement: File Handling
    void loadData();
    BaseProduct* getProductById(int id);
    double calculateTotal() const;
};
#endif
