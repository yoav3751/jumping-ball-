#define len 60
#include "raylib.h"
int main()
{ 
InitWindow(1300, 800, "My Box Project");
    
    SetTargetFPS(60);

    float ballY = 200.0f;
    float ballX = 300.0f;
     
    // can change
    float ballRadius = 50.0f;
    float velocityY = 50.0f;
    float velocityX = 50.0f;
    float gravity = 1.5f;
    float friction = 0.99f;
    float stop_valX = 0.1f;
    float stop_valY = 1.0f;
    float path = 15;
    Vector2 track[len] = {0};
   
    int indx = 0;
    float boxX = 200.0f;
    float boxY = 100.0f;
    float boxWidth = 900.0f;
    float boxHeight = 600.0f;

    while (!WindowShouldClose()) 
    {
        velocityY += gravity;
        velocityX *= friction;

        ballX += velocityX;
        ballY += velocityY;
       if(ballX - ballRadius < boxX)
        {
            ballX = boxX + ballRadius;
            velocityX *= -0.8f;
        }
        if(ballY - ballRadius < boxY)
        {
            ballY = boxY + ballRadius;
            velocityY *= -0.8f;
        }
        if(ballX + ballRadius > boxX + boxWidth)
        {
            ballX = boxX + boxWidth - ballRadius;
            velocityX *= -0.8f;
        }
        if(ballY + ballRadius > boxY + boxHeight)
        {
            ballY = boxY + boxHeight - ballRadius;
            velocityY *= -0.8f;
        }
        track[indx % len] = (Vector2){ballX, ballY};
        indx++;
        if(velocityY < stop_valY &&  velocityY > - stop_valY)
        {
            velocityY = 0.0f;
        }
        if(velocityX < stop_valX && velocityX > - stop_valX)
        {
            velocityX = 0;
        }
        BeginDrawing();
            
            for(int i = 0;i < len;i++)
            {
                float alpha = (float)i / len;
                Color trailColor = Fade(RED, alpha * 0.4f);
                int index = (indx + i) % len;
                if (track[index].x != 0 && track[index].y != 0) {
                DrawCircleV(track[index], path * 0.4f, WHITE);
                }
            }
            ClearBackground(BLACK);
            DrawRectangleLines(boxX, boxY, boxWidth, boxHeight,WHITE);
            DrawCircle(ballX,ballY, 50,RED);

        EndDrawing();
    }

    CloseWindow();    
    return 0;
}  