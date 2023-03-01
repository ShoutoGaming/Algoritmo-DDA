#include<windows.h>
#include<math.h>
#include<iostream>
#include<GL/glut.h>

using namespace std;
void iniciarProyecion()
{
       glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-40,40,-40,40);
}

void dibujarLinea(GLint x0,GLint y0, GLint xf, GLint yf)
{

       glColor3f(0.0,1.0,0.0);
    glPointSize(1);

       for(float i=-39.5; i<40; i++)
    {

        glBegin(GL_LINES);
        glVertex3f(i,40,1);
        glVertex3f(i,-40,1);
        glVertex3f(40,i,1);
        glVertex3f(-40,i,1);
        glEnd();

    }
       glColor3f(0.0,0.0,1.0);

       glBegin(GL_LINES);
    glVertex2i(40,0);
    glVertex2i(-40,0);
    glVertex2i(0,40);
    glVertex2i(0,-40);
    glEnd();

      glBegin(GL_LINES);

    glEnd();

       glBegin(GL_LINES);
       glColor3f(0.0,0.0,0.0);
       glVertex2i(x0,y0);
    glVertex2i(xf,yf);
    glEnd();
}
/*---------------------------------------------PRIMERA SECCION ------------------------------------------------------------*/
void setPixel(GLint x, GLint y)
{
       glColor3f(1.0,0.0,0.0);
    glPointSize(8);
      glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
}


void dda(GLint x0,GLint y0, GLint xf, GLint yf)
{
    GLint i;
    float x,y,ax,ay,res;

        if(abs(xf-x0)>=abs(yf-y0))
    {
        res=abs(xf-x0);
    }
    else
    {
        res=abs(yf-y0);
    }

    
    ax=(xf-x0)/res;
    ay=(yf-y0)/res;

   
    i=0;

    x=(float)x0;
    y=(float)y0;

    
    while(i<=res)
    {

        setPixel(roundf(x),roundf(y));
        cout<<roundf(x)<<" , "<<roundf(y)<<endl;
        x=x+ax;
        y=y+ay;
        i++;
    }
}
/*---------------------------------------------SEGUNDA SECCION ------------------------------------------------------------*/
void draw(void)
{
   
    glClear(GL_COLOR_BUFFER_BIT);


    GLint
                                     x0=-10,
                                     y0=-5,
                                     xf=5,
                                     yf=35;

       dda(x0,y0,xf,yf);
    dibujarLinea(x0,y0,xf,yf);
    glFlush();

}

int main (int argc, char* argv[])
{
   
    glutInit(&argc,argv);
    
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   
    glutInitWindowSize(800,600);
    
    glutInitWindowPosition(300,100);

    
    glutCreateWindow("DDA line");

    iniciarProyecion();
    
    glutDisplayFunc(draw);
    
    glutMainLoop();

}
/*---------------------------------------------TERCERA SECCION ------------------------------------------------------------*/
