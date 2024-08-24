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

#include "src/examples/Pong-Like/game/BounceSphere.h"
#include "src/examples/Pong-Like/game/PaddleLeft.h"
#include "src/examples/Pong-Like/game/PaddleRight.h"
#include "src/examples/Pong-Like/game/PongGameScene.h"

#include "src/examples/Pong-Like/ui/StartUI.h"
#include "src/examples/Pong-Like/ui/EndUI.h"

Button buttonA = Button(BUTTON_A_PIN, "Button A");
Button buttonB = Button(BUTTON_B_PIN, "Button B");
Button buttonSW = Button(SW, "Button SW");
JoystickAxis xAxis = JoystickAxis(VRX, "X axis");
JoystickAxis yAxis = JoystickAxis(VRY, "Y axis");

Adafruit_SSD1325 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
RenderEngine renderEngine = RenderEngine();
PongGameScene pongGameScene = PongGameScene("Pong Game");
GameScene startMenuGameScene = GameScene("Start");
GameScene endMenuGameScene = GameScene("End");
StartUI startUI = StartUI();
EndUI endUI = EndUI();
GameEngine gameEngine = GameEngine();

InputManager *inputManager = InputManager::getInstance();
SceneManager *sceneManager = SceneManager::getInstance();

// BounceSphere
int radius = 3;
int speedX = 3;
int speedY = 3;
int initialX = SCREEN_WIDTH / 2;
int initialY = SCREEN_HEIGHT / 2;
BounceSphere bounceSphere = BounceSphere(radius, initialX, initialY, speedX, speedY);

// Paddle
int paddleX = 12;
int paddleY = 12;
int paddleWidth = 4;
int paddleHeight = 12;
int paddleSpeed = 4;
PaddleLeft paddleLeft = PaddleLeft(paddleX, paddleY, paddleWidth, paddleHeight, paddleSpeed);
PaddleRight paddleRight = PaddleRight(SCREEN_WIDTH - paddleX + paddleWidth, paddleY, paddleWidth, paddleHeight, paddleSpeed);

void setup()
{
    Serial.begin(115200);

    // Add all the inputs to the InputManager
    inputManager->addInputs({&buttonA, &buttonB, &buttonSW, &xAxis, &yAxis});

    // Add all the game objects to pongGameScene
    pongGameScene.addGameObject(&bounceSphere);
    pongGameScene.addGameObject(&paddleLeft);
    pongGameScene.addGameObject(&paddleRight);
    bounceSphere.setParentScene(&pongGameScene);

    // Add all the game objects to startMenuGameScene
    startMenuGameScene.addGameObject(&startUI);

    // Add all the game objects to endMenuGameScene
    endMenuGameScene.addGameObject(&endUI);

    // Add all the GameScenes to the sceneManager and set default one
    sceneManager->addGameScene(&pongGameScene);
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
