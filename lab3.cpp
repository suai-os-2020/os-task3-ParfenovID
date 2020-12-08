#include "lab3.h"
#include <windows.h>
#include <iostream>

#define T_COUNT 11

DWORD ThreadID;
// идентификаторы потоков
HANDLE hThread[T_COUNT];
// мьютекс
HANDLE hold;
// семафоры
HANDLE semD, semE, semG, semSectionWait, semSectionContinue;

using namespace std;

unsigned int lab3_thread_graph_id()
{
    return 11;
}

const char *lab3_unsynchronized_threads()
{
    return "bcde";
}

const char *lab3_sequential_threads()
{
    return "deg";
}

DWORD WINAPI thread_a(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "a" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_b(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "b" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_c(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "c" << flush;
        ReleaseMutex(hold);
        computation();
    }

    ReleaseSemaphore(semSectionWait, 1, NULL);
    WaitForSingleObject(semSectionContinue, INFINITE);

    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "c" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_d(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "d" << flush;
        ReleaseMutex(hold);
        computation();
    }

    ReleaseSemaphore(semSectionWait, 1, NULL);
    WaitForSingleObject(semSectionContinue, INFINITE);

    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "d" << flush;
        ReleaseMutex(hold);
        computation();
    }

    ReleaseSemaphore(semSectionWait, 1, NULL);
    WaitForSingleObject(semSectionContinue, INFINITE);

    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "d" << flush;
        ReleaseMutex(hold);
        computation();
    }

    ReleaseSemaphore(semSectionWait, 1, NULL);
    WaitForSingleObject(semSectionContinue, INFINITE);

    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(semD, INFINITE);
        WaitForSingleObject(hold, INFINITE);
        cout << "d" << flush;
        ReleaseMutex(hold);
        computation();
        ReleaseSemaphore(semE, 1, NULL);
    }

    ReleaseSemaphore(semSectionWait, 1, NULL);
    WaitForSingleObject(semSectionContinue, INFINITE);

    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "d" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_e(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "e" << flush;
        ReleaseMutex(hold);
        computation();
    }

    ReleaseSemaphore(semSectionWait, 1, NULL);
    WaitForSingleObject(semSectionContinue, INFINITE);

    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "e" << flush;
        ReleaseMutex(hold);
        computation();
    }

    ReleaseSemaphore(semSectionWait, 1, NULL);
    WaitForSingleObject(semSectionContinue, INFINITE);

    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(semE, INFINITE);
        WaitForSingleObject(hold, INFINITE);
        cout << "e" << flush;
        ReleaseMutex(hold);
        computation();
        ReleaseSemaphore(semG, 1, NULL);
    }
    return 0;
}

DWORD WINAPI thread_f(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "f" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_g(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(semG, INFINITE);
        WaitForSingleObject(hold, INFINITE);
        cout << "g" << flush;
        ReleaseMutex(hold);
        computation();
        ReleaseSemaphore(semD, 1, NULL);
    }
    return 0;
}

DWORD WINAPI thread_h(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "h" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_i(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "i" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_k(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "k" << flush;
        ReleaseMutex(hold);
        computation();
    }

    ReleaseSemaphore(semSectionWait, 1, NULL);
    WaitForSingleObject(semSectionContinue, INFINITE);

    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "k" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_m(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < 3; ++i)
    {
        WaitForSingleObject(hold, INFINITE);
        cout << "m" << flush;
        ReleaseMutex(hold);
        computation();
    }
    return 0;
}

int lab3_init()
{
    // создание семафоров
    semD = CreateSemaphore(
            NULL,           // аттрибуты безопасности по умолчанию
            1,  // начальное значение счетчика
            1,  // максимальное значение счетчика
            NULL);          // безымянный семафор
    semE = CreateSemaphore(NULL, 0, 1, NULL);
    semG = CreateSemaphore(NULL, 0, 1, NULL);
    semSectionWait = CreateSemaphore(NULL, 0, 3, NULL);
    semSectionContinue = CreateSemaphore(NULL, 0, 3, NULL);

    // создание мьютекса
    hold = CreateMutex(NULL, FALSE, NULL);
    if (hold == NULL)
    {
        cerr << "Mutex init failed" << endl;
        return 1;
    }

/* 1 */
    // старт A, D
    hThread[0] = CreateThread(NULL, 0, thread_a, NULL, 0, &ThreadID);
    if (hThread[0] == NULL)
    {
        cerr << "Can't create thread A. Error: " << GetLastError() << endl;
        return 1;
    }
    hThread[3] = CreateThread(NULL, 0, thread_d, NULL, 0, &ThreadID);
    if (hThread[3] == NULL)
    {
        cerr << "Can't create thread d. Error: " << GetLastError() << endl;
        return 1;
    }
    // ожидание окончания потока А
    WaitForSingleObject(hThread[0], INFINITE);
    // ожидание завершения интервала D
    WaitForSingleObject(semSectionWait, INFINITE);

/* 2 */
    ReleaseSemaphore(semSectionContinue, 1, NULL);
    hThread[1] = CreateThread(NULL, 0, thread_b, NULL, 0, &ThreadID);
    if (hThread[1] == NULL)
    {
        cerr << "Can't create thread b. Error: " << GetLastError() << endl;
        return 1;
    }
    hThread[2] = CreateThread(NULL, 0, thread_c, NULL, 0, &ThreadID);
    if (hThread[2] == NULL)
    {
        cerr << "Can't create thread c. Error: " << GetLastError() << endl;
        return 1;
    }
    hThread[4] = CreateThread(NULL, 0, thread_e, NULL, 0, &ThreadID);
    if (hThread[4] == NULL)
    {
        cerr << "Can't create thread b. Error: " << GetLastError() << endl;
        return 1;
    }
    WaitForSingleObject(hThread[1], INFINITE);
    WaitForSingleObject(semSectionWait, INFINITE);
    WaitForSingleObject(semSectionWait, INFINITE);
    WaitForSingleObject(semSectionWait, INFINITE);

/* 3 */
    ReleaseSemaphore(semSectionContinue, 3, NULL);
    hThread[5] = CreateThread(NULL, 0, thread_f, NULL, 0, &ThreadID);
    if (hThread[5] == NULL)
    {
        cerr << "Can't create thread f. Error: " << GetLastError() << endl;
        return 1;
    }
    WaitForSingleObject(hThread[2], INFINITE);
    WaitForSingleObject(hThread[5], INFINITE);
    WaitForSingleObject(semSectionWait, INFINITE);
    WaitForSingleObject(semSectionWait, INFINITE);

/* 4 */
    hThread[6] = CreateThread(NULL, 0, thread_g, NULL, 0, &ThreadID);
    if (hThread[6] == NULL)
    {
        cerr << "Can't create thread g. Error: " << GetLastError() << endl;
        return 1;
    }
    ReleaseSemaphore(semSectionContinue, 2, NULL);
    WaitForSingleObject(semSectionWait, INFINITE);
    WaitForSingleObject(hThread[4], INFINITE);
    WaitForSingleObject(hThread[6], INFINITE);

/* 5 */
    ReleaseSemaphore(semSectionContinue, 1, NULL);
    hThread[7] = CreateThread(NULL, 0, thread_h, NULL, 0, &ThreadID);
    if (hThread[7] == NULL)
    {
        cerr << "Can't create thread h. Error: " << GetLastError() << endl;
        return 1;
    }
    hThread[8] = CreateThread(NULL, 0, thread_i, NULL, 0, &ThreadID);
    if (hThread[8] == NULL)
    {
        cerr << "Can't create thread i. Error: " << GetLastError() << endl;
        return 1;
    }
    hThread[10] = CreateThread(NULL, 0, thread_k, NULL, 0, &ThreadID);
    if (hThread[10] == NULL)
    {
        cerr << "Can't create thread k. Error: " << GetLastError() << endl;
        return 1;
    }
    WaitForSingleObject(hThread[3], INFINITE);
    WaitForSingleObject(hThread[7], INFINITE);
    WaitForSingleObject(hThread[8], INFINITE);
    WaitForSingleObject(semSectionWait, INFINITE);

/* 6 */
    ReleaseSemaphore(semSectionContinue, 1, NULL);
    hThread[9] = CreateThread(NULL, 0, thread_m, NULL, 0, &ThreadID);
    if (hThread[9] == NULL)
    {
        cerr << "Can't create thread m. Error: " << GetLastError() << endl;
        return 1;
    }
    WaitForSingleObject(hThread[9], INFINITE);
    WaitForSingleObject(hThread[10], INFINITE);

    // освобождение ресурсов
    for (int i = 0; i < T_COUNT; ++i)
        CloseHandle(hThread[i]);
    CloseHandle(hold);
    // close semaphores
    CloseHandle(semD);
    CloseHandle(semE);
    CloseHandle(semG);
    CloseHandle(semSectionWait);
    CloseHandle(semSectionContinue);
    cout << endl;
    return 0;
}
