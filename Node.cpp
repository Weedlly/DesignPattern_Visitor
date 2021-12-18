#include "Node.h"
#include "Visitor.h"

// Node
// Optimize constructor //begin
Node::Node() {
	location_.x_ = 0;
	location_.y_ = 0;
	name_ = "";
	id_ = ++count_id;
}
Node::Node(int x, int y) : Node() {
	location_.x_ = x;
	location_.y_ = y;
}
Node::Node(int x, int y, string name) : Node(x, y) {
	name_ = name;
}
Node::Node(int x, int y, int len, int wid, string name) : Node(x, y, name) {
	size_.length = len;
	size_.width = wid;
}
//// Optimize constructor //end

bool CheckNodeIsExist(int length, int width, int x, int y, vector<vector<int>> Map_Txt) {
	for (int i = x; i < x + length; i++) {
		for (int j = y; j < y + width; j++) {
			if (Map_Txt[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}
vector<Node*> readfile(string filename, vector<vector<int>>& Map_Txt) {
	vector<Node* >node;
	ifstream fin(filename);
	string tmp;

	while (!fin.eof()) {
		getline(fin, tmp, ' ');
		string type = tmp;
		int length = 0;
		int width = 0;
		int x_ = 0;
		int y_ = 0;
		string name_ = "";
		getline(fin, tmp, ' ');
		length = stoi(tmp);
		getline(fin, tmp, ' ');
		width = stoi(tmp);
		getline(fin, tmp, ' ');
		x_ = stoi(tmp);
		getline(fin, tmp, ' ');
		y_ = stoi(tmp);
		getline(fin, tmp, ' ');
		name_ = tmp;

		bool overlap = 1;
		if (type == "Industry") {
			getline(fin, tmp, ' ');
			int stf = stoi(tmp);
			getline(fin, tmp, '\n');
			string fo = tmp;
			if (CheckNodeIsExist(length, width, x_, y_, Map_Txt)) {
				Industry* Ins = new Industry(length, width, x_, y_, name_, stf, fo);
				node.push_back(Ins);
				overlap = 0;
			}
		}
		else if (type == "Factory") {
			getline(fin, tmp, ' ');
			bool sta = stoi(tmp);
			getline(fin, tmp, ' ');
			string mode = tmp;
			getline(fin, tmp, '\n');  // D ver 8
			int nP = stoi(tmp);

			if (CheckNodeIsExist(length, width, x_, y_, Map_Txt)) {
				Factory* fac = new Factory(length, width, x_, y_, name_, sta, mode, nP);
				node.push_back(fac);
				overlap = 0;
			}
		}
		else if (type == "Residential") {
			getline(fin, tmp, ' ');
			int pop = stoi(tmp);
			getline(fin, tmp);
			vector<string>apart;
			int x = 0;
			int i;
			for (i = 0; i < tmp.size(); ++i) {
				if (tmp[i] == ' ') {
					string tmp1 = tmp.substr(x, i - x);
					if (tmp1 != "") {
						apart.push_back(tmp1);
					}
					x = i + 1;
				}
			}
			string tmp1 = tmp.substr(x, i - x);
			if (tmp1 != "") {
				apart.push_back(tmp1);
			}
			if (CheckNodeIsExist(length, width, x_, y_, Map_Txt)) {
				Residential* res = new Residential(length, width, x_, y_, name_, pop, apart);
				node.push_back(res);
				overlap = 0;
			}
		}
		else if (type == "City") {
			getline(fin, tmp, '\n');
			int population_ = stoi(tmp);
			if (CheckNodeIsExist(length, width, x_, y_, Map_Txt)) {
				City* city = new City(length, width, x_, y_, name_, population_);
				overlap = 0;
				node.push_back(city);
			}
		}
		else if (type == "Commercial") {
			getline(fin, tmp, '\n');
			bool sta = stoi(tmp);
			if (CheckNodeIsExist(length, width, x_, y_, Map_Txt)) {
				Commercial* com = new Commercial(length, width, x_, y_, name_, sta);
				node.push_back(com);
				overlap = 0;
			}
		}
		else if (type == "Construction") {
			getline(fin, tmp, ' ');
			int staff_ = stoi(tmp);
			getline(fin, tmp, '\n');
			string type_ = tmp;

			if (CheckNodeIsExist(length, width, x_, y_, Map_Txt)) {
				Construction* con = new Construction(length, width, x_, y_, name_, staff_, type_);
				node.push_back(con);
				overlap = 0;
			}
		}
		// Add to MapTxt

		if (!overlap) {
			for (int i = x_; i < x_ + length; i++) {
				for (int j = y_; j < y_ + width; j++) {
					Map_Txt[i][j] = 1;
				}
			}
		}
		else {
			cout << "   Can't add " << name_ << "  " << x_ << "  " << y_ << endl;
		}
	}
	fin.close();
	return node;
}

int Node::count_id = 0;

// City
City::City() : Node(), population_(0) {}
City::City(int len, int wid, int x, int y, string name, int population) : Node(x, y, len, wid, name) {
	population_ = population;
}
void City::accept(Visitor* v) {
	v->visitCity(this);
}

//Construction
Construction::Construction(int len, int wid, int x, int y, string name, int s, string t) : Node(x, y, len, wid, name) {
	staff = s;
	type = t;
}
void Construction::accept(Visitor* v)
{
	v->visitConstruction(this);
}
//Industry
void Industry::accept(Visitor* v) {
	v->visitIndustry(this);
}
Industry::Industry(int len, int wid, int x, int y, string name, int s, string fo) :Node(x, y, name) {
	size_.length = len;
	size_.width = wid;
	staff = s;
	form = fo;
}

// Factory
Factory::Factory(int len, int wid, int x, int y, string name, bool sta, string mode, int nP) : Node(x, y, name) {
	size_.length = len;
	size_.width = wid;
	status = sta;
	modeOfOperation = mode;
	numProduct = nP;  // D ver 8
}
void Factory::accept(Visitor* v) {
	v->visitFactory(this);
}

// Commercial
Commercial::Commercial(int len, int wid, int x, int y, string name, bool sta) : Node(x, y, len, wid, name) {
	status = sta;
}

void Commercial::accept(Visitor* v) {
	v->visitCommercial(this);
}

//Residential
Residential::Residential(int len, int wid, int x, int y, string name, int pop, vector<string> noA) : Node(x, y, name) {  // new code by D
	size_.length = len;
	size_.width = wid;
	population = pop;
	nameOfApartment = noA;
}

void Residential::accept(Visitor* v) {
	v->visitResidential(this);
}