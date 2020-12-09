#define GHACK_STATIC -10
#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4154)
#pragma warning(disable: 4265)
#pragma warning(disable: 4144)
#pragma warning(disable: 4311)
#pragma warning(disable: 4302)
#pragma warning(disable: 4313)
#include <Windows.h>
#include <iostream>
#include <GHackCore.h>
#include <string>
#include <algorithm>
#include <TlHelp32.h>
#include <stdio.h>
using namespace std;
void DriverController(int disable)
{
SC_HANDLE sc_manager = OpenSCManagerA(NULL, NULL, SC_MANAGER_ALL_ACCESS);
if (sc_manager != nullptr)
 
{
 
if (dissable == 1)
 
{
 
SC_HANDLE sc_service = OpenServiceA(sc_manager, "FairplayKD", SC_MANAGER_ALL_ACCESS);
 
if (sc_service != nullptr)
 
{
 
SERVICE_STATUS service_status;
 
ControlService(sc_service, SERVICE_CONTROL_STOP, &service_status);
 
BOOL service = DeleteService(sc_service); CloseServiceHandle(sc_service);
 
if (service) printf("Service succussfully deleted!\n");
 
else printf("Failed to stop service. Last Error: %d\n", GetLastError());
 
}