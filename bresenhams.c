#include <GL/glut.h> 
#include <math.h> 
int ww = 600, wh = 400; 
int first = 0; 
int xi, yi, xf, yf; 
void putPixel (int x, int y) 
{ 
   glBegin (GL_POINTS); 
   glVertex2i (x, y); 
   glEnd (); 
   glFlush ();
  } 
  
  void bresenhamAlg (int x0, int y0, int x1, int y1) 
  { 
  int dx = abs (x1 - x0); 
  int dy = abs (y1 - y0); 
  int x, y; 
  if (dx >= dy) 
  { 
   int d = 2*dy-dx; 
   int ds = 2*dy; 
   int dt = 2*(dy-dx); 
       if (x0 < x1)  
       { 
            x = x0; 
            y = y0; 
       } 
        else 
        {  
             x = x1; 
             y = y1; 
             x1 = x0; 
             y1 = y0; 
        } 
       putPixel (x, y); 
   while (x < x1) 
   { 
        if (d < 0) 
        d += ds; 
        else { 
             if (y < y1) { 
              y++; 
              d += dt; 
             }  
             else { 
              y--; 
              d += dt; 
             } 
            } 
   x++; 
        putPixel (x, y); 
       }  }
       else {  
             int d = 2*dx-dy; 
             int ds = 2*dx; 
             int dt = 2*(dx-dy); 
             if (y0 < y1) { 
             x = x0; 
             y = y0; 
             } 
             else {  
             x = x1; 
             y = y1; 
             y1 = y0; 
             x1 = x0; 
             } 
            putPixel (x, y);  
        while (y < y1) 
        { 
              if (d < 0) 
                 d += ds; 
              else { 
                      if (x > x1){ 
                      x--; 
                      d += dt; 
                 } else { 
                      x++; 
                      d += dt; 
                   } 
              } 
              y++; 
              putPixel (x, y); 
        } 
       } 
  } 
      
      void display() 
  { 
   glClearColor(0.0, 0.0, 0.0, 0.0); 
   glClear(GL_COLOR_BUFFER_BIT); 
   glFlush(); 
   glColor3f(1.0,0.0,0.0);
    bresenhamAlg(xi,yi,xf,yf);
  } 
  void myinit() 
  {       
     glViewport(0,0,ww,wh); 
     glMatrixMode(GL_PROJECTION); 
     glLoadIdentity(); 
     gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh); 
     glMatrixMode(GL_MODELVIEW); 
  } 

  int main(int argc, char** argv) 
  { 
    printf("Enter the points\n(X1,Y1,X2,Y2):-\n");
scanf("%d %d %d %d",&xi,&yi,&xf,&yf);

     glutInit(&argc,argv); 
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
     glutInitWindowSize(ww,wh); 
     glutCreateWindow("Bresenham Line Algorithm"); 
     glutDisplayFunc(display); 
     myinit(); 
    
     glutMainLoop(); 
     return 0; 
  } 