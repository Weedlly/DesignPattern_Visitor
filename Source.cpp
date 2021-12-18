#include "Node.h"
#include "Visitor.h"

int main(int _argc, char* _argv[]) {
	if (_argc < 2)
		cout << "Invalid command - Too few arguments !" << endl;
	else if (_argc > 4)
		cout << "Invalid command - Too many arguments !" << endl;
	else if (_argc == 2) {
		if (strcmp(_argv[1], "-tax") == 0)
		{
			cout << "TAX MODE" << endl;
			Application Client("DPdata.txt");
			Client.console_Tax(); // D ver 8
		}
	}
	else if (_argc == 3) {
		if (strcmp(_argv[1], "-export") == 0)
		{
			if (strcmp(_argv[2], "-xml") == 0)
			{
				cout << "EXPORT XML MODE" << endl;
				Application Client("DPdata.txt");
				Client.export_XML();
			}
			else if (strcmp(_argv[2], "-txt") == 0)
			{
				cout << "EXPORT TXT MODE" << endl;
				Application Client("DPdata.txt");
				Client.export_TXT();
			}
			else if (strcmp(_argv[2], "-csv") == 0)
			{
				cout << "EXPORT CSV MODE" << endl;
				Application Client("DPdata.txt");
				Client.export_CSV();
			}
			else if (strcmp(_argv[2], "-all") == 0)
			{
				cout << "EXPORT ALL MODE" << endl;
				Application Client("DPdata.txt");
				Client.export_XML();
				Client.export_TXT();
				Client.export_CSV();
			}
		}
	}

	//Application Client("DPdata.txt");
	//Client.export_XML();
	//cout << "======================" << endl;
	//Client.export_TXT();
	//Client.export_CSV();
	//Client.console_Tax(); // D ver
	return 0;
}