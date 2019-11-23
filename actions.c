#include <GL/gl.h>
#include <math.h> 
#include "actions.h"
#define PI 3.14149

int win_square = 0;
extern int hit;
extern int miss;

//Function that draws all routes in action
void draw_selected_action(void)
{
    glLineWidth(5);
    switch(action)
    {
        case 1:
            draw_route(action1_r1, action1_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action1_r2, action1_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action1_r3, action1_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action1_r4, action1_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 2:
            draw_route(action2_r1, action2_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action2_r2, action2_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action2_r3, action2_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action2_r4, action2_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 3:
            draw_route(action3_r1, action3_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action3_r2, action3_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action3_r3, action3_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action3_r4, action3_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 4:
            draw_route(action4_r1, action4_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action4_r2, action4_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action4_r3, action4_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action4_r4, action4_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 5:
            draw_route(action5_r1, action5_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action5_r2, action5_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action5_r3, action5_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action5_r4, action5_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 6:
            draw_route(action6_r1, action6_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action6_r2, action6_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action6_r3, action6_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action6_r4, action6_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 7:
            draw_route(action7_r1, action7_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action7_r2, action7_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action7_r3, action7_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action7_r4, action7_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 8:
            draw_route(action8_r1, action8_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action8_r2, action8_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action8_r3, action8_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action8_r4, action8_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 9:
            draw_route(action9_r1, action9_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action9_r2, action9_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action9_r3, action9_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action9_r4, action9_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
        case 10:
            draw_route(action10_r1, action10_r1_n, route_1_color_parameter_1, route_1_color_parameter_2, route_1_color_parameter_3);
            draw_route(action10_r2, action10_r2_n, route_2_color_parameter_1, route_2_color_parameter_2, route_2_color_parameter_3);
            draw_route(action10_r3, action10_r3_n, route_3_color_parameter_1, route_3_color_parameter_2, route_3_color_parameter_3);
            draw_route(action10_r4, action10_r4_n, route_4_color_parameter_1, route_4_color_parameter_2, route_4_color_parameter_3);
            break;
    }
    glLineWidth(1);
}

//Functions that draws routes of reciever
void draw_route(point action[], int n, float color_parametar_1, float color_parametar_2, float color_parametar_3)
{
    glColor3f(color_parametar_1, color_parametar_2, color_parametar_3);
    glBegin(GL_LINE_STRIP);
        for(int i = 0; i < n-1; ++i)
        {
            glVertex3f(action[i].x, 0, action[i].z);
            glVertex3f(action[i+1].x, 0, action[i+1].z);
        }
    glEnd();
}

//Function that draws target square and colors it yellow if you threw the ball to the reciever inside of target square or green if you didn't
void draw_target_square(point square[], int n)
{
    glColor3f(0, 0, 0);
	if(win_square == 0)
	{
		glBegin(GL_LINE_LOOP);
	}
	else if(win_square == 1)
	{
		glBegin(GL_QUADS);
		glColor3f(1, 1, 0.4);
	}
	else
	{
		glBegin(GL_QUADS);
		glColor3f(0, 0.6, 0.2);
	}
        for(int i = 0; i < n-1; ++i)
        {
            glVertex3f(square[i].x, 0, square[i].z);
            glVertex3f(square[i+1].x, 0, square[i+1].z);
        }
    glEnd();
}

//Function that moves target square
void move_target_square(point square[], int n)
{
	static float parm = 0;
	if(win_square != 0)
	{
		return ;
	}

	int sign = (cos(parm/10) < 0) ? -1 : 1;

	for(int i = 0; i < n; ++i)
	{
		square[i].x += sign * 0.1;
	}

	parm += PI/20;
}

//Variables for route of receiver 1 in action 1
point action1_r1[] = {

    {-14, 0}, {-14, 2}, {0, 8}
};
int action1_r1_n = sizeof(action1_r1)/sizeof(point);

//Variables for route of receiver 2 in action 1
point action1_r2[] = {
    {-10, 0}, {-10, 7}, {-7, 4}
};
int action1_r2_n = sizeof(action1_r2)/sizeof(point);

//Variables for route of receiver 3 in action 1
point action1_r3[] = {
    {10, 0}, {10, 5}, {5, 10}
};
int action1_r3_n = sizeof(action1_r3)/sizeof(point);

//Variables for route of receiver 4 in action 1
point action1_r4[] = {
    {14, 0}, {14, 2}, {0, 6}
};
int action1_r4_n = sizeof(action1_r4)/sizeof(point);



//Variables for route of receiver 1 in action 2
point action2_r1[] = {
    {-14, 0}, {-14, 5}, {0, 5}
};
int action2_r1_n = sizeof(action2_r1)/sizeof(point);

//Variables for route of receiver 2 in action 2
point action2_r2[] = {
    {-10, 0}, {-8, 6}, {-5, 4}
};
int action2_r2_n = sizeof(action2_r2)/sizeof(point);

//Variables for route of receiver 3 in action 2
point action2_r3[] = {
    {10, 0}, {7.5, 5}, {-2.5, 12.5}
};
int action2_r3_n = sizeof(action2_r3)/sizeof(point);

//Variables for route of receiver 4 in action 2
point action2_r4[] = {
    {14, 0}, {12, 7}, {10, 4}
};
int action2_r4_n = sizeof(action2_r4)/sizeof(point);



//Variables for route of receiver 1 in action 3
point action3_r1[] = {
    {-14, 0}, {-10, 2}, {-5, 6}
};
int action3_r1_n = sizeof(action3_r1)/sizeof(point);

//Variables for route of receiver 2 in action 3
point action3_r2[] = {
    {-10, 0}, {-8, 3}, {5,5}
};
int action3_r2_n = sizeof(action3_r2)/sizeof(point);

//Variables for route of receiver 3 in action 3
point action3_r3[] = {
    {10, 0}, {10, 7}, {0, 7}
};
int action3_r3_n = sizeof(action3_r3)/sizeof(point);

//Variables for route of receiver 4 in action 3
point action3_r4[] = {
    {14, 0}, {13, 3}, {10, 10}
};
int action3_r4_n = sizeof(action3_r4)/sizeof(point);


//Variables for route of receiver 1 in action 4
point action4_r1[] = {
    {-14, 0}, {-14, 3}, {-7, 3}
};
int action4_r1_n = sizeof(action4_r1)/sizeof(point);

//Variables for route of receiver 2 in action 4
point action4_r2[] = {
    {-10, 0}, {-10, 5}, {-7, 10}, {-5, 6}
};
int action4_r2_n = sizeof(action4_r2)/sizeof(point);

//Variables for route of receiver 3 in action 4
point action4_r3[] = {
    {10, 0}, {10, 5}, {7, 10}, {5, 6}
};
int action4_r3_n = sizeof(action4_r3)/sizeof(point);

//Variables for route of receiver 4 in action 4
point action4_r4[] = {
    {14, 0}, {14, 3}, {7, 3}
};
int action4_r4_n = sizeof(action4_r4)/sizeof(point);


//Variables for route of receiver 1 in action 5
point action5_r1[] = {
    {-14, 0}, {-14, 3}, {0, 3}
};
int action5_r1_n = sizeof(action5_r1)/sizeof(point);

//Variables for route of receiver 2 in action 5
point action5_r2[] = {
    {-10, 0}, {-10, 5}, {5, 8}
};
int action5_r2_n = sizeof(action5_r2)/sizeof(point);

//Variables for route of receiver 3 in action 5
point action5_r3[] = {
    {10, 0}, {10, 5}, {10, 7}, {14, 7}
};
int action5_r3_n = sizeof(action5_r3)/sizeof(point);

//Variables for route of receiver 4 in action 5
point action5_r4[] = {
    {14, 0}, {13, 0}, {6, 3}, {-4, 5}
};
int action5_r4_n = sizeof(action5_r4)/sizeof(point);


//Variables for route of receiver 1 in action 6
point action6_r1[] = {
    {-14, 0}, {-10, 0.5}, {5, 8}
};
int action6_r1_n = sizeof(action6_r1)/sizeof(point);

//Variables for route of receiver 2 in action 6
point action6_r2[] = {
    {-10, 0}, {-10, 6}, {-7.5, 3.5}
};
int action6_r2_n = sizeof(action6_r2)/sizeof(point);

//Variables for route of receiver 3 in action 6
point action6_r3[] = {
    {10, 0}, {10, 7}, {7.5, 3.5} 
};
int action6_r3_n = sizeof(action6_r3)/sizeof(point);

//Variables for route of receiver 4 in action 6
point action6_r4[] = {
    {14, 0}, {13.5, 2}, {0, 4}
};
int action6_r4_n = sizeof(action6_r4)/sizeof(point);


//Variables for route of receiver 1 in action 7
point action7_r1[] = {
    {-14, 0}, {-12, 2}, {-7, 4}
};
int action7_r1_n = sizeof(action7_r1)/sizeof(point);

//Variables for route of receiver 2 in action 7
point action7_r2[] = {
    {-10, 0}, {-6, 3}, {-4, 1.5}
};
int action7_r2_n = sizeof(action7_r2)/sizeof(point);

//Variables for route of receiver 3 in action 7
point action7_r3[] = {
    {10, 0}, {10, 5}, {-5, 5}
};
int action7_r3_n = sizeof(action7_r3)/sizeof(point);

//Variables for route of receiver 4 in action 7
point action7_r4[] = {
    {14, 0}, {14, 5}, {-5, 8}
};
int action7_r4_n = sizeof(action7_r4)/sizeof(point);


//Variables for route of receiver 1 in action 8
point action8_r1[] = {
    {-14, 0}, {-12, 6}, {-7, 3.5}
};
int action8_r1_n = sizeof(action8_r1)/sizeof(point);

//Variables for route of receiver 2 in action 8
point action8_r2[] = {
    {-10, 0}, {1, 12}
};
int action8_r2_n = sizeof(action8_r2)/sizeof(point);

//Variables for route of receiver 3 in action 8
point action8_r3[] = {
    {10, 0}, {7, 3}, {-5, 5}
};
int action8_r3_n = sizeof(action8_r3)/sizeof(point);

//Variables for route of receiver 4 in action 8
point action8_r4[] = {
    {14, 0}, {14, 5}, {-5, 8}
};
int action8_r4_n = sizeof(action8_r4)/sizeof(point);


//Variables for route of receiver 1 in action 9
point action9_r1[] = {
    {-14, 0}, {-12, 6}, {-7, 3.5}
};
int action9_r1_n = sizeof(action9_r1)/sizeof(point);

//Variables for route of receiver 2 in action 9
point action9_r2[] = {
    {-10, 0}, {-6, 3}, {0, 5}
};
int action9_r2_n = sizeof(action9_r2)/sizeof(point);

//Variables for route of receiver 3 in action 9
point action9_r3[] = {
    {10, 0}, {10, 5}, {0, 10}
};
int action9_r3_n = sizeof(action9_r3)/sizeof(point);

//Variables for route of receiver 4 in action 9
point action9_r4[] = {
    {14, 0}, {12, 6}, {7, 3.5}
};
int action9_r4_n = sizeof(action9_r4)/sizeof(point);


//Variables for route of receiver 1 in action 10
point action10_r1[] = {
    {-14, 0}, {-14, 4}, {-7, 6}
};
int action10_r1_n = sizeof(action10_r1)/sizeof(point);

//Variables for route of receiver 2 in action 10
point action10_r2[] = {
    {-10, 0}, {-7, 3}, {-4, 1.5}, {1, 5}
};
int action10_r2_n = sizeof(action10_r2)/sizeof(point);

//Variables for route of receiver 3 in action 10
point action10_r3[] = {
    {10, 0}, {10, 5}, {0, 10}
};
int action10_r3_n = sizeof(action10_r3)/sizeof(point);

//Variables for route of receiver 4 in action 10
point action10_r4[] = {
    {14, 0}, {14, 6.5}, {7.5, 7.5}
};
int action10_r4_n = sizeof(action10_r4)/sizeof(point);


//Variables for target square 1
point square_1[] = {
    {0, 7.5}, {-7.5, 7.5}, {-7.5, 0}, {0, 0}, {0, 7.5}
};
int square_1_n = sizeof(square_1)/sizeof(point);

//Variables for target square 2
point square_2[] = {
    {7.5, 10}, {3, 10}, {3, 3}, {7.5, 3}, {7.5, 10}
};
int square_2_n = sizeof(square_1)/sizeof(point);

//Color parameters for route 1
float route_1_color_parameter_1 = 1;
float route_1_color_parameter_2 = 0.694;
float route_1_color_parameter_3 = 0;

//Color parameters for route 2
float route_2_color_parameter_1 = 1;
float route_2_color_parameter_2 = 0.3137;
float route_2_color_parameter_3 = 0.3137;

//Color parameters for route 3
float route_3_color_parameter_1 = 0.6;
float route_3_color_parameter_2 = 0.4;
float route_3_color_parameter_3 = 1;

//Color parameters for route 4
float route_4_color_parameter_1 = 0.2;
float route_4_color_parameter_2 = 0.4;
float route_4_color_parameter_3 = 0.6;
