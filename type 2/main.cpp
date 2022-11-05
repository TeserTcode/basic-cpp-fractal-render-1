/**************************
 * Includes
 *
 **************************/
#include <iostream>
#include <windows.h>
#include <gl/gl.h>
#include <math.h>
#include <fstream>
#include <string>


/**************************
 * Function Declarations
 *
 **************************/ 

int julia = 0;
long double jr=-1.0f;
long double ji=0.0f;
LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
WPARAM wParam, LPARAM lParam);
void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC);
void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC);

         int cac(long double r, long double i, long double b=0.0f, long double max=50.0f, long double temp=0.0f,int func=0,int julia=0,float jr = -1.0f,float ji=0.0f){
         	long double rr;
			long double ii;
		 if(julia == 1){
		 
		 	rr=jr;
			ii=ji;
		 }else{
		 	rr=r;
			ii=i;
		 }
		 switch(func){
		 
	     		case 1://mandelbrot
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i;  r+=rr;i+=ii;b += 1;}return (b); break;
	            case 2://perpendicular mandelbrot
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}i=-i;r=fabs(r);temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i;  r+=rr;i+=ii;b += 1;}return (b); break;
	            
	            case 3://burning ship
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}i=fabs(i);r=fabs(r);temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i;  r+=rr;i+=ii;b += 1;}return (b); break;
	            
	            case 4://perpendicular burning ship
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}i=fabs(i);temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i;  r+=rr;i+=ii;b += 1;}return (b); break;
	            
	            case 5://tricorn
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}i=-i;temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i;  r+=rr;i+=ii;b += 1;}return (b); break;
	            
	            case 6://perpendicular tricorn
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}r=fabs(r);temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i;  r+=rr;i+=ii;i=-i;temp = r;r=r*r-i*i;    i=2.0f*temp*i;       b += 1;}return (b); break;
	            
	            case 7://celtic
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i; r=fabs(r); r+=rr;i+=ii;b += 1;}return (b); break;
	            
	            case 8://perpendicular celtic
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i; r=fabs(r); i=-i; r+=rr;i+=ii;b += 1;}return (b); break;
	            
	            case 9://buffalo
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i; r=fabs(r); i=fabs(i); r+=rr;i+=ii;b += 1;}return (b); break;
	            
				case 10://perpendicular buffalo
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}i=fabs(i);temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i; r=fabs(r); r+=rr;i+=ii;b += 1;}return (b); break;
	            
	            case 11://inverse mandelbrot
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i;  temp = r; r=r/(r*r+i*i); i=i/(temp*temp+i*i);     r+=rr;i+=ii;b += 1;}return (b); break;
	            
	            case 12://s lambda
	     		 	for(int k=1;k > -10;k++){if(b > max or fabs(r)+fabs(i)>4.0f){k = -900;}temp = r;
	            r=r*r-i*i;    i=2.0f*temp*i; r=1-r;i=-i; temp = r; r=rr*r-i*ii;i=temp*ii+rr*i;    b += 1;}return (b); break;
	            
	            
	
	
}}
    void draw(float col,int maxa,int x,int y,int system){
    	
    	switch(system){
		case 1:
    		glBegin (GL_POINTS);
            if(col  >  0.9){
            glColor3f(0.0f,0.0f,0.0f);                     glVertex2f (x/360.0f, y/360.0f);
	      	}else{
            glColor3f (col/1.42, 0.0f, 0.0f);   glVertex2f (x/360.0f, y/360.0f);
            } break;
    	case 2:
    		glBegin (GL_POINTS);
            if(col  >  0.9){
            glColor3f(0.0f,0.0f,0.0f);                     glVertex2f (x/360.0f, y/360.0f);
	      	}else{
            glColor3f (0.0f, col/1.42f, 0.0f);   glVertex2f (x/360.0f, y/360.0f);
            } break;
        case 3:
    		glBegin (GL_POINTS);
            if(col  >  0.9){
            glColor3f(0.0f,0.0f,0.0f);                     glVertex2f (x/360.0f, y/360.0f);
	      	}else{
            glColor3f (0.0f, 0.0f, col/1.42f);   glVertex2f (x/360.0f, y/360.0f);
            } break;
        case 4:
    		glBegin (GL_POINTS);
            if(col  >  0.9){
            glColor3f(0.0f,0.0f,0.0f);                     glVertex2f (x/360.0f, y/360.0f);
	      	}else{
            glColor3f (col/1.42f, col/1.42f, 0.0f);   glVertex2f (x/360.0f, y/360.0f);
            } break;
        case 5:
    		glBegin (GL_POINTS);
            if(col  >  0.9){
            glColor3f(0.0f,0.0f,0.0f);                     glVertex2f (x/360.0f, y/360.0f);
	      	}else{
            glColor3f (0.0f, col/1.42f, col/1.42f);   glVertex2f (x/360.0f, y/360.0f);
            } break;
        case 6:
    		glBegin (GL_POINTS);
            if(col  >  0.9){
            glColor3f(0.0f,0.0f,0.0f);                     glVertex2f (x/360.0f, y/360.0f);
	      	}else{
            glColor3f (col/1.42f, 0.0f,col/1.42f);   glVertex2f (x/360.0f, y/360.0f);
            } break;
        case 7:
    		glBegin (GL_POINTS);
            if(col  >  0.9){
            glColor3f(0.0f,0.0f,0.0f);                     glVertex2f (x/360.0f, y/360.0f);
	      	}else{
            glColor3f (col/1.42f, col/1.42f, col/1.42f);   glVertex2f (x/360.0f, y/360.0f);
            } break;
        case 8:
    		glBegin (GL_POINTS);
            if(col  >  0.9){
            glColor3f(0.0f,0.0f,0.0f);                     glVertex2f (x/360.0f, y/360.0f);
	      	}else{
            glColor3f (sin(col), col/1.42f, col/1.42f);   glVertex2f (x/360.0f, y/360.0f);
            } break;
    	
    	
    	
    	
	}

}



/**************************
 * WinMain
 *
 **************************/

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int iCmdShow)
{

    WNDCLASS wc;
    HWND hWnd;
    HDC hDC;
    HGLRC hRC;        
    MSG msg;
    BOOL bQuit = FALSE;
    long double size =  500;
    long double zoom=64.0f;
    long double xoff=0.0f;
    long double yoff=0.0f;
    long double maxa=50.0f;
    unsigned int funky = 1;
    unsigned int drawsys = 1;
    
    /* register window class */
    wc.style = CS_OWNDC;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH) GetStockObject (BLACK_BRUSH);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = "GLSample";
    RegisterClass (&wc);

    /* create main window */
    hWnd = CreateWindow (
      "GLSample", "OpenGL Sample", 
      WS_CAPTION | WS_POPUPWINDOW | WS_VISIBLE,
      0, 0, size, size,
      NULL, NULL, hInstance, NULL);
      

    /* enable OpenGL for the window */
    EnableOpenGL (hWnd, &hDC, &hRC);
    
    


    /* program main loop */
    while (!bQuit)
    {
        /* check for messages */
        if (PeekMessage (&msg, NULL, 0, 0, PM_REMOVE))
        {
            /* handle or dispatch messages */
            if (msg.message == WM_QUIT)
            {
                bQuit = TRUE;
            }
            else
            {
                TranslateMessage (&msg);
                DispatchMessage (&msg);
            }
        }
        else
        {
            /* OpenGL animation code goes here */
              
              //julia stuff
              POINT p;
              if (GetCursorPos(&p) and GetKeyState('J') & 0x8000) 
{
   jr=p.x/125.0f-2.0f;
   ji=p.y/125.0f-2.0f;
}
              
              
              //
              
            glClearColor (0.0f, 0.0f, 0.0f, 0.0f);
            glClear (GL_COLOR_BUFFER_BIT);

            for(int i=-size;i<size;i++){
		    for(int j=-size;j<size;j++){
			
			
			
				
			
				float col = cac(i/zoom+xoff,j/zoom+yoff,0.0f,maxa,0.0f,funky,julia,jr,ji)/maxa;	
			
			    draw(col,maxa,i,j,drawsys);
            
            
            }
            }
            glEnd ();
            glPopMatrix ();

            SwapBuffers (hDC);
            if(GetKeyState('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             yoff += 8.0f/zoom;
            }
            if(GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             xoff -= 8.0f/zoom;
            }
            if(GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             yoff -= 8.0f/zoom;
            }
            if(GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             xoff += 8.0f/zoom;
            }
            if(GetKeyState('Z') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             zoom += zoom/16;
            }
            if(GetKeyState('X') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             zoom -= zoom/16;
            }
            if(GetKeyState('V') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             funky += 1;
             Sleep(100);
            }
            if(GetKeyState('B') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             funky -= 1;
             Sleep(100);
            }
             if(GetKeyState('N') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             drawsys += 1;
             Sleep(100);
            }
            if(GetKeyState('M') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             drawsys -= 1;
             Sleep(100);
            }
            if(GetKeyState('Q') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             maxa += 10;
            }
            
            if(GetKeyState('E') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
            	if(maxa != 10){
				
             maxa -= 10;
         }
            }
            if(GetKeyState('K') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
            {
             if(julia == 1){
             	julia = 0;
			 }else{
			 	julia = 1;
			 }
			 Sleep(100);
            }
            
            
        }
    }

    /* shutdown OpenGL */
    DisableOpenGL (hWnd, hDC, hRC);

    /* destroy the window explicitly */
    DestroyWindow (hWnd);

    return msg.wParam;
}


/********************
 * Window Procedure
 *
 ********************/

LRESULT CALLBACK WndProc (HWND hWnd, UINT message,
                          WPARAM wParam, LPARAM lParam)
{

    switch (message)
    {
    case WM_CREATE:
        return 0;
    case WM_CLOSE:
        PostQuitMessage (0);
        return 0;

    case WM_DESTROY:
        return 0;

    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_ESCAPE:
            PostQuitMessage(0);
            return 0;
        }
        return 0;

    default:
        return DefWindowProc (hWnd, message, wParam, lParam);
    }
}


/*******************
 * Enable OpenGL
 *
 *******************/

void EnableOpenGL (HWND hWnd, HDC *hDC, HGLRC *hRC)
{
    PIXELFORMATDESCRIPTOR pfd;
    int iFormat;

    /* get the device context (DC) */
    *hDC = GetDC (hWnd);

    /* set the pixel format for the DC */
    ZeroMemory (&pfd, sizeof (pfd));
    pfd.nSize = sizeof (pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | 
      PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 12;
    pfd.cDepthBits = 8;
    pfd.iLayerType = PFD_MAIN_PLANE;
    iFormat = ChoosePixelFormat (*hDC, &pfd);
    SetPixelFormat (*hDC, iFormat, &pfd);

    /* create and enable the render context (RC) */
    *hRC = wglCreateContext( *hDC );
    wglMakeCurrent( *hDC, *hRC );

}


/******************
 * Disable OpenGL
 *
 ******************/

void DisableOpenGL (HWND hWnd, HDC hDC, HGLRC hRC)
{
    wglMakeCurrent (NULL, NULL);
    wglDeleteContext (hRC);
    ReleaseDC (hWnd, hDC);
}
