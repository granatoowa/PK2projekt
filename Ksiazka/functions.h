/**@file*/
#ifndef functions_h
#define functions_h

#pragma warning(disable:4996)

/**Funkcja czyszczaca ekran z opoznieniem 100.*/
void system_CLS();

/**Funkcja czyszczaca ekran z opoznieniem 3000.*/
void system_3CLS();

/**Funkcja wypisujaca przepis na standardowe wyjscie.
@param pHead Wskaznik na pierwszy element listy
*/
void writeRec(Recipe** pHead);

/**Funkcja wypisujaca nazwy wszystkich przepisow z listy na standardowe wyjscie.
@param pHead Wskaznik na pierwszy element listy
*/
void writeAllNames(Recipe* pHead);

/**Funkcja pobierajaca z pliku dane dotyczace nazwy przepisu i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void nameAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja pobierajaca z pliku dane dotyczace kosztu przepisu i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void costAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja pobierajaca z pliku dane dotyczace skladnikow przepisu i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void ingredientsAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja pobierajaca z pliku dane dotyczace receptury i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void recipeAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja pobierajaca z pliku dane dotyczace oceny przepisu i alokujaca dla nich pamiec.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void markAssign(Recipe** pHead, struct FILE* fp);

/**Funkcja przypisujaca konketne dane do elementow listy.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void assign(Recipe** pHead, struct FILE* fp);

/**Funkcja alokujaca pamiec dla listy przepisow.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void addRecipe(Recipe** pHead, struct FILE* fp);

/**Funkcja wypisujaca menu programu na standardowe wyjscie.*/
void printStartMenu();

/**Funkcja wyszukujaca wszystkie przepisy z podanym przez uzytkownika skladnikiem oraz wypisujaca je na ekran. 
@param pHead Wskaznik na pierwszy element listy
@param ing Wskaznik na podany skladnik
*/
void searchIng(Recipe* pHead, char* ing);

/**Funkcja pobierajaca nazwe skladnika od uzytkownika do wyszukania przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void searchRecipe(Recipe* pHead);

/**Funkcja zmieniajaca ocene przepisu.
@param pHead Wskaznik na pierwszy element listy
@param mark Zawiera ocene podana przez uzytkownika
@param listlength Zawiera dlugosc listy
@param num Zawiera numer przepisu podany przez uzytkownika
*/
void changeMark(Recipe* pHead, float mark, int listlength, int num);

/**Funkcja pobierajaca od uzytkownika numer przepisu oraz ocene, aby zmienic ocene przepisu.
@param pHead Wskaznik na pierwszy element listy
@param listlength Zawiera dlugosc listy
*/
void markRecipe(Recipe* pHead, int listlength);

/**Funkcja pobierajaca od uzytkownika dane dotyczace nazwy przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userNameAssign(Recipe** pHead);

/**Funkcja pobierajaca od uzytkownika dane dotyczace kosztu przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userCostAssign(Recipe** pHead);

/**Funkcja pobierajaca od uzytkownika dane dotyczace skladnikow przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userIngredientsAssign(Recipe** pHead);

/**Funkcja pobierajaca od uzytkownika dane dotyczace receptury.
@param pHead Wskaznik na pierwszy element listy
*/
void userRecipeAssign(Recipe** pHead);

/**Funkcja pobierajaca od uzytkownika dane dotyczace oceny przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userMarkAssign(Recipe** pHead);

/**Funkcja pobierajaca dane od uzytkownika dotyczace przepisu.
@param pHead Wskaznik na pierwszy element listy
*/
void userAssign(Recipe** pHead);

/**Funkcja dodajaca do listy przepis wpisany przez uzytkownika.
@param pHead Wskaznik na pierwszy element listy
*/
void userAddRecipe(Recipe** pHead);

/**Funkcja wpisujaca przepisy do pliku zwiazanym z menu.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
*/
void writeRecMenu(Recipe* pHead, struct FILE* fp);

/**Funkcja wyszukujaca przepisy, ktore maja zostac wpisane do menu.
@param pHead Wskaznik na pierwszy element listy
@param fp Wskaznik na plik
@param which Zawiera numer przepisu podanego przez uzytkownika
*/
double whichRecipe(Recipe* pHead, struct FILE* fp, int which);

/**Funkcja pobierajaca dane z pliku dotyczacego menu i wypisujaca je na ekran.*/
void fReadMenu();

/**Funkcja wpisujaca menu do pliku oraz wyliczajaca jego koszt.
@param pHead Wskaznik na pierwszy element listy
@param people Zawiera ilosc osob podana przez uzytkownika
@param menulength Zawiera dlugosc menu
*/
void writeFMenu(Recipe* pHead, int people, int menulength);

/**Funkcja tworzaca menu.
@param pHead Wskaznik na pierwszy element listy
@param listlength Zawiera iloœæ przepisow na liscie
*/
void menu(Recipe* pHead, int listlength);

/**Funkcja zapisujaca koncowa liste do pliku
@param pHead Wskaznik na pierwszy element listy
*/
void endFWrite(Recipe* pHead);

/**Funkcja dealokujaca pamiec listy z przepisami. 
@param pHead Wskaznik na pierwszy element listy
*/
void deleteList(Recipe** pHead);

/**Funkcja zawierajaca cale menu glowne wraz z mozliwoscia wyboru.*/
void runProgram();

#endif
