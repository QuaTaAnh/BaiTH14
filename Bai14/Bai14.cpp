// Bai14.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "Bai14.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
//Khai báo
INT_PTR CALLBACK    DangKyDialog(HWND, UINT, WPARAM, LPARAM);
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_BAI14, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_BAI14));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_BAI14));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_BAI14);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
        HWND hDlg;
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
             //Mở Header Files chọn resource.h xong ENTER
               //Láy id của menu
            case ID_FILE_DANGKY:
                hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DangKyDialog);
                ShowWindow(hDlg, SW_SHOW);
                break;
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
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
INT_PTR CALLBACK DangKyDialog(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam){
    static TCHAR maSV[10], hoten[30], ketqua[50], monhoc[50], khoa[50], KhoaHoc[50];
    static int indexKhoa, indexKhoaHoc, listCount;
    static int count = 0;
    switch (message)
    {
    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case btnThoat:
            if (MessageBox(NULL, TEXT("Bạn có muốn thoát không?"), TEXT("TB"), MB_YESNO | MB_ICONQUESTION) == IDYES)
            {
                EndDialog(hDlg, TRUE);
            }
            break;
        case btnLamLai:

            SetWindowText(GetDlgItem(hDlg, txtMaSV), TEXT("")); //lấy handle khi lấy id

            SetWindowText(GetDlgItem(hDlg, txtHoTen), TEXT(""));

            SendMessage(GetDlgItem(hDlg, chkTin), BM_SETCHECK, 0, 0);

            SendMessage(GetDlgItem(hDlg, chkGiaiTich), BM_SETCHECK, 0, 0);

            SendMessage(GetDlgItem(hDlg, chkTA), BM_SETCHECK, 0, 0);

            SendMessage(GetDlgItem(hDlg, chkTriet), BM_SETCHECK, 0, 0);

            SendMessage(GetDlgItem(hDlg, cboKhoa), CB_SETCURSEL, -1, 0);

            SendMessage(GetDlgItem(hDlg, cboKhoaHoc), CB_SETCURSEL, -1, 0);

            count = 0;
            break;
        
        case btnDangKy:

            wsprintf(ketqua, L"");

            wsprintf(monhoc, L"");

            if (GetWindowText(GetDlgItem(hDlg, txtMaSV), maSV, 9) != 8)

            {

                MessageBox(NULL, TEXT("Bạn phải nhập mã SV là chuỗi gồm 8 ký tự"), TEXT(""), MB_OK);

                SetFocus(GetDlgItem(hDlg, txtMaSV));

                return 0;

            }

            if (GetWindowText(GetDlgItem(hDlg, txtHoTen), hoten, 30) == 0)

            {

                MessageBox(NULL, TEXT("Bạn phải nhập họ tên SV"), TEXT(""), MB_OK);

                SetFocus(GetDlgItem(hDlg, txtHoTen));

                return 0;

            }

            indexKhoa = SendMessage(GetDlgItem(hDlg, cboKhoa), CB_GETCURSEL, 0, 0);

            if (indexKhoa < 0)

            {

                MessageBox(NULL, TEXT("Bạn phải chọn Khoa"), TEXT(""), MB_OK);



            }
            else {
                SendMessage(GetDlgItem(hDlg, cboKhoa), CB_GETLBTEXT, indexKhoa, (LPARAM)khoa);

            }

            indexKhoaHoc = SendMessage(GetDlgItem(hDlg, cboKhoaHoc), CB_GETCURSEL, 0, 0);

            if (indexKhoaHoc < 0)
            {
                MessageBox(NULL, TEXT("Bạn phải chọn Khóa học"), TEXT(""), MB_OK);
            }
            else {
                SendMessage(GetDlgItem(hDlg, cboKhoaHoc), CB_GETLBTEXT, indexKhoaHoc, (LPARAM)KhoaHoc);
            }
            if (SendMessage(GetDlgItem(hDlg, chkTin), BM_GETCHECK, 0, 0) == TRUE)
            {
                count++;
                wsprintfW(monhoc, L"%s;Tin học đại cương", monhoc);
            }
            if (SendMessage(GetDlgItem(hDlg, chkGiaiTich), BM_GETCHECK, 0, 0) == TRUE)
            {
                count++;
                wsprintfW(monhoc, L"%s;Giải tích F1", monhoc);
            }
            if (SendMessage(GetDlgItem(hDlg, chkTA), BM_GETCHECK, 0, 0) == TRUE)
            {
                count++;
                wsprintfW(monhoc, L"%s;Tiếng anh A1", monhoc);
            }
            if (SendMessage(GetDlgItem(hDlg, chkTriet), BM_GETCHECK, 0, 0) == TRUE)
            {
                count++;
                wsprintfW(monhoc, L"%s;Triết học F1", monhoc);

            }

            if (count < 2)

            {

                MessageBox(NULL, TEXT("Bạn phải đăng ký ít nhất hai môn"), TEXT("Hi"), MB_OK);

                return 0;

            }

            listCount = SendMessage(GetDlgItem(hDlg, lstDanhSach), LB_GETCOUNT, 0, 0);

            wsprintfW(ketqua, L"%d.%s|%s|%s|%s|%s", (listCount + 1), maSV, hoten, khoa, KhoaHoc, monhoc);

            SendMessage(GetDlgItem(hDlg, lstDanhSach), LB_INSERTSTRING, -1, (LPARAM)ketqua);
            break;
        case lstDanhSach:
            if (HIWORD(wParam) == LBN_SELCHANGE)
            {
                EnableWindow(GetDlgItem(hDlg, btnXoa), TRUE);
            }
            break;
        case btnXoa:
            int xoa = (int)SendMessage(GetDlgItem(hDlg, lstDanhSach), LB_GETCURSEL, 0, (LPARAM)ketqua);
            SendMessage(GetDlgItem(hDlg, lstDanhSach), LB_DELETESTRING, xoa, 0);
            break;
        }
    break;
    case WM_INITDIALOG:

        SendMessage(GetDlgItem(hDlg, cboKhoa), CB_INSERTSTRING, -1, (LPARAM)TEXT("Công nghệ thông tin"));

        SendMessage(GetDlgItem(hDlg, cboKhoa), CB_INSERTSTRING, -1, (LPARAM)TEXT("Công trình"));

        SendMessage(GetDlgItem(hDlg, cboKhoa), CB_INSERTSTRING, -1, (LPARAM)TEXT("Kinh tế vận tải"));

        SendMessage(GetDlgItem(hDlg, cboKhoaHoc), CB_INSERTSTRING, -1, (LPARAM)TEXT("55"));

        SendMessage(GetDlgItem(hDlg, cboKhoaHoc), CB_INSERTSTRING, -1, (LPARAM)TEXT("56"));

        SendMessage(GetDlgItem(hDlg, cboKhoaHoc), CB_INSERTSTRING, -1, (LPARAM)TEXT("57"));

        EnableWindow(GetDlgItem(hDlg, btnXoa), FALSE);

        count = 0;

        return (INT_PTR)TRUE;
        break;
    case WM_CLOSE:
        EndDialog(hDlg, TRUE);
        break;
    default:
        return FALSE;
    }
    return FALSE;
}
