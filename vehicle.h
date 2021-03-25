#pragma once
#include "header.h"

class Vehicle
{
protected:
	string brand;
	string model;
	string engine;
	int productionYear;
	double price;

public:
	Vehicle()
	{
		brand = "unknown";
		model = "unknown";
		engine = "unknown";
		productionYear = 0;
		price = 0;
	};
	virtual void create() = 0;
	virtual void update() = 0;
	virtual string toFile() = 0;
	virtual void retrieve(string input) = 0;
	friend class Client;
	///Compares 2 vehicles alphabetically and chronologically (first brand, second model, last production Year)
	friend bool operator<(const Vehicle& l, const Vehicle& r);
};

class Car : public Vehicle
{
protected:
	int numberOfDoors;
	string drive;

public:
	Car()
	{
		numberOfDoors = 0;
		drive = "unknown";
	}
	///Create car with given datas
	void create();
	///Updates datas of car
	void update();
	///Takes datas of car from given string
	void retrieve(string input);
	///Returns string with datas of car to pass to file
	string toFile();
	///Prints to output stream datas of car
	friend ostream& operator<<(ostream& os, const Car& obj);
	///Takes from input stream datas of car 
	friend istream& operator>>(istream& is, Car& obj);
};

class Bike : public Vehicle
{
protected:
	string type;

public:
	Bike()
	{
		type = "unknown";
	}
	///Create bike with given datas
	void create();
	///Updates datas of bike
	void update();
	///Takes datas of bike from given string
	void retrieve(string input);
	///Returns string with datas of bike to pass to file
	string toFile();
	///Prints to output stream datas of bike
	friend ostream& operator<<(ostream& os, const Bike& obj);
	///Takes from input stream datas of bike 
	friend istream& operator>>(istream& is, Bike& obj);
};