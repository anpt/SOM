#include "filehandler.hpp"

void filehandler::newTodo(std::string text, std::string file, std::string date)
{
       std::fstream outfile;
       outfile.open(file.c_str(), std::fstream::app);
       outfile << "* TODO " << text << "\n" << "<" << date << ">\n";
       outfile.close();
}
void filehandler::clockin(std::string header, std::string file)
{
	std::fstream outfile;
	std::string actLine;
	std::vector<std::string> lines;
	outfile.open(file.c_str());
	std::vector<std::string>::iterator it;
	
//skriv in alla strängar i en vektor
	while(std::getline(outfile, actLine)){
		lines.push_back(actLine);
	}
	it = lines.begin();
	for (int i = 0; i < lines.size(); ++i)
	{
		it++;
		if (lines.at(i).find(header) != std::string::npos)
		{
			//insert line.
			lines.insert(it, ("CLOCK: " + cTime()));
			
		}
	}
	outfile.close();
	//skriv till file
	std::ofstream of;
	of.open(file.c_str());
	
	for (it = lines.begin(); it < lines.end(); ++it)
	{
		of << *it << std::endl;
	}
	of.close();
}
void filehandler::clockout(std::string header, std::string file)
{
	std::fstream outfile;
	std::string actLine;
	std::vector<std::string> lines;
	outfile.open(file.c_str());
	std::vector<std::string>::iterator it;
	
//skriv in alla strängar i en vektor
	while(std::getline(outfile, actLine)){
		lines.push_back(actLine);
	}
	it = lines.begin();
	for (int i = 0; i < lines.size(); ++i)
	{
		if (lines.at(i).find(header) != std::string::npos)
		{
			//fix lines
			lines[i+1] += "--";
			lines[i+1] += cTime();
		}
	}
	outfile.close();
	//skriv till file
	std::ofstream of;
	of.open(file.c_str());
	
	for (it = lines.begin(); it < lines.end(); ++it)
	{
		of << *it << std::endl;
	}
	of.close();
}

std::string filehandler::cTime()
{
	std::string retVal;
	std::time_t t = std::time(0);
	struct tm * now = localtime(&t);
	int year, month, day;
	year = 1900 + now->tm_year;
	month = 1 + now->tm_mon;
	day = now->tm_mday;
	retVal =  "[";
	retVal += std::to_string(year);
	retVal += "-";
	retVal += std::to_string(month);
	retVal += "-";
	if (day<10)
	{
		retVal += "0";
	}
	retVal += std::to_string(day);
	
	if (now->tm_wday == 1)
	{
		retVal += " Mon ";
	}else if (now->tm_wday == 2)
	{
		retVal += " Tus ";
	} else if (now->tm_wday == 3)
	{
		retVal += " Wed ";
	} else if (now->tm_wday == 4)
	{
		retVal += " Thu ";
	} else if (now->tm_wday == 5)
	{
		retVal += " Fri ";
	} else if (now->tm_wday == 6)
	{
		retVal += " Sat ";
	} else if (now->tm_wday == 0)
	{
		retVal += " Sun ";
	}
	if (now->tm_hour<10)
	{
		retVal += "0";
	}
	retVal += std::to_string(now->tm_hour);
	retVal += ":";
	if (now->tm_min < 10)
	{
		retVal += "0";
	}
	
	retVal += std::to_string(now->tm_min);
	retVal += "]";
	return retVal;
}

void filehandler::listHeaders(std::string file)
{
	std::vector<std::string> lines;
	std::fstream outFile;
	outFile.open(file.c_str());
	std::string actLine;
	while(std::getline(outFile, actLine)){
		lines.push_back(actLine);
	}
	for (int i = 0; i < lines.size(); ++i)
	{
		if (lines.at(i).find("*") != std::string::npos)
		{
			std::cout << lines[i] << std::endl;
		}
	}
	outFile.close();
}
