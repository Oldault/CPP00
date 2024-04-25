#ifndef _COLORS_H
#	define _COLORS_H

/* FOREGROUND */
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED x RST
#define FGRN(x) KGRN x RST
#define FYEL(x) KYEL x RST
#define FBLU(x) KBLU x RST
#define FMAG(x) KMAG x RST
#define FCYN(x) KCYN x RST
#define FWHT(x) KWHT x RST

/* BACKGROUND */
#define KRED40  "\x1B[41m"
#define KGRN40  "\x1B[42m"
#define KYEL40  "\x1B[43m"
#define KBLU40  "\x1B[44m"
#define KMAG40  "\x1B[45m"
#define KCYN40  "\x1B[46m"
#define KWHT40  "\x1B[47m"

#define BRED(x) KRED40 x RST
#define BGRN(x) KGRN40 x RST
#define BYEL(x) KYEL40 x RST
#define BBLU(x) KBLU40 x RST
#define BMAG(x) KMAG40 x RST
#define BCYN(x) KCYN40 x RST
#define BWHT(x) KWHT40 x RST

#define BOLD(x) "\x1B[1m" x RST
#define ITAL(x) "\x1B[3m" x RST
#define UNDL(x) "\x1B[4m" x RST

#endif  /* _COLORS_ */