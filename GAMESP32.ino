#include <SPI.h>
#include <Adafruit_SSD1325.h>
#include <Adafruit_GFX.h>

#include "config/Constants.h"

#include "src/components/Button.h"
#include "src/components/JoystickAxis.h"
#include "src/managers/InputManager.h"
#include "src/managers/SceneManager.h"
#include "src/game_engine/RenderEngine.h"
#include "src/game_engine/GameEngine.h"
#include "src/game_engine/GameScene.h"

#include "src/examples/Snake-Like/game/Snake.h"
#include "src/examples/Snake-Like/game/Food.h"
#include "src/examples/Snake-Like/game/SnakeGameScene.h"
#include "src/examples/Snake-Like/ui/SnakeStartUI.h"
#include "src/examples/Snake-Like/ui/SnakeEndUI.h"

// Initialize buttons and joystick axes
Button buttonA = Button(BUTTON_A_PIN, "Button A");
Button buttonB = Button(BUTTON_B_PIN, "Button B");
Button buttonSW = Button(SW, "Button SW");
JoystickAxis xAxis = JoystickAxis(VRX, "X axis");
JoystickAxis yAxis = JoystickAxis(VRY, "Y axis");

// Initialize display
Adafruit_SSD1325 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

// Initialize core components
RenderEngine renderEngine = RenderEngine();
GameEngine gameEngine = GameEngine();

// Initialize scenes
SnakeGameScene snakeGameScene = SnakeGameScene("Snake Game");
GameScene startMenuGameScene = GameScene("Start");
GameScene endMenuGameScene = GameScene("End");
SnakeStartUI startUI = SnakeStartUI();
SnakeEndUI endUI = SnakeEndUI();

// Initialize managers
InputManager *inputManager = InputManager::getInstance();
SceneManager *sceneManager = SceneManager::getInstance();

// Initialize game objects
Snake snake = Snake(10, 10, 3, 6, 12); // Start with length 1
Food food = Food(40, 10, 3);           // Initial food position

void setup()
{
    Serial.begin(115200);

    // Add all the inputs to the InputManager
    inputManager->addInputs({&buttonA, &buttonB, &buttonSW, &xAxis, &yAxis});

    // Add all the game objects to snakeGameScene
    snakeGameScene.addGameObject(&snake);
    snakeGameScene.addGameObject(&food);
    snakeGameScene.setSnake(&snake);
    snakeGameScene.setFood(&food);

    // Add all the game objects to startMenuGameScene
    startMenuGameScene.addGameObject(&startUI);

    // Add all the game objects to endMenuGameScene
    endMenuGameScene.addGameObject(&endUI);

    // Add all the GameScenes to the sceneManager and set default one
    sceneManager->addGameScene(&snakeGameScene);
    sceneManager->addGameScene(&startMenuGameScene);
    sceneManager->addGameScene(&endMenuGameScene);
    sceneManager->setCurrentGameScene("Start");

    // Add sceneManager and renderEngine to the gameEngine
    gameEngine.addGameObject(sceneManager);
    gameEngine.addGameObject(&renderEngine);
}

void loop()
{
    gameEngine.update();
    gameEngine.render(display);
    waitUntilEndOfFrame();
}

void waitUntilEndOfFrame()
{
    static unsigned long lastLoop;
    while (millis() - lastLoop < FRAME_DURATION_MS)
    {
    }
    lastLoop = millis();
}
