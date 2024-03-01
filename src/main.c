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

static char* task_name = NULL;

static float* data;
static long long data_count = 0;
static long long data_size = 16;

static float data_max = FLT_MIN; // init as min value
static float data_min = FLT_MAX; // init as max value

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

    for (size_t i = 0; fgets(line, sizeof(line), fp); ++i) {
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

        data_count = i;
    }
    fclose(fp);

    InitWindow(g_screen_width, g_screen_height, g_app_title);
    SetTargetFPS(60);
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
        const int rect_w = 500;
        const int rect_h = 250;
        DrawRectangleLines(rect_x, rect_y, rect_w, rect_h, LIGHTGRAY);
        for (size_t x = 0; x < data_count; ++x) {
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
        DrawText(TextFormat("Max: %.2f", data_max), 5, rect_y+rect_h+10, 18, LIGHTGRAY);
        DrawText(TextFormat("Min: %.2f", data_min), 5, rect_y+rect_h+35, 18, LIGHTGRAY);
    EndDrawing();
}
