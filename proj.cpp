#include "client.h"
#include "vehicle.h"
#include "header.h"

int main()
{
	vector<Client> dataBase;
	loadDB(dataBase);
	int x = 0;
	while (x != 27)
	{
		cout << "What do you want to do?"
			<< "\n1. Show all clients."
			<< "\n2. Add new client."
			<< "\n3. Update client."
			<< "\n4. Remove client."
			<< "\n5. Client's vehicles."
			<< "\nESC to exit.\n"
			<< endl;
		x = _getch();
		switch (x)
		{
		case '1':
			system("cls");
			showClients(dataBase);
			cout << endl;
			break;
		case '2':
			system("cls");
			addClient(dataBase);
			system("cls");
			break;
		case '3':
			system("cls");
			updateClient(dataBase);
			system("cls");
			break;
		case '4':
			system("cls");
			removeClient(dataBase);
			system("cls");
			break;
		case '5':
			system("cls");
			cout << "Which client's:\n"
				<< endl;
			showClients(dataBase);
			cout << dataBase.size() + 1 << ". Cancel\n"
				<< endl;
			int x;
			cin >> x;
			cin.ignore();
			system("cls");
			if (x == dataBase.size() + 1)
				break;
			else if (x > 0 && x < dataBase.size() + 1)
				choose(dataBase[x - 1]);
			else
			{
				cout << "Wrong number. Press any key to continue" << endl;
				_getch();
			}
			system("cls");
			break;
		case 27:
			cout << "Closing program." << endl;
			break;
		default:
			system("cls");
			break;
		}
	}
	saveDB(dataBase);
	return 0;
}