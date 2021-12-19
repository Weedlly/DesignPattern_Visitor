#pragma once
#ifndef Visitor_h
#define Visitor_h
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Node.h"
#include "tinyxml.h"
#include <Windows.h>
using namespace std;

#define Map_Size  100

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

class Visitor {
public:
	virtual void visitCity(City*) = 0;
	virtual void visitIndustry(Industry*) = 0;
	virtual void visitFactory(Factory*) = 0;
	virtual void visitCommercial(Commercial*) = 0;
	virtual void visitConstruction(Construction*) = 0;
	virtual void visitResidential(Residential*) = 0;
};

class XMLExportVisitor : public Visitor {
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

class TXTExportVisitor : public Visitor {
public:
	//Export the industry's location , center coordinates and filename.
	void visitCity(City* city);
	void visitIndustry(Industry* industry);
	void visitFactory(Factory* factory);
	void visitCommercial(Commercial* commercial);
	void visitConstruction(Construction* construction);
	void visitResidential(Residential* residential);
};

class TaxVisitor :public Visitor { // D ver 8
public:
	// Calculate the tax of Nodes 
	void visitCity(City* city);
	void visitIndustry(Industry* industry);
	void visitFactory(Factory* factory);
	void visitCommercial(Commercial* commercial);
	void visitConstruction(Construction* construction);
	void visitResidential(Residential* residential);
};




#endif // !Visitor_h