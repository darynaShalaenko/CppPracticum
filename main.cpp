// Сервер з кількома клієнтами
#include <iostream>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

using namespace std;

void main()
{

	// Iніціалізовуємо WinSock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsOK = WSAStartup(ver, &data);
	if (wsOK != 0)
	{
		cerr << "Can't initialize winsock! Quitting" << endl;
		return;
	}

	// Створюємо сокет
	SOCKET listening = socket(AF_INET, SOCK_STREAM, 0);
	if (listening == INVALID_SOCKET)
	{
		cerr << "Can't create socket! Quitting" << endl;

		return;
	}

	// З'єднуємо IP адресу та порт до сокету
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);
	hint.sin_addr.S_un.S_addr = INADDR_ANY; // Можна використати також inet_pton

	bind(listening, (sockaddr*)&hint, sizeof(hint));

	// Визначаємо, що сокет призначений для прослуховування 
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
				// Приймаємо нове підключення...
				SOCKET client = accept(listening, nullptr, nullptr);

				// Додаємо нове підключення до списку підключених клієнтів
				FD_SET(client, &master);

				// Надсилаємо повідомлення підключеному клієнту...
				string welcomeMsg = "Welcome to the Awesome Chat Server!";
				send(client, welcomeMsg.c_str(), welcomeMsg.size() + 1, 0);
	
			}
			else
			{
				char buf[4096];
				ZeroMemory(buf, 4096);

				// Отримуємо повідомлення
				int bytesIn = recv(sock, buf, 4096, 0);
				if(bytesIn <=0)
				{
					// Прибираємо клієнта
					closesocket(sock);
					FD_CLR(sock, &master);

				}
				else
				{
					// Надсилаємо повідомлення іншим клієнтам, але не в сокет для прослуховування

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
	

	// Очищуємо winsock
	WSACleanup();
}
	
	
