#pragma once
#include "header.h"
#include "vehicle.h"

using namespace std;

class Client
{
private:
	string name;
	string surname;
	vector<Car> carDB;
	vector<Bike> bikeDB;

public:
	Client()
	{
		name = "unknown";
		surname = "unknown";
	};
	///Adds new vehicle to client (either car or bike)
	void addVehicle();
	///Removes vehicle of client (either car or bike)
	void removeVehicle();
	///Updates vehicle of client (either car or bike)
	void updateVehicle();
	///Shows all cars and vehicles of client
	void showVehicles();
	///Shows all cars of client
	void showCars();
	///Shows all bikes of client
	void showBikes();
	///Compares 2 clients alphabetically (first surnames, next names)
	friend bool operator<(const Client& l, const Client& r);
	///Adds new client to dataBase
	friend void addClient(vector<Client>& dataBase); 
	///Loads from file all clients and their cars nad bikes to dataBase
	friend void loadDB(vector<Client>& dataBase);
	///Saves to file all clients and their cars nad bikes to dataBase
	friend void saveDB(vector<Client>& dataBase);
	///Prints to output stream name and surname of client
	friend ostream& operator<<(ostream& os, const Client& obj);
	///Takes from input stream name and surname of client 
	friend istream& operator>>(istream& is, Client& obj);
};

///Shows all clients
void showClients(vector<Client>& dataBase);
///Updates client info 
void updateClient(vector<Client>& dataBase);
///Removes client 
void removeClient(vector<Client>& dataBase);
///Shows what you can do to vehicles of given client
void choose(Client& client);