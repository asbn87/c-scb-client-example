#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <winhttp.h>

#pragma comment(lib, "Winhttp.lib")

#define DEFAULT_BUFLEN 40960                                            // Default buflength of page, increase if you need.

char in_buf[DEFAULT_BUFLEN];                                            // In buf
char out_buf[DEFAULT_BUFLEN];                                           // Out buf

BOOL res;                                                               // Return result
HINTERNET
    hSession,                                                           // Session handler
    hConnect,                                                           // Connection handler
    hRequest;                                                           // Request handler

void winhttp_init();                                                    // Use WinHttpOpen to obtain a session handle.
void winhttp_connect(unsigned short* host);                             // Specify an HTTP server.
void winhttp_open_request(unsigned short* cmd, unsigned short* path);   // Create an HTTP request handle.
int winhttp_send_request();                                             // Send a request.
int winhttp_end_request();                                              // End the request.
int winhttp_read_data();                                                // Read data until end
void winhttp_print_data();                                              // Print in_buf
void report_error();                                                    // Report any errors.
void winhttp_close();                                                   // Close any open handles.
