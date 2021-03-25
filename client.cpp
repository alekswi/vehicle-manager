#include "client.h"

ostream &operator<<(ostream &os, const Client &obj)
{
    os << obj.name << " " << obj.surname;
    return os;
};

istream &operator>>(istream &is, Client &obj)
{
    is >> obj.name >> obj.surname;
    return is;
};

void Client::showVehicles()
{
    system("cls");
    showCars();
    cout << endl;
    showBikes();
};

void Client::showCars()
{
    cout << "Cars:" << endl;
    for (auto i = 0; i < carDB.size(); ++i)
        cout << i + 1 << ".\n"
             << carDB[i] << "\n"
             << endl;
};

void Client::showBikes()
{
    cout << "Bikes:" << endl;
    for (auto i = 0; i < bikeDB.size(); ++i)
        cout << i + 1 << ".\n"
             << bikeDB[i] << "\n"
             << endl;
};

void Client::addVehicle()
{
    int i, x = 0;
    Car car;
    Bike bike;
    while (x != '1' && x != '2' && x != '3')
    {
        cout << "Please select what type of vehicle you want to add:\n1. Car\n2. Bike\n3. Cancel" << endl;
        x = _getch();
        switch (x)
        {
        case '1':
            car.create();
            for (i = 0; i < carDB.size(); ++i)
            {
                if (car < carDB[i])
                    break;
            }
            carDB.insert(carDB.begin() + i, car);
            break;
        case '2':
            bike.create();
            for (i = 0; i < bikeDB.size(); ++i)
            {
                if (bike < bikeDB[i])
                    break;
            }
            bikeDB.insert(bikeDB.begin() + i, bike);
            break;
        default:
            break;
        }
        system("cls");
    }
};

void Client::updateVehicle()
{
    int i, x = 0;
    while (x != '1' && x != '2' && x != '3')
    {
        cout << "What you want to edit:\n1. Car\n2. Bike\n3. Cancel." << endl;
        x = _getch();
        system("cls");
        switch (x)
        {
        case '1':
            cout << "Which car you want to edit:\n"
                 << endl;
            showCars();
            cin >> i;
            while (!cin.good())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter correct number: ";
                cin >> x;
            }
            cin.ignore();
            if (i > 0 && i < carDB.size() + 1)
            {
                carDB[i - 1].update();
                sort(carDB.begin(), carDB.end());
            }
            else
            {
                cout << "Wrong number. Press any key to continue" << endl;
                _getch();
            }
            break;
        case '2':
            cout << "Which bike you want to edit:\n"
                 << endl;
            showBikes();
            cin >> i;
            while (!cin.good())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter correct number: ";
                cin >> x;
            }
            cin.ignore();
            if (i > 0 && i < bikeDB.size() + 1)
            {
                bikeDB[i - 1].update();
                sort(bikeDB.begin(), bikeDB.end());
            }
            else
            {
                cout << "Wrong number. Press any key to continue" << endl;
                _getch();
            }
            break;
        default:
            break;
        }
        system("cls");
    }
};

void Client::removeVehicle()
{
    int i, x = 0;
    while (x != '1' && x != '2' && x != '3')
    {
        cout << "What you want to remove:\n1. Car\n2. Bike\n3. Cancel." << endl;
        x = _getch();
        system("cls");
        switch (x)
        {
        case '1':
            cout << "Which car you want to delete:\n"
                 << endl;
            showCars();
            cin >> i;
            while (!cin.good())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter correct number: ";
                cin >> x;
            }
            cin.ignore();
            if (i > 0 && i < carDB.size() + 1)
                carDB.erase(carDB.begin() + i - 1);
            else
            {
                cout << "Wrong number. Press any key to continue" << endl;
                _getch();
            }
            break;
        case '2':
            cout << "Which bike you want to delete:\n"
                 << endl;
            showBikes();
            cin >> i;
            while (!cin.good())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter correct number: ";
                cin >> x;
            }
            cin.ignore();
            if (i > 0 && i < bikeDB.size() + 1)
                bikeDB.erase(bikeDB.begin() + i - 1);
            else
            {
                cout << "Wrong number. Press any key to continue" << endl;
                _getch();
            }
            break;
        default:
            break;
        }
        system("cls");
    }
};

bool operator<(const Client &l, const Client &r)
{
    return tie(l.surname, l.name) < tie(r.surname, r.name);
};

void loadDB(vector<Client> &dataBase)
{
    fstream file;
    file.open("database.txt", ios::in);
    if (file)
    {
        streampos position;
        int i = 0;
        Client tempClient;
        Car tempCar;
        Bike tempBike;
        string check, temp;
        while (!file.eof())
        {
            file >> check;
            if (check == "Client:")
            {
                file >> tempClient;
                dataBase.push_back(tempClient);
                file >> check;
                if (check == "Cars:")
                {
                    file.ignore();
                    getline(file, check);
                    while (check != "---")
                    {
                        tempCar.retrieve(check);
                        dataBase[i].carDB.push_back(tempCar);
                        getline(file, check);
                    }
                }
                sort(dataBase[i].carDB.begin(), dataBase[i].carDB.end());
                file >> check;
                if (check == "Bikes:")
                {
                    file.ignore();
                    getline(file, check);
                    while (check != "---")
                    {
                        tempBike.retrieve(check);
                        dataBase[i].bikeDB.push_back(tempBike);
                        getline(file, check);
                    }
                }
                sort(dataBase[i].bikeDB.begin(), dataBase[i].bikeDB.end());
                ++i;
            }
        }
        sort(dataBase.begin(), dataBase.end());
    }
    file.close();
};

void saveDB(vector<Client> &dataBase)
{
    fstream file;
    file.open("database.txt", ios::out);
    if (file)
    {
        sort(dataBase.begin(), dataBase.end());

        for (int i = 0; i < dataBase.size(); ++i)
        {
            file << "Client: " << dataBase[i] << endl;
            file << "Cars:" << endl;
            sort(dataBase[i].carDB.begin(), dataBase[i].carDB.end());
            for (int j = 0; j < dataBase[i].carDB.size(); ++j)
                file << dataBase[i].carDB[j].toFile() << endl;
            file << "---\nBikes:" << endl;
            sort(dataBase[i].bikeDB.begin(), dataBase[i].bikeDB.end());
            for (int j = 0; j < dataBase[i].bikeDB.size(); ++j)
                file << dataBase[i].bikeDB[j].toFile() << endl;
            file << "---" << endl;
        }
    }
    file.close();
};

void showClients(vector<Client> &dataBase)
{
    for (int i = 0; i < dataBase.size(); ++i)
        cout << i + 1 << ". " << dataBase[i] << endl;
};

void addClient(vector<Client> &dataBase)
{
    Client temp;
    cout << "Please enter name and surname of client:" << endl;
    cin >> temp;
    cin.ignore();
    int i;
    for (i = 0; i < dataBase.size(); ++i)
    {
        if (temp < dataBase[i])
            break;
    }
    dataBase.insert(dataBase.begin() + i, temp);
};

void updateClient(vector<Client> &dataBase)
{
    cout << "Which client you want to edit:\n"
         << endl;
    showClients(dataBase);
    cout << dataBase.size() + 1 << ". Cancel\n"
         << endl;
    int x;
    cin >> x;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter correct number: ";
        cin >> x;
    }
    cin.ignore();
    if (x == dataBase.size() + 1)
        return;
    else if (x > 0 && x <= dataBase.size())
    {
        system("cls");
        cout << "Please enter new name and surname of " << dataBase[x - 1] << ":" << endl;
        cin >> dataBase[x - 1];
        cin.ignore();
        sort(dataBase.begin(), dataBase.end());
    }
    else
    {
        system("cls");
        cout << "Wrong number. Press any key to continue" << endl;
        _getch();
    }
};

void removeClient(vector<Client> &dataBase)
{
    cout << "Which client you want to delete?\n"
         << endl;
    showClients(dataBase);
    cout << dataBase.size() + 1 << ". Cancel\n"
         << endl;
    int x;
    cin >> x;
    while (!cin.good())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter correct number: ";
        cin >> x;
    }
    cin.ignore();
    if (x == dataBase.size() + 1)
        return;
    else if (x > 0 && x <= dataBase.size())
    {
        dataBase.erase(dataBase.begin() + x - 1);
    }
    else
    {
        system("cls");
        cout << "Wrong number. Press any key to continue" << endl;
        _getch();
    }
};

void choose(Client &client)
{
    system("cls");
    int x = 0;
    while (x != 27)
    {
        cout << "You are in " << client << " "
             << "What do you want to do?"
             << "\n1. Show client vehicles."
             << "\n2. Add new vehicle."
             << "\n3. Update vehicle."
             << "\n4. Remove vehicle."
             << "\nESC to exit." << endl;
        x = _getch();
        switch (x)
        {
        case '1':
            system("cls");
            client.showVehicles();
            break;
        case '2':
            system("cls");
            client.addVehicle();
            break;
        case '3':
            system("cls");
            client.updateVehicle();
            break;
        case '4':
            system("cls");
            client.removeVehicle();
            break;
        default:
            break;
        }
    }
}