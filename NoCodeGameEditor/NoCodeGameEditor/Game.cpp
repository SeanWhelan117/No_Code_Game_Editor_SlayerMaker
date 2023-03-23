/// <summary>
/// @author Sean Whelan
/// @date 2022
/// @license Attribution-NonCommercial 4.0 International
/// </summary>

#include "Game.h"
#include <iostream>


/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{  gameWidth, gameHeight, 32U }, "SlayerMaker" },
	m_exitGame{false} //when true game will exit
{
	viewsCreation();
	//if (__cplusplus == 202101L) std::cout << "C++23";
	//else if (__cplusplus == 202002L) std::cout << "C++20";
	//else if (__cplusplus == 201703L) std::cout << "C++17";
	//else if (__cplusplus == 201402L) std::cout << "C++14";
	//else if (__cplusplus == 201103L) std::cout << "C++11";
	//else if (__cplusplus == 199711L) std::cout << "C++98";
	//else std::cout << "pre-standard C++." << __cplusplus;
	//std::cout << "\n";
	if (!bloodSplatterTexture.loadFromFile("ASSETS\\IMAGES\\BloodSplatter.png"))
	{
		// simple error message if previous call fails
		std::cout << "problem loading BloodSplatter (BloodSplatter.png)" << std::endl;
	}
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
		if (sf::Event::MouseButtonPressed == newEvent.type)
		{
			processMouseClicks(newEvent);
		}
		if (sf::Event::TextEntered == newEvent.type)
		{
			processTextEntered(newEvent);
		}
		if (sf::Event::MouseWheelScrolled == newEvent.type)
		{
			//std::cout << newEvent.mouseWheelScroll.delta << std::endl;
			processMouseWheel(newEvent);
		}
		if (sf::Event::MouseButtonReleased == newEvent.type)
		{
			processMouseRelease(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}

	if (sf::Keyboard::Tab == t_event.key.code)
	{
		if (myState == GameState::gameOptions)
		{
			myState = GameState::mainmenu;
			gameChoice.findFiles();
		}
		else if (myState == GameState::createGame)
		{
			myState = GameState::gameOptions;
			myTools.enemyOneSpawnsPlaced = 0;
			myTools.enemyTwoSpawnsPlaced = 0;
			myTools.enemyThreeSpawnsPlaced = 0;
			clearVectors();
			
		}
		else if (myState == GameState::chooseGame)
		{
			myState = GameState::mainmenu;
			clearVectors();
		}
		else if (myState == GameState::options)
		{
			myState = GameState::mainmenu;
		}
		else if (myState == GameState::testGame)
		{
			myState = GameState::createGame;
		}
		else if (myState == GameState::play)
		{
			myState = GameState::chooseGame;
		}
	}

	if (gameOptions.canType == true)
	{
		if (sf::Keyboard::BackSpace == t_event.key.code)
		{
			if (!gameOptions.gameName.empty())
			{
				gameOptions.gameName.pop_back();
			}

		}
	}

	
}

void Game::processMouseClicks(sf::Event t_event)
{
	if (sf::Mouse::Left == t_event.mouseButton.button)
	{
		changeGridSize = true;
	}


}

void Game::processTextEntered(sf::Event t_event)
{
	if (gameOptions.canType == true)
	{
		if (t_event.text.unicode != 8)
		{
			if (gameOptions.gameName.size() < 12)
			{
				gameOptions.gameName += t_event.text.unicode;
			}
		}
	}
}

void Game::processMouseWheel(sf::Event t_event)
{
	
	if (mainViewActive == true)
	{
		if (scrolling == false)
		{
			if (t_event.mouseWheelScroll.delta == 1)
			{
				//Zooming In
				zoomAmount -= 0.1;
				mainView.zoom(zoomAmount);
			}
			else if (t_event.mouseWheelScroll.delta == -1)
			{
				zoomAmount += 0.1;
				mainView.zoom(zoomAmount);
			}
			//std::cout << zoomAmount << std::endl;
			zoomAmount = 1;
		}
		else if (scrolling)
		{
			sf::Vector2f viewPos = mainView.getCenter();
			if (t_event.mouseWheelScroll.delta == 1)
			{
				viewPos.y -= 15;
				mainView.setCenter(viewPos);
			}
			else if (t_event.mouseWheelScroll.delta == -1)
			{
				viewPos.y += 15;
				mainView.setCenter(viewPos);
			}
		}
	}
}

void Game::processMouseRelease(sf::Event t_event)
{
	if (myState == GameState::createGame)
	{
		if (sf::Mouse::Left == t_event.mouseButton.button)
		{
			myTools.wallsPlaced = true;
			myTools.enemySpawnersPlaced = true;
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	mousePos = m_window.mapPixelToCoords(sf::Mouse::getPosition(m_window));

	if (m_exitGame || myState == GameState::exitGame)
	{
		m_window.close();
	}

	if (myState != GameState::testGame && myState != GameState::play)
	{
		m_window.setView(mainView);
		if (myState != GameState::createGame)
		{
			mainView.reset(sf::FloatRect(0, 0, gameWidth, gameHeight));
		}
		m_window.setMouseCursorVisible(true);
	}

	//CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME
	//CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME 
	//CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME CREATE GAME 
	if (myState == GameState::createGame)
	{
		
		mainViewActive = true;
		testViewActive = false;
		if (gridCreated == false)
		{
			gridSize = gameOptions.getGridSize();
			if (myGrid.theGrid.size() > 0)
			{
				myGrid.theGrid.clear();
			}
			myGrid.setupGrid(gridSize);
			gridCreated = true;
		}
		myGrid.update(t_deltaTime);

		if (myTools.wallsPlaced == true)
		{

			for (int i = 0; i < gridSize; i++)
			{
				for (int m = 0; m < gridSize; m++)
				{
					if (myGrid.theGrid.at(m).at(i).getType() == "wall1")
					{
						myGrid.theGrid.at(m).at(i).getType("filled");
						wallVector.push_back(new Wall(createWallVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 0)));
						numOfWalls++;
					}
					else if (myGrid.theGrid.at(m).at(i).getType() == "wall2")
					{
						myGrid.theGrid.at(m).at(i).getType("filled");
						wallVector.push_back(new Wall(createWallVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 1)));
						numOfWalls++;
					}
					else if (myGrid.theGrid.at(m).at(i).getType() == "wall3")
					{
						myGrid.theGrid.at(m).at(i).getType("filled");
						wallVector.push_back(new Wall(createWallVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 2)));
						numOfWalls++;
					}
				}
			}
			for (int i = 0; i < wallVector.size(); i++)
			{
				wallVector.at(i)->loadFiles();
			}
			myTools.wallsPlaced = false;
			wallVectorCreated = true;
		}

		if (myTools.enemySpawnersPlaced == true)
		{

			for (int i = 0; i < gridSize; i++)
			{
				for (int m = 0; m < gridSize; m++)
				{
					if (myGrid.theGrid.at(m).at(i).getType() == "enemy1")
					{
						myGrid.theGrid.at(m).at(i).getType("filled");
						enemySpawnerVector.push_back(new EnemySpawner(createSpawnerVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 0)));
						numOfSpawners++;

					}
					if (myGrid.theGrid.at(m).at(i).getType() == "enemy2")
					{
						myGrid.theGrid.at(m).at(i).getType("filled");
						enemySpawnerVector.push_back(new EnemySpawner(createSpawnerVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 1)));
						numOfSpawners++;
					}
					if (myGrid.theGrid.at(m).at(i).getType() == "enemy3")
					{
						myGrid.theGrid.at(m).at(i).getType("filled");
						enemySpawnerVector.push_back(new EnemySpawner(createSpawnerVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 2)));
						numOfSpawners++;
					}
				}
			}
			for (int i = 0; i < enemySpawnerVector.size(); i++)
			{
				enemySpawnerVector.at(i)->loadFiles();
			}
			enemySpawnerVectorCreated = true;
			myTools.enemySpawnersPlaced = false;
		}
		myTools.update(t_deltaTime, m_window, myGrid.theGrid, gridSize, myChoice.choiceMade, myChoice.currentChoice);
		myChoice.update(t_deltaTime, m_window, myTools.currentMode);

		if (enemySpawnerVectorCreated && wallVectorCreated && myTools.saved)
		{
			saveDataToCSV();
			myTools.saved = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			scrolling = true;
		}
		else
		{
			scrolling = false;
		}
	}

	//MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU 
	//MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU 
	//MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU MAINMENU 

	if (myState == GameState::mainmenu)
	{
		gridCreated = false;
		myMenu.update(myState, m_window);

	}
	
	//GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS 
	//GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS 
	//GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS GAME OPTIONS 

	if (myState == GameState::gameOptions)
	{
		gridCreated = false;
		gameOptions.update(t_deltaTime, m_window, myState);
		checkMousePos();

	}

	//TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME
	//TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME
	//TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME TEST GAME

	if (myState == GameState::testGame)
	{
		myPlayer.update(m_window);
		myCrosshair.update(m_window);
		m_window.setMouseCursorVisible(false);
		myBackground.update(gameOptions.chosenBG);
		testView.setCenter(myPlayer.getPlayer().getPosition());

		if (enemySpawnerVectorCreated == true)
		{
			for (int i = 0; i < enemySpawnerVector.size(); i++)
			{
				enemySpawnerVector.at(i)->update(myPlayer.getPlayer().getPosition());
			}
		}
		collisionDetection();
		m_window.setView(testView);
	}

	//CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME
	//CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME 
	//CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME 

	if (myState == GameState::chooseGame)
	{
		gameChoice.update(t_deltaTime, m_window);

		if (gameChoice.gameChosen)
		{
			myState = GameState::play;
			
			createLevel();
			for (int i = 0; i < wallVector.size(); i++)
			{
				wallVector.at(i)->loadFiles();
			}
			for (int i = 0; i < enemySpawnerVector.size(); i++)
			{
				enemySpawnerVector.at(i)->loadFiles();
			}
		}
	}
	
	if (myTools.testingGame == true)
	{
		myState = GameState::testGame;
		myTools.testingGame = false;
		
	}

	if (myState == GameState::play)
	{
		gameChoice.gameChosen = false;
		
		myPlayer.update(m_window);
		myCrosshair.update(m_window);
		m_window.setMouseCursorVisible(false);
		myBackground.update(gameOptions.chosenBG);
		testView.setCenter(myPlayer.getPlayer().getPosition());

		
		for (int i = 0; i < enemySpawnerVector.size(); i++)
		{
			enemySpawnerVector.at(i)->update(myPlayer.getPlayer().getPosition());
		}
		collisionDetection();
		m_window.setView(testView);
	}

	removeWallVector();
	removeEnemySpawnerVector();
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::White);
	if (myState == GameState::createGame)
	{
		if (gridCreated == true)
		{
			gridSize = gameOptions.getGridSize();
			myGrid.render(m_window, gridSize);
			
			if (wallVectorCreated == true)
			{
				for (int i = 0; i < wallVector.size(); i++)
				{
					wallVector.at(i)->render(m_window);
				}
			}

			if (enemySpawnerVectorCreated == true)
			{
				for (int i = 0; i < enemySpawnerVector.size(); i++)
				{
					enemySpawnerVector.at(i)->render(m_window, "create");
				}
			}
			
			myTools.render(m_window);
			myChoice.render(m_window);
		}
		
	}

	if (myState == GameState::mainmenu)
	{
		myMenu.render(m_window);
	}

	if (myState == GameState::gameOptions)
	{
		gameOptions.render(m_window);
	}
	else
	{
		changeGridSize = false;
	}

	if (myState == GameState::testGame)
	{
		myBackground.render(m_window);
		myPlayer.render(m_window);

		for (int i = 0; i < wallVector.size(); i++)
		{
			wallVector.at(i)->render(m_window);
		}

		for (int i = 0; i < enemySpawnerVector.size(); i++)
		{
			enemySpawnerVector.at(i)->render(m_window, "test");
		}
		myCrosshair.render(m_window);
	}

	if (myState == GameState::chooseGame)
	{
		gameChoice.render(m_window);
	}

	if (myState == GameState::play)
	{
		myBackground.render(m_window);

		for (int i = 0; i < bloodSplatterVector.size(); i++)
		{
			bloodSplatterVector.at(i)->getSplatter().setTexture(bloodSplatterTexture);
			bloodSplatterVector.at(i)->render(m_window);
		}

		myPlayer.render(m_window);

		for (int i = 0; i < wallVector.size(); i++)
		{
			wallVector.at(i)->render(m_window);
		}

		for (int i = 0; i < enemySpawnerVector.size(); i++)
		{
			enemySpawnerVector.at(i)->render(m_window, "test");
		}
		myCrosshair.render(m_window);

		
	}

	m_window.display();
}


void Game::checkMousePos()
{
	for (int i = 0; i < gameOptions.NUM_OF_TRIANGLES; i++)
	{
		if (gameOptions.triangles[i].getGlobalBounds().contains(mousePos))
		{
			if (changeGridSize == true)
			{
				changeGridSize = false;
				gameOptions.changeGridSize(i);
			}
		}

	}
}

Wall Game::createWallVector(sf::Vector2f t_wallPos, int t_wallTextNum)
{
	Wall tempWall{t_wallTextNum, t_wallPos };

	return tempWall;
}

EnemySpawner Game::createSpawnerVector(sf::Vector2f t_spawnerPos, int t_spawnerTextNum)
{
	EnemySpawner tempSpawner{ t_spawnerTextNum, t_spawnerPos };

	return tempSpawner;
}

void Game::removeWallVector()
{
	if (wallVectorCreated == true)
	{
		if (!wallVector.empty())
		{
			for (int i = 0; i < wallVector.size(); i++)
			{
				if (wallVector.at(i)->getWall().getGlobalBounds().contains(mousePos))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left()))
					{
						if (myTools.rubberToolSelected)
						{
							vector<Wall *>::iterator begin = wallVector.begin();
							begin += i;
							wallVector.at(i) = NULL;
							delete wallVector.at(i);
							wallVector.erase(begin);
						}
					}																											
				}
			}
		}
	}
}

void Game::removeEnemySpawnerVector()
{
	if (enemySpawnerVectorCreated == true)
	{
		if (!enemySpawnerVector.empty())
		{
			for (int i = 0; i < enemySpawnerVector.size(); i++)
			{
				if (enemySpawnerVector.at(i)->getSpawner().getGlobalBounds().contains(mousePos))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left()))
					{
						if (myTools.rubberToolSelected)
						{
							vector<EnemySpawner*>::iterator begin = enemySpawnerVector.begin();
							begin += i;
							enemySpawnerVector.at(i) = NULL;
							delete enemySpawnerVector.at(i);
							enemySpawnerVector.erase(begin);
						}
					}
				}
			}
		}
	}
}

void Game::viewsCreation()
{
	mainView.reset(sf::FloatRect(0,0, gameWidth, gameHeight ));
	testView.reset(sf::FloatRect(100,100, gameWidth * 0.3, gameHeight * 0.3));
}

void Game::saveDataToCSV()
{
	std::ofstream myFile;
	myFile.open(".\\ASSETS\\GAMEDATA\\" + gameOptions.gameName + ".csv");
	myFile << "WALLS,\n";
	myFile << "X,Y,Type,Object,\n";
	
	for (int i = 0; i < wallVector.size(); i++)
	{
		myFile << static_cast<int>(wallVector.at(i)->getWall().getPosition().x);
		myFile << ",";
		myFile << static_cast<int>(wallVector.at(i)->getWall().getPosition().y);
		myFile << ",";
		myFile << wallVector.at(i)->wallTextureNumber;
		myFile << ",";
		myFile << "W";
		myFile << "\n";
	}

	/*myFile << "\n";
	myFile << "\n";*/
	myFile << "SPAWNERS,\n";
	myFile << "X,Y,Type,Object,\n";

	for (int i = 0; i < enemySpawnerVector.size(); i++)
	{
		myFile << static_cast<int>(enemySpawnerVector.at(i)->getSpawner().getPosition().x);
		myFile << ",";
		myFile << static_cast<int>(enemySpawnerVector.at(i)->getSpawner().getPosition().y);
		myFile << ",";
		myFile << enemySpawnerVector.at(i)->spawnerTextureNumber;
		myFile << ",";
		myFile << "S";
		myFile << "\n";
	}
	
	
	//myfile << "c,s,v,\n";
	//myfile << "1,2,3.456\n";
	//myfile << "semi;colon";
	myFile.close();
}

void Game::createLevel()
{
	clearVectors();
	for (int i = 0; i < gameChoice.loader.wallData.size(); i++)
	{
		sf::Vector2f tempWallPos = { gameChoice.loader.wallData.at(i).x , gameChoice.loader.wallData.at(i).y };
		wallVector.push_back(new Wall(createWallVector(tempWallPos, gameChoice.loader.wallData.at(i).z)));
	}

	for (int i = 0; i < gameChoice.loader.spawnerData.size(); i++)
	{
		sf::Vector2f tempSpawnerPos = { gameChoice.loader.spawnerData.at(i).x , gameChoice.loader.spawnerData.at(i).y };
		enemySpawnerVector.push_back(new EnemySpawner(createSpawnerVector(tempSpawnerPos, gameChoice.loader.spawnerData.at(i).z)));
	}
}

void Game::clearVectors()
{

	wallVector.clear();
	enemySpawnerVector.clear();
}

bool Game::isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2)
{
	return t_obj1.intersects(t_obj2);
}

void Game::collisionDetection()
{
	int count = 0;
	for (auto& bullet : myPlayer.bulletVector) 
	{
		count++;
		for (auto& spawner : enemySpawnerVector)
		{
			for (auto& enemy : spawner->enemyVector) 
			{
				if (isColliding(bullet.getBullet().getGlobalBounds(), enemy->getEnemy().getGlobalBounds()))
				{
					spawner->enemyVector.erase(std::remove(spawner->enemyVector.begin(), spawner->enemyVector.end(), enemy), spawner->enemyVector.end());
					bloodSplatterVector.push_back(new BloodSplatter(spawnBloodSplatter(enemy->getEnemy().getPosition())));

					//myPlayer.bulletVector.erase(std::remove(myPlayer.bulletVector.begin(), myPlayer.bulletVector.end(), bullet), myPlayer.bulletVector.end());
					if (count < myPlayer.bulletVector.size())
					{
						myPlayer.removeBullet(count);
					}
				}
			}
		}
	}
}

BloodSplatter Game::spawnBloodSplatter(sf::Vector2f t_splatterPos)
{
	BloodSplatter tempBlood{t_splatterPos, bloodSplatterTexture };

	return tempBlood;
}
