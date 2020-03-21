#include "shared.h"
int main(int argc, char ** args)
{
	vector<string> vs;
	cout << "find all commonChars in the following strings" << endl;
	if (argc > 1)
	{
		int i=1;
		while ( argc-- > 1)
		{
			vs.push_back(args[i++]);
			// cout << argc << " " << args[i-1] << " " << i <<endl;
		}
		// minimum 1 element
		parseArgs(1, vs);
	}
	else
	{
		cout << "no args provided" << endl;
		exit(0);
	}
	bool debug = true;
	if (commonChars(vs, debug) !=0)
	{
		cout << "error processing entries" <<endl;
	}
	exit(0);
}
