
#include "raylib.h"

int main()
{
    //window dimentions
    ChangeDirectory(GetApplicationDirectory());
   const int windowWidth{512};
   const int windowHeight{380};

   


   InitWindow(windowWidth, windowHeight, "Dapper Dasher!");
// aceleration due to gravity (pixels per second)
    const int gravity{1'000};
    int jumpVel{-600};
    bool isInAir{false};

// nebula variables
Texture2D nebula = LoadTexture("textures/12_nebula_spritesheet.png");
Rectangle nebRec;
nebRec.x = 0;
nebRec.y = 0;
nebRec.height = nebula.height/8;
nebRec.width = nebula.width/8;
Vector2 nebPos{windowWidth, windowHeight - nebRec.height};


Rectangle neb2Rec{0.0, 0.0, static_cast<float>(nebula.width/8), static_cast<float>(nebula.height/8)};
Vector2 neb2pos{windowWidth + 300, windowHeight - nebRec.height};

// animation variables nebula
int nebFrame{};
const float nebUpdateTime(1.0/12.0);
float nebRunningTime{0};

int neb2Frame{};
const float neb2UpdateTime{1.0/16.0};
float neb2RunningTime{};



// nebula x velocity (pixels/ second)
int nebVel{-200};

//2d texture scarfy
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;

//animation frame
int frame{0};
// amount of time before we update the animation frame
//12 animation per second
const float updateTime{1.0/12.0};

float runningTime{0};


 

//movment variables
    int velocity{0};
    

   SetTargetFPS(60);

/// game cycle
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
    
    // update nebula position
    nebPos.x += nebVel * dT;

    // update the socond nebula position
    neb2pos.x += nebVel * dT;


    // update scarfy position
    scarfyPos.y += velocity * dT;

    //updating nebula animation

    nebRunningTime += dT;

    if(nebRunningTime >= nebUpdateTime)
    {
        nebRunningTime = 0;
        nebRec.x = nebFrame * nebRec.width;
        nebFrame++;
        if(nebFrame > 7)
        {
            nebFrame = 0;
        }
    }

    // update the scond nebula animation

    neb2RunningTime += dT;

    if(neb2RunningTime >= neb2UpdateTime)
    {
        neb2RunningTime = 0;
        neb2Rec.x = neb2Frame * neb2Rec.width;
        neb2Frame++;
        if(neb2Frame > 7)
        {
            neb2Frame = 0;
        }
    }


    // animation scarfy
    if(isInAir == false)
    {
             // update runing time
            runningTime += dT;
            if(runningTime >= updateTime )
        {
            //update animation frame
            scarfyRec.x = frame * scarfyRec.width;
            frame++;
            if (frame > 5)
            {
                frame = 0;
            }
            
            runningTime = 0.0;

        }
        
    }
    
   

   
    
    
    // draw nebula
    DrawTextureRec(nebula, nebRec, nebPos, WHITE);
    // drae the second nebula
    DrawTextureRec(nebula, neb2Rec, neb2pos,RED);

    // draw scarfy
    DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

    EndDrawing();
   }
   UnloadTexture(scarfy);
   UnloadTexture(nebula);
   CloseWindow();
   return 0;
   
   

}





