#include "filehandler.hpp"
#include <iostream>
#include <string>
int main()
{
	filehandler fh;
	std::string date;
	std::string filename;
	std::string text;
	std::cout << "Filename: ";
	std::cin >> filename;
	std::cout << "Text :";
	std::cin >> text;
	std::cout << "date: ";
	std::cin >> date;
	fh.newTodo(text,filename,date);
	fh.clockin(text, filename);
	fh.clockout(text,filename);
	fh.listHeaders(filename);
}
