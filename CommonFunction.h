#pragma once
#include "Node.h"
#include "Visitor.h"

///      CLASS INTERFACE
class Application {
private:
	vector<Node*> set_of_shape;
	vector<vector<int>> Map_Txt;

public:
	Application(string readFileName);
	vector<Node*> getNodeArr();
	void export_XML();
	void export_TXT(); // new code by Hoang ver7
	void export_CSV(); // new code by D ver6

	void console_Tax(); // D ver 8
};
std::string GetCurrentDirectory();
wstring StringToWString(const std::string& s);
bool CheckNodeIsExist(int length, int width, int x, int y, vector<vector<int>> Map_Txt);
vector<Node*> readfile(string filename, vector<vector<int>>& Map_Txt);
