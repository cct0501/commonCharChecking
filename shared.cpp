#include "shared.h"
map<char, bool> pMap;
map<char, bool> tMap;
enum mapType {primary, temp};
static int setDefault(mapType mt)
{
	if (mt == primary)
	{
		for (char ch='0'; ch<='9'; ch++)
		{
			pMap[ch] = true;
		}
		for (char ch='A'; ch<='Z'; ch++)
		{
			pMap.insert(pair<char, bool>(ch, true));
		}
		for (char ch='a'; ch<='z'; ch++)
		{
			pMap.insert(pair<char, bool>(ch, true));
		}
	}
	else
	{
		for (char ch='0'; ch<='9'; ch++)
		{
			tMap[ch] = false;
		}
		for (char ch='A'; ch<='Z'; ch++)
		{
			tMap.insert(pair<char, bool>(ch, false));
		}
		for (char ch='a'; ch<='z'; ch++)
		{
			tMap.insert(pair<char, bool>(ch, false));
		}
	}
	return 0;
}
int parseArgs(int min, vector<string> vs)
{
	auto cnt = vs.size();
	if ( cnt >= min)
	{
		for (int i = 0; i<cnt; i++)
		{
			cout << vs.at(i) << endl;
		}
	}
	return 0;
}
int commonChars(vector<string> vs, bool debug)
{
	setDefault(primary);
	setDefault(temp);
	map<char, bool>::iterator priIt;
	map<char, bool>::iterator tmpIt;
	for (vector<string>::iterator i = vs.begin(); i !=vs.end(); i++)
	{
		for (string::iterator si = (*i).begin(); si != (*i).end(); si++)
		{
			if (debug)
			{
				cout << *si << " "; 
			}
			priIt = pMap.find(*si);
			if (priIt != pMap.end())
			{
				tMap[*si] = priIt->second;
			}
		}
		pMap=tMap;
		tMap.clear();
		setDefault(temp);
	}
	cout << endl;
	cout << "Common Chars are [";
	for (priIt = pMap.begin(); priIt != pMap.end(); priIt++)
		if (priIt->second == true)
			cout << priIt->first << " ";
	cout << "]" << endl;
	return 0;
}


