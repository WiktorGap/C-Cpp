#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(si));
    si.cb = sizeof(si);
    ZeroMemory(&pi, sizeof(pi));

    // Utworzenie procesu potomnego
    if (!CreateProcess(
            NULL,                   // Aplikacja do uruchomienia
            "cmd /c echo Proces potomny działa", // Komenda dla procesu potomnego
            NULL,                   // Atrybuty zabezpieczeń procesu
            NULL,                   // Atrybuty zabezpieczeń wątku
            FALSE,                  // Dziedziczenie uchwytów
            0,                      // Flagi tworzenia
            NULL,                   // Blok środowiskowy
            NULL,                   // Katalog początkowy
            &si,                    // Informacje o procesie startowym
            &pi                     // Informacje o procesie
        )) {
        fprintf(stderr, "Błąd podczas tworzenia procesu (%lu).\n", GetLastError());
        return 1;
    }

    printf("Proces potomny uruchomiony. PID: %lu\n", pi.dwProcessId);

    // Oczekiwanie na zakończenie procesu potomnego
    WaitForSingleObject(pi.hProcess, INFINITE);

    // Pobranie kodu zakończenia procesu potomnego
    DWORD exitCode;
    if (GetExitCodeProcess(pi.hProcess, &exitCode)) {
        printf("Proces potomny zakończył się. Kod wyjścia: %lu\n", exitCode);
    } else {
        fprintf(stderr, "Błąd podczas pobierania kodu wyjścia (%lu).\n", GetLastError());
    }

    // Zamknięcie uchwytów
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
