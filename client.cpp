#include <iostream>
#include <WS2tcpip.h>
#include <string>

#pragma comment (lib, "ws2_32.lib")
using namespace std;
int main()
{
	string ipAddress = "192.168.1.101";			// IP Address of the server
	int port = 5600;
//WSAstartup
	WSADATA wsadata;
	DWORD version = MAKEWORD(2, 2);
	WSAStartup(version, &wsadata);
//socket
	SOCKET socket1;
	socket1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//sockaddr_in
	sockaddr_in ip;
	ip.sin_family = AF_INET;
	ip.sin_port = htons(port);
	inet_pton(AF_INET, ipAddress.c_str(), &ip.sin_addr);
//connect
	int ketnoi;
	ketnoi = connect(socket1, (sockaddr*)&ip, sizeof(ip));
	if (ketnoi == SOCKET_ERROR)
		cout << "ket noi fail" << WSAGetLastError() << endl;
	else
		cout << "ket noi thanh cong" << endl;
	//do-while
	char guidi[4096];
	string nhapvo;
	do
	{
		ZeroMemory(guidi, 4096);
	//nhan tin tu server truoc
		int nhantin1 = recv(socket1,guidi, 4096, 0);
		if (nhantin1 != SOCKET_ERROR)
			cout << string(guidi, 0, nhantin1) << endl;
		else
			cout << "nhan that bai" << endl;
	//gui tin nhan
		cout << "client nhap>>";
		getline(cin, nhapvo);
		int guitinnhan = send(socket1,nhapvo.c_str(),nhapvo.size() + 1, 0);
		
			

	} while (nhapvo.size()> 0);
	system("pause");
	return 0;
}
