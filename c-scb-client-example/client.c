#include "client.h"

void winhttp_init() {
    memset(&out_buf, 0, sizeof(out_buf));
    memset(&in_buf, 0, sizeof(in_buf));

    hSession = WinHttpOpen(
        L"WinHTTP Example/1.0",
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
        WINHTTP_NO_PROXY_NAME,
        WINHTTP_NO_PROXY_BYPASS, 0);
}

void winhttp_connect(unsigned short* host) {
    if (hSession) {
        hConnect = WinHttpConnect(
            hSession,
            host,
            INTERNET_DEFAULT_HTTPS_PORT, 0);
    }
}

void winhttp_open_request(unsigned short* cmd, unsigned short* path) {
    if (hConnect) {
        hRequest = WinHttpOpenRequest(
            hConnect,
            cmd,
            path,
            NULL,
            WINHTTP_NO_REFERER,
            WINHTTP_DEFAULT_ACCEPT_TYPES,
            WINHTTP_FLAG_SECURE);
    }
}

int winhttp_send_request() {
    if (hRequest) {
        res = WinHttpSendRequest(
            hRequest,
            WINHTTP_NO_ADDITIONAL_HEADERS, 0,
            out_buf, strlen(out_buf), 0, 0);
    }
    return res;
}

int winhttp_end_request() {
    if (res) {
        res = WinHttpReceiveResponse(hRequest, NULL);
    }
    return res;
}

int winhttp_read_data() {
    if (res) {
        res = WinHttpReadData(hRequest, in_buf, sizeof(in_buf), NULL);
    }
    return res;
}

void winhttp_print_data() {
    printf("%s", in_buf);
}

void report_error() {
    if (!res) {
        printf("Error %d has occurred.\n", GetLastError());
    }
}

void winhttp_close() { 
    if (hRequest) WinHttpCloseHandle(hRequest);
    if (hConnect) WinHttpCloseHandle(hConnect);
    if (hSession) WinHttpCloseHandle(hSession);
}