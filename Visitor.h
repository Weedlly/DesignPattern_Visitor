#pragma once
#ifndef Visitor_h
#define Visitor_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Node.h"
using namespace std;

#define Map_Size  20

struct Location;
class Node;
class City;
class Construction;
class Industry;
class Factory;
class Commercial;
class Residential;
class ReadDataFile;
class XMLExportVisitor;

class Visitor
{
public:
	virtual void visitCity(City*) = 0;
	virtual void visitIndustry(Industry*) = 0;
	virtual void visitFactory(Factory*) = 0;
	virtual void visitCommercial(Commercial*) = 0;
	virtual void visitConstruction(Construction*) = 0;
	virtual void visitResidential(Residential*) = 0;
};

class XMLExportVisitor : public Visitor
{
public:
	// Export the City's ID and center coordinates and name.
	void visitCity(City* city);

	//void countPopulation(City* city);         // Warning
	//void citySquare(City* city);
	
	//Export the industry's ID, center coordinates and name.
	void visitIndustry(Industry* industry);

	//void countEmployee(Industry* industry);  // Warning
	//void industrySquare(Industry* industry);
	// 
	// Export the Factory's ID, center coordinates and name.
	void visitFactory(Factory* factory);
	// Export the Commercial's ID, center coordinates and name.
	void visitCommercial(Commercial* commercial);

	//void commercialSquare(Commercial* commercial);   Warning


	// Export the Construction's ID, center coordinates and name.
	void visitConstruction(Construction* construction);
	//void countEmployee(Construction* construction);   // Warning
	//void constructionSquare(Construction* construction);

	// Export the Residential's ID, center coordinates and name.
	void visitResidential(Residential* residential);
};
class CSVExportVisitor : public Visitor  // new code by D ver6
{
public:
	// Export the City's ID and center coordinates and name.
	void visitCity(City* city);
	
	//Export the industry's ID, center coordinates and name.
	void visitIndustry(Industry* industry);
	
	// Export the Factory's ID, center coordinates and name.
	void visitFactory(Factory* factory);
	// Export the Commercial's ID, center coordinates and name.
	void visitCommercial(Commercial* commercial);
	
	// Export the Construction's ID, center coordinates and name.
	void visitConstruction(Construction* construction);
	
	// Export the Residential's ID, center coordinates and name.
	void visitResidential(Residential* residential);
};


class TXTExportVisitor : public Visitor
{
public:
	void Print_MapTXT(vector<vector<int>> Map_Txt);
};

class Application
{
private:
	vector<Node*> set_of_shape;
	vector<vector<int>> Map_Txt;

	
public:
	Application(string readFileName);
	vector<Node*> getNodeArr();
	void export_XML();
	void printMapTXT();

	void export_CSV(); // new code by D ver6
};

#endif // !Visitor_h

