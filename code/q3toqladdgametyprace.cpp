// Defrag to Quake Live map converter


#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "math.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stdio.h>

using namespace std;

//remove symbols from the coordinates
bool IsParenthesesOrDash(char c)
{
	switch (c)
	{
	case '"':
		return true;
	default:
		return false;
	}
}
std::string GetFileExtension(const std::string& FileName)
{
	if (FileName.find_last_of(".") != std::string::npos)
		return FileName.substr(FileName.find_last_of(".") + 1);
	return "";
}
//main program
int main(int argc, char* argv[])
{
	string starttimerstring = "\"classname\" \"item"; //danach wird gesucht
	string starttimerstring2 = "\"classname\" \"weapon"; //danach wird gesucht
	string starttimerstring3 = "\"classname\" \"ammo"; //danach wird gesucht
	string starttimerstring4 = "\"classname\" \"holdable"; //danach wird gesucht

	string starttimerline; //hiermit wird gesucht
	string starttimerline2; //hiermit wird gesucht


	string racepoint = "\"gametype\" \"race\""; // das hier wird eingesetzt


	ifstream infile(argv[1]); //filename
	


	string filename = argv[1];
	string filenameending = GetFileExtension(filename);

	string outputname = argv[1];

	for (int i = 0; i < 4; i++) {
		outputname.pop_back();
	}

	outputname += "_c.";
	outputname += filenameending;


	//count the linenumbers
	size_t lines_count = 0;
	lines_count = std::count(std::istreambuf_iterator<char>(infile),
	std::istreambuf_iterator<char>(), '\n');
	lines_count = lines_count + 1; //add +1 since we start at 1 not 0

	infile.seekg(0, ios::beg);  //reset
	


	//write to the file
	string inbuf;
	ofstream output_file(outputname); //output file i fix that later
	infile.seekg(0, ios::beg); //reset again


	while (!infile.eof())
	{
		getline(infile, inbuf);

		size_t foundpos = inbuf.find(starttimerstring);
		size_t foundpos2 = inbuf.find(starttimerstring2);
		size_t foundpos3 = inbuf.find(starttimerstring3);
		size_t foundpos4 = inbuf.find(starttimerstring4);

		if (foundpos != std::string::npos || foundpos2 != std::string::npos || foundpos3 != std::string::npos || foundpos4 != std::string::npos)
		{

			output_file << racepoint << endl; //output to file
		}

		output_file << inbuf << endl;

	}
	
}
	
	


