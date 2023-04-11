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
	m_window.setActive(true);
	viewsCreation();
	//if (__cplusplus == 202101L) std::cout << "C++23";
	//else if (__cplusplus == 202002L) std::cout << "C++20";
	//else if (__cplusplus == 201703L) std::cout << "C++17";
	//else if (__cplusplus == 201402L) std::cout << "C++14";
	//else if (__cplusplus == 201103L) std::cout << "C++11";
	//else if (__cplusplus == 199711L) std::cout << "C++98";
	//else std::cout << "pre-standard C++." << __cplusplus;
	//std::cout << "\n";

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
		if (zooming == true)
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
		else if (zooming == false && scrollingX == false)
		{
			sf::Vector2f viewPos = mainView.getCenter();
			if (t_event.mouseWheelScroll.delta == 1)
			{
				viewPos.y -= scrollSpeed;
				mainView.setCenter(viewPos);
			}
			else if (t_event.mouseWheelScroll.delta == -1)
			{
				viewPos.y += scrollSpeed;
				mainView.setCenter(viewPos);
			}
		}
		
		if (scrollingX)
		{
			sf::Vector2f viewPos = mainView.getCenter();
			if (t_event.mouseWheelScroll.delta == 1)
			{
				viewPos.x -= scrollSpeed;
				mainView.setCenter(viewPos);
			}
			else if (t_event.mouseWheelScroll.delta == -1)
			{
				viewPos.x += scrollSpeed;
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
			if (myChoice.currentMode == "WALLS")
			{
				myTools.wallsPlaced = true;
			}
			else if (myChoice.currentMode == "ENEMIES")
			{
				myTools.enemySpawnersPlaced = true;
			}
			else if (myChoice.currentMode == "OBJECTIVES")
			{
				myTools.objectivesPlaced = true;
			}
			else if (myChoice.currentMode == "ITEMS")
			{
				myTools.itemsPlacedBool = true;
			}


			for (int i = 0; i < myTools.MAX_NAV_TRIANGLES; i++)
			{
				if (myTools.navigationTriangles[i].getGlobalBounds().contains(mousePos))
				{
					myTools.navigating = true;
					myTools.changeMode(i);
					myTools.navigating = false;

				}
			}
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
			createWallVector();
		}

		if (myTools.enemySpawnersPlaced == true)
		{
			createSpawnerVector();
		}
		if (myTools.objectivesPlaced == true)
		{
			createObjectives();
		}
		if (myTools.itemsPlacedBool == true)
		{
			createItems();
		}
		myTools.update(t_deltaTime, m_window, myGrid.theGrid, gridSize, myChoice.choiceMade, myChoice.currentChoice);
		myChoice.update(t_deltaTime, m_window, myTools.currentMode, gameOptions.chosenGT);

		if (enemySpawnerVectorCreated && wallVectorCreated && myTools.saved)
		{
			saveDataToCSV();
			myTools.saved = false;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
		{
			zooming = true;
		}
		else
		{
			zooming = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
		{
			scrollingX = true;
		}
		else
		{
			scrollingX = false;
		}

		removeWallVector();
		removeEnemySpawnerVector();
		removeObjectiveVector();

		objectives.update(t_deltaTime, m_window, myPlayer.getPlayer().getGlobalBounds(), coinsCollected, maxCoins);
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
				if (gameOptions.chosenGT == 0)
				{
					enemySpawnerVector.at(i)->update(myPlayer.getPlayer().getPosition(), wallVector, t_deltaTime, gameOptions.chosenGT, objectives.monumentVector);
				}
				else if (gameOptions.chosenGT == 1)
				{
					if (objectives.monumentVector.size() > 0)
					{
						enemySpawnerVector.at(i)->update(objectives.monumentVector.at(0).get()->getMonument().getPosition(), wallVector, t_deltaTime, gameOptions.chosenGT, objectives.monumentVector);
					}
				}
			}
		}
		checkWallHealth();
		collisionDetection();
		m_window.setView(testView);

		objectives.update(t_deltaTime, m_window, myPlayer.getPlayer().getGlobalBounds(), coinsCollected, maxCoins);
	}

	//CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME
	//CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME 
	//CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME CHOOSE GAME 

	if (myState == GameState::chooseGame)
	{
		gameChoice.update(t_deltaTime, m_window);

		if (gameChoice.gameChosen && !gameChoice.gameBuilt)
		{
			myState = GameState::play;
			
			createLevel();
		}
		else if (gameChoice.gameChosen && gameChoice.gameBuilt)
		{
			createLevel();
			myBuilder.buildGame(gameChoice.chosenGame);
		}
	}

	//PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME
	//PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME
	//PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME PLAY GAME

	if (myState == GameState::play)
	{
		gameChoice.gameChosen = false;
		
		myPlayer.update(m_window);
		myCrosshair.update(m_window);
		m_window.setMouseCursorVisible(false);
		myBackground.update(gameOptions.chosenBG);
		testView.setCenter(myPlayer.getPlayer().getPosition());
		playerHUD.update(t_deltaTime, m_window, myPlayer.getPlayer().getPosition());
		
		
		for (int i = 0; i < enemySpawnerVector.size(); i++)
		{
			if (gameOptions.chosenGT == 0)
			{
				enemySpawnerVector.at(i)->update(myPlayer.getPlayer().getPosition(), wallVector, t_deltaTime, gameOptions.chosenGT, objectives.monumentVector);
			}
			else if (gameOptions.chosenGT == 1)
			{
				if (objectives.monumentVector.size() > 0)
				{
					enemySpawnerVector.at(i)->update(objectives.monumentVector.at(0).get()->getMonument().getPosition(), wallVector, t_deltaTime, gameOptions.chosenGT, objectives.monumentVector);
				}
			}
		}

		collisionDetection();
		checkWallHealth();

		m_window.setView(testView);

		objectives.update(t_deltaTime, m_window, myPlayer.getPlayer().getGlobalBounds(), coinsCollected, maxCoins);

		if (objectives.gameOver == true || playerHUD.myHealthBar.gameOver == true || objectives.monumentVector.at(0).get()->gameOver == true)
		{
			objectives.gameOver = false;
			playerHUD.myHealthBar.gameOver = false;
			objectives.gameOver = false;
			myState = GameState::gameOver;
		}
	}

	if (myState == GameState::gameOver)
	{
		gameOver.update(t_deltaTime);

		if (gameOver.buttonPressed == 0)
		{
			gameOver.buttonPressed = -10;
			myState = GameState::mainmenu;
		}
		else if (gameOver.buttonPressed == 1)
		{
			gameOver.buttonPressed = -10;
			gameChoice.gameChosen = true;
			myState = GameState::play;
			createLevel();
		}
	}

	if (myTools.testingGame == true)
	{
		myState = GameState::testGame;
		myTools.testingGame = false;

	}
	
	coinsCollected = maxCoins - objectives.coinVector.size();
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

			objectives.render(m_window);
			items.render(m_window);
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
		for (int i = 0; i < bloodSplatterVector.size(); i++)
		{
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

		objectives.render(m_window);
		items.render(m_window);


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

		objectives.render(m_window);
		items.render(m_window);

		myCrosshair.render(m_window);

		playerHUD.render(m_window);
	}

	if (myState == GameState::gameOver)
	{
		gameOver.render(m_window);
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

void Game::createWallVector()
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int m = 0; m < gridSize; m++)
		{
			if (myGrid.theGrid.at(m).at(i).getType() == "wall1" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				wallVector.emplace_back(new Wall(createIndividualWall(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 0)));
				numOfWalls++;
			}
			else if (myGrid.theGrid.at(m).at(i).getType() == "wall2" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				wallVector.emplace_back(new Wall(createIndividualWall(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 1)));
				numOfWalls++;
			}
			else if (myGrid.theGrid.at(m).at(i).getType() == "wall3" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				wallVector.emplace_back(new Wall(createIndividualWall(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 2)));
				numOfWalls++;
			}
		}
	}
	myTools.wallsPlaced = false;
	wallVectorCreated = true;
}

Wall Game::createIndividualWall(sf::Vector2f t_wallPos, int t_wallTextNum)
{
	Wall tempWall{ t_wallTextNum, t_wallPos, textureManager };

	return tempWall;
}

void Game::createSpawnerVector()
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int m = 0; m < gridSize; m++)
		{
			if (myGrid.theGrid.at(m).at(i).getType() == "enemy1" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				enemySpawnerVector.emplace_back(new EnemySpawner(createIndividualSpawner(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 0)));
				numOfSpawners++;

			}
			if (myGrid.theGrid.at(m).at(i).getType() == "enemy2" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				enemySpawnerVector.emplace_back(new EnemySpawner(createIndividualSpawner(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 1)));
				numOfSpawners++;
			}
			if (myGrid.theGrid.at(m).at(i).getType() == "enemy3" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				enemySpawnerVector.emplace_back(new EnemySpawner(createIndividualSpawner(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 2)));
				numOfSpawners++;
			}
		}
	}
	enemySpawnerVectorCreated = true;
	myTools.enemySpawnersPlaced = false;
}

EnemySpawner Game::createIndividualSpawner(sf::Vector2f t_spawnerPos, int t_spawnerTextNum)
{
	EnemySpawner tempSpawner{ t_spawnerTextNum, t_spawnerPos, textureManager };

	return tempSpawner;
}

void Game::createObjectives()
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int m = 0; m < gridSize; m++)
		{
			if (myGrid.theGrid.at(m).at(i).getType() == "objective1" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				objectives.addToVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 0);
				numOfCoins++;
			}
			else if (myGrid.theGrid.at(m).at(i).getType() == "objective2" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				objectives.addToVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 1);	
				numOfDoors++;
			}
			else if (myGrid.theGrid.at(m).at(i).getType() == "objective3" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				objectives.addToVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 2);
				numOfMonuments++;
			}
		}
	}

	objectiveVectorCreated = true;
	myTools.objectivesPlaced = false;
}

void Game::createItems()
{
	for (int i = 0; i < gridSize; i++)
	{
		for (int m = 0; m < gridSize; m++)
		{
			if (myGrid.theGrid.at(m).at(i).getType() == "item1" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				items.addToVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 0);
				numOfMedkits++;
			}
			else if (myGrid.theGrid.at(m).at(i).getType() == "item2" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				items.addToVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 1);
				numOfExplosives++;
			}
			else if (myGrid.theGrid.at(m).at(i).getType() == "item3" && myGrid.theGrid.at(m).at(i).filled == false)
			{
				myGrid.theGrid.at(m).at(i).filled = true;
				items.addToVector(myGrid.theGrid.at(m).at(i).getCellShape().getPosition(), 2);
				numOfGuns++;
			}
		}
	}

	itemVectorCreated = true;
	myTools.itemsPlacedBool = false;
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
							vector<unique_ptr<Wall >>::iterator begin = wallVector.begin();
							begin += i;
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
							vector<std::unique_ptr<EnemySpawner>>::iterator begin = enemySpawnerVector.begin();
							begin += i;
							enemySpawnerVector.erase(begin);
						}
					}
				}
			}
		}
	}
}

void Game::removeObjectiveVector()
{
	if (objectiveVectorCreated == true)
	{
		if (!objectives.coinVector.empty())
		{
			for (int i = 0; i < objectives.coinVector.size(); i++)
			{
				if (objectives.coinVector.at(i)->getCoin().getGlobalBounds().contains(mousePos))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left()))
					{
						if (myTools.rubberToolSelected)
						{
							vector<std::unique_ptr<Coin>>::iterator begin = objectives.coinVector.begin();
							begin += i;
							objectives.coinVector.erase(begin);
						}
					}
				}
			}
		}

		if (!objectives.doorVector.empty())
		{
			for (int i = 0; i < objectives.doorVector.size(); i++)
			{
				if (objectives.doorVector.at(i)->getDoor().getGlobalBounds().contains(mousePos))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left()))
					{
						if (myTools.rubberToolSelected)
						{
							vector<std::unique_ptr<Door>>::iterator begin = objectives.doorVector.begin();
							begin += i;
							objectives.doorVector.erase(begin);
						}
					}
				}
			}
		}

		if (!objectives.monumentVector.empty())
		{
			for (int i = 0; i < objectives.monumentVector.size(); i++)
			{
				if (objectives.monumentVector.at(i)->getMonument().getGlobalBounds().contains(mousePos))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left()))
					{
						if (myTools.rubberToolSelected)
						{
							vector<std::unique_ptr<Monument>>::iterator begin = objectives.monumentVector.begin();
							begin += i;
							objectives.monumentVector.erase(begin);
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
	
	//myFile << "WALLS,\n";
	//myFile << "X,Y,Type,Object,\n";
	//
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


	//myFile << "SPAWNERS,\n";
	//myFile << "X,Y,Type,Object,\n";

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

	//myFile << "OBJECTIVES,\n";
	//myFile << "X,Y,Type,Object,\n";

	for (int i = 0; i < objectives.coinVector.size(); i++)
	{
		myFile << static_cast<int>(objectives.coinVector.at(i).get()->getCoin().getPosition().x);
		myFile << ",";
		myFile << static_cast<int>(objectives.coinVector.at(i).get()->getCoin().getPosition().y);
		myFile << ",";
		myFile << "0";
		myFile << ",";
		myFile << "C";
		myFile << "\n";
	}

	for (int i = 0; i < objectives.doorVector.size(); i++)
	{
		myFile << static_cast<int>(objectives.doorVector.at(i).get()->getDoor().getPosition().x);
		myFile << ",";
		myFile << static_cast<int>(objectives.doorVector.at(i).get()->getDoor().getPosition().y);
		myFile << ",";
		myFile << "1";
		myFile << ",";
		myFile << "D";
		myFile << "\n";
	}

	for (int i = 0; i < objectives.monumentVector.size(); i++)
	{
		myFile << static_cast<int>(objectives.monumentVector.at(i).get()->getMonument().getPosition().x);
		myFile << ",";
		myFile << static_cast<int>(objectives.monumentVector.at(i).get()->getMonument().getPosition().y);
		myFile << ",";
		myFile << "2";
		myFile << ",";
		myFile << "M";
		myFile << "\n";
	}

	//myFile << "GAMEOPTIONS,\n";
	//myFile << "BGChoice,GTChoice,Type,Object\n";

	myFile << gameOptions.chosenBG;
	myFile << ",";
	myFile << gameOptions.chosenGT;
	myFile << ",";
	myFile << "0";
	myFile << ",";
	myFile << "Z";
	myFile << "\n";


	myFile.close();
}

void Game::createLevel()
{
	clearVectors();
	playerHUD.myHealthBar.plusHealth(1000);
	playerHUD.myClock.startClock();
	coinsCollected = 0;
	myPlayer.getPlayer().setPosition(sf::Vector2f(gameWidth / 2, gameHeight / 2));

	for (int i = 0; i < gameChoice.loader.wallData.size(); i++)
	{
		sf::Vector2f tempWallPos = { gameChoice.loader.wallData.at(i).x , gameChoice.loader.wallData.at(i).y };
		wallVector.emplace_back(new Wall(createIndividualWall(tempWallPos, gameChoice.loader.wallData.at(i).z)));
	}

	for (int i = 0; i < gameChoice.loader.spawnerData.size(); i++)
	{
		sf::Vector2f tempSpawnerPos = { gameChoice.loader.spawnerData.at(i).x , gameChoice.loader.spawnerData.at(i).y };
		enemySpawnerVector.emplace_back(new EnemySpawner(createIndividualSpawner(tempSpawnerPos, gameChoice.loader.spawnerData.at(i).z)));
	}

	for (int i = 0; i < gameChoice.loader.coinData.size(); i++)
	{

		sf::Vector2f tempCoinPos = { gameChoice.loader.coinData.at(i).x , gameChoice.loader.coinData.at(i).y };
		objectives.addToVector(tempCoinPos, 0);
	}

	for (int i = 0; i < gameChoice.loader.doorData.size(); i++)
	{
		sf::Vector2f tempDoorPos = { gameChoice.loader.doorData.at(i).x , gameChoice.loader.doorData.at(i).y };
		objectives.addToVector(tempDoorPos, 1);

	}

	for (int i = 0; i < gameChoice.loader.monumentData.size(); i++)
	{
		sf::Vector2f tempMonumentPos = { gameChoice.loader.monumentData.at(i).x , gameChoice.loader.monumentData.at(i).y };
		objectives.addToVector(tempMonumentPos, 2);

	}

	gameOptions.chosenBG = gameChoice.loader.BGGTChoices.x;
	gameOptions.chosenGT = gameChoice.loader.BGGTChoices.y;

	maxCoins = gameChoice.loader.coinData.size();
}

void Game::clearVectors()
{
	wallVector.clear();
	enemySpawnerVector.clear();
	bloodSplatterVector.clear();

	objectives.coinVector.clear();
	objectives.doorVector.clear();
	objectives.monumentVector.clear();
}

bool Game::isColliding(sf::FloatRect t_obj1, sf::FloatRect t_obj2)
{
	return t_obj1.intersects(t_obj2);
}

void Game::collisionDetection()
{
	for (auto spawnerIt = enemySpawnerVector.begin(); spawnerIt != enemySpawnerVector.end(); ++spawnerIt)
	{
		auto& spawner = *spawnerIt;

		for (auto enemyIt = spawner->enemyVector.begin(); enemyIt != spawner->enemyVector.end(); )
		{
			auto& enemy = *enemyIt;

			for (auto bulletIt = myPlayer.bulletVector.begin(); bulletIt != myPlayer.bulletVector.end(); )
			{
				auto& bullet = *bulletIt;

				if (isColliding(bullet.get()->getBullet().getGlobalBounds(), enemy->getEnemy().getGlobalBounds()))
				{
					if (enemy->getHealth() > 0)
					{
						enemy->setHealth(5);
					}
					else if (enemy->getHealth() <= 0)
					{
						bloodSplatterVector.emplace_back(new BloodSplatter(spawnBloodSplatter(enemy->getEnemy().getPosition())));
						enemyIt = spawner->enemyVector.erase(enemyIt);
					}
					
					bulletIt = myPlayer.bulletVector.erase(bulletIt);
				}
				else 
				{
					++bulletIt;
				}
			}
			if (enemyIt != spawner->enemyVector.end()) 
			{
				++enemyIt;
			}
		}
	}

	for (int i = 0; i < enemySpawnerVector.size(); i++)
	{
		for (int p = 0; p < enemySpawnerVector.at(i).get()->enemyVector.size(); p++)
		{
			if (isColliding(enemySpawnerVector.at(i).get()->enemyVector.at(p).get()->getEnemy().getGlobalBounds(), myPlayer.getPlayer().getGlobalBounds()))
			{
				playerHUD.myHealthBar.minusHealth(2);
			}
		}
	}
}



BloodSplatter Game::spawnBloodSplatter(sf::Vector2f t_splatterPos)
{
	BloodSplatter tempBlood{t_splatterPos, textureManager};

	return tempBlood;
}

void Game::checkWallHealth()
{
	for (int i = 0; i < wallVector.size(); i++)
	{
		if (wallVector.at(i).get()->getWallHealth() <= 0)
		{
			vector<unique_ptr<Wall >>::iterator begin = wallVector.begin();
			begin += i;
			wallVector.erase(begin);
		}
	}
}
