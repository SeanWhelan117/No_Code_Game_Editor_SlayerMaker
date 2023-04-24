#include "NetworkManager.h"

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
    std::ifstream infile(t_filename + ".csv");
    std::string line;
    getline(infile, line);
    boost::tokenizer<boost::escaped_list_separator<char>> tokenizer(line);
    for (auto& token : tokenizer) {
        create_table_sql += token + " TEXT,";
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

    // Insert data
    while (getline(infile, line)) {
        boost::tokenizer<boost::escaped_list_separator<char>> tokenizer(line);
        std::string insert_sql = "INSERT INTO " + t_filename + " VALUES (";
        for (auto& token : tokenizer) {
            insert_sql += "'" + token + "',";
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

    // Close database connection
    sqlite3_close(db);
}