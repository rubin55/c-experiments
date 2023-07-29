#include <stdio.h>
#include <GL/glut.h>

void triangle (GLfloat *a, GLfloat *b, GLfloat *c) {
  glBegin(GL_TRIANGLES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
  glEnd();
}

void divide_triangle(GLfloat *a, GLfloat *b, GLfloat *c, int m) {
  GLfloat v[3][2];
  int j;
  if (m > 0) {
    for (j = 0; j < 2; j++) v[0][j] = (a[j] + b[j]) / 2;
    for (j = 0; j < 2; j++) v[1][j] = (a[j] + c[j]) / 2;
    for (j = 0; j < 2; j++) v[2][j] = (b[j] + c[j]) / 2;
    divide_triangle(a, v[0], v[1], m - 1);
    divide_triangle(c, v[1], v[2], m - 1);
    divide_triangle(b, v[2], v[0], m - 1);
  } else {
    triangle(a, b, c);
  }
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  GLfloat v[3][2] = {{-1.0f, -1.0f}, {0.0f, 1.0f}, {1.0f, -1.0f}};
  divide_triangle(v[0], v[1], v[2], 2);
  glFlush();
}

void init() {
  printf("Vendor:     %s\n", glGetString(GL_VENDOR));
  printf("Version:    %s\n", glGetString(GL_VERSION));
  printf("Renderer:   %s\n", glGetString(GL_RENDERER));
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
