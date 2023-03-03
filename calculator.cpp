#include <windows.h>
#include <stdio.h>

HWND text ,plus,minus,mul,divide,TextBox1,TextBox2;
char TextSave1[20],TextSave2[20];

/* This is where all the input to the window goes to */
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		
		case WM_CREATE:
			text = CreateWindow("STATIC","Please input two numbers",WS_VISIBLE|WS_CHILD|WS_BORDER,20,20,200,20,hwnd,NULL,NULL,NULL);
			plus = CreateWindow ("BUTTON","+",WS_VISIBLE | WS_CHILD | WS_BORDER,60,120,20,20,hwnd,(HMENU) 1,NULL,NULL);
			minus = CreateWindow ("BUTTON","-",WS_VISIBLE | WS_CHILD | WS_BORDER,90,120,20,20,hwnd,(HMENU) 2,NULL,NULL);
			mul = CreateWindow ("BUTTON","*",WS_VISIBLE | WS_CHILD | WS_BORDER,120,120,20,20,hwnd,(HMENU) 3,NULL,NULL);
			divide = CreateWindow ("BUTTON","/",WS_VISIBLE | WS_CHILD | WS_BORDER,150,120,20,20,hwnd,(HMENU) 4,NULL,NULL);
			TextBox1 = CreateWindow("EDIT","",WS_VISIBLE | WS_CHILD | WS_BORDER,45,50,150,20,hwnd,NULL,NULL,NULL);
			TextBox2 = CreateWindow("EDIT","",WS_VISIBLE | WS_CHILD | WS_BORDER,45,80,150,20,hwnd,NULL,NULL,NULL);
			
			break;
		case WM_COMMAND:
			if(LOWORD(wParam)==1){
				int getstat1 = 0,getstat2 = 0;
				getstat1 = GetWindowText(TextBox1,&TextSave1[0],20);
				getstat2 = GetWindowText(TextBox2,&TextSave2[0],20);
				float result=atof(TextSave1)+atof(TextSave2);
				char t[100];
				sprintf(t, "%f", result);
				:: MessageBox (hwnd,t,"result",MB_OK);
			}
			if(LOWORD(wParam)==2){
				int getstat1 = 0,getstat2 = 0;
				getstat1 = GetWindowText(TextBox1,&TextSave1[0],20);
				getstat2 = GetWindowText(TextBox2,&TextSave2[0],20);
				float result=atof(TextSave1)-atof(TextSave2);
				char t[100];
				sprintf(t, "%f", result);
				:: MessageBox (hwnd,t,"result",MB_OK);
			}
			if(LOWORD(wParam)==3){
				int getstat1 = 0,getstat2 = 0;
				getstat1 = GetWindowText(TextBox1,&TextSave1[0],20);
				getstat2 = GetWindowText(TextBox2,&TextSave2[0],20);
				float result=atof(TextSave1)*atof(TextSave2);
				char t[100];
				sprintf(t, "%f", result);
				:: MessageBox (hwnd,t,"result",MB_OK);
			}
			if(LOWORD(wParam)==4){
				int getstat1 = 0,getstat2 = 0;
				getstat1 = GetWindowText(TextBox1,&TextSave1[0],20);
				getstat2 = GetWindowText(TextBox2,&TextSave2[0],20);
				float result=atof(TextSave1)/atof(TextSave2);
				char t[100];
				sprintf(t, "%f", result);
				:: MessageBox (hwnd,t,"result",MB_OK);
			}
			
		
			
		
		
			break;	
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		
		/* All other messages (a lot of them) are processed using default procedures */
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc; /* A properties struct of our window */
	HWND hwnd; /* A 'HANDLE', hence the H, or a pointer to our window */
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc,0,sizeof(wc));
	wc.cbSize	 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* This is where we will send messages to */
	wc.hInstance	 = hInstance;
	wc.hCursor	 = LoadCursor(NULL, IDC_ARROW);
	
	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+9);
	wc.lpszClassName = "WindowClass";
	wc.hIcon	 = LoadIcon(NULL, IDI_APPLICATION); /* Load a standard icon */
	wc.hIconSm	 = LoadIcon(NULL, IDI_APPLICATION); /* use the name "A" to use the project icon */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,"WindowClass","My Calculator",WS_VISIBLE|WS_SYSMENU,
		500, /* x */
		300, /* y */
		250, /* width */
		200, /* height */
		NULL,NULL,hInstance,NULL);

	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	/*
		This is the heart of our program where all input is processed and 
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	while(GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}
	return msg.wParam;
}
