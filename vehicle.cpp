#include "vehicle.h"

bool operator<(const Vehicle &l, const Vehicle &r)
{
	return tie(l.brand, l.model, l.productionYear) < tie(r.brand, r.model, r.productionYear);
}

void Car::create()
{
	cout << "Please enter brand: ";
	getline(cin, brand);
	cout << "Please enter model: ";
	getline(cin, model);
	cout << "Please enter number of doors: ";
	cin >> numberOfDoors;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter correct number of doors: ";
		cin >> numberOfDoors;
	}
	cout << "Please enter engine: ";
	cin.ignore();
	getline(cin, engine);
	cout << "Please enter drive type: ";
	getline(cin, drive);
	cout << "Please enter year of production: ";
	cin >> productionYear;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter correct year of production: ";
		cin >> productionYear;
	}
	cout << "Please enter price: ";
	cin >> price;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter correct price: ";
		cin >> price;
	}
	cin.ignore();
};

void Car::update()
{
	char x = '0';
	while (x != '8')
	{
		system("cls");
		cout << "Which data you want to update?"
			 << "\n1. Brand: " << brand
			 << "\n2. Model: " << model
			 << "\n3. Number of doors: " << numberOfDoors
			 << "\n4. Engine: " << engine
			 << "\n5. Drive type: " << drive
			 << "\n6. Year of production: " << productionYear
			 << "\n7. Price: " << price << "$"
			 << "\n8. Cancel\n"
			 << endl;
		x = _getch();
		switch (x)
		{
		case '1':
			cout << "Please enter brand: ";
			getline(cin, brand);
			break;
		case '2':
			cout << "Please enter model: ";
			getline(cin, model);
			break;
		case '3':
			cout << "Please enter number of doors: ";
			cin >> numberOfDoors;
			while (!cin.good())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter correct number of doors: ";
				cin >> numberOfDoors;
			}
			cin.ignore();
			break;
		case '4':
			cout << "Please enter engine: ";
			getline(cin, engine);
			break;
		case '5':
			cout << "Please enter drive(AWD, FWD, RWD): ";
			getline(cin, drive);
			break;
		case '6':
			cout << "Please enter year of production: ";
			cin >> productionYear;
			while (!cin.good())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter correct year of production: ";
				cin >> productionYear;
			}
			cin.ignore();
			break;
		case '7':
			cout << "Please enter price: ";
			cin >> price;
			while (!cin.good())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter correct price: ";
				cin >> price;
			}
			cin.ignore();
			break;
		case '8':
			return;
		default:
			cout << "Wrong number. Press any key to continue" << endl;
			_getch();
			break;
		}
	}
};

void Car::retrieve(string input)
{
	int j = 0;
	for (int i = 0; i < 7; ++i)
	{
		string temp;
		while (input[j] != '%' && j < input.size())
		{
			temp += input[j];
			++j;
		}
		++j;
		switch (i)
		{
		case 0:
			brand = temp;
			break;
		case 1:
			model = temp;
			break;
		case 2:
			numberOfDoors = stoi(temp);
			break;
		case 3:
			engine = temp;
			break;
		case 4:
			drive = temp;
			break;
		case 5:
			productionYear = stoi(temp);
			break;
		case 6:
			price = stoi(temp);
			break;
		default:
			break;
		}
	}
};

string Car::toFile()
{
	return brand + "%" + model + "%" + to_string(numberOfDoors) + "%" + engine + "%" + drive + "%" + to_string(productionYear) + "%" + to_string(price);
}

ostream &operator<<(ostream &os, const Car &obj)
{
	os << "Brand:\t\t\t" << obj.brand
	   << "\nModel:\t\t\t" << obj.model
	   << "\nNumber of doors:\t" << obj.numberOfDoors
	   << "\nEngine:\t\t\t" << obj.engine
	   << "\nDrive:\t\t\t" << obj.drive
	   << "\nYear of production:\t" << obj.productionYear
	   << "\nPrice:\t\t\t" << obj.price << "$";
	return os;
};

istream &operator>>(istream &is, Car &obj)
{
	is >> obj.brand >> obj.model >> obj.numberOfDoors >> obj.engine >> obj.drive >> obj.productionYear >> obj.price;
	return is;
};

void Bike::create()
{
	cout << "Please enter brand: ";
	getline(cin, brand);
	cout << "Please enter model: ";
	getline(cin, model);
	cout << "Please enter bike type(e.g. scooter, motorcycle): ";
	getline(cin, type);
	cout << "Please enter engine: ";
	getline(cin, engine);
	cout << "Please enter year of production: ";
	cin >> productionYear;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter correct year of production: ";
		cin >> productionYear;
	}
	cout << "Please enter price: ";
	cin >> price;
	while (!cin.good())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter correct price: ";
		cin >> price;
	}
	cin.ignore();
};

void Bike::update()
{
	char x = '0';
	while (x != '7')
	{
		system("cls");
		cout << "Which data you want to update?"
			 << "\n1. Brand: " << brand
			 << "\n2. Model: " << model
			 << "\n3. Type: " << type
			 << "\n4. Engine: " << engine
			 << "\n5. Year of production: " << productionYear
			 << "\n6. Price: " << price
			 << "\n7. Cancel" << endl;
		switch (x = _getch())
		{
		case '1':
			cout << "Please enter brand: ";
			getline(cin, brand);
			break;
		case '2':
			cout << "Please enter model: ";
			getline(cin, model);
			break;
		case '3':
			cout << "Please enter bike type: ";
			getline(cin, type);
			break;
		case '4':
			cout << "Please enter engine: ";
			getline(cin, engine);
			break;
		case '5':
			cout << "Please enter year of production: ";
			cin >> productionYear;
			while (!cin.good())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter correct year of production: ";
				cin >> productionYear;
			}
			cin.ignore();
			break;
		case '6':
			cout << "Please enter price: ";
			cin >> price;
			while (!cin.good())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Please enter correct price: ";
				cin >> price;
			}
			cin.ignore();
			break;
		case '7':
			return;
		default:
			cout << "Wrong number. Press any key to continue" << endl;
			_getch();
			break;
		}
		system("cls");
	}
};

void Bike::retrieve(string input)
{
	int j = 0;
	for (int i = 0; i < 6; ++i)
	{
		string temp;
		while (input[j] != '%' && j < input.size())
		{
			temp += input[j];
			++j;
		}
		++j;
		switch (i)
		{
		case 0:
			brand = temp;
			break;
		case 1:
			model = temp;
			break;
		case 2:
			type = temp;
			break;
		case 3:
			engine = temp;
			break;
		case 4:
			productionYear = stoi(temp);
			break;
		case 5:
			price = stoi(temp);
			break;
		default:
			break;
		}
	}
}

string Bike::toFile()
{
	return brand + "%" + model + "%" + type + "%" + engine + "%" + to_string(productionYear) + "%" + to_string(price);
}

ostream &operator<<(ostream &os, const Bike &obj)
{
	os << "Brand:\t\t\t" << obj.brand
	   << "\nModel:\t\t\t" << obj.model
	   << "\nType:\t\t\t" << obj.type
	   << "\nEngine:\t\t\t" << obj.engine
	   << "\nYear of production:\t" << obj.productionYear
	   << "\nPrice:\t\t\t" << obj.price << "$";
	return os;
};

istream &operator>>(istream &is, Bike &obj)
{
	is >> obj.brand >> obj.model >> obj.type >> obj.engine >> obj.productionYear >> obj.price;
	return is;
};
