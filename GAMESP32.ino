#include <SPI.h>

#include <Adafruit_SSD1325.h>
#include <Adafruit_GFX.h>

#include "config/Constants.h"

#include "src/components/Button.h"
#include "src/components/JoystickAxis.h"
// #include "src/components/DisplayOLED.h"
#include "src/managers/InputManager.h"
#include "src/game_engine/RenderEngine.h"
#include "src/game_engine/GameEngine.h"
#include "src/game_engine/GameScene.h"

#include "src/demo/BounceSphere.h"
#include "src/demo/PaddleLeft.h"
#include "src/demo/PaddleRight.h"
#include "src/demo/PongGameScene.h"

Button buttonA = Button(BUTTON_A_PIN, "Button A");
Button buttonB = Button(BUTTON_B_PIN, "Button B");
Button buttonSW = Button(SW, "Button SW");
JoystickAxis xAxis = JoystickAxis(VRX, "X axis");
JoystickAxis yAxis = JoystickAxis(VRY, "Y axis");

Adafruit_SSD1325 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
RenderEngine renderEngine = RenderEngine();
PongGameScene gameScene = PongGameScene();
GameEngine gameEngine = GameEngine();

InputManager *inputManager = InputManager::getInstance();

// BounceSphere
int radius = 4;
int speedX = 3;
int speedY = 3;
int initialX = SCREEN_WIDTH / 2;
int initialY = SCREEN_HEIGHT / 2;
BounceSphere bounceSphere = BounceSphere(radius, initialX, initialY, speedX, speedY);

// Paddle
int paddleX = 12;
int paddleY = 12;
int paddleWidth = 4;
int paddleHeight = 20;
int paddleSpeed = 4;
PaddleLeft paddleLeft = PaddleLeft(paddleX, paddleY, paddleWidth, paddleHeight, paddleSpeed);
PaddleRight paddleRight = PaddleRight(SCREEN_WIDTH - paddleX + paddleWidth, paddleY, paddleWidth, paddleHeight, paddleSpeed);

void setup()
{
    Serial.begin(115200);
    inputManager->addInputs({&buttonA, &buttonB, &buttonSW, &xAxis, &yAxis});

    display.begin();
    display.display();
    display.clearDisplay();

    gameScene.addGameObject(&bounceSphere);
    gameScene.addGameObject(&paddleLeft);
    gameScene.addGameObject(&paddleRight);
    bounceSphere.setParentScene(&gameScene);
    // paddle.setParentScene(&gameScene);

    gameEngine.addGameObject(&gameScene);
    // gameEngine.addGameObject(&renderEngine);
}

void loop()
{
    unsigned long startTime = millis();

    display.clearDisplay();
    gameEngine.update();
    gameEngine.render(display);
    display.display();

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
