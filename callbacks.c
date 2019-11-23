#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include "callbacks.h"
#include "functions.h"
#include "global_variables.h"
#include "actions.h"


// Extern variable declarations.
extern int width, height;
extern float ex, ey, ez, px, py, pz, r1_x, r1_y, r1_z, delta_r1_x, delta_r1_z;
extern float r2_x, r2_y, r2_z, r3_x, r3_y, r3_z, r4_x, r4_y, r4_z;
extern int action;
extern int started;
extern int hit;
extern int miss;
extern int attempts;
extern int another;
extern char answer;


// Called on window reshape.
void reshape_callback(int w, int h)
{
	// Get window width and height
	width = w;
	height = h;

	// Set the viewport
	glViewport(0, 0, w, h);

	// Set the projection matrix
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70, (float)w/h, 1, 100);

	// Enter modelview
	glMatrixMode(GL_MODELVIEW);
}


//Draws the scene.
void display_callback(void)
{
	// Clear the color and depth buffers
	glClear(GL_DEPTH_BUFFER_BIT |
			GL_COLOR_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();

	// Set camera
	gluLookAt(	ex, ey, ez,
				px, py, pz,
				0, 1, 0);

	// Draw field and add texture to it
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, field_texutre);
	glPushMatrix();
		glTranslatef(0, -1, 35);
		glScalef(40, 0.07, 100);
		glBegin(GL_QUADS);
			glTexCoord2f(1, 1);
			glVertex3f(0.5, 0, -0.5);

			glTexCoord2f(1, 0 );
			glVertex3f(-0.5, 0, -0.5);

			glTexCoord2f(0, 0);
			glVertex3f(-0.5, 0, 0.5);

			glTexCoord2f(0, 1);
			glVertex3f(0.5, 0, 0.5);
		glEnd();
		//glutSolidCube(1);
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	// Draw quarterback 
	glPushMatrix();
		move_quarterback();
		glTranslatef(px, py, pz);
		glColor3f(0, 0, 0.6);
		glutSolidCube(0.5);
		glTranslatef(0, 0.5, 0);
		glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	//If ball is not alive(thrown) place it to quarterback, else move it to receiver that is thrown to
	if(!ball_alive)
	{
		ball_x = *ball_target_x - 0.4;
		ball_z = *ball_target_z;
	}
	else
	{
		move_ball();
	}

	//Draw ball
	glPushMatrix();
		glTranslatef(ball_x, ball_y, ball_z);
		glColor3f(0.4, 0.2, 0);
		glutSolidSphere(0.15, 50, 50);
	glPopMatrix();

	//If action has started move receivers along the routes
	if(started)
	{
		move_receivers();
	}
	// Draw receiver one
	glPushMatrix();
		glTranslatef(r1_x, r1_y, r1_z);
		glColor3f(0, 0, 0.6);
		glutSolidCube(0.5);
		glTranslatef(0, 0.5, 0);
		glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	// Draw receiver two
	glPushMatrix();
		glTranslatef(r2_x, r2_y, r2_z);
		glColor3f(0, 0, 0.6);
		glutSolidCube(0.5);
		glTranslatef(0, 0.5, 0);
		glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	// Draw receiver three
	glPushMatrix();
		glTranslatef(r3_x, r3_y, r3_z);
		glColor3f(0, 0, 0.6);
		glutSolidCube(0.5);
		glTranslatef(0, 0.5, 0);
		glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	// Draw receiver four
	glPushMatrix();
		glTranslatef(r4_x, r4_y, r4_z);
		glColor3f(0, 0, 0.6);
		glutSolidCube(0.5);
		glTranslatef(0, 0.5, 0);
		glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	// Draws selected action
	glPushMatrix();
		draw_selected_action();
	glPopMatrix();
	
	//Draw target square 1 and move it
	move_target_square(square_1, square_1_n);
	glPushMatrix();
		draw_target_square(square_1, square_1_n);
	glPopMatrix();

	//Draw target square 2 and move it
	move_target_square(square_2, square_2_n);
	glPushMatrix();
		draw_target_square(square_2, square_2_n);
	glPopMatrix();

	
	// Swap buffers
	glutSwapBuffers();

	//Checks if you failed the game or succeeded
	if((attempts == 5 && hit < 2) || (miss == 4 && (attempts == 4 || attempts == 5)))
	{
		printf("Failure :( .\nYour statistics: \nHits: %d\nMisses: %d\nAttempts: %d\nWould you like to play another game ? Press y for yes or n for no.\n", hit, miss, attempts);
		scanf(" %c", &answer);
		if(answer == 'y' || answer == 'Y')
		{
			attempts = 0;
			miss = 0;
			hit = 0;
		}
		else
			exit(0);
	}
	else if(attempts <= 5 && hit == 2)
	{
		printf("Success :) !!!\nYour statistics: \nHits: %d\nMisses: %d\nAttempts: %d\nWould you like to play another game ? Press y for yes or n for no. \n", hit, miss, attempts);
		scanf(" %c", &answer);
		if(answer == 'y' || answer == 'Y')
		{
			attempts = 0;
			miss = 0;
			hit = 0;
		}
		else
			exit(0);
	} 

}

// Description: Registering different key presses and taking actions accordingly
void keyboard_down_callback(unsigned char key, int x, int y)
{
	// Casting away unused variables.
	(void)(x), (void)(y);
	
	switch(key)
	{
		// Exit on escape key.
		case 27:
			printf("Hits: %d\nMisses: %d\nAttempts: %d", hit, miss, attempts);
			exit(0);
		//Action starts and receivers start to move
		case 's':
		case 'S':
			started = 1;
			break;
		//Reseting game
		case 'r':
		case 'R':
			started = 0;
			ball_alive = 0;

			r1_target_point = 1;
			r2_target_point = 1;
			r3_target_point = 1;
			r4_target_point = 1;

			r1_x = -15;
			r1_y = 0; 
			r1_z = 0;

			r2_x = -10;
			r2_y = 0; 
			r2_z = 0;

			r3_x = 10;
			r3_y = 0; 
			r3_z = 0;

			r4_x = 15;
			r4_y = 0; 
			r4_z = 0;

			ex = 0;
			ey = 10;
			ez = -15;
			px = py = pz =  0;
	
			ball_target_x = &px;
			ball_target_z = &pz;
			win_square = 0;

			break;

		//Throw ball to the receiver 1
		case 'l':
		case 'L':
			ball_x = px;	
			ball_z = pz;
			ball_target_x = &r1_x;
			ball_target_z = &r1_z;
			ball_alive = 1;
			break;
		//Throw ball to the receiver 2
		case 'k':
		case 'K':
			ball_x = px;	
			ball_z = pz;
			ball_target_x = &r2_x;
			ball_target_z = &r2_z;
			ball_alive = 1;
			break;
		//Throw ball to the receiver 3
		case 'j':
		case 'J':
			ball_x = px;	
			ball_z = pz;
			ball_target_x = &r3_x;
			ball_target_z = &r3_z;
			ball_alive = 1;
			break;
		//Throw ball to the receiver 4
		case 'h':
		case 'H':
			ball_x = px;	
			ball_z = pz;
			ball_target_x = &r4_x;
			ball_target_z = &r4_z;
			ball_alive = 1;
			break;
		//Call action 1
		case '1':
			if(!started)
			{
				action = 1;
			}
			break;
		//Call action 2
		case '2':
			if(!started)
			{
				action = 2;
			}
			break;
		//Call action 3
		case '3':
			if(!started)
			{
				action = 3;
			}
			break;
		//Call action 4
		case '4':
			if(!started)
			{
				action = 4;
			}
			break;
		//Call action 5
		case '5':
			if(!started)
			{
				action = 5;
			}
			break;
		//Call action 6
		case '6':
			if(!started)
			{
				action = 6;
			}
			break;
		//Call action 7
		case '7':
			if(!started)
			{
				action = 7;
			}
			break;
		//Call action 8
		case '8':
			if(!started)
			{
				action = 8;
			}
			break;
		//Call action 9
		case '9':
			if(!started)
			{
				action = 9;
			}
			break;
		//Call action 10
		case '0':
			if(!started)
			{
				action = 10;
			}
			break;
	

	}
}


//Description: Updating player deltas for movement.

void special_down_callback(int key, int x, int y)
{
	// Casting away unused variables.
	(void)(x), (void)(y);

	switch(key)
	{
		case GLUT_KEY_UP:
			delta_pz = 0.07;
			break;
		case GLUT_KEY_DOWN:
			delta_pz = -0.07;
			break;
		case GLUT_KEY_LEFT:
			delta_px = 0.07;
			break;
		case GLUT_KEY_RIGHT:
			delta_px = -0.07;
			break;
		
	}
}

//Description: Stoping player movement.
void special_up_callback(int key, int x, int y)
{
	// Casting away unused variables.
	(void)(x), (void)(y);

	switch(key)
	{
		case GLUT_KEY_UP:
		case GLUT_KEY_DOWN:
			delta_pz = 0;
			break;
		case GLUT_KEY_LEFT:
		case GLUT_KEY_RIGHT:
			delta_px = 0;
			break;
	}
}



//Description: Handle timers.
void timer_callback(int timer_id)
{
	// Refresh display
	if(REDISPLAY_TIMER == timer_id) {
		glutPostRedisplay();
		glutTimerFunc(REDISPLAY_INTERVAL, timer_callback, REDISPLAY_TIMER);
	}
}

