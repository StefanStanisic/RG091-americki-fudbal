#pragma once

// Window width and height
int width = 0, height = 0;

// Camera parameters
float ex = 0, ey = 10, ez = -14, px = 0, py = 0, pz = 0;

// Reciever one parameters
float r1_x = -14, r1_y = 0, r1_z = 0;
int r1_target_point = 1;

// Reciever two parameters
float r2_x = -10, r2_y = 0, r2_z = 0;
int r2_target_point = 1;

// Reciever three parameters
float r3_x = 10, r3_y = 0, r3_z = 0;
int r3_target_point = 1;

// Reciever four parameters
float r4_x = 14, r4_y = 0, r4_z = 0;
int r4_target_point = 1;

// Moving delta variables
float delta_px = 0, delta_pz = 0;
float delta_r1_x = 0, delta_r1_z = 0;

//Selected action
int action = 1;
//Is game started
int started = 0;
//Reciever speed
float speed = 0.1;
//EPS
float eps = 0.1;

//Ball parameters
int ball_alive = 0;
float ball_x = -1, ball_z, ball_y = 0.4;
float *ball_target_x = &px, *ball_target_z = &pz;
float ball_speed = 0.2;

//Parameter for field texture
extern unsigned field_texutre;

//Score variables
int hit = 0;
int miss = 0;
int attempts = 0;

//Variables for another try
int another = 0;
char answer;
