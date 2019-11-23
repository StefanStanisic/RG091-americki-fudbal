#pragma once 

#include "actions.h"

// Helper functions
void move_quarterback(void);
void move_receivers(void);
void move_ball(void);
void move_receiver(point action[], int* curr_target, float* x, float* z);
int is_in_square(point square[], int n);
