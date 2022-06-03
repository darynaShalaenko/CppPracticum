// ������ � ������� �볺�����
#include <iostream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void main()
{

	// I����������� WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsOK = WSAStartup(ver, &data);
	if (wsOK != 0)
	{
		cerr << "Can't initialize winsock! Quitting" << endl;
		return;
	}

	// ��������� �����
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Can't create socket! Quitting" << endl;

		return;
	}

	// �'������ IP ������ �� ���� �� ������
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // ����� ����������� ����� inet_pton

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// ���������, �� ����� ����������� ��� ��������������� 
	listen(listening, SOMAXCONN);

	fd_set master;

	FD_ZERO(&master);

	FD_SET(listening, &master);

	while (true) 
	{

		fd_set copy = master;

		int socketCount = select(0, &copy, nullptr, nullptr, nullptr);

		for (int i = 0; i < socketCount; i++)
		{
			SOCKET sock = copy.fd_array[i];
			if (sock == listening)
			{
				// �������� ���� ����������...
				SOCKET client = accept(listening, nullptr, nullptr);

				// ������ ���� ���������� �� ������ ���������� �볺���
				FD_SET(client, &master);

				// ��������� ����������� ����������� �볺���...
				string welcomeMsg = "Welcome to the Awesome Chat Server!";
				send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
	
			}
			else
			{
				char buf[4096];
				ZeroMemory(buf, 4096);

				// �������� �����������
				int bytesIn = recv(sock, buf, 4096, 0);
				if(bytesIn <=0)
				{
					// ��������� �볺���
					closesocket(sock);
					FD_CLR(sock, &master);

				}
				else
				{
					// ��������� ����������� ����� �볺����, ��� �� � ����� ��� ���������������

					for (int i = 0; i < master.fd_count; i++)
					{
						SOCKET outSock = master.fd_array[i];
						if (outSock != listening && outSock != sock)
						{
							send(outSock, buf, bytesIn, 0);
						}
					}
				}
				
				
			}
		}
	}
	

	// ������� winsock
	WSACleanup();
}
	
	
