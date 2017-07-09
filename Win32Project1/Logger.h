#pragma once
#include <string>
#include <iostream>
#include <vector>

class Logger
{
public:
	std::string getLog();

	void addToLog(std::string s);

	void printLog();

	void turnOn(bool s);

	void cleanLog();

	void addVectorToLog(std::vector<long double> printedArray);

	void addVector2DToLog(std::vector<std::vector<long double> > printedArray);

private:
	
	std::string logger;

	bool isActive;

	
};


