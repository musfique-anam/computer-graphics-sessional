#include<GL/glut.h>

int X1=50, Y1=50, X2=150, Y2=50, X3=100, Y3=150;
float sx=1.5, sy=1.5;

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

    // Draw the original triangle
    glColor3f(1, 1, 1);
    drawTriangle(X1, Y1, X2, Y2, X3, Y3);

    // Draw the scaled triangle
    int x1s = X1 * sx, y1s = Y1 * sy;
    int x2s = X2 * sx, y2s = Y2 * sy;
    int x3s = X3 * sx, y3s = Y3 * sy;  

    glColor3f(1,1,0);
    drawTriangle(x1s, y1s, x2s, y2s, x3s, y3s);

    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Scaling");
    gluOrtho2D(-320, 320, -240, 240);
    glutDisplayFunc(display);
    glutMainLoop();
}