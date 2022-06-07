#include "Node.h"
#include "Visitor.h"

// Export the City's ID and center coordinates and name.
void XMLExportVisitor::visitCity(City* city) {
	Location location = city->getLocation();
	cout << location.x_ << "/" << location.y_ << "/" << city->getName() << "/" << endl;
	cout << "Export coordinates of City" << endl;
}
//void XMLExportVisitor::countPopulation(City* city) {
//	cout << "City's population:" << city->getPopulation();
//}
//
//void XMLExportVisitor::citySquare(City* city) { //fixed
//	cout << "City's square:" << city->getPopulation();
//}
//Export the industry's ID, center coordinates and name.
void XMLExportVisitor::visitIndustry(Industry* industry) {
	Location location = industry->getLocation();
	cout << location.x_ << "/" << location.y_ << "/" << industry->getName() << endl;
	cout << "Export coordinates of Industry" << endl;
}
//void XMLExportVisitor::countEmployee(Industry* industry) {
//	cout << "Industry's Employee:" << industry->getEmployee();
//}
//void XMLExportVisitor::industrySquare(Industry* industry) {
//	cout << "Industry's square" << industry->square();
//}

// Export the Factory's ID, center coordinates and name.
void XMLExportVisitor::visitFactory(Factory* factory) {
	Location location = factory->getLocation();
	cout << location.x_ << "/" << location.y_ << "/" << factory->getName() << endl;
	cout << "Export coordinates of Factory" << endl;
}

// Export the Construction's ID, center coordinates and name.
void XMLExportVisitor::visitConstruction(Construction* construction) {
	Location location = construction->getLocation();
	cout << location.x_ << "/" << location.y_ << "/" << construction->getName() << endl;
	cout << "Export coordinates of Construction" << endl;
}
//void XMLExportVisitor::countEmployee(Construction* construction) {
//	cout << "Construction's Employee:" << construction->getEmployee();
//}
//void XMLExportVisitor::constructionSquare(Construction* construction) {
//	cout << "Construction's square" << construction->square();
//}

// Export the Commercial's ID, center coordinates and name.
void XMLExportVisitor::visitCommercial(Commercial* commercial) {
	Location location = commercial->getLocation();
	cout << location.x_ << "/" << location.y_ << "/" << commercial->getName() << endl;
	cout << "Export coordinates of Commercial" << endl;
}
//void XMLExportVisitor::commercialSquare(Commercial* commercial) {
//	cout << "Commercial's square:" << commercial->square();
//} //new add
// Export the Residential's ID, center coordinates and name.
void XMLExportVisitor::visitResidential(Residential* residential) {               // new code by D
	Location location = residential->getLocation();
	cout << location.x_ << "/" << location.y_ << "/" << residential->getName() << endl;
	cout << "Export coordinates of Residential" << endl;
}

void export_MapCSV(Node* node, ofstream& fout) {  // new code by D ver6
	for (int i = 0; i < Map_Size; i++)
	{
		for (int j = 0; j < Map_Size; j++)
		{
			if ((i >= node->getLocation().x_ && i < node->getLocation().x_ + node->getSize().length) && (j >= node->getLocation().y_ && j < node->getLocation().y_ + node->getSize().width)) {
				fout << 1 << ",";
			}
			else fout << 0 << ",";
		}
		fout << endl;
	}
}

void CSVExportVisitor::visitCity(City* city) {   // new code by D ver6
	string nameF = "City_" + city->getName() + ".csv";
	ofstream fout(nameF);

	export_MapCSV(city, fout);
	fout << endl << endl;
	fout << "Population: " << city->getPopulation();
	fout.close();
}

void CSVExportVisitor::visitCommercial(Commercial* commercial) { // new code by An 
	string nameF = "Commercial_" + commercial->getName() + ".csv";
	ofstream fout(nameF);

	export_MapCSV(commercial, fout);
	fout << endl << endl;
	fout << "Status: " << commercial->getStatus();
	fout.close();
}

void CSVExportVisitor::visitConstruction(Construction* construction) { // new code by An 
	string nameF = "Construction_" + construction->getName() + ".csv";
	ofstream fout(nameF);

	export_MapCSV(construction, fout);
	fout << endl << endl;
	fout << "Staff: " << construction->getEmployee();
	fout.close();
}

void CSVExportVisitor::visitFactory(Factory* factory) {    // new code by D ver6
	string nameF = "Factory_" + factory->getName() + ".csv";
	ofstream fout(nameF);

	export_MapCSV(factory, fout);
	fout << endl << endl;
	fout << "Status: " << factory->getStatus() << endl;
	fout << "Mode of operation: " << factory->getMode();
	fout.close();
}

void CSVExportVisitor::visitIndustry(Industry* industry) {    // new code by D ver6
	string nameF = "Industry_" + industry->getName() + ".csv";
	ofstream fout(nameF);

	export_MapCSV(industry, fout);
	fout << endl << endl;
	fout << "Form: " << industry->getForm() << endl;
	fout << "Staff: " << industry->getEmployee();
	fout.close();
}

void CSVExportVisitor::visitResidential(Residential* residential) {  // new code by D ver6
	string nameF = "Residential_" + residential->getName() + ".csv";
	ofstream fout(nameF);

	export_MapCSV(residential, fout);
	fout << endl << endl;
	fout << "Population: " << residential->getPop() << endl;
	fout << "Apartment Names: ";
	for (int i = 0; i < residential->getNOA().size(); i++) {
		fout << residential->getNOA()[i] << ",";
	}
	
	fout.close();
}




// TXTExport
void TXTExportVisitor::Print_MapTXT(vector<vector<int>> Map_Txt) {
	for (int i = 0; i < Map_Size; i++)
	{
		for (int j = 0; j < Map_Size; j++)
		{
			cout << Map_Txt[i][j] << "   ";
		}
		cout << endl;
	}
}

/// Application
Application::Application(string readFileName) {
	Map_Txt.resize(Map_Size);
	for (int i = 0; i < Map_Size; i++)
	{
		Map_Txt[i].resize(Map_Size);
	}

	set_of_shape = readfile(readFileName, Map_Txt);
}
vector<Node*> Application::getNodeArr() {
	return set_of_shape;
}
void Application::export_XML() {
	XMLExportVisitor* customer = new XMLExportVisitor;
	for (int i = 0; i < set_of_shape.size(); i++)
	{
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}
void Application::printMapTXT() {
	for (int i = 0; i < Map_Size; i++)
	{
		for (int j = 0; j < Map_Size; j++)
		{
			cout << Map_Txt[i][j] << "   ";
		}
		cout << endl;
	}
}

void Application::export_CSV() {
	
	CSVExportVisitor* customer = new CSVExportVisitor;
	for (int i = 0; i < set_of_shape.size(); i++)
	{
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}

//void Application::printMapTXT() {
//	TXTExportVisitor* customer = new TXTExportVisitor;
//
//}

