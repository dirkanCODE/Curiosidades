// By: dirkan (@dirkanSYN) -> https://twitter.com/dirkanSYN

#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;
float xmin=-2, xmax=1, ymin=-1, ymax=1;
int width=900,height=600;
int fzoom=4, nivel=1;
float xradio= (xmax-xmin)/fzoom;
float yradio= (ymax-ymin)/fzoom;
float iterac=500, fres=500, res=yradio/fres;

void init()
{
    glClearColor(0.0,0.0,0.0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport (0,0, width, height);
    gluOrtho2D(xmin,xmax,ymin,ymax);
}


void procesarRaton(int button, int state, int x, int y)
{
    float lxmin,lxmax,lymin,lymax;
    float posratonx,posratony;
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
        {
            xradio=xradio/fzoom;
            yradio=yradio/fzoom;
            nivel=nivel+1;
        }
        if (button == GLUT_RIGHT_BUTTON)
        {
            xradio=xradio*fzoom;
            yradio=yradio*fzoom;
            if (nivel > 1)
                nivel=nivel-1;
        }
        res=yradio/fres;
        posratonx=((xmax-xmin)*x/width)+xmin;
        posratony=-((ymax-ymin)*y/height)+ymax;
        lxmin=posratonx-xradio;
        lxmax=posratonx+xradio;
        lymin=posratony-yradio;
        lymax=posratony+yradio;
        xmin=lxmin;
        xmax=lxmax;
        ymin=lymin;
        ymax=lymax;
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        glViewport (0,0, width, height);
        gluOrtho2D(xmin,xmax,ymin,ymax);
        glutPostRedisplay();
    }
}

void Mandelbrot()
{

  float zx,zy,nzx,nzy;
  int iter = nivel*iterac;
  int color;
  bool dentro;

  glBegin(GL_POINTS);
    for (float x=xmin; x<=xmax; x=x+res)
    {
        for (float y=ymin; y<=ymax; y=y+res)
        {
            zx=0;
            zy=0;
            dentro=true;
            for (int i=0; i<=iter-1; i++)
            {
                nzx=zx*zx-zy*zy+x;
                nzy=2*zx*zy+y;
                zx=nzx;
                zy=nzy;
                if ((zx*zx+zy*zy) > 25.0)
                {
                    color=i;
                    dentro=false;
                    i=iter;
                }
            }
            if (dentro)
                glColor3f(0,0,0);
            else
                if (x<0)
                   glColor3f(0,color*y*y/15,color*(-x)/25);
                else
                   glColor3f(color*x/5,color*y*y/15,0);

            glVertex2f(x,y);
        }
        glFlush();
        glutSwapBuffers();
    }
  glEnd();
  glFlush();
  glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(width,height);
    glutCreateWindow("Conjunto de Mandelbrot");
    init();
    glutMouseFunc(procesarRaton);
    glutDisplayFunc(Mandelbrot);
    
    glutMainLoop();
    return 0;
}
