#include <stdio.h>
#include <math.h>
#include "functions.h"
#include "actions.h"


// Extern variable declarations.
extern float ex, ey, ez, px, py, pz; 
extern float delta_px, delta_pz;
extern float r1_x, r1_z, r2_x, r2_z, r3_x, r3_z, r4_x, r4_z;
extern int started;
extern int action;
extern int r1_target_point;
extern int r2_target_point;
extern int r3_target_point;
extern int r4_target_point;
extern float speed;
extern float eps;
extern float ball_x, ball_z, *ball_target_x, *ball_target_z, ball_speed;
extern int ball_alive;
extern int hit;
extern int miss;
extern int attempts;


//Function that moves quarterback
void move_quarterback(void)
{	

	px += delta_px;
	pz += delta_pz;

	if(0 != delta_px)
	{
		int signum = (delta_px < 0) ? -1 : 1;
		ex -= signum * logf(signum * delta_px) / 50;
	}

	if(0 != delta_pz)
	{
		int signum = (delta_pz < 0) ? -1 : 1;
		ez -= signum * logf(signum * delta_pz) / 50;
	}
	
}

//Function that moves receiver along his route in action
void move_receiver(point action[], int* curr_target, float* x, float* z)
{
	float vx, vz;
	vx = action[*curr_target].x - *x;	
	vz = action[*curr_target].z - *z;	

	float alpha = speed/sqrt(pow(vx,2) + pow(vz,2));
	
	*x += alpha*vx;
	*z += alpha*vz;

	float distance = sqrt(pow(*x-action[*curr_target].x, 2) + pow(*z-action[*curr_target].z, 2));
	if(fabs(distance) < eps)
	{
		++(*curr_target);
	}

}

//Function that passes ball from quaterback to the receiver
void move_ball(void)
{
	float vx, vz;
	vx = *ball_target_x - ball_x;	
	vz = *ball_target_z - ball_z;	

	float alpha = ball_speed/sqrt(pow(vx,2) + pow(vz,2));
	
	ball_x += alpha*vx;
	ball_z += alpha*vz;

	float distance = sqrt(pow(ball_x - *ball_target_x, 2) + pow(ball_z - *ball_target_z, 2));
	if(fabs(distance) < eps)
	{
		ball_alive = 0;
		if(is_in_square(square_1, square_1_n))
		{
			win_square = 1;
			hit++;
			attempts++;
		}
		else if(is_in_square(square_2, square_2_n))
		{
			win_square = 1;
			hit++;
			attempts++;
		}
		else
		{
			win_square = -1;
			miss++;
			attempts++;
		}
	}
}

//Function that moves receivers along their routes
void move_receivers(void)
{
	switch(action)
	{	
		//Action 1
		case 1:
			if(r1_target_point < action1_r1_n)
			{
				move_receiver(action1_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action1_r2_n)
			{
				move_receiver(action1_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action1_r3_n)
			{
				move_receiver(action1_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action1_r4_n)
			{
				move_receiver(action1_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

		//Action 2
		case 2:
			if(r1_target_point < action2_r1_n)
			{
				move_receiver(action2_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action2_r2_n)
			{
				move_receiver(action2_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action2_r3_n)
			{
				move_receiver(action2_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action2_r4_n)
			{
				move_receiver(action2_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

		//Action 3
		case 3:
			if(r1_target_point < action3_r1_n)
			{
				move_receiver(action3_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action3_r2_n)
			{
				move_receiver(action3_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action3_r3_n)
			{
				move_receiver(action3_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action3_r4_n)
			{
				move_receiver(action3_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

		//Action 4
		case 4:
			if(r1_target_point < action4_r1_n)
			{
				move_receiver(action4_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action4_r2_n)
			{
				move_receiver(action4_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action4_r3_n)
			{
				move_receiver(action4_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action4_r4_n)
			{
				move_receiver(action4_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

		//Action 5
		case 5:
			if(r1_target_point < action5_r1_n)
			{
				move_receiver(action5_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action5_r2_n)
			{
				move_receiver(action5_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action5_r3_n)
			{
				move_receiver(action5_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action5_r4_n)
			{
				move_receiver(action5_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

		//Action 6
		case 6:
			if(r1_target_point < action6_r1_n)
			{
				move_receiver(action6_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action6_r2_n)
			{
				move_receiver(action6_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action6_r3_n)
			{
				move_receiver(action6_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action6_r4_n)
			{
				move_receiver(action6_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;
		
		//Action 7
		case 7:
			if(r1_target_point < action7_r1_n)
			{
				move_receiver(action7_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action7_r2_n)
			{
				move_receiver(action7_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action7_r3_n)
			{
				move_receiver(action7_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action7_r4_n)
			{
				move_receiver(action7_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

		//Action 8
		case 8:
			if(r1_target_point < action8_r1_n)
			{
				move_receiver(action8_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action8_r2_n)
			{
				move_receiver(action8_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action8_r3_n)
			{
				move_receiver(action8_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action8_r4_n)
			{
				move_receiver(action8_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

		//Action 9
		case 9:
			if(r1_target_point < action9_r1_n)
			{
				move_receiver(action9_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action9_r2_n)
			{
				move_receiver(action9_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action9_r3_n)
			{
				move_receiver(action9_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action9_r4_n)
			{
				move_receiver(action9_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

		//Action 10
		case 10:
			if(r1_target_point < action10_r1_n)
			{
				move_receiver(action10_r1, &r1_target_point, &r1_x, &r1_z);	
			}

			if(r2_target_point < action10_r2_n)
			{
				move_receiver(action10_r2, &r2_target_point, &r2_x, &r2_z);	
			}

			if(r3_target_point < action10_r3_n)
			{
				move_receiver(action10_r3, &r3_target_point, &r3_x, &r3_z);	
			}

			if(r4_target_point < action10_r4_n)
			{
				move_receiver(action10_r4, &r4_target_point, &r4_x, &r4_z);	
			}
			break;

	}

}

//Function that check if player that has ball is insied of targeted square based on his X and Z coordinates
int is_in_square(point square[], int n)
{
	(void)(n);
	float x1 = square[0].x;
	float x2 = square[1].x;
	float z1 = square[0].z;
	float z2 = square[3].z;

	return *ball_target_x <= x1 && *ball_target_x >= x2 && *ball_target_z>= z2 && *ball_target_z<= z1;
}

