#ifndef FileHandler_H_
#define FileHandler_H_

#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <vector>
#include <unistd.h>

class FileHandler
{

	public:
		FileHandler(std::string fName) : fileName(fName)
		{}

		~FileHandler();
		bool openFile(); //TODO options

		std::string findLineWithData(std::string data);
		bool readFile();

		void createFile();		
		void removeFile();		
		static bool doesFileExist(const std::string& name, bool printInfo=1);
		std::string readFileToString();
    void close();
	protected:
	  std::fstream fileHnd;
		int numberOfCurrentLine;
		const std::string fileName;
};

/*
  ofstream: Stream class to write on files
  ifstream: Stream class to read from files
  fstream: Stream class to both read and write from/to files.
*/

#endif
