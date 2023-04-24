#include "NetworkManager.h"

NetworkManager::NetworkManager()
{
}

void NetworkManager::writeGameDataToDB(std::string t_filename)
{
    // Open database connection
    sqlite3* db;
    int rc = sqlite3_open("GameData.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Create table
    std::string create_table_sql = "CREATE TABLE IF NOT EXISTS " + t_filename + " (";
    std::ifstream infile(".\\ASSETS\\GAMEDATA\\" + t_filename + ".csv");
    std::string line;
    std::getline(infile, line);
    auto headers = split_string(line, '\t');
    for (auto& header : headers) {
        create_table_sql += header + " TEXT,";
    }
    create_table_sql.pop_back(); // Remove the trailing comma
    create_table_sql += ")";
    char* error_msg;
    rc = sqlite3_exec(db, create_table_sql.c_str(), nullptr, nullptr, &error_msg);
    if (rc != SQLITE_OK) {
        std::cerr << "Error creating table: " << error_msg << std::endl;
        sqlite3_free(error_msg);
        sqlite3_close(db);
        return;
    }
    std::cout << "Table created" << std::endl;

    // Insert data
    while (std::getline(infile, line)) {
        auto values = split_string(line, '\t');
        std::string insert_sql = "INSERT INTO " + t_filename + " VALUES (";
        for (auto& value : values) {
            insert_sql += "'" + value + "',";
        }
        insert_sql.pop_back();
        insert_sql += ")";
        rc = sqlite3_exec(db, insert_sql.c_str(), nullptr, nullptr, &error_msg);
        if (rc != SQLITE_OK) {
            std::cerr << "Error inserting data: " << error_msg << std::endl;
            sqlite3_free(error_msg);
            sqlite3_close(db);
            return;
        }
    }
    std::cout << "Data added to table" << std::endl;

    // Close database connection
    sqlite3_close(db);
}

std::vector<std::string> NetworkManager::split_string(const std::string& str, char delimiter)
{
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;

    while (std::getline(iss, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
