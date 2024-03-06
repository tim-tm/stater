/**
 *  main.c
 *  
 *  This file contains the entry point of the program and most of its logic.
 *
 *
 *  MIT License
 *  Copyright (c) 2024 Tim Teichmann
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 * 
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

#include "constants.h"
#include <float.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

static int screen_width = 800;
static int screen_height = 450;

static char* task_name = NULL;

static float* data;
static long long data_count = 0;
static long long data_size = 16;

static float data_max = FLT_MIN; // init as min value
static float data_min = FLT_MAX; // init as max value
static float data_max_diff = FLT_MIN; // init as min value
static float data_average = 0;
static float data_average_diff = 0;

static void UpdateDrawFrame(void);

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <.state file>\n", argv[0]);
        return 1;
    }
    printf("Reading %s\n", argv[1]);
    
    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        fprintf(stderr, "Failed to read file %s\n", argv[1]);
        return 1;
    }
    char line[128];
    task_name = calloc(128, sizeof(char));
    data = calloc(data_size, sizeof(float));

    for (long long i = 0; fgets(line, sizeof(line), fp); ++i) {
        if (i == 0) {
            strncpy(task_name, line, 128);
            continue;
        }
        
        // i+1 is redundant because the first string is the title and was skipped
        if (i > data_size) {
            data_size *= 2;
            data = realloc(data, data_size*sizeof(float));
        }

        data[i-1] = strtof(line, NULL);
        if (data[i-1] > data_max) {
            data_max = data[i-1];
        }
        if (data[i-1] < data_min) {
            data_min = data[i-1];
        }

        const float absdiff = fabs(data[i-1]-data[i-2]);
        if (absdiff > data_max_diff) {
            data_max_diff = absdiff;
        }

        data_count = i;
        data_average += data[i-1];
        data_average_diff += absdiff;
    }
    data_average /= data_count;
    data_average_diff /= data_count;
    fclose(fp);

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screen_width, screen_height, g_app_title);
    SetTargetFPS(60);
    SetWindowMinSize(g_window_min_width, g_window_min_height);

    while (!WindowShouldClose()) {
        UpdateDrawFrame();
    }

    CloseWindow();
    free(task_name);
    free(data);
    return 0;
}

static void UpdateDrawFrame(void) {
    BeginDrawing();
        ClearBackground(COLOR_DEFAULT_BLACK);
        DrawText(task_name, 5, 5, 30, LIGHTGRAY);

        const int rect_x = 5;
        const int rect_y = 45;
        const int rect_w = screen_width*0.8f;
        const int rect_h = screen_height*0.5f;
        DrawRectangleLines(rect_x, rect_y, rect_w, rect_h, LIGHTGRAY);
        for (long long x = 0; x < data_count; ++x) {
            /*DrawCircle(rect_x+((float)rect_w/(float)data_count)*x,
                    rect_y+rect_h-((data[x]-data_min)/(data_max-data_min))*rect_h,
                    3.f,
                    LIGHTGRAY);*/
            DrawLineEx(
                    (Vector2){
                        rect_x+((float)rect_w/(float)data_count)*x,
                        rect_y+rect_h-((data[x]-data_min)/(data_max-data_min))*rect_h
                    },
                    (Vector2){
                        rect_x+((float)rect_w/(float)data_count)*(x+1),
                        rect_y+rect_h-((data[x+1]-data_min)/(data_max-data_min))*rect_h
                    },
                    1.5f,
                    LIGHTGRAY);
        }
        DrawText(TextFormat("%.2f", data_max), rect_x+rect_w+5, rect_y, 12, LIGHTGRAY);
        DrawText(TextFormat("%.2f", data_min), rect_x+rect_w+5, rect_y+rect_h-11, 12, LIGHTGRAY);
        if (data_min < 0) {
            const float zeroY = rect_y+rect_h-((-data_min)/(data_max-data_min))*rect_h;
            DrawText("0.00", rect_x+rect_w+5, zeroY, 12, LIGHTGRAY);
            DrawLine(rect_x, zeroY, rect_x+rect_w, zeroY, LIGHTGRAY);
        }
        DrawText("0", rect_x, rect_y+rect_h+5, 12, LIGHTGRAY);
        const char* x_axis_end = TextFormat("%i", data_count);
        DrawText(x_axis_end, rect_x+rect_w-MeasureText(x_axis_end, 12), rect_y+rect_h+5, 12, LIGHTGRAY);

        DrawText(TextFormat("Average: %.2f", data_average), rect_x, rect_y+rect_h+40, 18, LIGHTGRAY);
        DrawText(TextFormat("Biggest difference: %.2f", data_max_diff), rect_x, rect_y+rect_h+65, 18, LIGHTGRAY);
        DrawText(TextFormat("Average difference: %.2f", data_average_diff), rect_x, rect_y+rect_h+85, 18, LIGHTGRAY);
        
        // Check if the mouse is on the plot
        // NOTE: Extract this to a seperate function if it is needed again
        if (rect_x < GetMouseX() &&
            rect_x+rect_w > GetMouseX() &&
            rect_y < GetMouseY() &&
            rect_y+rect_h > GetMouseY()) {
            // get the hovered index using math
            const int i = ((float)(GetMouseX()-rect_x)/(float)rect_w)*data_count;
            const float x = rect_x+((float)rect_w/(float)data_count)*i;
            const float y = rect_y+rect_h-((data[i]-data_min)/(data_max-data_min))*rect_h;
            
            // get the y coordinate of the x-Axis of the plot
            float zero_y = rect_y+rect_h;
            if (data_min < 0) {
                zero_y = rect_y+rect_h-((-data_min)/(data_max-data_min))*rect_h;
            }

            // Draw a point on the x-Axis and a connection from the x-Axis to the graph
            DrawLine(x, y, x, zero_y, RED);
            DrawCircle(x, zero_y, 3.f, RED);

            // display the current value
            const char* value_text = TextFormat("%.2f", data[i]);
            float text_x = x-(MeasureText(value_text, 12)/2.f);
            // prevents first coordinate from being cut off the screen
            if (i == 0) {
                text_x = x;
            }
            DrawText(value_text, text_x, rect_y+rect_h+5, 12, RED);
        }
    EndDrawing();
    screen_width = GetScreenWidth();
    screen_height = GetScreenHeight();
}
