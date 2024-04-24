#define BUTTON_A_PIN 37
#define BUTTON_B_PIN 21

#define VRX 8
#define VRY 3
#define SW 46

#define FRAME_DURATION_MS 33
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#include <SPI.h>

#include "src/components/Button.h"
#include "src/components/JoystickAxis.h"
#include "src/components/Display.h"
#include "src/managers/InputManager.h"
#include "src/game_engine/RenderEngine.h"
#include "src/game_engine/GameEngine.h"

#include "src/demo/DemoBounceSphere.h"
#include "src/demo/DemoPaddle.h"

Button buttonA = Button(BUTTON_A_PIN, "Button A");
Button buttonB = Button(BUTTON_B_PIN, "Button B");
Button buttonSW = Button(SW, "Button SW");
JoystickAxis xAxis = JoystickAxis(VRX, "X axis");
JoystickAxis yAxis = JoystickAxis(VRY, "Y axis");

Display display = Display(SCREEN_WIDTH, SCREEN_HEIGHT);
RenderEngine renderEngine = RenderEngine();
GameEngine gameEngine = GameEngine();

InputManager *inputManager = InputManager::getInstance();

// DemoBounceSphere
int radius = 4;
int speedX = 1;
int speedY = 1;
int screenWidth = SCREEN_WIDTH;
int screenHeight = SCREEN_HEIGHT;
int initialX = screenWidth / 2;
int initialY = screenHeight / 2;
DemoBounceSphere bounceSphere = DemoBounceSphere(radius, initialX, initialY, speedX, speedY, screenWidth, screenHeight);

// DemoPaddle
int paddleX = 12;
int paddleY = 12;
int paddleWidth = 4;
int paddleHeight = 20;
int paddleSpeed = 4;
DemoPaddle paddle = DemoPaddle(paddleX, paddleY, paddleWidth, paddleHeight, paddleSpeed);

void setup()
{
    Serial.begin(115200);
    inputManager->addInputs({&buttonA, &buttonB, &buttonSW, &xAxis, &yAxis});

    display.begin();
    gameEngine.addGameObject(&bounceSphere);
    gameEngine.addGameObject(&paddle);
    gameEngine.addGameObject(&renderEngine);
}

void loop()
{
    unsigned long startTime = millis();

    gameEngine.update();
    gameEngine.render(display.getSprite());

    unsigned long endTime = millis();
    unsigned long duration = endTime - startTime;
    Serial.println("Loop iteration duration: " + String(duration) + "ms");
}

void waitUntilEndOfFrame()
{
    static unsigned long lastLoop;
    while (millis() - lastLoop < FRAME_DURATION_MS)
    {
    }
    lastLoop = millis();
}
