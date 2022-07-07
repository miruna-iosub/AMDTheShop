#include <iostream>
#include<fstream>
#include<conio.h>
#include <string.h>
#include "product.h"
#include "CPU.h"
#include "GPU.h"
#include "APU.h"
#include "Login.h"
using namespace std;
/*int main() {

	//Product p(10.41, 13.28, 65, 7, 3.60);
	//p.showProduct();
	APU apu(10.41, 13.28, 65, 7, 3.60, "Ryzen 7 4700G", 8, 16, "AM4", "Radeon Graphics", 4, "DirectX 11");
	apu.showAPU();

	return 0;
}
*/
int main()
{

    Login l1;
    while (1)
    {
        system("cls");
        string username, password;
        int ch, role;
        cout << " ********  Welcome  *********";
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
       /* case 3:
            cout << " Username : "; cin >> username;
            cout << " Password : "; cin >> password;
            if (l1.getRoleIfLogin(username, password) == "client")
            {
                //accesez meniul pentru client
            }
            else
            {
                //accesez meniul pentru administrator
            }*/
        case 4:
            exit(1);
        }
        getchar();
    }
}