#include "CStore.h"
void displayMenu() {
    cout << "----- Store Menu -----\n";
    cout << "1. Output products\n";
    cout << "2. Delete a product\n";
    cout << "3. Buy a product\n";
    cout << "4. View products by expiration date\n";
    cout << "5. View product quantities\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}
int main()
{
    CStore abc;
    int choice;
    abc.Input();
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            abc.Output();
            break;
        case 2:
            abc.Delete();
            break;
        case 3:
            abc.Buy();
            break;
        case 4:
            abc.ViewExpDate();
            break;
        case 5:
            abc.ViewQuantity();
            break;
        case 0:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
}