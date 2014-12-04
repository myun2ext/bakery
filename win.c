#include <windows.h>

WNDCLASSEX* bakery_window_class(WNDCLASSEX* wc, LPCSTR class_name, WNDPROC window_proc);

LRESULT CALLBACK bakery_default_window_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		default:
			break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

HWND bakery_create_window(const char* title, unsigned int width, unsigned int height)
{
	WNDCLASSEX wc;
	bakery_window_class(&wc, "BakeryDefaultWindowClass", bakery_default_window_proc);

	return CreateWindowEx(
	        WS_EX_APPWINDOW,
            "BakeryDefaultWindowClass",
	        title,
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            width, height,
            NULL,
            NULL,
            NULL,
            NULL);
}
