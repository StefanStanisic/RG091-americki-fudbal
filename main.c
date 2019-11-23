#include <stdlib.h>
#include <GL/glut.h>
#include "callbacks.h"
#include "image.h"


//Variable for field texture
unsigned field_texutre = -1;

//Variables for lighting and material
float light_position[4] = {10, 0, 10, 0};
float material_ambient[4] = {1, 1, 1, 1};
float material_diffuse[4] = {0.7, 0.7, 0.7, 1};
float material_specular[4] = {0.3, 0.3, 0.3, 1};
float shininess = 10;

int main(int argc, char **argv)
{
	// Initialize OpenGL
	glutInit(&argc, argv);

	// Initialize window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(1024, 768);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0] + 2);

	// Setting up OpenGL
	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	//Seting up texture parameters
    Image * image;
	glEnable(GL_TEXTURE_2D);

    glTexEnvf(GL_TEXTURE_ENV,
              GL_TEXTURE_ENV_MODE,
              GL_REPLACE);
    image = image_init(0, 0);
    image_read(image, "teren5.bmp");

	glGenTextures(1, &field_texutre);

	glBindTexture(GL_TEXTURE_2D, field_texutre);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,
                    GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,
                 image->width, image->height, 0,
                 GL_RGB, GL_UNSIGNED_BYTE, image->pixels);
    image_done(image);
    glDisable(GL_TEXTURE_2D);


	// Display callbacks
	glutReshapeFunc(reshape_callback);
	glutDisplayFunc(display_callback);

	// Keyboard callbacks
	glutKeyboardFunc(keyboard_down_callback);
	glutSpecialFunc(special_down_callback);
	glutSpecialUpFunc(special_up_callback);

	// Timer callbacks
	glutTimerFunc(REDISPLAY_INTERVAL, timer_callback, REDISPLAY_TIMER);


	//Enabling lighting
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_COLOR_MATERIAL);


	//Lighting functions
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glLightfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glLightfv(GL_FRONT, GL_SPECULAR, material_specular);
	glLightf(GL_FRONT, GL_SHININESS, shininess);

	//Material functions
	glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, shininess);

	// Start main loop
	glutMainLoop();

	return 0;
}
