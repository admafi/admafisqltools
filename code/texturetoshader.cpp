// texturetoshader.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

using namespace std;
using namespace std::tr2::sys;
namespace fs = experimental::filesystem;



int main()
{
	string shaderpathname;
	string shaderadd1 = "textures/";
	string shaderadd2 = "{";
	string shaderadd3 = "map ";
	string shaderadd4 = "}";
	string outputname = "textures.shader";
	string temppath;
	string path = "textures";
		

	

	ofstream newmap;
	newmap.open(outputname);
	for (auto & p : fs::recursive_directory_iterator(path))
	{

		if (is_regular_file(p))
		{
		

		temppath = p.path().string();

		replace(temppath.begin(), temppath.end(), '\\', '/'); 
		size_t lastindex = temppath.find_last_of(".");
		string rawname = temppath.substr(0, lastindex);

		newmap << rawname;
		newmap << endl;
		newmap << shaderadd2;
		newmap << endl;
		newmap << shaderadd2;
		newmap << endl;
		newmap << shaderadd3;
		newmap << rawname;	
		newmap << endl;
		newmap << shaderadd4;
		newmap << endl;
		newmap << shaderadd4;
		newmap << endl;
		newmap << endl;


		}
	}

}
