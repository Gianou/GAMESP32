#include "SceneManager.h"

SceneManager *SceneManager::instance_ = nullptr;

SceneManager *SceneManager::getInstance()
{
    if (instance_ == nullptr)
    {
        instance_ = new SceneManager();
    }
    return instance_;
}

void SceneManager::update()
{
    currentGameScene->update();
}

void SceneManager::render(Adafruit_SSD1325 &display)
{
    currentGameScene->render(display);
}

void SceneManager::addGameScene(GameScene *scene)
{

    if (gamesScenes.find(scene->getName()) != gamesScenes.end())
    {
        Serial.println("Error: Scene with the same name already exists.");
        throw std::invalid_argument("Scene with the same name already exists.");
    }
    // set scene as current if it is the only scene
    if (gamesScenes.empty())
    {
        setCurrentGameScene(scene);
    }
    gamesScenes[scene->getName()] = scene;
}

void SceneManager::setCurrentGameScene(GameScene *scene)
{
    currentGameScene = scene;
}

void SceneManager::setCurrentGameScene(String gameSceneName)
{
    // Check if a GameScene exits for gameSceneName
    if (gamesScenes.find(gameSceneName) == gamesScenes.end())
    {
        Serial.println("Error: Scene with name : " + gameSceneName + " not found");
        throw std::invalid_argument("Scene name not found");
    }
    currentGameScene = gamesScenes[gameSceneName];
}