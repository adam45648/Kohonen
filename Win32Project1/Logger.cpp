#include "Logger.h"


std::string Logger::getLog()
{
	return logger;
}

void Logger::addToLog(std::string s)
{
	if (isActive)
	{
		logger += s;
		logger += '\n';
	}
}

void Logger::cleanLog()
{
	if (isActive)
		logger = "";
}

void Logger::printLog()
{
	if (isActive)
	{
		std::cout << logger << std::endl;
		cleanLog();
	}
}

void Logger::turnOn(bool s)
{
	isActive = s;
}

void Logger::addVectorToLog(std::vector<long double> printedArray)
{
	if (isActive)
	{
		for (auto w : printedArray)
		{
			addToLog(std::to_string(w));
		}
	}
}

void Logger::addVector2DToLog(std::vector<std::vector<long double>> printedArray)
{
	if (isActive)
	{
		for (int j = 0; j < printedArray[0].size(); ++j)
		{
			std::string s;
			for (int i = 0; i < printedArray.size(); ++i)
			{
				s += std::to_string(printedArray[i][j]) + "\t";
				
			}
			addToLog(s);
		}
	}
}