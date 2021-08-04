#include<GL/glut.h>
#include<math.h>
#include<stdio.h>   //definitions/declarations for standard I/O routines
#include<stdlib.h>   //declarations/definitions for commonly used library functions
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define H_SPIN 0.02
static GLfloat g_spin=H_SPIN;
unsigned int bg2;
GLfloat a = 0, b = 0, c = 0, d = 0, e = 0;
void helicopter(int xx,int yy);
int start=0;
float xx=100,yy=200;
GLfloat theta=0.0,theta1=0.0,theta2=0.0,theta3=0.0,flag1=0,flag2=0;
void obstruction(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4)
{
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();
}
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glBegin(GL_TRIANGLE_FAN);
	for (int i = 0; i < num_segments; i++)
	{
		float theta = 2.0f * 3.1415926f * (float)i / (float)(num_segments);//get the current angle 
		float x = r * cosf(theta);//calculate the x component 
		float y = r * sinf(theta);//calculate the y component 
		glVertex2f(x + cx, y + cy);//output vertex 
	}
	glEnd();
}
void drawSun(int x)
{	
	glColor3f(1.0, 0.5, 0.0);
	DrawCircle(800, 800, 70, 1000);	
}
void sky()
{
	glBegin(GL_POLYGON); //Sky  
	glColor3f(0.4, 0.5, 1.0);
	glVertex2i(0, 1500);
	glVertex2i(2000, 1500);
	glColor3f(0.7, 0.7, 1.0);
	glVertex2i(2000, 0);
	glVertex2i(0, 0);
	glEnd();
}
void road()
{
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON); //black road
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 100.0);
    glVertex2f(1000.0, 100.0);
    glVertex2f(1000.0, 0.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON); //white strips on roadglVertex2f(0.0,40.0);
    glVertex2f(8.0, 60.0);
    glVertex2f(58.0, 60.0);
    glVertex2f(50.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(100.0, 40.0);
    glVertex2f(108.0, 60.0);
    glVertex2f(158.0, 60.0);
    glVertex2f(150.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(200.0, 40.0);
    glVertex2f(208.0, 60.0);
    glVertex2f(258.0, 60.0);
    glVertex2f(250.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(300.0, 40.0);
    glVertex2f(308.0, 60.0);
    glVertex2f(358.0, 60.0);
    glVertex2f(350.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(400.0, 40.0);
    glVertex2f(408.0, 60.0);
    glVertex2f(458.0, 60.0);
    glVertex2f(450.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(500.0, 40.0);
    glVertex2f(508.0, 60.0);
    glVertex2f(558.0, 60.0);
    glVertex2f(550.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(600.0, 40.0);
    glVertex2f(608.0, 60.0);
    glVertex2f(658.0, 60.0);
    glVertex2f(650.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(700.0, 40.0);
    glVertex2f(708.0, 60.0);
    glVertex2f(758.0, 60.0);
    glVertex2f(750.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(800.0, 40.0);
    glVertex2f(808.0, 60.0);
    glVertex2f(858.0, 60.0);
    glVertex2f(850.0, 40.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glTranslated(b, 0.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(900.0, 40.0);
    glVertex2f(908.0, 60.0);
    glVertex2f(958.0, 60.0);
    glVertex2f(950.0, 40.0);
    glEnd();
    glPopMatrix();
}
void drawstring(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
	for(c=string;*c!='\0';c++)
 	{
  		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
    }
}
void drawstring1(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
	for(c=string;*c!='\0';c++)
	{
	  glutBitmapCharacter(GLUT_BITMAP_8_BY_13,*c);
	}
}
void drawstring2(float x,float y,float z,char *string)
{
	char *c;
	glRasterPos3f(x,y,z);
	for(c=string;*c!='\0';c++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,*c);
	}
}
//welcome screen here or front screen
void frontscreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
   
    
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg2);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 1000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(1000, 1000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(1000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
	glGenTextures(1, &bg2);
    glBindTexture(GL_TEXTURE_2D, bg2);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("intro1.jpeg", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        printf("Failed to load bg1");
    }
    stbi_image_free(data);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1000, 0, 1000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
	/*glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1,1,1,0);
	glBegin(GL_POLYGON);
			 
	glColor3f(1,0,0);
	glVertex2f(0,1000);
	glColor3f(0,1,0);
	glVertex2f(1000,1000);
	glColor3f(0,0,1);
	glVertex2f(1000,0);

	glColor3f(.5,.5,.5);
	glVertex2f(0,0);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	drawstring(400,900,0.0,"CGV MINI PROJECT");
	//drawstring(470,900,0.0,"MINI");
	//drawstring(550,900,0.0,"PROJECT");
	glColor3f(0.0,0.0,0.0);
	drawstring(340,850,0.0,"DEMONSTRATION OF HELICOPTER");
	//drawstring(270,410,0.0,"");
	//drawstring(350,410,0.0,"BOOTH]");
	glColor3f(0.0,0.0,0.0);
	drawstring1(300,700,0.0,"Presented by:");
	
	glColor3f(0.0,0.0,0.0);
	drawstring1(300,620,0.0,"Students Name                 USN");
	glColor3f(1.0,1.0,1.0);
	drawstring2(300,580,0.0,"SUMUKH P VASISTA        1BI18CS162");
	drawstring2(300,540,0.0,"SUMUK K                 1BI18CS161");
	glColor3f(0.0,0.0,0.0);
	drawstring1(270,480,0.0,"Under the Guidance of");
	glColor3f(1.0,1.0,1.0);
	drawstring2(280,440,0.0,"Dr. Girija J");
	drawstring2(280,400,0.0,"Prof N Thanuja");
	glColor3f(0.0,0.0,0.0);
	drawstring1(400,270,0.0,"Year 2020-21");
	glColor3f(0.0,0.0,0.0);
	drawstring1(200,230,0.0,"For instructions press: n");
	glFlush();
	glutSwapBuffers();*/
}
void instruction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	drawstring(460,850,0.0,"Instructions");
 	glColor3f(1.0,0.0,0.0);
	drawstring2(300,700,0.0,"s: Start");
	drawstring2(300,650,0.0,"m: move");
	drawstring2(300,600,0.0,"h: Speed increase");
	drawstring2(300,550,0.0,"l: speed decrease");
	drawstring2(300,500,0.0,"r: move right");
	drawstring2(300,450,0.0,"b: move left");
	drawstring2(300,400,0.0,"u: move up");
	drawstring2(300,350,0.0,"d: move down");
	drawstring2(300,300,0.0,"q: quit");
	drawstring2(300,250,0.0,"for next press: c");
	glFlush();
	//glutSwapBuffers();
}
void  mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
    sky();
    drawSun(1000);
    road();
    
	glClearColor(0.0,1.0,1.0,1.0);
	if(flag1==0)
	{
		frontscreen();
	}
	else
	{

	if(flag2==0)

		instruction();

	else
	{
	if(!start)
	{

		glColor3f(1.0,1.0,1.0);
		helicopter(xx,yy);

		glRasterPos2f(200, 200);


		glutIdleFunc(NULL);
	}

	else
	{


		glColor3f(1.0,1.0,1.0);
		helicopter(xx,yy);
		glutSwapBuffers();
	}
	glFlush();

	}
	}
	glutSwapBuffers();
}


void limit()
{

		if(theta<100)
		  theta+=50.0;
		else theta=0;

		if(theta1<100)
		 theta1+=50.0;
		else theta1=0;

		if(theta2<100)
		 theta2+=50.0;
		else theta2=0;

		if(theta3<100)
		 theta3+=50.0;
		else theta3=0;

		glutPostRedisplay();
}

void helicopter(int x,int y)

{
     GLfloat i,cosine,sine;
	GLint r=35,m=20;

	

	//head
	glColor3f(0.35,0.35,0.35);
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	{
		cosine=(x+100)+(r*cos(i));
        	sine=y+(r*sin(i));
		glVertex2f(cosine,sine);
	}
	glEnd();

	glColor3f(1.,1.,1.);
	glBegin(GL_POLYGON);
	glVertex2f(x,y+5);
	glVertex2f(x+75,y+20);
	glVertex2f(x+75,y-20);
	glVertex2f(x,y-5);
	glEnd();

	//black line (seperator)
	glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINES);
	glVertex2f(x+75,y-20);
	glVertex2f(x+75,y+20);
	glEnd();

	//door
	glColor3f(.3,.5,.8);
	glBegin(GL_POLYGON);
	glVertex2f(x+85,y-20);
	glVertex2f(x+85,y+5);
	glVertex2f(x+97,y+5);
	glVertex2f(x+97,y-20);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(x+105,y-20);
	glVertex2f(x+105,y);
	glVertex2f(x+115,y);
	glVertex2f(x+115,y-20);
	glEnd();

	//wing big
	glColor3f(.3,.5,.8);
	glPushMatrix();
	glTranslatef(x+90,y+30,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(-(x+90),-(y+30),0);

	//1
        glBegin(GL_POLYGON);
        glVertex2i(x+90,y+30);
	glVertex2i(x+80,y+100);
	glVertex2i(x+100,y+100);
	glEnd();
	glPopMatrix();

	glPushMatrix();

	glTranslatef(x+90,y+30,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta1,0.0,0.0,1.0);
	glTranslatef(-(x+90),-(y+30),0);

	//2
        glBegin(GL_POLYGON);
        glVertex2i(x+90,y+30);
	glVertex2i(x+80,y-20);
	glVertex2i(x+100,y-20);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x+90,y+30,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta2,0.0,0.0,1.0);
	glTranslatef(-(x+90),-(y+30),0);

	//3
        glBegin(GL_POLYGON);
        glVertex2i(x+90,y+30);
	glVertex2i(x+30,y-10);
	glVertex2i(x+30,y+10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x+90,y+30,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta3,0.0,0.0,1.0);
	glTranslatef(-(x+90),-(y+30),0);

	//4
        glBegin(GL_POLYGON);
    	glVertex2i(x+160,y+50);
	glVertex2i(x+90,y+30);
	glVertex2i(x+160,y+70);
	glEnd();
	glPopMatrix();

	//wing small
	glPushMatrix();
	glTranslatef(x,y+10,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(-(x),-(y+10),0);

	//a
        glBegin(GL_POLYGON);
        glVertex2i(x,y+10);
	glVertex2i(x,y+30);
	glVertex2i(x-10,y+30);
	glEnd();
	glPopMatrix();

        glPushMatrix();
	glTranslatef(x,y+10,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta1,0.0,0.0,1.0);
	glTranslatef(-(x),-(y+10),0);

	//b
        glBegin(GL_POLYGON);
        glVertex2i(x,y+10);
	glVertex2i(x,y-10);
	glVertex2i(x-10,y-10);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x,y+10,0);
	glRotatef(-60,0.0,0.0,1.0);
	glRotatef(theta2,0.0,0.0,1.0);
	glTranslatef(-(x),-(y+10),0);

	//c
        glBegin(GL_POLYGON);
        glVertex2i(x,y+10);
	glVertex2i(x+20,y+10);
	glVertex2i(x+20,y);
	glEnd();
	glPopMatrix();

	glBegin(GL_POINTS);
	for(i=0;i<360;i++)
	{

		cosine=(x)+(m*cos(i));
        		sine=(y+10)+(m*sin(i));
		glVertex2f(cosine,sine);


	}
	glEnd();


	glColor3f(1.0,1.0,0.0);
	//foot
            glBegin(GL_LINE_LOOP);
	    glVertex2i(x+80,y-45);
	    glVertex2i(x+80,y-40);
	    glVertex2i(x+120,y-40);
	    glVertex2i(x+125,y-45);
	    glEnd();

	//foot line
	glBegin(GL_LINES);
	glVertex2i(x+100,y-35);
	glVertex2i(x+90,y-40);
	glEnd();

	glBegin(GL_LINES);
	glVertex2i(x+100,y-35);
	glVertex2i(x+110,y-40);
	glEnd();

    //obstruction
    obstruction(500,500,520,500,520,600,500,600);//3
    obstruction(300,300,320,300,320,400,300,400);//2
    obstruction(800,500,820,500,820,600,800,600);//5
    obstruction(80,500,100,500,100,600,80,600);//back1
    obstruction(900,800,920,800,920,900,900,900);//6
	obstruction(650,125,670,125,670,225,650,225);//4
	obstruction(950,300,970,300,970,400,950,400);//7
}

void lastscreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,0.0,0.0,0.0);
	glRasterPos2f(460.0,850.0);
        char s[]="Game Over";
        int i;
        glColor3f(1.0,1.0,1.0);
        for(i=0;s[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
	glFlush();

	//exit(0);
}
void gameover()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,0.0,0.0,0.0);
	glRasterPos2f(460.0,850.0);
        char s[]="You Won";
        int i;
        glColor3f(1.0,1.0,1.0);
        for(i=0;s[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
	glFlush();	
}
void move()
{
if(xx>1000.0)
		glutIdleFunc(gameover);
if(xx<601.0)
{	//exit(0);
    if(xx>=365.0&&xx<=385.0&&yy>=500.0&&yy<=600.0)//500 3    //135 x diff  383.25
        glutIdleFunc(lastscreen);
	if(xx>=165.0&&xx<=185.0&&yy>=300.0&&yy<=400.0)//300 2 
		glutIdleFunc(lastscreen);
	
	if(xx>=515.0&&xx<=535.0&&yy>=125.0&&yy<=225.0)//650 4
		glutIdleFunc(lastscreen);
	
	if(yy>=400.0)
	{
        
	do{
		xx=xx+0.01;//0.03
	}
		while(xx==600.0);

   	}
    else
	{	
		xx=xx+0.01;

		yy=yy+0.03;
	}
	}
else{
	if(xx>=665.0&&xx<=685.0&&yy>=500.0&&yy<=600.0)//800 5
		glutIdleFunc(lastscreen);//exit(0);
	if(xx>=765.0&&xx<=785.0&&yy>=800.0&&yy<=900.0)//900 6
		glutIdleFunc(lastscreen);
	if(xx>=815.0&&xx<=835.0&&yy>=300.0&&yy<=400.0)//950 7
		glutIdleFunc(lastscreen);
	

		do
		{
			xx=xx+0.02;
			yy=yy-0.02;
		}
		while(yy<=200.0);

 }

	if(theta<100){	
		  theta+=50.0;}
		else {	
		theta=0;}

		if(theta1<100){ 
		 theta1+=50.0;}
		else theta1=0;

		if(theta2<100)
		 theta2+=50.0;
		else theta2=0;

		if(theta3<100)
		 theta3+=50.0;
		else theta3=0;
   	glutPostRedisplay();
}


void inc()
{
	if(xx<601.0)
	{
		if(yy>=400.0)
		{
			do{
				xx=xx+0.03+g_spin;
			}while(xx==600.0);
	   	}
		else
		{
			xx=xx+0.01+g_spin;
			yy=yy+0.03+g_spin;
		}
	}
	else{
			do
			{
				xx=xx+0.02+g_spin;
				yy=yy-0.02-g_spin;
			}while(yy<=200.0);
		}
	if(theta<100)
	  theta+=50.0;
	else theta=0;

	if(theta1<100)
	 theta1+=50.0;
	else theta1=0;

	if(theta2<100)
	 theta2+=50.0;
	else theta2=0;

	if(theta3<100)
	 theta3+=50.0;
	else theta3=0;
   	glutPostRedisplay();
}



void dec()
{

	if(xx<601.0)
	{	
		if(yy>=400.0)
		{
			do{
				xx=xx+0.08+g_spin;
			}while(xx==600.0);
   		}
		else
		{
			xx=xx+0.005+g_spin;
			yy=yy+0.01-g_spin;
		}
	}
	else{
			do
			{
				xx=xx+0.01+g_spin;
				yy=yy+0.01-g_spin;
			}while(yy<=200.0);
		}

	if(theta<100)
		theta+=50.0;
	else theta=0;

	if(theta1<100)
		theta1+=50.0;
	else theta1=0;

	if(theta2<100)
	 theta2+=50.0;
	else theta2=0;

	if(theta3<100)
	 theta3+=50.0;
	else theta3=0;
	glutPostRedisplay();
}

void mykeyboard(unsigned char key, int x, int y)
{
   switch(key)
   {
		case 115:
				start=1;
		 		glutIdleFunc(limit);
				break;
		case 109:
			glutIdleFunc(move);
			break;
		case 113:
				exit(0);
				break;
		case 104:
			glutIdleFunc(inc);
				g_spin+=H_SPIN;
				break;
		case 108:
				glutIdleFunc(dec);
					g_spin-=H_SPIN;
						break;
		case 114:
				if(xx>=1000)
					xx=0;
				xx=xx+1;
				break;
        case 98:
				xx=xx-1;
				break;
		case 100:	yy=yy-1;
                    break;
        case 117:
		   		yy=yy+1;
				glutPostRedisplay();
				break;
		case 110:
			 flag1=1;
			 break;
		case 99:
			 flag2=1;
			 break;
   }
}
void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutCreateWindow("THE HELICOPTER");
	glutDisplayFunc(mydisplay);
	glutIdleFunc(limit);
	glutKeyboardFunc(mykeyboard);
	init();
	glutMainLoop();
}