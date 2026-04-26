#include <iostream>
#include <vector>
#include <fstream>
#include "Manager.h"
#include "Electronics.h"
#include "Clothing.h"

using namespace std;


bool validateCard(string card) {
    int sum = 0; bool alt = false;
    for (int i = card.length() - 1; i >= 0; i--) {
        int d = card[i] - '0';
        if (alt) { d *= 2; if (d > 9) d -= 9; }
        sum += d; alt = !alt;
    }
    return (sum % 10 == 0);
}

int main() {
    Manager shop;
    shop.loadData(); 
    int roleChoice;

    while (true) {
        cout << "\n--- ROLE SELECTION ---\n1. Admin (Manage Shop)\n2. Customer (Buy Items)\n3. Exit\nChoice: ";
        if (!(cin >> roleChoice) || roleChoice == 3) {
            shop.saveData(); // 
            break;
        }

        try {
            if (roleChoice == 1) { // ADMIN ROLE
                int adminOption;
                cout << "\n[Admin] 1.Add Product 2.Delete 3.View All 4.Back: ";
                cin >> adminOption;

                if (adminOption == 1) {
                    int type, id; string name; double price;
                    cout << "Type (1:Electronics, 2:Clothing): "; cin >> type;
                    cout << "ID Name Price: "; cin >> id >> name >> price;

                    if (type == 1) {
                        int war; cout << "Warranty (mo): "; cin >> war;
                        shop.addProduct(new Electronics(id, name, price, war));
                    } else {
                        string size; cout << "Size (S/M/L): "; cin >> size;
                        shop.addProduct(new Clothing(id, name, price, size));
                    }
                    cout << "Product Added!\n";
                } else if (adminOption == 2) {
                    int id; cout << "Enter ID to delete: "; cin >> id;
                    shop.deleteProduct(id);
                } else if (adminOption == 3) {
                    shop.displayAll();
                }
            } 
            else if (roleChoice == 2) { // CUSTOMER ROLE
                vector<BaseProduct*> cart; // Session-based shopping cart
                int custOption;

                while (true) {
                    cout << "\n[Customer] 1.View Catalog 2.Add to Cart 3.Checkout/Pay 4.Back: ";
                    cin >> custOption;

                    if (custOption == 1) {
                        shop.displayAll();
                    } 
                    else if (custOption == 2) {
                        int id;
                        cout << "Enter Product ID to add: "; cin >> id;
                        BaseProduct* p = shop.getProductById(id);
                        if (p) {
                            cart.push_back(p);
                            cout << p->getName() << " added to cart!\n";
                        } else {
                            cout << "Product not found!\n";
                        }
                    }
                    else if (custOption == 3) {
                        if (cart.empty()) {
                            cout << "Cart is empty!\n";
                            continue;
                        }

                        double cartTotal = 0;
                        cout << "\n--- Your Cart Items ---\n";
                        for (auto item : cart) {
                            item->displayDetails();
                            cartTotal += item->getPrice();
                        }
                        cout << "Total Amount Due: $" << cartTotal << endl;

                        cout << "Proceed to payment? (1:Yes, 2:No): ";
                        int payChoice; cin >> payChoice;

                        if (payChoice == 1) {
                            string card;
                            cout << "Enter 16-digit Card Number: "; cin >> card;
                            
                            if (!validateCard(card)) throw runtime_error("Payment Denied: Invalid Card!");

                            // Generate Receipt File
                            ofstream receipt("receipt.txt");
                            receipt << "**************** RECEIPT ****************\n";
                            for (auto p : cart) {
                                receipt << p->getName() << "\t\t$" << p->getPrice() << "\n";
                            }
                            receipt << "----------------------------------------\n";
                            receipt << "TOTAL PAID: \t$" << cartTotal << "\n";
                            receipt << "Card: \t\t****" << card.substr(card.length() - 4) << "\n";
                            receipt << "****************************************\n";
                            receipt.close();

                            cout << "Payment Successful! receipt.txt generated.\n";
                            cart.clear(); // Empty cart after payment
                            break; // Exit to role selection
                        }
                    }
                    else break; // Back to role selection
                }
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    }
    return 0;
}
