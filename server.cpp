#include <iostream>
#include <WS2tcpip.h>
#include <string>

#pragma comment (lib, "ws2_32.lib")
using namespace std;
int main()
{
	//tao winsock
	WSADATA wsaserver;
	DWORD version = MAKEWORD(2, 2);
	WSAStartup(version, &wsaserver);
	// tao socket
	SOCKET  socket1;
	socket1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	//khai bao cau truc sockaddr_in
	sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(5600);
	server.sin_addr.S_un.S_addr = INADDR_ANY;
	//bind
	int bind1;
	bind1 = bind(socket1, (sockaddr*)&server, sizeof(server));
	//listen
	listen(socket1, 3);
	//accept
	sockaddr_in client;
	SOCKET server2;
	int kichco = sizeof(sockaddr_in);
	server2 = accept(socket1, (sockaddr*)&client,&kichco);
	// While loop: accept and echo message back to client
	string guidi;
	char nhanduoc[4096];
	while (true)
	{
		cout << "server nhap>>";
		getline(cin, guidi);
		ZeroMemory(nhanduoc, 4096);
		int guitinnhan;
		guitinnhan = send(server2,guidi.c_str(), 4096, 0);
		if (guitinnhan == SOCKET_ERROR)
			cout << "gui tin that bai" << endl;
		else
			cout << "gui tin thanh cong" << endl;
		int nhantinnhan;
		nhantinnhan = recv(server2, nhanduoc, 4096, 0);
		if (nhantinnhan == SOCKET_ERROR)
			cout << "nhan tin nhan fail" << endl;
		else
		{
			cout << "nhan tin nhan thanh cong" << endl;
			cout <<"--->"<< string(nhanduoc, 0, nhantinnhan) << endl;

		}
	}
	return 0;









}
