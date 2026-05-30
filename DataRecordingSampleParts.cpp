#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <direct.h>

void GetDriveSpace()
{
    _In_ LPCTSTR Drive = L"C:\\";
    ULARGE_INTEGER FreeBytesAvailableToCaller, TotalNumberOfBytes, TotalNumberOfFreeBytes;

    GetDiskFreeSpaceEx(Drive, &FreeBytesAvailableToCaller, &TotalNumberOfBytes, &TotalNumberOfFreeBytes);

    double TotalSpaceGB = (double)TotalNumberOfBytes.QuadPart / (1024.0 * 1024.0 * 1024.0);
    double FreeSpaceGB = (double)TotalNumberOfFreeBytes.QuadPart / (1024.0 * 1024.0 * 1024.0);
    double FreeSpaceAvailableGB = (double)FreeBytesAvailableToCaller.QuadPart / (1024.0 * 1024.0 * 1024.0);

    printf("Disk Information for drive %s:\n", Drive);
    printf("Total space: %.2f GB\n", TotalSpaceGB);
    printf("Free space: %.2f GB\n", FreeSpaceGB);
    printf("Free space available to caller: %.2f GB\n", FreeSpaceAvailableGB);
}

void MD5Zip()
{
    char Command[1000];
    const char* ZipPath = "C:\\Users\\Administrator\\source\\repos\\DataRecordingSampleParts\\DataRecordingSampleParts";

    if (_chdir(ZipPath) == 0) //path change
    {
        printf("Directory changed successfully.\n");
        sprintf(Command, "certutil -hashfile Notes.zip md5");
        system(Command);
    }
    else
    {
        perror("Error changing directory");
    }
}

void ZipFolder()
{
    char Command[1000];
    const char* FolderPath = "C:\\Users\\Administrator\\source\\repos\\DataRecordingSampleParts\\DataRecordingSampleParts\\Notes";
    const char* ZipPath = "C:\\Users\\Administrator\\source\\repos\\DataRecordingSampleParts\\DataRecordingSampleParts\\Notes.zip";

    sprintf(Command, "powershell Compress-Archive -Path \"%s\" -DestinationPath \"%s\"", FolderPath, ZipPath);
    system(Command);
    printf("File zipped successfully using PowerShell.\n");
}

void UnzipFolder()
{
    char Command[1000];
    const char* ZipPath = "C:\\Users\\Administrator\\source\\repos\\DataRecordingSampleParts\\DataRecordingSampleParts\\Notes.zip";
    const char* ExtractPath = "C:\\Users\\Administrator\\source\\repos\\DataRecordingSampleParts\\DataRecordingSampleParts";

    sprintf(Command, "powershell -command \"Expand-Archive -Path \\\"%s\\\" -DestinationPath \\\"%s\\\" -Force\"", ZipPath, ExtractPath);
    system(Command);
    printf("File unzipped successfully using PowerShell.\n");
}


int main()
{
    //GetDriveSpace();
    //MD5Zip();
    //ZipFolder();
    //UnzipFolder();
    
    return 0;
}
