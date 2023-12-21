// create an application that helps a store manager to add items to his store and generate bill for each of his customers.in CPP
// for example : Welcome to Tezo Cart.
// Choose from the following options:
// 1.Manage Storage
// 2.Sell Items
// 3.Exit

// Enter your options:

// After taking the output from option 1,2,3 , ask another question..

// choose from the following options:
// 1. Add product(s)
// 2. Back
// 3. Exit

// if option 2 pressed take back to the last procedure of(manage storage , sell items , Exit)
// if option 3 pressed than terminate the code and exit.
// if option 1 pressed than again give them the option to enter product details: by
// ID:
// Name:
// Price:
// Quantity:
// user should be able to add the product details and add it to inventory.

// Do you want to add another item? respond with Y/N
// if Y entered by user then repeat the last process of(ID , Name,Price , Quantity)

// keep on repeating until the user press Y.

// If the user click N,
// give them the option to choose : 1. Add to Cart.2. Checkout 3. Back 4. Exit

// If option 1 pressed,
// show the product list : by ID, Product, Price

// Select items : (enter id)enter quantity to add to cart : (quantity)Do you want to add another item to cart.reply with Y / N,

// LAstly option 2.checkout when pressed then show them the list in billing manner example;
// (ID, Product, Quantity, Price)

// then list down the selected item
// and at the bottom show the total = sum of price

#include <iostream>
#include <iomanip>
#include <map>
#include <vector>

using namespace std;

struct Product
{
    string name;
    double price;
    int quantity;
};

class StoreManager
{

private:
    map<int, Product> inventory;
    vector<pair<int, int>> cart;

public:
    void manageStorage()
    {
        int option;
        do
        {
            cout << "Choose from the following options:" << std::endl;
            cout << "1. Add Product" << endl;
            cout << "2. View Products" << endl;
            cout << "3. Back" << endl;
            cout << "4. Exit" << endl;
            cin >> option;

            switch (option)
            {
            case 1:
                addProduct();
                break;
            case 2:
                viewProducts();
                break;
            case 3:
                return;
            case 4:
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        } while (true);
    }

    void sellItems()
    {
        int option;
        do
        {
            cout << "Choose from the following options:" << endl;
            cout << "1. Add to Cart" << endl;
            cout << "2. Checkout" << endl;
            cout << "3. Back" << endl;
            cout << "4. Exit" << endl;
            cin >> option;

            switch (option)
            {
            case 1:
                addToCart();
                break;
            case 2:
                checkout();
                break;
            case 3:
                return;
            case 4:
                exit(0);
            default:
                cout << "Invalid option. Please try again." << endl;
            }
        } while (true);
    }

    void addProduct()
    {
        int id;
        string name;
        double price;
        int quantity;

        do
        {
            cout << "Enter product details:" << endl;
            cout << "ID: ";
            cin >> id;
            cout << "Name: ";
            cin >> name;
            cout << "Price: ";
            cin >> price;
            cout << "Quantity: ";
            cin >> quantity;

            inventory[id] = {name, price, quantity};

            char choice;
            cout << "Do you want to add another item? (Y/N): ";
            cin >> choice;
            if (choice == 'N' || choice == 'n')
            {
                break;
            }
        } while (true);
    }

    void viewProducts()
    {
        cout << setw(5) << "ID" << setw(15) << "Product" << setw(10) << "Price" << setw(10) << "Quantity" << endl;
        for (auto const &item : inventory)
        {
            cout << setw(5) << item.first << setw(15) << item.second.name << setw(10) << item.second.price << setw(10) << item.second.quantity << endl;
        }
    }

    void addToCart()
    {
        int id, quantity;
        char choice;

        do
        {
            cout << "Product list:" << endl;
            for (auto const &item : inventory)
            {
                cout << "ID: " << item.first << ", Product: " << item.second.name << ", Price: " << item.second.price << endl;
            }

            cout << "Select items (enter ID): ";
            cin >> id;
            cout << "Enter quantity to add to cart: ";
            cin >> quantity;

            if (inventory[id].quantity < quantity)
            {
                cout << "Not enough stock for this item." << endl;
                continue;
            }

            cart.push_back(make_pair(id, quantity));
            inventory[id].quantity -= quantity;

            cout << "Do you want to add another item to cart? (Y/N): ";
            cin >> choice;
            if (choice == 'N' || choice == 'n')
            {
                break;
            }
        } while (true);
    }

    void checkout()
    {
        double total = 0.0;

        cout << "Billing:" << endl;
        cout << setw(5) << "ID" <<
                setw(15) << "Product" <<
                setw(10) << "Quantity" << 
                setw(10) << "Price" << endl;
        for (auto const &item : cart)
        {
            int id = item.first;
            int quantity = item.second;
            Product product = inventory[id];
            cout << setw(5) << id <<
                    setw(15) << product.name << 
                    setw(10) << quantity << 
                    setw(10) << product.price * quantity << endl;
            total += product.price * quantity;
        }
        cout << "Total: " << total << endl;

        cart.clear();
    }
};

int main()
{
    StoreManager storeManager;
    int option;
    do
    {
        cout << "Welcome to Tezo Cart." << endl;
        cout << "Choose from the following options:" << endl;
        cout << "1. Manage Storage" << endl;
        cout << "2. Sell Items" << endl;
        cout << "3. Exit" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            storeManager.manageStorage();
            break;
        case 2:
            storeManager.sellItems();
            break;
        case 3:
            exit(0);
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (true);

    return 0;
}