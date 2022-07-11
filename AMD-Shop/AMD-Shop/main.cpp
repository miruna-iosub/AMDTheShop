#include <iostream>
#include<fstream>
#include<conio.h>
#include <string.h>
#include "Product.h" 
#include "CPU.h"
#include "GPU.h"
#include "APU.h"
#include "Login.h"
#include "User.h"
using namespace std;

/*int main() {

	//Product p(10.41, 13.28, 65, 7, 3.60);
	//p.showProduct();
	APU apu(10.41, 13.28, 65, 7, 3.60, "Ryzen 7 4700G", 8, 16, "AM4", "Radeon Graphics", 4, "DirectX 11");
	apu.showAPU();

	return 0;
}*/

int main()
{
    Login l1;
    while (1)
    {
        system("cls");
        string username, password;
        int ch, role, option;
        cout << " ********  Welcome to AMD-Shop  *********";
        cout << "\n 1. Login \n 2. Register \n 3. Role \n 4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1: 
            cout << " Username : "; cin >> username;
            cout << " Password : "; cin >> password;
            l1.login(username, password);
            return 0;
        case 2:
            l1.Register();
            break;
        case 3:
            cout << " Username : "; cin >> username;
            cout << " Password : "; cin >> password;
            if (l1.getRoleIfLogin(username, password) == "administrator")
            {
                //meniul pentru administrator
                system("cls");
                cout << "\n1. Add a product in database\n";
                cout << "2. Delete a product from database\n";
                cout << "3. Add admin\n";
                cout << "Your choice: ";
                cin >> option;
                switch (option) {
                case 1: { /*AddProduct in database (ProductsData.txt, delimitat de ;)*/ }
                case 2: {/*DeleteProduct per linie*/}
                case 3: {/*change role, procedura asemanatoare ca la delete*/ }
                default: { cout << "Try again!\n"; }
                }
            }
            else
            {
                //accesez meniul pentru client
                system("cls");
                cout << "\n1. Add a product to cart\n";
                cout << "2. Show the cart\n";
                cout << "3. Delete a product from cart\n";
                cout << "Your choice: ";
                cin >> option;
                switch (option) {
                case 1: { /*AddProduct in cart*/}
                case 2: { /*ShowCart*/  }
                case 3: { /*DeleteProduct per linie (un alt fisier cu datele fara cel selectat, temp.txt, apoi stergere cel vechi si redenumire temp.txt in cart_username.txt*/ }
                default: { cout << "Try again!\n";}
            }
        case 4:
            exit(1);
        }
        getchar();
    }

}
