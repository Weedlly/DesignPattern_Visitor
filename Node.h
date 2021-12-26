#pragma once
#ifndef Node_h
#define Node_h
#include "Visitor.h"

class Application;
class XMLExportVisitor;
class Visitor;

struct Location {
	int x_;
	int y_;
};
struct Size {
	int length;
	int width;
};
// Base class Shape
class Node {
protected:
	Location location_;
	Size size_;
	string name_;
	int id_;
	static int count_id;
public:
	Node();
	Node(int x, int y);
	Node(int x, int y, string name);
	Node(int x, int y, int len, int wid, string name);
	string getName() {
		return name_;
	}
	Size getSize() {
		return size_;
	}
	Location getLocation() {
		return location_;
	}
	virtual void accept(Visitor* v) = 0;
	virtual void print() {}
};

// Derived classes of Node
// City
class City : public Node {
private:
	int population_;
public:
	City();
	City(int len, int wid, int x, int y, string name, int population);
	void accept(Visitor* v);
	int getPopulation() {
		return population_;
	}
	void print() override {
		cout << size_.length << " " << size_.width << " " << location_.x_ << " " << location_.y_ << " " << name_ << " " << population_ << endl;
	}
};

// Industry
class Industry : public Node {
private:
	long int staff;
	string form;
public:
	void accept(Visitor* v);
	Industry() : Node(), staff(0), form("") {}
	Industry(int len, int wid, int x, int y, string name, int s, string fo);
	int getEmployee() {
		return staff;
	}
	string getForm() {
		return form;
	}
	void print() override {
		cout << size_.length << " " << size_.width << " " << location_.x_ << " " << location_.y_ << " " << name_ << " " << staff << " ";
		cout << form << endl;
	}
};

// Construction
class Construction : public Node {
private:
	int staff;
	string type;
public:
	Construction() : Node(), staff(0), type("") {}
	Construction(int len, int wid, int x, int y, string name, int s, string t);
	void accept(Visitor* v);
	int getEmployee() {
		return staff;
	}
	void print() override {
		cout << size_.length << " " << size_.width << " " << location_.x_ << " " << location_.y_ << " " << name_ << " " << staff << " ";
		cout << type << endl;
	}
	string getType() {
		return type;
	}
};

// Factory
class Factory : public Node {
private:
	bool status;
	string modeOfOperation;
	int numProduct; // D ver 8
public:
	Factory() :Node(), status(0), modeOfOperation(""), numProduct(0) {}
	Factory(int len, int wid, int x, int y, string name, bool sta, string mode, int nP);
	void print() override {
		cout << size_.length << " " << size_.width << " " << location_.x_ << " " << location_.y_ << " " << name_ << " " << status << " ";
		cout << modeOfOperation << endl;
	}
	bool getStatus() {
		return status;
	}
	string getMode() {
		return modeOfOperation;
	}
	int getNumProduct() {
		return numProduct;
	}
	void accept(Visitor* v);
};

// Commercial
class Commercial : public Node {
private:
	bool status;
public:
	Commercial(int len, int wid, int x, int y, string name, bool sta);
	void accept(Visitor* v);
	bool getStatus()
	{
		return status;
	}
	void print() override {
		cout << size_.length << " " << size_.width << " " << location_.x_ << " " << location_.y_ << " " << name_ << " " << status << endl;
	}
};

// Residential
class Residential : public Node                 // new code by D
{
private:
	vector<string> nameOfApartment;
	int population;
public:
	Residential() :Node(), population(0), nameOfApartment(NULL) {}
	Residential(int len, int wid, int x, int y, string name, int pop, vector<string> noA);
	void accept(Visitor* v);
	int getPopulation() {
		return population;
	}
	vector<string>getNOA() {
		return nameOfApartment;
	}
	void print() override {
		cout << size_.length << " " << size_.width << " " << location_.x_ << " " << location_.y_ << " " << name_ << " " << population << " ";
		for (int i = 0; i < nameOfApartment.size(); i++)
			cout << nameOfApartment[i] << " ";
	}
};

#endif // !Node_h