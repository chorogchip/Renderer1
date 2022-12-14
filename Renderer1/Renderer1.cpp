// Renderer1.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//


#include "framework.h"
#include "Renderer1.h"
#include "RenderingPipeline.h"

#define MAX_LOADSTRING 100

HINSTANCE hInst; 
WCHAR szTitle[MAX_LOADSTRING]; 
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int, HWND *);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

RenderingPipeline rendering_pipeline{};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine, _In_ int       nCmdShow) {

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_RENDERER1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    HWND window;
    if (!InitInstance(hInstance, nCmdShow, &window))
        return FALSE;


    if (!rendering_pipeline.init(window)) return FALSE;

    {
        RECT ClientRect;
        GetClientRect(window, &ClientRect);
        auto client_width = ClientRect.right - ClientRect.left;
        auto client_height = ClientRect.bottom - ClientRect.top;
        rendering_pipeline.update_w_h(client_width, client_height);
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_RENDERER1));
    MSG msg;
    while (GetMessage(&msg, nullptr, 0, 0)) {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        rendering_pipeline.draw();
    }

    return (int) msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_RENDERER1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_RENDERER1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, HWND *window)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
                             CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
   if (!hWnd)
      return FALSE;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   *window = hWnd;
   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam) 
        { 
        case VK_LEFT:
            rendering_pipeline.y_rot += 0.1f;
            rendering_pipeline.draw();
            break;
        case VK_RIGHT:
            rendering_pipeline.y_rot -= 0.1f;
            rendering_pipeline.draw();
            break;
        case VK_UP:
            rendering_pipeline.x_rot += 0.1f;
            rendering_pipeline.draw();
            break;
        case VK_DOWN:
            rendering_pipeline.x_rot -= 0.1f;
            rendering_pipeline.draw();
            break;
        case VK_HOME:
            break;
        case VK_END: 
            break;
        case VK_INSERT: 
            break;
        case VK_DELETE: 
            break;
        case VK_F2: 
            break;
        } 
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);

    case WM_SIZING:
        {
            RECT ClientRect;
            GetClientRect(hWnd, &ClientRect);
            auto client_width = ClientRect.right - ClientRect.left;
            auto client_height = ClientRect.bottom - ClientRect.top;
            rendering_pipeline.update_w_h(client_width, client_height);
        }
        break;
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    UNREFERENCED_PARAMETER(lParam);
    switch (message) {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
