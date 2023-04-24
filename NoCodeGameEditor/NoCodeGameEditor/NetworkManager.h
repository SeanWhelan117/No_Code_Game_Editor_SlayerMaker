#pragma once
#include <iostream>
#include <sqlite3.h>
#include <boost/tokenizer.hpp>
#include <fstream>
#include <string>

class NetworkManager
{
	NetworkManager();

	void writeGameDataToDB(std::string t_filename);

};

