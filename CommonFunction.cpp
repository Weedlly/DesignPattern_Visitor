#include "CommonFunction.h"

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

	wstring FilePath = StringToWString(Folder);

	// Full code
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

void Application::console_Tax() {
	TaxVisitor* taxV = new TaxVisitor;
	for (int i = 0; i < set_of_shape.size(); i++) {
		set_of_shape[i]->accept(taxV);
	}
	delete taxV;
}