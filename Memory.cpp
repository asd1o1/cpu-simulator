#include "Memory.h"

Memory::Memory(){};											//the default constructr does nothing - size is handled by the vector directly
Memory::Memory(int size){instructionMemory.reserve(size);}; //reserve needed amount of memory
Memory::~Memory(){};

bool Memory::loadFile(std::string filename){
	filename = parseInputAsCommand(filename);		//convert filename input to an actual filename
	std::ifstream File;

	File.open(filename);											//attempt to open file
	try {if (!File) throw Exception(0);}							//if file not opened, throw exception #0
	catch(Exception error){std::cout << error.what();return false;}	//output error message and return false
	
	std::string data;								//temp storage for data read
	while (getline(File, data, ',')){				//while there are values left to grab, grab them
		std::string temp = data;data = "";			//move data to a temp string, then empty data
		for (int i=0; i < temp.size();i++) if (isdigit(temp[i])) data += temp[i];	//go through data and keep only digits
		instructionMemory.push_back(stoul(data));	//add the unsigned int to instruction memory
	};
	return true;
};

unsigned Memory::getInstruction(int pos){return instructionMemory[pos];};

bool Memory::instructionExists(int pos){
	if (pos < instructionMemory.size()) return true;
	else return false;
};

std::string Memory::parseInputAsCommand(std::string input){
	std::string output = "";
	for (int i=0; i < input.size();i++) if (input[i] != '.' && input[i] != '/') output += input[i];	//remove the "./" before commands
	return "samples/" + output + ".csv";
};