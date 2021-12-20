#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<string.h>
//struct date dt;
char signs[12][10]={"Capricorn","Aquarius","Pisces","Aires","Taurus","Gemini","Cancer","Leo","Virgo","Libra","Scorpio","Sagitarius"};
char good[5][255] = {
					"Your ventures are bound to succeed.",
					"Your efforts will make a difference.",
					"Economic  gains are favourable.",
					"Disasters and bad energy steer away from you.",
					"Lady luck favous you a lot."
					};
char bad[5][255]={
					"May face financial loss.",
					"Bad energy has accumulated on you.",
					"Danger near bodies of water.",
					"Minor accidents may occur.",
					"Emotional and pshycological issues may arise."	
				};
				
int main() {
	int choice;
	choice = showMenu();
	switch(choice){
		case 1:{
			findSign();
			break;
		}
		case 2:{
			getReading();
			break;
		}
		case 3:{
			viewHistory();
			break;
		}
		default:{
			exit(0);
			break;
		}
	}	
	return 0;
}

int showMenu(){
	int choice;
	lineDesign();
	printf("|%14s %15s|","Menu", " ");
	lineDesign();
	printf("|1.Find Sign. %17s|\n", " ");
	printf("|2.Today's reading. %11s|\n", " ");
	printf("|3.View Reading History. %6s|\n", " ");
	printf("|4.Exit. %22s|", " ");
	lineDesign();
	scanf("%d", &choice);
	system("cls");
	return choice;
}

int findSign(){
	int day, month;
	system("cls");
	lineDesign();
	printf("|Enter Birthday%16s|"," ");
	lineDesign();
	lineDesign();
	printf("|Enter day:%19s |"," ");
	lineDesign();
	scanf("%d", &day);
	lineDesign();
	printf("|Enter month:%18s|", " ");
	lineDesign();
	scanf("%d", &month);	
	printf("Your Sign: ");
	switch(month){
		case 1:{
			if(day<=20){
				printf("%s\n", signs[0]);	
			}
			else{
				printf("%s\n", signs[1]);		
			}
			break;
		}
		case 2:{
			if(day<=18){
				printf("%s\n", signs[1]);	
			}
			else{
				printf("%s\n", signs[2]);		
			}
			break;
		}
		case 3:{
			if(day<=20){
				printf("%s\n", signs[2]);	
			}
			else{
				printf("%s\n", signs[3]);		
			}
			break;
		}
		case 4:{
			if(day<=19){
				printf("%s\n", signs[3]);	
			}
			else{
				printf("%s\n", signs[4]);		
			}
			break;
		}
		case 5:{
			if(day<=20){
				printf("%s\n", signs[4]);	
			}
			else{
				printf("%s\n", signs[5]);		
			}
			break;
		}
		case 6:{
			if(day<=20){
				printf("%s\n", signs[5]);	
			}
			else{
				printf("%s\n", signs[6]);		
			}
			break;
		}
		case 7:{
			if(day<=22){
				printf("%s\n", signs[6]);	
			}
			else{
				printf("%s\n", signs[7]);		
			}
			break;
		}case 8:{
			if(day<=22){
				printf("%s\n", signs[7]);	
			}
			else{
				printf("%s\n", signs[8]);		
			}
			break;
		}
		case 9:{
			if(day<=22){
				printf("%s\n", signs[8]);	
			}
			else{
				printf("%s\n", signs[9]);		
			}
			break;
		}
		case 10:{
			if(day<=22){
				printf("%s\n", signs[9]);	
			}
			else{
				printf("%s\n", signs[10]);		
			}
			break;
		}
		case 11:{
			if(day<=21){
				printf("%s\n", signs[10]);	
			}
			else{
				printf("%s\n", signs[11]);		
			}
			break;
		}
		case 12:{
			if(day<=21){
				printf("%s\n", signs[11]);	
			}
			else{
				printf("%s\n", signs[0]);		
			}
			break;
		}
		default:{
			printf("Invalid Date.");
			break;
		}
	}
	return 0;
}

int getReading(){
	srand(time(NULL));
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	int flag =  rand() % 1 ;
	int pick = rand() % 4 ;
	char name[20];
	char filename[25];
	char data[255];
	FILE *file;
	system("cls");
	printf("Enter your name:");
	scanf("%s", name);
	strcpy(filename, name);
	strcat(filename, ".txt");
	system("cls");
	printf("+------------------------------------------------------------------------------------------+\n");
	printf("|Today is:  %d/ %d/ %d. %65s|",tm.tm_year+1900, tm.tm_mon,tm.tm_mday," ");
	printf("\n");
	printf("|Your reading  for today is: %62s|", " ");
	if(flag == 0){
		printf("\n|%s\n",good[pick]," ");
		printf("+------------------------------------------------------------------------------------------+\n");
		strcpy(data, good[pick]);
	}else{
		printf("\n|%s\n",bad[pick]);
		printf("+------------------------------------------------------------------------------------------+\n");
		strcpy(data, bad[pick]);
	}  
	file = fopen (filename, "a+");
	fprintf(file, "\n Date(%d/%d/%d) Time(%d:%d:%d) :%s",tm.tm_year+1900, tm.tm_mon,tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec, data);
	fclose(file);
	return 0;
}

int viewHistory(){
	FILE * fPtr;
    char ch;
    char name[20];
	char filename[25];
    printf("Enter your name:");
	scanf("%s", name);
	strcpy(filename, name);
	strcat(filename, ".txt");
	system("cls");
    fPtr = fopen(filename, "r");
	if(fPtr == NULL){
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }
    printf("+------------------------------------------------------------------------------------------+\n");
    printf("|File opened successfully. Reading file contents character by character. %18s|\n"," ");
	printf("+------------------------------------------------------------------------------------------+\n");
    
    do{
		ch = fgetc(fPtr);
		putchar(ch);
    } while(ch != EOF);
    fclose(fPtr);
    return 0;
}

void lineDesign(){
	printf("\n+------------------------------+\n");
}
