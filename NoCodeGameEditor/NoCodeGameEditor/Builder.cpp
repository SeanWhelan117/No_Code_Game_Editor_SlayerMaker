#include "Builder.h"

Builder::Builder()
{
}

void Builder::buildGame(std::string t_gameName)
{
	//// Create build directory
	//std::string build_dir = "build";
	//std::filesystem::create_directory(build_dir);

	//// Copy game files

	//std::filesystem::path current_dir = std::filesystem::current_path();
	////std::filesystem::path game_path = current_dir / game_dir;
	//
	//if (!std::filesystem::exists(current_dir))
	//{
	//	// handle the case where the directory doesn't exist
	//	std::cout << "doesnt exist" << std::endl;
	//}
	//else 
	//{
	//	for (auto& file : std::filesystem::directory_iterator(current_dir))
	//	{
	//		if (file.is_regular_file() && (file.path().extension() == ".cpp" || file.path().extension() == ".h"))
	//		{
	//			std::filesystem::copy(file.path(), build_dir + "\\" + file.path().filename().string());
	//		}
	//	}
	//}

	//// Compile the game
	//std::string compiler_path = "C:\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\VC\\Tools\\MSVC\\14.29.30133\\bin\\Hostx86\\x86\\cl.exe";
	//std::string command = "\"" + compiler_path + "\" /EHsc \"" + build_dir + "\\main.cpp\" /Fe:\"" + build_dir + "\\newGame.exe\"";
	//std::system(command.c_str());

	//// Copy DLLs
	//std::string sfml_dir = "C:\\SFML-2.5.1\\bin";
	//for (auto& file : std::filesystem::directory_iterator(sfml_dir))
	//{
	//	if (file.is_regular_file() && file.path().extension() == ".dll")
	//	{
	//		std::filesystem::copy(file.path(), build_dir + "\\" + file.path().filename().string());
	//	}
	//}

	//// Copy assets
	//std::string asset_dir = "ASSETS";
	//for (auto& file : std::filesystem::recursive_directory_iterator(asset_dir))
	//{
	//	if (file.is_regular_file())
	//	{
	//		auto relative_path = std::filesystem::relative(file.path(), asset_dir);
	//		auto dest_path = build_dir / relative_path;
	//		std::filesystem::create_directories(dest_path.parent_path());
	//		std::filesystem::copy(file.path(), dest_path);
	//	}
	//}

	//std::cout << "Game executable built: " << std::endl;
}
