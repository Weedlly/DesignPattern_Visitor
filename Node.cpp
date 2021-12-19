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
