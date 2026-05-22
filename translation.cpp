#include<GL/glut.h>

int X1=50, Y1=50, X2=150, Y2=50, X3=100, Y3=150;
int tx=-150, ty=80;

void drawTriangle(int ax, int ay, int bx, int by, int cx, int cy){
    glBegin(GL_LINE_LOOP);
        glVertex2i(ax,ay);
        glVertex2i(bx,by);
        glVertex2i(cx,cy);
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_LINES);
        glVertex2i(0, -240);
        glVertex2i(0, 240);
        glVertex2i(-320, 0);
        glVertex2i(320, 0);
    glEnd();


    //Original (white)
    glColor3f(1, 1, 1);
    drawTriangle(X1, Y1, X2, Y2, X3, Y3);

    //Translated (yellow): x' = x+tx, y' = y+ty
    int x1t = X1 + tx, y1t = Y1 + ty;
    int x2t = X2 + tx, y2t = Y2 + ty;
    int x3t = X3 + tx, y3t = Y3 + ty;

    glColor3f(1, 1, 0);
    drawTriangle(x1t, y1t, x2t, y2t, x3t, y3t);

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Translation");
    gluOrtho2D(-320, 320, -240, 240);
    glutDisplayFunc(display);
    glutMainLoop();
}