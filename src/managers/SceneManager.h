#ifndef SceneManager_h
#define SceneManager_h

#include <map>

#include "../game_engine/AbstractGameObject.h"
#include "../game_engine/GameScene.h"

class SceneManager : public AbstractGameObject
{
public:
    static SceneManager *getInstance();
    SceneManager(const SceneManager &) = delete;
    void operator=(const SceneManager &) = delete;

    void update() override;
    void render(Adafruit_SSD1325 &display) override;

    void addGameScene(GameScene *gameScene);
    void setCurrentGameScene(GameScene *gameScene);
    void setCurrentGameScene(String gameSceneName);

private:
    SceneManager() {}
    static SceneManager *instance;
    std::map<String, GameScene *> gameScenes;
    GameScene *currentGameScene;
};
#endif