#ifndef Magellan_h
#define Magellan_h

#define ATLSOFTSERIAL 1
#include <Arduino.h>
#include <Stream.h>

#define MODE_STRING 0
#define MODE_STRING_HEX 1

#if ATLSOFTSERIAL 
	#include "AltSoftSerial.h"
#endif

	#include <SoftwareSerial.h>

  const byte maxretrans=4;	

  const char con[]="40";
  const char non_con[]="50";
  const char ack[]="60";
  const char rst[]="70";

  const char EMPTY[]="00";
  const char GET[]="01";
  const char POST[]="02";
  const char PUT[]="03";
  const char DELETE[]="04";

struct AIS_BC95_RES
{
	char status;
	String data;
	String temp;
};

struct signal
{
	String csq;
	String rssi;
	String ber;
};
struct pingRESP
{
	bool status;
	String addr;
	String ttl;
	String rtt;
};

enum rspcode {
	CREATED=65,
	DELETED=66,
	VALID=67,
	CHANGED=68,
	CONTENT=69,
	CONTINUE=95,
	BAD_REQUEST=128,
	FORBIDDEN=131,
	NOT_FOUND=132,
	METHOD_NOT_ALLOWED=133,
	NOT_ACCEPTABLE=134,
	REQUEST_ENTITY_INCOMPLETE=136,
	PRECONDITION_FAILED=140,
	REQUEST_ENTITY_TOO_LARGE=141,
	UNSUPPORTED_CONTENT_FORMAT=143,
	INTERNAL_SERVER_ERROR=160,
	NOT_IMPLEMENTED=161,
	BAD_GATEWAY=162,
	SERVICE_UNAVAILABLE=163,
	GATEWAY_TIMEOUT=164,
	PROXY_NOT_SUPPORTED=165
};


class Magellan
{


public:
	Magellan();

	bool debug;
	bool default_server;

	void (*Event_debug)(char *data);
	void reset();
	void rebootModule();
	bool waitReady();
	bool setPhoneFunction(unsigned char mode);

	//Network
	bool setAutoConnectOn();
	bool setAPN(const char *apn);
	bool cgatt(unsigned char mode);
	bool connectNBnetwork();
	bool disconnectNBnetwork();
	bool getNBConnect();
	signal getSignal();
	void createUDPSocket(const char *port);
	bool closeUDPSocket(String socket);
    void getAPN();
    pingRESP pingIP(char *IP);

    //################# Magellan Platform ########################
    bool Magellan::begin(char *auth);
    void Magellan::printHEX(char *str);
    void Magellan::printmsgID(unsigned int messageID);
    void Magellan::cnt_auth_len(char *auth);
    String Magellan::post(String payload);
    void Magellan::send(String payload,int style=1,int interval=20);
    String Magellan::get(String Resource);
    String Magellan::get_data(String Resource);
    void Magellan:: waitResponse();
private:
	
	AIS_BC95_RES Magellan:: wait_rx_bc(long tout,String str_wait);
	void Magellan::print(char *str);
	void Magellan::print_rsp_header(const String Msgstr);
	void Magellan::print_rsp_Type(const String Msgstr,unsigned int msgID);
	//void Magellan::receive_data(const String rx);
	void Magellan::miniresponse(String rx);

	void Magellan::print_pathlen(unsigned int path_len,char *init_str);

protected:
	 Stream *_Serial;
};


#endif