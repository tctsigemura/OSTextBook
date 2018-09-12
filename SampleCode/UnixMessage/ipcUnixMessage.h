// ipcUnixMessage.h : メッセージ構造体の宣言
#define MAXMSG 100                              // メッセージ本体の長さ
struct msgBuf {                                 // メッセージ格納用構造体
  long mtype;                                   //   メッセージの型
  char mtext[MAXMSG];                           //   メッセージの本体
};
