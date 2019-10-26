#ifndef SONG
#define SONG
#include <cstdio>
#include <windows.h>
const int qdo = 262;
const int qre = 294;
const int qmi = 330;
const int qfa = 349;
const int qso = 392;
const int qla = 440;
const int qsi = 494;
const int doo = 523;
const int re = 578;
const int mi = 659;
const int fa = 698;
const int so = 784;
const int la = 880;
const int si = 988;
const int do1 = 1046;
const int re1 = 1175;
const int mi1 = 1318;
const int fa1 = 1480;
const int so1 = 1568;
const int la1 = 1760;
const int si1 = 1976;
const int sqdo = 277;
const int sqre = 311;
const int sqfa = 370;
const int sqso = 415;
const int sqla = 466;
const int sdo = 554;
const int sre = 622;
const int sfa = 740;
const int sso = 831;
const int sla = 932;
const int sdo1 = 1046;
const int sre1 = 1245;
const int sfa1 = 1480;
const int sso1 = 1661;
const int sla1 = 1865;
const int pai = 600;
const int ban = 300;
inline void sys_wrong_sound()
{
    Beep(sla1,pai+ban);
}
inline void loading_qdo_onehalf()
{
    Beep(qdo, pai + ban);
}
inline void loading_mi_one()
{
    Beep(mi, pai);
}
inline void loading_so_one()
{
    Beep(so,pai);
}
inline void loading_sound()
{
    Beep(doo,ban);
}
inline void GAME_OVER_sound()
{
    Beep(fa,ban);
    Beep(mi,ban);
    Beep(re,ban);
    Beep(doo,ban);
}
inline void EAT_sound()
{
    Beep(la,100);
}
inline void WALK_sound()
{
    Beep(qsi,100);
}
#endif