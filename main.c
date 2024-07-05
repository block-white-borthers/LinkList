#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void datastructure(){
	system("chrome https://www.bilibili.com/video/BV1db411Y7Lm?p=22&vd_source=a90d9fd711e1e6ed9371309a471c21f9");
}

void dos(){
	system("color 07");
	system("mode con cols=155 lines=30");
	system("cmd /k cd /d d:\\dos");
}

void cmd()
{
	/* cpu 占用率太高了，到了100 */
int i;/**/
char ping[128];/**/
for(i=100;/**/i<111;/**/i++){
memset(ping,0,sizeof(ping));/**/
snprintf(ping, sizeof(ping),"ping 192.168.2.%d 1>>log", i);/* format data */
printf("%s\n",ping);/* tip */
system(ping); /*ping network*/
memset(ping,0,sizeof(ping));/**/
}
}

int main(int argc, char *argv[]) {
	cmd();
	
	
	
	
	return 0;
}
