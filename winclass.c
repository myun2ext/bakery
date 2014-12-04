#include <windows.h>

WNDCLASSEX* bakery_window_class(WNDCLASSEX* wc, LPCSTR class_name, CALLBACK window_proc)
{
	wc->cbSize        = sizeof(wc);
	wc->style         = CS_HREDRAW | CS_VREDRAW;
	wc->lpfnWndProc   = window_proc;
	wc->cbClsExtra    = 0;
	wc->cbWndExtra    = 0;
	wc->hInstance     = NULL;
	wc->hIcon         = LoadIcon(NULL, IDI_APPLICATION);
	wc->hCursor       = LoadCursor(NULL, IDC_ARROW);
	wc->hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc->lpszMenuName  = NULL;
	wc->lpszClassName = class_name;
	wc->hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassEx(wc);
	return wc;
}
