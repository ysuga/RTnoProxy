#pragma once

#include "libysuga.h"

#ifdef WIN32
#include <windows.h>

#else



#endif

#include <string>
#include <exception>

namespace net {
	namespace ysuga {
		class LIBYSUGA_API SocketException : public std::exception {
		private:
			std::string msg;
		public:
			SocketException(const char* msg) {this->msg = msg;}
			virtual ~SocketException() throw() {}
		public:
			const char* what() throw() {return msg.c_str();}
		};


		class LIBYSUGA_API SocketCreateException : public SocketException {
		public:
			SocketCreateException(void) : SocketException("SocketCreate Error") {}
			virtual ~SocketCreateException(void) throw() {}
		};


		class LIBYSUGA_API SocketConnectException : public SocketException {
		public:
			SocketConnectException(void) : SocketException("SocketConnect Error") {}
			virtual ~SocketConnectException(void) throw() {}
		};

		class LIBYSUGA_API Socket
		{
		private:
		#ifdef WIN32
			SOCKET m_Socket;
			struct sockaddr_in m_SocketAddr;
		#else

			/**
			 * @brief file descriptor
			 */
			int m_Fd;
		#endif

		public:
			Socket(const char* ipAddress, unsigned short port);
			~Socket(void);


		public:
			int setNonBlock(unsigned int flag);
			int recv(char* buf, int len);
			int send(const char* buf, int len);
		};

	};
};