// q3toqlconverter
//drag and drop to convert

#include "stdafx.h"
#include <fstream>
#include <iterator>
#include <iostream>

using namespace std;


int main(int argc, char* argv[]) 

{
	string mapname = argv[1];
	fstream infile;
	infile.open(mapname, fstream::in | fstream::out | fstream::binary);

	infile.seekp(4);

	infile << hex << "/";
	infile.close();


 }
