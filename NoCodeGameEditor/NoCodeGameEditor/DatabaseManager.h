/// <summary>
/// @author Sean Whelan
/// @date 2022/23
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#include <Python.h>
#include <iostream>
#include <SFML/Graphics.hpp>
class DatabaseManager
{
public:
    DatabaseManager(const std::string& t_script_path);

    ~DatabaseManager();
 

    void upload_csv(const std::string& t_filename);
    
private:
    std::string script_path_;
    PyObject* pModule_;
};

