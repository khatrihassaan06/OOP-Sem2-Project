# OOP-Sem2-Project
This repository contains all the files and description of 25k-0802's 2nd semester project for OOP


### Project Name: 
Multi-Tiered E-commerce System with Secure Payment Validation 

### Project Description:
A comprehensive C++ console application that simulates a full retail lifecycle, from inventory management to secure checkout. The system features an Admin Module for product CRUD operations (Add, Update, Delete) and a Customer Module with product filtering and a shopping cart. It implements a Payment Gateway to validate credit card integrity.

### Members Name/ ID: 
Muhammad Hassaan: 25K-0802                                       
Muhammad Yaseen:  25K-0791

### Prerequisites
Compiler: GCC/G++ (version 7.0 or higher recommended for modern C++ features).
Environment: Any IDE (VS Code, Visual Studio, Code::Blocks) or a standard terminal.

### Instruction to compile the program:
- Navigate to the project folder and run the following command on a new terminal to compile all files:
  
                  g++ main.cpp Manager.cpp -o EShopApp 

### Instruction to run the program:
- After successful compilation, launch the executable:
  
               .\EShopApp.exe

### Instructions to Use the System:
 -Launch: Compile and run the program. You will see the Role Selection screen.
 
 -Inventory Setup (Admin): Select 1 for Admin. Add at least two products (one Electronics, one Clothing) to build the shop's catalog.
 
 -Browse & Shop (Customer): Select 2 for Customer. View the catalog to see available IDs.
 
 -Selection: Choose "Add to Cart" and enter the specific Product ID you want. You can repeat this for multiple items.
 
 -Payment: Go to "Checkout." Verify the total, enter a valid 16-digit card number (Luhn-compliant), and confirm.
 
 -Exit: Always use the "Exit" option in the main menu to ensure the catalog.txt is updated correctly.

### 5 Use Cases:
1. Inventory Management: An Admin adds a new "Smartphone" (Electronics) with a 24-month warranty and updates the catalog for customers.
2. Flexible Shopping: A Customer browses a catalog of 10 items but chooses to add only a "Denim Jacket" and "Headphones" to their cart, paying only for those two.
3. Secure Checkout: The system prevents a transaction from moving forward when a user types a random 16-digit number that fails the Luhn Algorithm check.
4. Data Persistence: A user adds items on Monday, turns off the computer, and returns on Tuesday to find the inventory exactly as they left it thanks to File I/O.
5. Dynamic Product Handling: Using Polymorphism, the system handles a "Smartwatch" and a "T-Shirt" in the same list, but displays unique attributes (Warranty vs. Size) for each.

### Assumptions:
- Unique IDs: It is assumed the Admin will assign unique integer IDs to each product (the system does not currently auto-check for ID duplicates).
- Numerical Input: The system assumes users will enter numbers for ID and Price (though basic exception handling is included).
- Local Storage: The program assumes it has permission to read/write files in the folder where it is running.

### Limitations
- Single-Session Cart: The Shopping Cart is stored in temporary memory. If a customer exits to the Role Selection screen or closes the app, their current cart is cleared (Inventory remains safe).
- No GUI: The system is Console-Based, meaning it does not have a graphical mouse-and-click interface.
- Simple Search: The current search/pick logic is case-sensitive and relies strictly on IDs.
- No User Login: For simplicity in this version, there is no password protection for the Admin role.

### Luhn Algorithm Used:
The system features a secure payment gateway simulation powered by the Luhn Algorithm (also known as the Mod 10 algorithm). This is the industry-standard checksum formula used worldwide by financial institutions to validate credit card numbers, IMEI numbers, and other sensitive identification strings.
