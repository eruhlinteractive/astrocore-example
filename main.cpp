#include "external/astrocore/AstroCore/game.h"
#include "sceneTemplate.h"
#include "raylib.h"

using namespace Astrocore;

int main()
{
    
    Game myGame = Game::instance();

    // Update the raylib flags (must be done BEFORE the game is initialized)
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    // Initialize the game, setting a window title/width/height/target FPS (0 = unbound)
    myGame.InitGame("Astrocore Template", 1280, 720, 0);

    // Set the base folder to load assets from (relative to the executable file)
    TextureManager::instance().SetBaseAssetDir("../assets");

    // Setup basic input events
    InputManager::instance().AddActionEvent("moveUp", KEY_W);
    InputManager::instance().AddActionEvent("moveDown", KEY_S);
    InputManager::instance().AddActionEvent("moveLeft", KEY_A);
    InputManager::instance().AddActionEvent("moveRight", KEY_D);

    // Set the current scene to a new example scene
    myGame.SetCurrentScene(make_unique<ExampleScene>());

    // Run the main game loop
    myGame.Run();

    // The game automatically cleans up memory on exit. Yay!
    return 0;
}