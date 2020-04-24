#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINPUT 255
	
typedef struct PhoneBook {
	char name[MAXINPUT];
	int code;
	char number[MAXINPUT];
};

int main() {
	//Opening and configuring the file
	FILE *fp;
	fopen_s(&fp,"PhoneBookBook.txt", "w");
	if(fp == NULL) {
		printf("Error opening file!");
		exit(0);
	}

	//Defining a structure we dont need an array as we will reset it with each itteration of the cycle
	struct PhoneBook WorkingStruct;

	//asking the user how many values he wants to record
	int numberOfContacts;
	char NumberOfContactsCharValue[MAXINPUT];
	printf("Enter amount of contacts: ");
	gets_s(NumberOfContactsCharValue, MAXINPUT);
	numberOfContacts = atoi(NumberOfContactsCharValue);

	//Work Cycle (consinst of 2 elements)
	for(int currentContact = 0; currentContact < numberOfContacts; currentContact++) {
		//We make an entry for the struct
		printf("Enter a name for contact N%d: ", currentContact+1);
		gets_s(WorkingStruct.name, MAXINPUT);

		char AreaCodeWorkValue[MAXINPUT];
		printf("Enter an area code: ");
		gets_s(AreaCodeWorkValue, MAXINPUT);
		WorkingStruct.code = atoi(AreaCodeWorkValue);

		printf("Enter a phone number: ");
		gets_s(WorkingStruct.number, MAXINPUT);

		//We save the entry on a file
		if(fwrite(&WorkingStruct, sizeof(struct PhoneBook), 1, fp)!= 1) {
			printf("Error writing to file!");
			exit(0);
		}
	}

	fclose(fp);

	//Second part of the program
	//We open the file again in read config
	fopen_s(&fp, "PhoneBookBook.txt", "r");
	if (fp == NULL) {
		printf("Error opening file!");
		exit(0);
	}

	while(fread(&WorkingStruct, sizeof(struct PhoneBook), 1, fp)){
		printf("Name: %s \nArea code: %d \nPhoneNumber: %s\n\n", WorkingStruct.name, WorkingStruct.code, WorkingStruct.number);
	}

	fclose(fp);
	
	return(0);
}