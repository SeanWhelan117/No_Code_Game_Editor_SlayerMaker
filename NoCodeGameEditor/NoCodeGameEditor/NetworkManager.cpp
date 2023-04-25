#include "NetworkManager.h"

NetworkManager::NetworkManager()
{
}

void NetworkManager::writeGameDataToDB(std::string t_filename)
{
    // Open DB
    // Open DB
    // Open DB
    sqlite3* db;
    int rc = sqlite3_open("GameData.db", &db);
    if (rc != SQLITE_OK) {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Create table
    // Create table
    // Create table

    std::string create_table_sql = "CREATE TABLE IF NOT EXISTS " + t_filename + " (";
    std::ifstream infile(".\\ASSETS\\GAMEDATA\\" + t_filename + ".csv");
    std::string line;
    std::getline(infile, line);
    auto headers = split_string(line, '\t');
    for (auto& header : headers) {
        create_table_sql += header + " TEXT,";
    }
    create_table_sql.pop_back();
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

    // Insert gameData
    // Insert gameData
    // Insert gameData
    while (std::getline(infile, line)) 
    {
        auto values = split_string(line, ',');
        for (int i = 0; i < values.size(); i++)
        {
            std::cout << values.at(i) << std::endl;
        }
       
        std::string insert_sql = "INSERT INTO " + t_filename + " (XPOS, YPOS, TYPE, OBJECT) VALUES ('" + values[0] + "', '" + values[1] + "', '" + values[2] + "', '" + values[3] + "')";
        rc = sqlite3_exec(db, insert_sql.c_str(), nullptr, nullptr, &error_msg);
        if (rc != SQLITE_OK)
        {
            std::cerr << "Error inserting data: " << error_msg << std::endl;
            sqlite3_free(error_msg);
            sqlite3_close(db);
            return;
        }
    }
    std::cout << "Data added to table" << std::endl;

    // Close DB
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

void NetworkManager::exportDBToCSV()
{
    // Open DB
    // Open DB
    // Open DB

    sqlite3* db;
    int rc = sqlite3_open("GameData.db", &db);
    if (rc != SQLITE_OK) 
    {
        std::cerr << "Error opening database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    // Table List
    // Table List
    // Table List

    std::vector<std::string> tables;
    sqlite3_stmt* stmt;
    rc = sqlite3_prepare_v2(db, "SELECT name FROM sqlite_master WHERE type='table' ORDER BY name;", -1, &stmt, nullptr);
    if (rc != SQLITE_OK) 
    {
        std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }
    while (sqlite3_step(stmt) == SQLITE_ROW) 
    {
        tables.push_back(std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
    }
    sqlite3_finalize(stmt);

    // Export to CSV
    // Export to CSV
    // Export to CSV

    for (const auto& table : tables) 
    {
        std::ofstream outfile(".\\ASSETS\\GAMEDATA\\" + table + ".csv");

        if (!outfile.is_open()) 
        {
            std::cerr << "Error opening file: " << table << ".csv" << std::endl;
            sqlite3_close(db);
            return;
        }

        // Column headers
        std::string header_sql = "PRAGMA table_info(" + table + ");";
        rc = sqlite3_prepare_v2(db, header_sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK) 
        {
            std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
            return;
        }

        std::string headers;
        while (sqlite3_step(stmt) == SQLITE_ROW) 
        {
            headers += std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1))) + ",";
        }
        headers.pop_back();
        outfile << headers << std::endl;
        sqlite3_finalize(stmt);

        // Data rows
        std::string select_sql = "SELECT * FROM " + table + ";";
        rc = sqlite3_prepare_v2(db, select_sql.c_str(), -1, &stmt, nullptr);
        if (rc != SQLITE_OK) 
        {
            std::cerr << "Error preparing statement: " << sqlite3_errmsg(db) << std::endl;
            sqlite3_close(db);
            return;
        }
        while (sqlite3_step(stmt) == SQLITE_ROW) 
        {
            for (int i = 0; i < sqlite3_column_count(stmt); i++) 
            {
                outfile << std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, i))) << ",";
            }
            outfile.seekp(-1, std::ios_base::cur);
            outfile << std::endl;
        }
        sqlite3_finalize(stmt);

        std::cout << "Data exported from table " << table << std::endl;
    }

    // Close DB
    // Close DB
    // Close DB

    sqlite3_close(db);
}
