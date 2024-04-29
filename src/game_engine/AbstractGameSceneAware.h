#ifndef Abstract_Game_Scene_Aware_H
#define Abstract_Game_Scene_Aware_H

#include "GameScene.h"

class AbstractGameSceneAware
{
public:
    virtual void setParentScene(GameScene *parent);
    virtual GameScene *getParentScene();

private:
};

#endif
