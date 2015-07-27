////////////////////////////////////////////////////////////////////////////////////////////////////
// HandMade Hero (For Compilation in Visual Studio Community 2015)
////////////////////////////////////////////////////////////////////////////////////////////////////

/*
	Original Code by:	Casey Muratori
	Website:			https://handmadehero.org
	
	Tutorial ID:		Handmade Hero Day 002
	Tutorial Title:		Opening a Win32 Window
	
	Youtube Link:		https://www.youtube.com/watch?v=4ROiWonnWGk
	
	Source Files:		WinMain.cpp

	Modified by:		Mieleke
	Github:				https://github.com/mieleke
	
	About:				Many people have problems compiling the HandMade Hero Tutorials in 
						Visual Studio Community 2015, so im creating a repository to work with just that. 
						
						The source code is also extra commented to clarify what's happening.
						Personally I prefer the variable name conventions based on MSDN instead of the 
						altered ones Casey uses in the original examples.
						
						In addition, the formatting of the source code differences according to my own style.


	NOTE:				For questions about this please use PM on Github: https://github.com/mieleke, 
						and do not ask Casey Muratori questions about this source code, as he is busy 
						enough with this project.
*/

#include <windows.h>

/*
	WindowProc callback function - https://msdn.microsoft.com/en-us/library/windows/desktop/ms633573(v=vs.85).aspx
	
	An application-defined function that processes messages sent to a window.
	The WNDPROC type defines a pointer to this callback function.

	WindowProc is a placeholder for the application-defined function name.
	
	SYNTAX:			LRESULT CALLBACK WindowProc	(	_In_ HWND   hwnd,
													_In_ UINT   uMsg,
													_In_ WPARAM wParam,
													_In_ LPARAM lParam	);

	RETURN VALUE:	LRESULT

	The return value is the result of the message processing and depends on the message sent.
*/

LRESULT CALLBACK WindowProc (	HWND hwnd,									// Handle to window https://msdn.microsoft.com/en-us/library/Aa979055(v=VS.71).aspx
								UINT uMsg,									// System-Defined Messages https://msdn.microsoft.com/en-us/library/windows/desktop/ms644927(v=vs.85).aspx
																			// (we use WM category only) https://msdn.microsoft.com/en-us/library/windows/desktop/ff468921(v=vs.85).aspx
								WPARAM wParam,								// Additional message information - depends on the value of the uMsg
								LPARAM lParam)								// Additional message information - depends on the value of the uMsg
{
	LRESULT Result = 0;														// WindowProc Return Value
	switch (uMsg)															// <-- WindowProc.uMsg (System-Defined Messages)
	{																		// Catch all the Messages we want to and do something with it via Switch
		case WM_SIZE: {  } break;				
		case WM_DESTROY: {  } break;			
		case WM_CLOSE: {  } break;				
		case WM_ACTIVATEAPP: {  } break;		
		case WM_HELP: {  } break;				
		
		default:															// If its not in the above list then let Windows Handle all uncaught uMsg
		{										
		Result = DefWindowProc(hwnd, uMsg, wParam, lParam); 				// DefWindowProc function - MSDN: https://msdn.microsoft.com/en-us/library/windows/desktop/ms633572(v=vs.85).aspx
		} break;
	
	} 

	return(Result);
}

/*
	WinMain entry point - https://msdn.microsoft.com/en-us/library/windows/desktop/ms633559(v=vs.85).aspx

	The user-provided entry point for a graphical Windows-based application.
	WinMain is the conventional name used for the application entry point. 

	SYNTAX:			int CALLBACK WinMain	(	_In_ HINSTANCE hInstance,
												_In_ HINSTANCE hPrevInstance,
												_In_ LPSTR     lpCmdLine,
												_In_ int       nCmdShow	);

	RETURN VALUE:	int
	
	If the function succeeds, terminating when it receives a WM_QUIT message, 
	it should return the exit value contained in that message's wParam parameter.
	If the function terminates before entering the message loop, it should return zero.
*/

int CALLBACK WinMain
					(	
						HINSTANCE hInstance,									
						HINSTANCE hPrevInstance,								
						LPSTR lpCmdLine,										
						int nCmdShow
					)											
{															
/* 
	WNDCLASS structure - https://msdn.microsoft.com/en-us/library/windows/desktop/ms633576(v=vs.85).aspx
	
	Contains the window class attributes that are registered by the RegisterClass function.

	SYNTAX:		typedef struct tagWNDCLASS {
												UINT      style;
												WNDPROC   lpfnWndProc;
												int       cbClsExtra;
												int       cbWndExtra;
												HINSTANCE hInstance;
												HICON     hIcon;
												HCURSOR   hCursor;
												HBRUSH    hbrBackground;
												LPCTSTR   lpszMenuName;
												LPCTSTR   lpszClassName;
											} WNDCLASS, *PWNDCLASS;
*/
	WNDCLASS WindowClass = {};												// Create WindowClass From WNDCLASS
	WindowClass.style = CS_OWNDC|CS_HREDRAW|CS_VREDRAW;						// Window Class Styles https://msdn.microsoft.com/en-us/library/windows/desktop/ff729176(v=vs.85).aspx
	WindowClass.lpfnWndProc = WindowProc;									// WindowProc callback function https://msdn.microsoft.com/en-us/library/windows/desktop/ms633573(v=vs.85).aspx
	WindowClass.hInstance = hInstance;										// A handle to the instance that contains the window procedure for the class.
	WindowClass.lpszClassName = L"OurWindowClass";							// Class Name to pass ro RegisterClass

/*
	RegisterClass function - https://msdn.microsoft.com/en-us/library/windows/desktop/ms633586(v=vs.85).aspx

	Registers a window class for subsequent use in calls to the CreateWindow or CreateWindowEx function.

	SYNTAX:			ATOM WINAPI RegisterClass	(	_In_ const WNDCLASS *lpWndClass		);

	PARAMETERS:		lpWndClass [in]	
					Type: const WNDCLASS*
	
	A pointer to a WNDCLASS structure. 
	You must fill the structure with the appropriate class attributes before passing it to the function.

	RETURN VALUE:	ATOM
	
	If the function succeeds, the return value is a class atom that uniquely identifies the class being registered.

	This atom can only be used by the CreateWindow, CreateWindowEx, GetClassInfo, GetClassInfoEx, 
	FindWindow, FindWindowEx, and UnregisterClass functions and the IActiveIMMap::FilterClientWindows method.

	If the function fails, the return value is zero. To get extended error information, call GetLastError.
*/
	RegisterClass(&WindowClass);											// Register our WindowClass

/*
	CreateWindowEx function - https://msdn.microsoft.com/en-us/library/windows/desktop/ms632680(v=vs.85).aspx
	
	Creates an overlapped, pop-up, or child window with an extended window style; otherwise, 
	this function is identical to the CreateWindow function. 
	
	For more information about creating a window and for full descriptions of the other parameters of CreateWindowEx, see CreateWindow.

	SYNTAX:			HWND WINAPI CreateWindowEx	(	_In_     DWORD     dwExStyle,
													_In_opt_ LPCTSTR   lpClassName,
													_In_opt_ LPCTSTR   lpWindowName,
													_In_     DWORD     dwStyle,
													_In_     int       x,
													_In_     int       y,
													_In_     int       nWidth,
													_In_     int       nHeight,
													_In_opt_ HWND      hWndParent,
													_In_opt_ HMENU     hMenu,
													_In_opt_ HINSTANCE hInstance,
													_In_opt_ LPVOID    lpParam	);

	RETURN VALUE:	HWND
	
	If the function succeeds, the return value is a handle to the new window.
	If the function fails, the return value is NULL. To get extended error information, call GetLastError.
*/
	HWND WindowHandle = CreateWindowEx(										// Init WindowHandle
		0,																	// DWORD dwExStyle
		WindowClass.lpszClassName, L"ClassName",							// LPCTSTR lpClassName
		WS_OVERLAPPEDWINDOW|WS_VISIBLE,										// DWORD dwStyle
		CW_USEDEFAULT,														// int x
		CW_USEDEFAULT,														// int y
		CW_USEDEFAULT,														// int nWidth
		CW_USEDEFAULT,														// int nHeight
		0,																	// HWND hWndParent
		0,																	// HMENU hMenu
		hInstance,															// HINSTANCE hInstance
		0);																	// LPVOID lpParam)
	
/*
	GetMessage function

	Retrieves a message from the calling thread's message queue. The function dispatches incoming sent messages until a posted message is available for retrieval.
	Unlike GetMessage, the PeekMessage function does not wait for a message to be posted before returning.
	
	SYNTAX:			BOOL WINAPI GetMessage(		_Out_    LPMSG lpMsg,
												_In_opt_ HWND  hWnd,
												_In_     UINT  wMsgFilterMin,
												_In_     UINT  wMsgFilterMax	);

	RETURN VALUE:	BOOL

	If the function retrieves a message other than WM_QUIT, the return value is nonzero.
	If the function retrieves the WM_QUIT message, the return value is zero.
*/
		MSG Message;
		for (;;)
		{
			BOOL MessageResult = GetMessage(&Message, 0, 0, 0);
			if (MessageResult > 0)
			{
				//Handle it
			}
			else
			{
				break;
			}
			{

			}
		}
	return(0);

}
