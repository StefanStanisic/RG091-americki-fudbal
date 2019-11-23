#pragma once

//Variable that says which action is chosen
extern int action;

//Variable that says if you passed ball to the receiver in square
extern int win_square;

// Structure for routes
typedef struct
{
    float x,z;
} point;

//Function to draw one route
void draw_route(point action[], int n, float color_parametar_1, float color_parametar_2, float color_parametar_3);

//Function to draw routes for all recievers at once
void draw_selected_action(void);

//Function to draw target squares
void draw_target_square(point square[], int n);
void move_target_square(point square[], int n);

//Parameters for colors of route 1
extern float route_1_color_parameter_1;
extern float route_1_color_parameter_2;
extern float route_1_color_parameter_3;

//Parameters for colors of route 2
extern float route_2_color_parameter_1;
extern float route_2_color_parameter_2;
extern float route_2_color_parameter_3;

//Parameters for colors of route 3
extern float route_3_color_parameter_1;
extern float route_3_color_parameter_2;
extern float route_3_color_parameter_3;

//Parameters for colors of route 4
extern float route_4_color_parameter_1;
extern float route_4_color_parameter_2;
extern float route_4_color_parameter_3;


//Variables for route of receiver 1 in action 1
extern point action1_r1[];
extern int action1_r1_n;

//Variables for route of receiver 2 in action 1
extern point action1_r2[];
extern int action1_r2_n;

//Variables for route of receiver 3 in action 1
extern point action1_r3[];
extern int action1_r3_n;

//Variables for route of receiver 4 in action 1
extern point action1_r4[];
extern int action1_r4_n;


//Variables for route of receiver 1 in action 2
extern point action2_r1[];
extern int action2_r1_n;

//Variables for route of receiver 2 in action 2
extern point action2_r2[];
extern int action2_r2_n;

//Variables for route of receiver 3 in action 2
extern point action2_r3[];
extern int action2_r3_n;

//Variables for route of receiver 4 in action 2
extern point action2_r4[];
extern int action2_r4_n;


//Variables for route of receiver 1 in action 3
extern point action3_r1[];
extern int action3_r1_n;

//Variables for route of receiver 2 in action 3
extern point action3_r2[];
extern int action3_r2_n;

//Variables for route of receiver 3 in action 3
extern point action3_r3[];
extern int action3_r3_n;

//Variables for route of receiver 4 in action 3
extern point action3_r4[];
extern int action3_r4_n;


//Variables for route of receiver 1 in action 4
extern point action4_r1[];
extern int action4_r1_n;

//Variables for route of receiver 2 in action 4
extern point action4_r2[];
extern int action4_r2_n;

//Variables for route of receiver 3 in action 4
extern point action4_r3[];
extern int action4_r3_n;

//Variables for route of receiver 4 in action 4
extern point action4_r4[];
extern int action4_r4_n;


//Variables for route of receiver 1 in action 5
extern point action5_r1[];
extern int action5_r1_n;

//Variables for route of receiver 2 in action 5
extern point action5_r2[];
extern int action5_r2_n;

//Variables for route of receiver 3 in action 5
extern point action5_r3[];
extern int action5_r3_n;

//Variables for route of receiver 4 in action 5
extern point action5_r4[];
extern int action5_r4_n;


//Variables for route of receiver 1 in action 6
extern point action6_r1[];
extern int action6_r1_n;

//Variables for route of receiver 2 in action 6
extern point action6_r2[];
extern int action6_r2_n;

//Variables for route of receiver 3 in action 6
extern point action6_r3[];
extern int action6_r3_n;

//Variables for route of receiver 4 in action 6
extern point action6_r4[];
extern int action6_r4_n;


//Variables for route of receiver 1 in action 7
extern point action7_r1[];
extern int action7_r1_n;

//Variables for route of receiver 2 in action 7
extern point action7_r2[];
extern int action7_r2_n;

//Variables for route of receiver 3 in action 7
extern point action7_r3[];
extern int action7_r3_n;

//Variables for route of receiver 4 in action 7
extern point action7_r4[];
extern int action7_r4_n;


//Variables for route of receiver 1 in action 8
extern point action8_r1[];
extern int action8_r1_n;

//Variables for route of receiver 2 in action 8
extern point action8_r2[];
extern int action8_r2_n;

//Variables for route of receiver 3 in action 8
extern point action8_r3[];
extern int action8_r3_n;

//Variables for route of receiver 4 in action 8
extern point action8_r4[];
extern int action8_r4_n;


//Variables for route of receiver 1 in action 9
extern point action9_r1[];
extern int action9_r1_n;

//Variables for route of receiver 2 in action 9
extern point action9_r2[];
extern int action9_r2_n;

//Variables for route of receiver 3 in action 9
extern point action9_r3[];
extern int action9_r3_n;

//Variables for route of receiver 4 in action 9
extern point action9_r4[];
extern int action9_r4_n;


//Variables for route of receiver 1 in action 10
extern point action10_r1[];
extern int action10_r1_n;

//Variables for route of receiver 2 in action 10
extern point action10_r2[];
extern int action10_r2_n;

//Variables for route of receiver 3 in action 10
extern point action10_r3[];
extern int action10_r3_n;

//Variables for route of receiver 4 in action 10
extern point action10_r4[];
extern int action10_r4_n;

//Variables for target square 1
extern point square_1[];
extern int square_1_n;

//Variables for target square 2
extern point square_2[];
extern int square_2_n;

