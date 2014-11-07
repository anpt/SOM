#ifndef _filehandler
#define _filehandler
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
class filehandler
{
private:
	std::string cTime();
public:
	void newTodo(std::string text, std::string file, std::string date);
	void clockin(std::string header, std::string file);
	void clockout(std::string header, std::string file);	
	void listHeaders(std::string file);
};
#endif
