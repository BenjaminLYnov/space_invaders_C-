
#include <Engine/GameManager/IGameManager.h>
//#include <SystemInputMgr.h>
#include <Engine/Render/Ressource/TextureManager.h>
#include <iostream>

int main() {
    // Texture Manager
    {
        TextureManager::Instance()->ExtractFileData("./Ressources/PlayerShip/PlayerShip.xml");
        TextureManager::Instance()->ExtractFileData("./Ressources/Weapons/Laser.xml");
        TextureManager::Instance()->ExtractFileData("./Ressources/Ennemies/Alien.xml");
        //TextureManager::Instance()->ExtractFileData("./Ressources/Basement.xml");
        //TextureManager::Instance()->ExtractFileData("./Ressources/Tear.xml");
    }

    //std::cout << TextureManager::Instance()->textures["IsaacSprite"].getSize().x;

    // INPUT
    /*{
        InputMgr::Instance()->Init();
        InputMgr::Instance()->AddNewPlayer();
    }*/

     //GAME MANAGER
    {
        IGameManager::Instance()->RunGame();
    }

    // Destroy Instances
    {
        IGameManager::DeleteInstance();
        //TextureManager::DeleteInstance();
        //InputMgr::DeleteInstance();
    }

    return 0;
}
