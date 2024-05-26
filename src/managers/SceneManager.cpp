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
    Serial.println(currentGameScene->getName());
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
    if (gamesScenes.empty())
    {
        setCurrentGameScene(scene);
    }
    gamesScenes[scene->getName()] = scene;
    // input->begin();
}

void SceneManager::setCurrentGameScene(GameScene *scene)
{
    currentGameScene = scene;
}