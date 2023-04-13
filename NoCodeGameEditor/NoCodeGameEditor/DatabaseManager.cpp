#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(const std::string& t_script_path) : script_path_(t_script_path)
{
    // Initialize the Python interpreter
    Py_Initialize();

    // Import the Python script as a module
    pModule_ = PyImport_ImportModule("updownGames");

    if (pModule_ == NULL)
    {
        std::cerr << "Error: Could not import the Python script" << std::endl;
    }
}

DatabaseManager::~DatabaseManager()
{
    // Clean up
    Py_XDECREF(pModule_);

    // Finalize the Python interpreter
    Py_Finalize();
}

void DatabaseManager::upload_csv(const std::string& t_filename)
{
    if (pModule_ != NULL)
    {
        // Get the function object for upload_csv
        PyObject* pFunc_upload_csv = PyObject_GetAttrString(pModule_, "upload_csv");

        // Call the upload_csv function for the specified CSV file
        PyObject* pArgs_upload_csv = PyTuple_New(1);
        PyTuple_SetItem(pArgs_upload_csv, 0, PyUnicode_FromString(t_filename.c_str()));
        PyObject_CallObject(pFunc_upload_csv, pArgs_upload_csv);
        Py_DECREF(pArgs_upload_csv);

        // Clean up
        Py_DECREF(pFunc_upload_csv);
    }
    else
    {
        std::cerr << "Error: Could not import the Python script" << std::endl;
    }
}
