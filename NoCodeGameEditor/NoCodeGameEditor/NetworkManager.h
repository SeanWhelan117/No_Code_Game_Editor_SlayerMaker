#pragma once
#include <sqlite3.h>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class NetworkManager
{
public:
	NetworkManager();

	void writeGameDataToDB(std::string t_filename);
	std::vector<std::string> split_string(const std::string& str, char delimiter);
private:
};

