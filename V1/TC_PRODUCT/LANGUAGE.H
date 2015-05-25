#ifndef	__LANGUAGE_h__ 
#define	__LANGUAGE_h__ 



#define   DEFAULT_LANGUAGE     1    

const unsigned char code LAN0[5] = {18,14,19,6,18};   // ENG -- 英文
const unsigned char code LAN1[5] = {18,12,16,1,18};   // CHI -- 中文
const unsigned char code LAN2[5] = {18,15,15,10,18};  // FRA -- 法文

const unsigned char code *LANGUAGE_STRING[2] = {LAN0, LAN2};
const unsigned char code  Machine_ID = 0x71;   // 7:7枚  1:英法版

#endif