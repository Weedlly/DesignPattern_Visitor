#include "Node.h"
#include "Visitor.h"

int main() {
	Application Client("DPdata.txt");
	Client.export_XML();
	cout << "======================" << endl;
	Client.export_TXT();
	Client.export_CSV();
	return 0;
}
//  city 5 5 10 20