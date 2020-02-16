// CovScript Launcher.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "CovScript Launcher.h"
#include <string>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    char buffer[MAX_PATH];
    ZeroMemory(buffer, sizeof(buffer));
    if (!GetCurrentDirectoryA(MAX_PATH, buffer))
        return -1;
    std::string current_path = buffer;
    std::string bin_path = "\"" + current_path + "\\bin\\cs.exe\"";
    std::string import_path = "\"" + current_path + "\\imports\"";
    std::string command = bin_path + " -i " + import_path + " -l \"" + current_path + "\\launcher.log\" \"" + current_path + "\\main.csc\"";
    STARTUPINFOA si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);
    si.dwFlags |= STARTF_USESTDHANDLES;
    if (!CreateProcessA(nullptr, const_cast<char*>(command.c_str()), nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi))
    {
        MessageBoxA(nullptr, "Launch Interpreter Failed.", "CovScript Launcher", MB_OK | MB_ICONERROR);
        return -1;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD ec;
    if (!GetExitCodeProcess(pi.hProcess, &ec))
    {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return -1;
    }
    else {
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return ec;
    }
}
