#include "Node.h"
#include "Visitor.h"

// Export the City's ID and center coordinates and name.
// XML export
//void XMLExportVisitor::countPopulation(City* city) {
//	cout << "City's population:" << city->getPopulation();   // Error
//}
//
//void XMLExportVisitor::citySquare(City* city) {
//	cout << "City's square:" << city->getPopulation();
//}
//Export the industry's ID, center coordinates and name.
//void XMLExportVisitor::countEmployee(Industry* industry) {
//	cout << "Industry's Employee:" << industry->getEmployee();			// Error
//}
//void XMLExportVisitor::industrySquare(Industry* industry) {
//	cout << "Industry's square" << industry->square();
//}
//void XMLExportVisitor::countEmployee(Construction* construction) {
//	cout << "Construction's Employee:" << construction->getEmployee();			// Error
//}
//void XMLExportVisitor::constructionSquare(Construction* construction) {
//	cout << "Construction's square" << construction->square();
//}
//void XMLExportVisitor::commercialSquare(Commercial* commercial) {			// Error
//	cout << "Commercial's square:" << commercial->square();
//} //new add
// Export the Residential's ID, center coordinates and name.

void export_TypeXML(TiXmlDocument& doc, Node* node, string _typeName) {				// Hoang ver7
	TiXmlDeclaration* dec = new TiXmlDeclaration("1.0", "utf-8", "");
	doc.LinkEndChild(dec);

	TiXmlElement* root = new TiXmlElement(&_typeName[0]);
	root->SetAttribute("id", 1);
	doc.LinkEndChild(root);

	TiXmlElement* location = new TiXmlElement("Location");

	// set up location x
	string xVal = to_string(node->getLocation().x_);
	TiXmlElement* locationX = new TiXmlElement("X");
	TiXmlText* locationXContent = new TiXmlText(&xVal[0]);
	location->LinkEndChild(locationX);
	locationX->LinkEndChild(locationXContent);

	// set up location y
	string yVal = to_string(node->getLocation().y_);
	TiXmlElement* locationY = new TiXmlElement("Y");
	TiXmlText* locationYContent = new TiXmlText(&yVal[0]);
	location->LinkEndChild(locationY);
	locationY->LinkEndChild(locationYContent);

	// set up Name
	string nameVal = node->getName();
	TiXmlElement* name = new TiXmlElement("Name");
	TiXmlText* nameContent = new TiXmlText(&nameVal[0]);
	root->LinkEndChild(name);
	name->LinkEndChild(nameContent);												// Hoang ver7

	root->LinkEndChild(location);
}

void XMLExportVisitor::visitCity(City* city) {
	string fileName = "City_" + city->getName() + ".xml";
	TiXmlDocument doc;
	export_TypeXML(doc, city, "City");

	TiXmlElement* root = doc.FirstChildElement();									// Hoang ver7

	string populationVal = to_string(city->getPopulation());
	TiXmlElement* population = new TiXmlElement("Population");
	TiXmlText* populationContent = new TiXmlText(&populationVal[0]);
	root->LinkEndChild(population);
	population->LinkEndChild(populationContent);

	doc.SaveFile(&fileName[0]);
}
void XMLExportVisitor::visitIndustry(Industry* industry) {
	string fileName = "Industry_" + industry->getName() + ".xml";
	TiXmlDocument doc;
	export_TypeXML(doc, industry, "Industry");
	// Hoang ver7
	TiXmlElement* root = doc.FirstChildElement();

	string EmployeeVal = to_string(industry->getEmployee());
	TiXmlElement* Employee = new TiXmlElement("Employee");
	TiXmlText* EmployeeContent = new TiXmlText(&EmployeeVal[0]);
	root->LinkEndChild(Employee);
	Employee->LinkEndChild(EmployeeContent);

	doc.SaveFile(&fileName[0]);
}

void XMLExportVisitor::visitFactory(Factory* factory) {
	// .........
}

void XMLExportVisitor::visitConstruction(Construction* construction) {
	// .........
}

void XMLExportVisitor::visitCommercial(Commercial* commercial) {
	// .........
}
void XMLExportVisitor::visitResidential(Residential* residential) {
	// .........
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

// TXT export

void export_MapTXT(Node* node, ofstream& fout) {  // new code by Hoang ver7
	for (int i = 0; i < Map_Size; i++)
	{
		for (int j = 0; j < Map_Size; j++)
		{
			if ((i >= node->getLocation().x_ && i < node->getLocation().x_ + node->getSize().length) && (j >= node->getLocation().y_ && j < node->getLocation().y_ + node->getSize().width)) {
				fout << 1 << " ";
			}
			else fout << 0 << " ";
		}
		fout << endl;
	}
}

void TXTExportVisitor::visitCity(City* city) {   // new code by Hoang ver7
	string nameF = "City_" + city->getName() + ".txt";
	ofstream fout(nameF);

	export_MapTXT(city, fout);
	fout << endl << endl;
	fout << "Population: " << city->getPopulation();
	fout.close();
}

void TXTExportVisitor::visitCommercial(Commercial* commercial) { // new code by Hoang ver 7
	string nameF = "Commercial_" + commercial->getName() + ".txt";
	ofstream fout(nameF);

	export_MapTXT(commercial, fout);
	fout << endl << endl;
	fout << "Status: " << commercial->getStatus();
	fout.close();
}

void TXTExportVisitor::visitConstruction(Construction* construction) { // new code by Hoang ver7
	string nameF = "Construction_" + construction->getName() + ".txt";
	ofstream fout(nameF);

	export_MapTXT(construction, fout);
	fout << endl << endl;
	fout << "Staff: " << construction->getEmployee();
	fout.close();
}

void TXTExportVisitor::visitFactory(Factory* factory) {    // new code by Hoang ver7
	string nameF = "Factory_" + factory->getName() + ".txt";
	ofstream fout(nameF);

	export_MapTXT(factory, fout);
	fout << endl << endl;
	fout << "Status: " << factory->getStatus() << endl;
	fout << "Mode of operation: " << factory->getMode();
	fout.close();
}

void TXTExportVisitor::visitIndustry(Industry* industry) {    // new code by Hoang ver7
	string nameF = "Industry_" + industry->getName() + ".txt";
	ofstream fout(nameF);

	export_MapTXT(industry, fout);
	fout << endl << endl;
	fout << "Form: " << industry->getForm() << endl;
	fout << "Staff: " << industry->getEmployee();
	fout.close();
}

void TXTExportVisitor::visitResidential(Residential* residential) {  // new code by Hoang ver7
	string nameF = "Residential_" + residential->getName() + ".txt";
	ofstream fout(nameF);

	export_MapTXT(residential, fout);
	fout << endl << endl;
	fout << "Population: " << residential->getPop() << endl;
	fout << "Apartment Names: ";
	for (int i = 0; i < residential->getNOA().size(); i++) {
		fout << residential->getNOA()[i] << ",";
	}

	fout.close();
}

/// Application : Interface
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

void Application::export_TXT() {
	TXTExportVisitor* customer = new TXTExportVisitor; // new code by Hoang ver7
	for (int i = 0; i < set_of_shape.size(); i++)
	{
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}

void Application::export_CSV() {
	CSVExportVisitor* customer = new CSVExportVisitor;
	for (int i = 0; i < set_of_shape.size(); i++)
	{
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}