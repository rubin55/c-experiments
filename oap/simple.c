#include <GL/glut.h>

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glEnable(GL_LINE_STIPPLE);
  glLineWidth(2.0f);
  glLineStipple(3, 0xcccc);
  glBegin(GL_LINE_LOOP);
    glColor3d(0.1, 0.4, 0.7);
    glVertex2d(-0.5, -0.5);
    glColor3d(0.5, 0.1, 0.2);
    glVertex2d(-0.5, 0.5);
    glColor3d(0.2, 0.6, 0.3);
    glVertex2d(0.5, 0.5);
    glColor3d(0.4, 0.3, 0.5);
    glVertex2d(0.5, -0.5);
  glEnd();

  glFlush();
}

void init() {
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  glColor3d(1.0, 0.4, 0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 0);
  glutCreateWindow("simple");
  glutDisplayFunc(&display);
  init();
  glutMainLoop();
}
