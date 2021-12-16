#include "Node.h"
#include "Visitor.h"

// Two function help to get directory and create new directory
std::string GetCurrentDirectory()				// Hoang ver7
{
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	std::string::size_type pos = std::string(buffer).find_last_of("\\/");
	return std::string(buffer).substr(0, pos);
}
wstring StringToWString(const std::string& s)				// Hoang ver7
{
	std::wstring wsTmp(s.begin(), s.end());

	return wsTmp;
}
//
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
	string Folder = GetCurrentDirectory() + "\\XMLExport";							// Hoang ver8
	string fileName = Folder + "\\City_" + city->getName() + ".xml";				//push all file to folder

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
	string Folder = GetCurrentDirectory() + "\\XMLExport";							// Hoang ver8
	string fileName = Folder + "\\Industry_" + industry->getName() + ".xml";			//push all file to folder

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
// Code by Duong ver 7
void XMLExportVisitor::visitFactory(Factory* factory) {
	string Folder = GetCurrentDirectory() + "\\XMLExport";							// Hoang ver8
	string fileName = Folder + "\\Factory_" + factory->getName() + ".xml";				//push all file to folder

	TiXmlDocument doc;
	export_TypeXML(doc, factory, "Factory");
	TiXmlElement* root = doc.FirstChildElement();

	string StatusVal = to_string(factory->getStatus());
	string ModeVal = factory->getMode();
	TiXmlElement* Status = new TiXmlElement("Status");
	TiXmlText* StatusContent = new TiXmlText(&StatusVal[0]);
	root->LinkEndChild(Status);
	TiXmlElement* Mode = new TiXmlElement("Mode");
	TiXmlText* ModeContent = new TiXmlText(&ModeVal[0]);
	root->LinkEndChild(Mode);
	doc.SaveFile(&fileName[0]);
}

void XMLExportVisitor::visitConstruction(Construction* construction) {
	string Folder = GetCurrentDirectory() + "\\XMLExport";						// Hoang ver8
	string fileName = Folder + "\\construction_" + construction->getName() + ".xml";	//push all file to folder

	TiXmlDocument doc;
	export_TypeXML(doc, construction, "Factory");
	TiXmlElement* root = doc.FirstChildElement();

	string EmployeeVal = to_string(construction->getEmployee());
	TiXmlElement* Employee = new TiXmlElement("Employee");
	TiXmlText* EmployeeContent = new TiXmlText(&EmployeeVal[0]);
	root->LinkEndChild(Employee);
	Employee->LinkEndChild(EmployeeContent);
	doc.SaveFile(&fileName[0]);
}
// code by An ver 7
void XMLExportVisitor::visitCommercial(Commercial* commercial) {
	string Folder = GetCurrentDirectory() + "\\XMLExport";							// Hoang ver8
	string fileName = Folder + "\\Commercial_" + commercial->getName() + ".xml";			//push all file to folder

	TiXmlDocument doc;
	export_TypeXML(doc, commercial, "Commercial");

	TiXmlElement* root = doc.FirstChildElement();
	string StatusVal = to_string(commercial->getStatus());
	TiXmlElement* Status = new TiXmlElement("Status");
	TiXmlText* StatusContent = new TiXmlText(&StatusVal[0]);
	root->LinkEndChild(Status);
	doc.SaveFile(&fileName[0]);
}
void XMLExportVisitor::visitResidential(Residential* residential) {
	string Folder = GetCurrentDirectory() + "\\XMLExport";							//push all file to folder
	string fileName = Folder + "\\Residential_" + residential->getName() + ".xml";			// Hoang ver8

	TiXmlDocument doc;
	export_TypeXML(doc, residential, "Residential");

	TiXmlElement* root = doc.FirstChildElement();
	string populationVal = to_string(residential->getPopulation());
	TiXmlElement* population = new TiXmlElement("Population");
	TiXmlText* populationContent = new TiXmlText(&populationVal[0]);
	vector<string> getApartment = residential->getNOA();
	string nameOfapartments = "";
	for (int i = 0; i < getApartment.size(); i++) {
		if (i == getApartment.size() - 1) {
			nameOfapartments = nameOfapartments + getApartment[i];
		}
		else {
			nameOfapartments = nameOfapartments + getApartment[i] + " ";
		}
	}
	TiXmlElement* Apartments = new TiXmlElement("nameOfApartment");
	TiXmlText* ApartmentContent = new TiXmlText(&nameOfapartments[0]);
	root->LinkEndChild(population);
	population->LinkEndChild(populationContent);
	root->LinkEndChild(Apartments);
	Apartments->LinkEndChild(ApartmentContent);
	doc.SaveFile(&fileName[0]);
}

void export_MapCSV(Node* node, ofstream& fout) {  // new code by D ver6
	for (int i = 0; i < Map_Size; i++) {
		for (int j = 0; j < Map_Size; j++) {
			if ((i >= node->getLocation().x_ && i < node->getLocation().x_ + node->getSize().length) && (j >= node->getLocation().y_ && j < node->getLocation().y_ + node->getSize().width)) {
				fout << 1 << ",";
			}
			else fout << 0 << ",";
		}
		fout << endl;
	}
}

void CSVExportVisitor::visitCity(City* city) {   // new code by D ver6
	string Folder = GetCurrentDirectory() + "\\CSVExport";								  //push to export folder
	string nameF = Folder + "\\City_" + city->getName() + ".csv";

	ofstream fout(nameF);

	export_MapCSV(city, fout);
	fout << endl << endl;
	fout << "Population: " << city->getPopulation();
	fout.close();
}

void CSVExportVisitor::visitCommercial(Commercial* commercial) { // new code by An
	string Folder = GetCurrentDirectory() + "\\CSVExport";								  //push to export folder
	string nameF = Folder + "\\Commercial_" + commercial->getName() + ".csv";

	ofstream fout(nameF);

	export_MapCSV(commercial, fout);
	fout << endl << endl;
	fout << "Status: " << commercial->getStatus();
	fout.close();
}

void CSVExportVisitor::visitConstruction(Construction* construction) { // new code by An
	/*string nameF = "Construction_" + construction->getName() + ".csv";*/
	string Folder = GetCurrentDirectory() + "\\CSVExport";								  //push to export folder
	string nameF = Folder + "\\Construction_" + construction->getName() + ".csv";

	ofstream fout(nameF);

	export_MapCSV(construction, fout);
	fout << endl << endl;
	fout << "Staff: " << construction->getEmployee();
	fout.close();
}

void CSVExportVisitor::visitFactory(Factory* factory) {    // new code by D ver6
	string Folder = GetCurrentDirectory() + "\\CSVExport";								  //push to export folder
	string nameF = Folder + "\\Factory_" + factory->getName() + ".csv";

	ofstream fout(nameF);

	export_MapCSV(factory, fout);
	fout << endl << endl;
	fout << "Status: " << factory->getStatus() << endl;
	fout << "Mode of operation: " << factory->getMode();
	fout.close();
}

void CSVExportVisitor::visitIndustry(Industry* industry) {    // new code by D ver6
	string Folder = GetCurrentDirectory() + "\\CSVExport";								  //push to export folder
	string nameF = Folder + "\\Industry_" + industry->getName() + ".csv";

	ofstream fout(nameF);

	export_MapCSV(industry, fout);
	fout << endl << endl;
	fout << "Form: " << industry->getForm() << endl;
	fout << "Staff: " << industry->getEmployee();
	fout.close();
}

void CSVExportVisitor::visitResidential(Residential* residential) {  // new code by D ver6
	string Folder = GetCurrentDirectory() + "\\CSVExport";								  //push to export folder
	string nameF = Folder + "\\Residential_" + residential->getName() + ".csv";

	ofstream fout(nameF);

	export_MapCSV(residential, fout);
	fout << endl << endl;
	fout << "Population: " << residential->getPopulation() << endl;
	fout << "Apartment Names: ";
	for (int i = 0; i < residential->getNOA().size(); i++) {
		fout << residential->getNOA()[i] << ",";
	}

	fout.close();
}

// TXT export

void export_MapTXT(Node* node, ofstream& fout) {  // new code by Hoang ver7
	for (int i = 0; i < Map_Size; i++) {
		for (int j = 0; j < Map_Size; j++) {
			if ((i >= node->getLocation().x_ && i < node->getLocation().x_ + node->getSize().length) && (j >= node->getLocation().y_ && j < node->getLocation().y_ + node->getSize().width)) {
				fout << 1 << " ";
			}
			else fout << 0 << " ";
		}
		fout << endl;
	}
}

void TXTExportVisitor::visitCity(City* city) {   // new code by Hoang ver7
	string Folder = GetCurrentDirectory() + "\\TXTExport";								  //push to export folder
	string nameF = Folder + "\\City_" + city->getName() + ".txt";

	ofstream fout(nameF);

	export_MapTXT(city, fout);
	fout << endl << endl;
	fout << "Population: " << city->getPopulation();
	fout.close();
}

void TXTExportVisitor::visitCommercial(Commercial* commercial) { // new code by Hoang ver 7
	string Folder = GetCurrentDirectory() + "\\TXTExport";								  //push to export folder
	string nameF = Folder + "\\Commercial_" + commercial->getName() + ".txt";

	ofstream fout(nameF);

	export_MapTXT(commercial, fout);
	fout << endl << endl;
	fout << "Status: " << commercial->getStatus();
	fout.close();
}

void TXTExportVisitor::visitConstruction(Construction* construction) { // new code by Hoang ver7
	string Folder = GetCurrentDirectory() + "\\TXTExport";								  //push to export folder
	string nameF = Folder + "\\Construction_" + construction->getName() + ".txt";

	ofstream fout(nameF);

	export_MapTXT(construction, fout);
	fout << endl << endl;
	fout << "Staff: " << construction->getEmployee();
	fout.close();
}

void TXTExportVisitor::visitFactory(Factory* factory) {    // new code by Hoang ver7
	string Folder = GetCurrentDirectory() + "\\TXTExport";								  //push to export folder
	string nameF = Folder + "\\Factory_" + factory->getName() + ".txt";

	ofstream fout(nameF);

	export_MapTXT(factory, fout);
	fout << endl << endl;
	fout << "Status: " << factory->getStatus() << endl;
	fout << "Mode of operation: " << factory->getMode();
	fout.close();
}

void TXTExportVisitor::visitIndustry(Industry* industry) {    // new code by Hoang ver7
	string Folder = GetCurrentDirectory() + "\\TXTExport";								  //push to export folder
	string nameF = Folder + "\\Industry_" + industry->getName() + ".txt";

	ofstream fout(nameF);

	export_MapTXT(industry, fout);
	fout << endl << endl;
	fout << "Form: " << industry->getForm() << endl;
	fout << "Staff: " << industry->getEmployee();
	fout.close();
}

void TXTExportVisitor::visitResidential(Residential* residential) {  // new code by Hoang ver7
	string Folder = GetCurrentDirectory() + "\\TXTExport";								  //push to export folder
	string nameF = Folder + "\\Residential_" + residential->getName() + ".txt";

	ofstream fout(nameF);

	export_MapTXT(residential, fout);
	fout << endl << endl;
	fout << "Population: " << residential->getPopulation() << endl;
	fout << "Apartment Names: ";
	for (int i = 0; i < residential->getNOA().size(); i++) {
		fout << residential->getNOA()[i] << ",";
	}

	fout.close();
}

/// Application : Interface
Application::Application(string readFileName) {
	//new code push all file to folder												// Hoang ver8
	//string Folder = GetCurrentDirectory() + "\\ResidentialFolder";
	//wstring FilePath = StringToWString(Folder);									// Full code
	//CreateDirectory(FilePath.c_str(), NULL);
	//CreateDirectory(StringToWString(GetCurrentDirectory() + "\\CityFolder").c_str(), NULL);
	//CreateDirectory(StringToWString(GetCurrentDirectory() + "\\ConstructionFolder").c_str(), NULL);			//optimize code
	//CreateDirectory(StringToWString(GetCurrentDirectory() + "\\CommercialFolder").c_str(), NULL);
	//CreateDirectory(StringToWString(GetCurrentDirectory() + "\\IndustryFolder").c_str(), NULL);
	//CreateDirectory(StringToWString(GetCurrentDirectory() + "\\ResidentialFolder").c_str(), NULL);
	//CreateDirectory(StringToWString(GetCurrentDirectory() + "\\FactoryFolder").c_str(), NULL);

	//new code push all file to export type folder												// Hoang ver8
	string Folder = GetCurrentDirectory() + "\\XMLExport";
	wstring FilePath = StringToWString(Folder);									// Full code
	CreateDirectory(FilePath.c_str(), NULL);
	CreateDirectory(StringToWString(GetCurrentDirectory() + "\\XMLExport").c_str(), NULL);
	CreateDirectory(StringToWString(GetCurrentDirectory() + "\\TXTExport").c_str(), NULL);			//optimize code
	CreateDirectory(StringToWString(GetCurrentDirectory() + "\\CSVExport").c_str(), NULL);

	Map_Txt.resize(Map_Size);
	for (int i = 0; i < Map_Size; i++) {
		Map_Txt[i].resize(Map_Size);
	}

	set_of_shape = readfile(readFileName, Map_Txt);
}

vector<Node*> Application::getNodeArr() {
	return set_of_shape;
}
void Application::export_XML() {
	XMLExportVisitor* customer = new XMLExportVisitor;
	for (int i = 0; i < set_of_shape.size(); i++) {
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}

void Application::export_TXT() {
	TXTExportVisitor* customer = new TXTExportVisitor; // new code by Hoang ver7
	for (int i = 0; i < set_of_shape.size(); i++) {
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}

void Application::export_CSV() {
	CSVExportVisitor* customer = new CSVExportVisitor;
	for (int i = 0; i < set_of_shape.size(); i++) {
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}
