#define BUTTON_A_PIN 37
#define BUTTON_B_PIN 21

#define VRX 8
#define VRY 3
#define SW 46

#define FRAME_DURATION_MS 33
#define SCREEN_WIDTH 480
#define SCREEN_HEIGHT 320

#include <SPI.h>

#include "src/components/Button.h"
#include "src/components/JoystickAxis.h"
#include "src/components/Display.h"
#include "src/managers/InputManager.h"
#include "src/game_engine/RenderEngine.h"
#include "src/game_engine/GameEngine.h"
#include "src/demo/DemoBounceSphere.h"
#include "src/demo/DemoBounceImage.h"

Button buttonA = Button(BUTTON_A_PIN, "Button A");
Button buttonB = Button(BUTTON_B_PIN, "Button B");
Button buttonSW = Button(SW, "Button SW");
JoystickAxis xAxis = JoystickAxis(VRX, "X axis");
JoystickAxis yAxis = JoystickAxis(VRY, "Y axis");

Display display = Display(SCREEN_WIDTH, SCREEN_HEIGHT);
RenderEngine renderEngine = RenderEngine();
GameEngine gameEngine = GameEngine();

InputManager *inputManager = InputManager::getInstance();

int radius = 40;
int speedX = 10;
int speedY = 10;
int screenWidth = SCREEN_WIDTH;
int screenHeight = SCREEN_HEIGHT;
int initialX = screenWidth / 2;
int initialY = screenHeight / 2;

DemoBounceSphere bounceSphere = DemoBounceSphere(radius, initialX, initialY, speedX, speedY, screenWidth, screenHeight);
DemoBounceSphere bounceSphere1 = DemoBounceSphere(radius, initialX - 2 * radius, initialY - 2 * radius, speedX, speedY, screenWidth, screenHeight);
DemoBounceSphere bounceSphere2 = DemoBounceSphere(radius, initialX - 4 * radius, initialY - 4 * radius, speedX, speedY, screenWidth, screenHeight);
DemoBounceSphere bounceSphere3 = DemoBounceSphere(radius, initialX + 2 * radius, initialY + 2 * radius, speedX, speedY, screenWidth, screenHeight);
DemoBounceSphere bounceSphere4 = DemoBounceSphere(radius, initialX + 4 * radius, initialY + 4 * radius, speedX, speedY, screenWidth, screenHeight);

DemoBounceImage bounceImage = DemoBounceImage(90, 90, initialX, initialY, speedX, speedY, screenWidth, screenHeight);
int counter = 0;

void setup()
{
    Serial.begin(115200);

    inputManager->addInputs({&buttonA, &buttonB, &buttonSW, &xAxis, &yAxis});

    display.begin();
    gameEngine.addGameObject(&bounceSphere);

    gameEngine.addGameObject(&bounceSphere1);

    gameEngine.addGameObject(&bounceSphere2);
    gameEngine.addGameObject(&bounceSphere3);
    /*
    gameEngine.addGameObject(&bounceSphere4);
    */
    gameEngine.addGameObject(&renderEngine);

    Serial.println("[Test] Width: " + String(SCREEN_WIDTH) + "Height: 0" + String(SCREEN_HEIGHT));
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
