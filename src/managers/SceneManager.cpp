#include "SceneManager.h"

SceneManager *SceneManager::instance = nullptr;

SceneManager *SceneManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new SceneManager();
    }
    return instance;
}

void SceneManager::update()
{
    if (currentGameScene != nullptr)
    {
        currentGameScene->update();
    }
}

void SceneManager::render(Adafruit_SSD1325 &display)
{
    if (currentGameScene != nullptr)
    {
        currentGameScene->render(display);
    }
}

void SceneManager::addGameScene(GameScene *scene)
{

    if (gameScenes.find(scene->getName()) != gameScenes.end())
    {
        Serial.println("Error: Scene with the same name already exists.");
        throw std::invalid_argument("Scene with the same name already exists.");
    }
    // set scene as current if it is the only scene
    if (gameScenes.empty())
    {
        setCurrentGameScene(scene);
    }
    gameScenes[scene->getName()] = scene;
}

void SceneManager::setCurrentGameScene(GameScene *scene)
{
    if (currentGameScene != nullptr)
    {
        currentGameScene->onExitScene();
    }
    currentGameScene = scene;
    currentGameScene->onEnterScene();
}

void SceneManager::setCurrentGameScene(String gameSceneName)
{
    // Check if a GameScene exits for gameSceneName
    if (gameScenes.find(gameSceneName) == gameScenes.end())
    {
        Serial.println("Error: Scene with name : " + gameSceneName + " not found");
        throw std::invalid_argument("Scene name not found");
    }
    currentGameScene->onExitScene();
    currentGameScene = gameScenes[gameSceneName];
    currentGameScene->onEnterScene();
}