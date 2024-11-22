
#include "raylib.h"

int main()
{
    //window dimentions
   const int windowWidth{512};
   const int windowHeight{380};

   InitWindow(windowWidth, windowHeight, "Dapper Dasher!");
// aceleration due to gravity (pixels per second)
    const int gravity{1'000};
    int jumpVel{-600};
    bool isInAir{false};

//2d texture
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;


    

   

   

//movment variables
    int velocity{0};
    

   SetTargetFPS(60);

   while ((!WindowShouldClose()))
   {
    
    //delta time (time since last frame)
    const float dT(GetFrameTime());

    //start drawing
    BeginDrawing();
    ClearBackground(WHITE);

    if(scarfyPos.y >= windowHeight - scarfyRec.height)
    {
        //rectangle is the ground

        velocity = 0;
        isInAir = false;
        
    }else{

        //rectanlge is in the air
         //apply gravity
        isInAir = true;
        velocity += gravity * dT;
    }

    //check for jumping
    if (IsKeyPressed(KEY_SPACE) && isInAir == false ){
        velocity += jumpVel;

    }
    
    // update position
    scarfyPos.y += velocity * dT;

    DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

    EndDrawing();
   }
   UnloadTexture(scarfy);
   CloseWindow();
   return 0;
   

}





