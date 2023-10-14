#include "external/astrocore/AstroCore/engine/scene.h"
#include "external/astrocore/AstroCore/entities/baseEntities/animatedSpriteEntity.h"

using namespace Astrocore;

class ExampleScene : public Scene
{
   
public:

    SpriteEntity* player;

    virtual void LoadScene() override final
    {
        // Create new camera and set it as the current
        SetCurrentCamera(new CameraEntity());

        // Set the 'target' resolution and instruct the camera to fill the window (cropping the largest dimension)
        GetCurrentCamera()->SetRenderDimensions(320, 160);
        GetCurrentCamera()->SetScaleMode(FILL_ASPECT);

        Texture2D* playerTexture = TextureManager::instance().GetTexture("characterSheet.png");
        player = new SpriteEntity(playerTexture, (Vector2){32,32}, Vector2{16,16}, {0,32});

    
        // Add the player entity to the scene to be updated and rendered
        RegisterEntity(player);

        // We can re-use the character sheet as a sprite atlas!
        SpriteAnimation* animatedPlayer = new SpriteAnimation(playerTexture, 4, 5, 4, {64,64}, {32,32});
        animatedPlayer->startPos = {0,32};

        AnimatedSpriteEntity* animSprite = new AnimatedSpriteEntity("anim", animatedPlayer, "defaultAnimation");
        RegisterEntity(animSprite);
    }

    void Update(float delta) override final
    {

        InputManager input = InputManager::instance();


        if(input.IsActionDown("moveUp"))
        {
            player->transform.MoveGlobal({0, -25 * delta});
        }
        else if(input.IsActionDown("moveDown"))
        {
            player->transform.MoveGlobal({0, 25 * delta});
        }
        if(input.IsActionDown("moveLeft"))
        {
            player->transform.MoveGlobal({-25 * delta, 0});
        }
        else if(input.IsActionDown("moveRight"))
        {
            player->transform.MoveGlobal({25 * delta, 0});
        }
        // When overriding functions, be sure to call the base!
        Scene::Update(delta);
    }
};

