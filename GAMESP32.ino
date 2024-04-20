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

// The whole inputs and outputs process is complex and could use a factory or something

Button buttonA = Button(BUTTON_A_PIN, "Button A");
Button buttonB = Button(BUTTON_B_PIN, "Button B");
Button buttonSW = Button(SW, "Button SW");
JoystickAxis xAxis = JoystickAxis(VRX, "X axis");
JoystickAxis yAxis = JoystickAxis(VRY, "Y axis");

Display display = Display(SCREEN_WIDTH, SCREEN_HEIGHT);
RenderEngine renderEngine = RenderEngine();
GameEngine gameEngine = GameEngine();

InputManager *inputManager = InputManager::getInstance();

// Define initial parameters for the DemoBounceSphere
int radius = 20;
int speedX = 2;
int speedY = 2;
int screenWidth = SCREEN_WIDTH;
int screenHeight = SCREEN_HEIGHT;
int initialX = screenWidth / 2;  // Center X position
int initialY = screenHeight / 2; // Center Y position

// Instantiate the DemoBounceSphere object
DemoBounceSphere bounceSphere = DemoBounceSphere(radius, initialX, initialY, speedX, speedY, screenWidth, screenHeight);

void setup()
{
    Serial.begin(115200);

    // Add buttons and joystick axes to the input manager
    inputManager->addInputs({&buttonA, &buttonB, &buttonSW, &xAxis, &yAxis});

    display.begin();
    gameEngine.addGameObject(&bounceSphere);
    gameEngine.addGameObject(&renderEngine); // Should be last in the array I think
}

void loop()
{
    // Record the start time of the loop iteration
    unsigned long startTime = millis();

    // Your loop code goes here
    gameEngine.update();
    gameEngine.render(display.getSprite());

    // Record the end time of the loop iteration
    unsigned long endTime = millis();
    // Calculate the duration of the loop iteration
    unsigned long duration = endTime - startTime;
    // Print the duration to the serial monitor
    Serial.print("Loop iteration duration: ");
    Serial.print(duration);
    Serial.println(" milliseconds");
}

void waitUntilEndOfFrame()
{
    static unsigned long lastLoop;
    while (millis() - lastLoop < FRAME_DURATION_MS)
    {
    }
    lastLoop = millis();
}
