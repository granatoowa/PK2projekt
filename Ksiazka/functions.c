#include "structures.h"
#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>

#pragma warning(disable:4996)

void system_CLS(){
	Sleep(100);
	system("cls");
}

void system_3CLS() {
	Sleep(3000);
	system("cls");
}

void writeRec(Recipe** pHead){
	printf("%s", (*pHead)->name);
	printf("Mark: %0.001f\nCost(one portion): %0.001f zl\n", (*pHead)->mark, (*pHead)->cost);
	printf("Ingredients: %s", (*pHead)->ingredients);
	printf("Recipe: %s\n", (*pHead)->recipe);
}

void writeAllNames(Recipe* pHead) {
	Recipe* wsk = pHead;
	int i = 1;
	printf("\nRECIPES TO CHOOSE FROM\n");
	while (wsk != NULL) {
		printf("%d.%s", i, wsk->name);
		wsk = wsk->pNext;
		i++;
	}
}

void nameAssign(Recipe** pHead, FILE* fp){
	char name1[50];
	fgets(name1, 50, fp);
	size_t len = strlen(name1);
	(*pHead)->name = malloc(len + 1);
	strcpy((*pHead)->name, name1);
}

void costAssign(Recipe** pHead, FILE* fp){
	char buf[50];
	double cost;
	fgets(buf, 50, fp);
	cost = atof(buf);
	(*pHead)->cost = cost;
}

void ingredientsAssign(Recipe** pHead, FILE* fp) {
	char buf1[200];
	fgets(buf1, 200, fp);
	size_t len1 = strlen(buf1);
	(*pHead)->ingredients = malloc(len1 + 1);
	strcpy((*pHead)->ingredients, buf1);
	char* pch;
	pch = strtok(buf1, ",\n");
	int i = 0;
	while (pch != NULL) {
		//printf("%s\n", pch);
		strcpy((*pHead)->ing[i], pch);
		//printf("%s\n", (*pHead)->ing[i]);
		pch = strtok(NULL, ",\n");
		i++;
	}
}

void recipeAssign(Recipe** pHead, FILE* fp) {
	char buf2[1000];
	fgets(buf2, 1000, fp);
	size_t len2 = strlen(buf2);
	(*pHead)->recipe = malloc(len2 + 1);
	strcpy((*pHead)->recipe, buf2);
}

void markAssign(Recipe** pHead, FILE* fp) {
	char buf3[50];
  double mark;
  fgets(buf3, 50, fp);
  mark = atof(buf3);
  (*pHead)->mark = mark;
}

void assign(Recipe** pHead, FILE* fp) {
	nameAssign(pHead, fp);
	costAssign(pHead, fp);
	ingredientsAssign(pHead, fp);
	recipeAssign(pHead, fp);
	markAssign(pHead, fp);
}

void addRecipe(Recipe** pHead, FILE* fp){
	if (*pHead == NULL){
		*pHead = (Recipe*)malloc(sizeof(Recipe));
		(*pHead)->pNext = NULL;
		assign(pHead, fp);
		//writeRec(pHead); // sprawdzenie
	}
	else{
		Recipe* pt = *pHead;
		while (pt->pNext != NULL) {
			pt = pt->pNext;
		}
		pt->pNext = (Recipe*)malloc(sizeof(Recipe));
		pt->pNext->pNext = NULL;
		assign(&(pt)->pNext, fp);
		//writeRec(&(pt)->pNext);   //sprawdzenie
	}
}

void printStartMenu() {
	printf("\nRecipe Cookbook\n\n");
	printf("MENU\n");
	printf("1.Search recipe\n");
	printf("2.Mark recipe\n");
	printf("3.Add recipe\n");
	printf("4.Create menu and calculate cost\n");
	printf("\nEnter number(1-4):");
}

void searchIng(Recipe* pHead, char* ing){
	Recipe* wsk = pHead;
	while (wsk != NULL) {
		for (int i = 0; i < HOWMANY; i++) {
			if (strcmp(wsk->ing[i], ing) == 0) {
				printf("\n");
				writeRec(&wsk);
			}
		}
		//printf("%s", wsk->name);
		wsk = wsk->pNext;
	}
}

void searchRecipe(Recipe* pHead) {
	printf("\nSEARCH RECIPE\n\n");
	char ing[20];
	printf("Enter ingredient: ");
	fgets(ing, 20, stdin);
	char* pch;
	pch = strtok(ing, ",\n");
	searchIng(pHead, pch);
}

void changeMark(Recipe* pHead, float mark, int length, int num) {
	//struct Struct* temp = pHead;
	Recipe* temp = pHead;
	for (int i = 0; i < length; i++) {
		if (i == (num - 1)) {
			//printf("%d.", i + 1);
			//printf("%s", temp->name);
			temp->mark = mark;
		}
		temp = temp->pNext;
	}
}

void markRecipe(Recipe* pHead, int listlength) {
	float mark;
	int num1;
	Recipe* wsk1 = pHead;
	printf("\nMARK RECIPE \n\n");
	writeAllNames(pHead);
	printf("\nEnter recipe's number: "); //wybranie cyfry (przepisu)
	scanf("%d", &num1);
	printf("\nEnter mark: ");
	scanf("%f", &mark);
	changeMark(wsk1, mark, listlength, num1);  //zmienienie oceny
	printf("\nMark saved!\n");
}

void userNameAssign(Recipe** pHead) {
	char name1[50];
	printf("Enter name: ");
	fgets(name1, 50, stdin);
	size_t len = strlen(name1);
	(*pHead)->name = malloc(len + 1);
	strcpy((*pHead)->name, name1);
}

void userCostAssign(Recipe** pHead) {
	double cost;
	char buf[50];
	printf("Enter cost of one portion(in zl): ");
	fgets(buf, 50, stdin);
	cost = atof(buf);
	(*pHead)->cost = cost;
}

void userIngredientsAssign(Recipe** pHead) {
	char buf1[200];
	printf("Enter ingredients: ");
	fgets(buf1, 200, stdin);
	size_t len1 = strlen(buf1);
	(*pHead)->ingredients = malloc(len1 + 1);
	strcpy((*pHead)->ingredients, buf1);
	char* pch;
	pch = strtok(buf1, ",\n");
	int i = 0;
	while (pch != NULL) {
		//printf("%s\n", pch);
		strcpy((*pHead)->ing[i], pch);
		//printf("%s\n", (*pHead)->ing[i]);
		pch = strtok(NULL, ",\n");
		i++;
	}
}

void userRecipeAssign(Recipe** pHead) {
	char buf2[1000];
	printf("Enter recipe: ");
	fgets(buf2, 1000, stdin);
	size_t len2 = strlen(buf2);
	(*pHead)->recipe = malloc(len2 + 1);
	strcpy((*pHead)->recipe, buf2);
}

void userMarkAssign(Recipe** pHead) {
	double mark;
	char buf3[50];
	printf("Enter mark: ");
	fgets(buf3, 50, stdin);
	mark = atof(buf3);
	(*pHead)->mark = mark;
}

void userAssign(Recipe** pHead){
	userNameAssign(pHead);
	userCostAssign(pHead);
	userIngredientsAssign(pHead);
	userRecipeAssign(pHead);
	userMarkAssign(pHead);
	writeRec(pHead);

}

void userAddRecipe(Recipe** pHead){
	printf("\nADD RECIPE\n");
	if (*pHead == NULL){
		*pHead = (Recipe*)malloc(sizeof(Recipe));
		(*pHead)->pNext = NULL;
		//PRZYPISANIE
		userAssign(pHead);
	}
	else{
		Recipe* pt = *pHead;
		while (pt->pNext != NULL) {
			pt = pt->pNext;
		}
		pt->pNext = (Recipe*)malloc(sizeof(Recipe));
		pt->pNext->pNext = NULL;
		//PRZYPISANIE
		userAssign(&(pt)->pNext);
	}
};

void writeRecMenu(Recipe* pHead, FILE* fp) {
	fprintf(fp, "%s", pHead->name);
	fprintf(fp, "Mark: %0.001f\nCost(one portion): %0.001f zl\n", pHead->mark, pHead->cost);
	fprintf(fp, "Ingredients: %s", pHead->ingredients);
	fprintf(fp, "Recipe: %s\n", pHead->recipe);
}

double whichRecipe(Recipe* pHead, FILE* fp, int which) {
	Recipe* wsk1 = pHead;
	double cost;
	for (int j = 0; j <= which; j++) {
		if (which == j) {
			//wpisanie do pliku menu
			writeRecMenu(wsk1, fp);
			cost = wsk1->cost;
		}
		wsk1 = wsk1->pNext;
	}
	return cost;
}

void fReadMenu() {
	char buff[10000];
	FILE* file1 = fopen("menu.txt", "r");
	if (file1 != NULL) {
		while (fgets(buff, 1000, file1) != NULL)
		{
			printf("%s", buff);
			//printf("%s\n", word);
		}
		fclose(file1);
	}
}

void writeFMenu(Recipe*pHead, int people, int menulength) {
	Recipe* wsk1 = pHead;
	int which;
	double cost;
	double recCost;
	cost = 0;
	FILE* file = fopen("menu.txt", "w");
	if (file != NULL) {
		fprintf(file, "\nMENU\n");
		for (int i = 0; i < 7; i++) {
			switch (i) {
			case 0:
				printf("\nMONDAY\n");
				fprintf(file, "\nMONDAY\n");
				break;
			case 1:
				printf("\nTUESDAY\n");
				fprintf(file, "\nTUESDAY\n");
				break;
			case 2:
				printf("\nWEDNESDAY\n");
				fprintf(file, "\nWEDNESDAY\n");
				break;
			case 3:
				printf("\nTHURDSAY\n");
				fprintf(file, "\nTHURSDAY\n");
				break;
			case 4:
				printf("\nFRIDAY\n");
				fprintf(file, "\nFRIDAY\n");
				break;
			case 5:
				printf("\nSATURDAY\n");
				fprintf(file, "\nSATURDAY\n");
				break;
			case 6:
				printf("\nSUNDAY\n");
				fprintf(file, "\nSUNDAY\n");
				break;
			}
			for (int i = 0; i < menulength; i++) {
				printf("Enter %d. number: ", i + 1);
				scanf("%d", &which);
				which = which - 1;
				recCost = whichRecipe(wsk1, file, which);
				cost += recCost;
			}
		}
		cost *= people;
		fprintf(file, "COST: %0.001f zl", cost);
		system_CLS();
		fclose(file);
	}
}

void menu(Recipe* pHead, int listlength) {
	int menulength;
	int people;
	printf("\nCREATE MENU AND CALCULATE COST\n");
	printf("For how many people: ");
	scanf("%d", &people);
	writeAllNames(pHead);
	printf("\nHow many recipes do you want to add to the daily menu: ");
	scanf("%d", &menulength);
	writeFMenu(pHead, people, menulength);
	fReadMenu();
}

void endFWrite(Recipe* pHead){
	//ZAPISANIE LISTY DO PLIKU!!!!!
	Recipe* temp = pHead;
	FILE* file = fopen("recipes.txt", "w");
	if (file != NULL) {
		while (temp) {
			fprintf(file, "%s", temp->name);
			fprintf(file, "%0.001f\n", temp->cost);
			fprintf(file, "%s", temp->ingredients);
			fprintf(file, "%s", temp->recipe);
			if (temp->pNext) {
				fprintf(file, "%0.001f\n", temp->mark);
			}
			else {
				fprintf(file, "%0.001f", temp->mark);
			}
			temp = temp->pNext;
		}
		fclose(file);
	}
}

void deleteList(Recipe** pHead){
	Recipe* current = *pHead;
	Recipe* next;

	while (current != NULL){
		next = current->pNext;
		free(current->name);
		free(current->ingredients);
		free(current->recipe);
		free(current);
		current = next;
	}
	*pHead = NULL;
}

void runProgram(){
	Recipe* pHead;
	pHead = (Recipe*)malloc(sizeof(Recipe));
	pHead = NULL;
	FILE* file = fopen("recipes.txt", "r");
	int listlength = 0;
	if (file)
	{
		do {
			addRecipe(&pHead, file);
			listlength++;
		} while (feof(file) == 0);
		fclose(file);
	}
	printStartMenu();
	int num;
	scanf("%d", &num);
	while ((getchar()) != '\n');
	system_CLS();
	switch (num) {
	case 1:
		searchRecipe(pHead);
		//runProgram(); umozliwic dalsze korzystanie?
		break;
	case 2:
		markRecipe(pHead, listlength);
		system_3CLS();
		endFWrite(pHead);
		deleteList(&pHead);
		runProgram();
		break;
	case 3:
		userAddRecipe(&pHead);
		endFWrite(pHead);
		deleteList(&pHead);
		runProgram();
		break;
	case 4:
		menu(pHead, listlength);
		deleteList(&pHead);
		//runProgram(); umozliwic dalsze korzystanie?
		break;
	default:
		break;
	}
}
