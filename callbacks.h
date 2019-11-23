#pragma once

// Display timer
#define REDISPLAY_TIMER 0
#define REDISPLAY_INTERVAL 16

// Declaring OpenGL callbacks
void reshape_callback(int w, int h);
void display_callback(void);
void keyboard_down_callback(unsigned char key, int x, int y);
void special_down_callback(int key, int x, int y);
void special_up_callback(int key, int x, int y);
void timer_callback(int timer_id);
