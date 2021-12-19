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
	CreateDirectory(StringToWString(GetCurrentDirectory() + "\\XMLExport").c_str(), NULL);			// Hoang ver8
	XMLExportVisitor* customer = new XMLExportVisitor;
	for (int i = 0; i < set_of_shape.size(); i++) {
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}

void Application::export_TXT() {
	CreateDirectory(StringToWString(GetCurrentDirectory() + "\\TXTExport").c_str(), NULL);			// Hoang ver8
	TXTExportVisitor* customer = new TXTExportVisitor; // new code by Hoang ver7
	for (int i = 0; i < set_of_shape.size(); i++) {
		set_of_shape[i]->accept(customer);
	}
	delete customer;
}

void Application::export_CSV() {
	CreateDirectory(StringToWString(GetCurrentDirectory() + "\\CSVExport").c_str(), NULL);			// Hoang ver8
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