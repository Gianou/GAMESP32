#include "SnakeEndUI.h"

SnakeEndUI::SnakeEndUI() {}

// Menu state variables
int menuSelection = 0;                      // 0-2: letters, 3: save, 4: cancel
char playerName[4] = {'A', 'A', 'A', '\0'}; // 3-character name with null terminator

void SnakeEndUI::update()
{
    // Get the input manager
    InputManager *inputManager = InputManager::getInstance();
    SceneManager *sceneManager = SceneManager::getInstance();

    // Handle input for navigating the menu and changing the player name
    handleInput(inputManager, sceneManager);
}

void SnakeEndUI::render(Adafruit_SSD1325 &display)
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);

    // Display "Game Over!" and the score
    display.setCursor(12, 4);
    display.print("Game Over");

    display.setTextSize(1);
    display.setCursor(10, 25);
    display.print("Score: ");
    display.print(scoreHandler->getDisplayScore());

    // Display player name input section
    display.setCursor(10, 40);
    display.print("Name: ");

    // Display each letter with an underscore or brackets for selection
    for (int i = 0; i < 3; i++)
    {
        display.setCursor(46 + (i * 14), 40);
        if (menuSelection == i)
        {
            // Highlight the current letter
            display.print("|");
            display.print(playerName[i]);
            display.print("|");
        }
        else
        {
            display.print(" ");
            display.print(playerName[i]);
            display.print(" ");
        }
    }

    // Display "Save" and "Cancel" buttons
    display.setCursor(10, 55);
    if (menuSelection == 3)
        display.print("> Save");
    else
        display.print("  Save");

    display.setCursor(70, 55);
    if (menuSelection == 4)
        display.print("> Cancel");
    else
        display.print("  Cancel");

    // Update the display
    display.display();
}

void SnakeEndUI::handleInput(InputManager *inputManager, SceneManager *sceneManager)
{
    // Get input from InputManager
    int xInput = inputManager->getInputValue("X axis");
    int yInput = inputManager->getInputValue("Y axis");

    // Define a small threshold for the joystick to be considered "centered"
    const int centerThreshold = 2000; // Close to neutral (centered)

    static bool xAxisMoved = false; // Track whether the X axis was moved

    // Handle X axis (left/right) movement
    if (xInput > 3000 && !xAxisMoved)
    {
        if (menuSelection < 4)
            menuSelection++; // Move right
        xAxisMoved = true;   // Mark that the X axis was moved
    }
    else if (xInput < 1000 && !xAxisMoved)
    {
        if (menuSelection > 0)
            menuSelection--; // Move left
        xAxisMoved = true;   // Mark that the X axis was moved
    }

    // Reset xAxisMoved when joystick returns to the center
    if (xInput >= 1000 && xInput <= 3000)
    {
        xAxisMoved = false; // Joystick is centered again
    }

    // Handle Y axis (up/down) movement for letter change
    if (yInput > 3800)
    {
        if (menuSelection < 3)
        {
            // Cycle the current letter up (A-Z)
            if (playerName[menuSelection] < 'Z')
            {
                playerName[menuSelection]++;
            }
            else
            {
                playerName[menuSelection] = 'A'; // Wrap around to 'A'
            }
        }
    }
    else if (yInput < 200)
    {
        if (menuSelection < 3)
        {
            // Cycle the current letter down (Z-A)
            if (playerName[menuSelection] > 'A')
            {
                playerName[menuSelection]--;
            }
            else
            {
                playerName[menuSelection] = 'Z'; // Wrap around to 'Z'
            }
        }
    }

    // Select action (Save or Cancel) when Button B is pressed
    if (!inputManager->getInputValue("Button B"))
    {
        if (menuSelection == 3)
        {
            // Save the name and exit to the start screen
            savePlayerName(playerName);
            NetworkManager *networkManager = NetworkManager::getInstance();
            networkManager->saveScoreFirestore(playerName, scoreHandler->getScore() * 100);
            menuSelection = 0;
            sceneManager->setCurrentGameScene("Start");
        }
        else if (menuSelection == 4)
        {
            // Cancel and go back to the start screen
            cancelNameInput();
            menuSelection = 0;
            sceneManager->setCurrentGameScene("Start");
        }
    }
}

void SnakeEndUI::savePlayerName(const char *name)
{
    Serial.print("Player name saved: ");
    Serial.println(name);
    // Implement actual save logic if needed
}

void SnakeEndUI::cancelNameInput()
{
    Serial.println("Name input canceled.");
    // Implement any logic if needed for canceling
}
