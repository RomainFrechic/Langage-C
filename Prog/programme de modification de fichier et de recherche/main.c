#define LINUX
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#ifdef LINUX
#define PATH "./"
#define sleep() sleep(3);
#define clearS "clear"
#endif
#ifdef WINDOWS
#include windows.h
#define sleep() Sleep(3000);
#define clearS "cls"
#define PATH ".\\"
#endif

#define SIZE 1000

void nEraser(char expression[]);
void cases(char entery[] , char Path_to_dir[] , int ans ,int ansN);

int main(void)
{
     //DECLARATIONS
    //----------------------------------------------------------------------------------------------
    char fullPath[SIZE] , fileNameContainer[SIZE] , entery[SIZE] , ans[3] , ansN[3] , *chrRes = NULL , fileNum[SIZE];
    int i , finderChecker = 0 , lenght = 0 , n = 0 , ansNInt =0 , fileNumInt = 0  ;
    DIR* directory = NULL;
    struct dirent* theFile = NULL;
    //----------------------------------------------------------------------------------------------
    do
    {
        /*these files need to be reinitialized after each 'y' answer*/
        /*-----------------------------------------------------------------------------------*/
        ansNInt = 0;
        finderChecker = 0;
        n = 0;
        strcpy(ans , "");
        strcpy(ansN , "");
        strcpy(fileNameContainer, "");
        strcpy(fileNum , "");
        /*-----------------------------------------------------------------------------------*/
        printf("Enter the path to the directory you want to search in  ( '%s' without quotes for current directory) : " , PATH);
	fgets(fullPath , sizeof(fullPath) , stdin);
	nEraser(fullPath);
	directory = opendir(fullPath);//opening the targeted folder
        /*checking to see if the file opened correctely*/
        if(directory == NULL)
        {
            perror("ERROR");
            exit(-1);
        }
        do
        {
            printf("enter the name of the file you want to look for : ");
            fgets(entery , sizeof(entery) , stdin);
        /*the fgets function prints in addition to the carateres needed the \n the following function removes the extra \n*/
            nEraser(entery);
            system(clearS);
            /*setting to minimum size of query to 3 characters*/
            lenght = (int)strlen(entery);
            if(lenght < 3)
            {
                printf("please enter a name that contains more than 3 caracters \n");
                n++;
                sleep();
                system(clearS);
            }
            if(n == 5)
            {
                printf("you don't want to enter a valid name ? bye then ");
                exit(1);
            }
        }
        while(lenght < 3);
        /*reading the fileNameContainer while there is something to read */
        while((theFile = readdir(directory)) != NULL)
        {
            strcpy(fileNameContainer,theFile->d_name);//copy the fileNameContainer name to fileNameContainer because its easier to deal with
            /*changing the name of the file to lower case so that it maches the name entered by the user*/
            for(i=0 ; fileNameContainer[i] != '\0' ; i++)
                fileNameContainer[i] = tolower(fileNameContainer[i]);
            /*this is where all the magic happens*/
            if((chrRes = strstr(fileNameContainer,entery)) != NULL)
            {
                printf("%d- \" %s \"\n", finderChecker + 1 , fileNameContainer);
                finderChecker++;
            }
        }
        /*in case there is a match*/
        if(finderChecker != 0)
        {
            printf("\n%d results in total\n\n" , finderChecker);
            printf("what file do you want to modify , choose a number : ");
            fgets(fileNum , sizeof(fileNum) , stdin);
            nEraser(fileNum);
            system(clearS);
            fileNumInt = strtol(fileNum , NULL , 10);
            printf("what do you want to do with this files ?\n");
            printf("1.rename\n2.remove\n3.nothing I just want to get the hell out of here\n");
            fgets(ansN , sizeof(ansN) , stdin);
            nEraser(ansN);
            system(clearS);
            ansNInt = strtol(ansN , NULL , 10);
            cases(entery , fullPath , ansNInt , fileNumInt);
            printf("would you like to perform another search ? y/n ");
            fgets(ans , sizeof(ans) , stdin);
            nEraser(ans);
            system(clearS);
            if(!strcmp(ans,"n") || !strcmp(ans,"N"))
                break;
        }
        else
        {
            printf("we were unable to find this file , would you like to make another search ? y/n ");
            fgets(ans , sizeof(ans) , stdin);
            nEraser(ans);
            system(clearS);
        }

        if(closedir(directory) == -1)
            exit(-2);
    }
    while(!strcmp(ans,"y") || !strcmp(ans,"Y"));
    getchar();
    return 0;
}

void nEraser(char expression[])
{
    int i , lenght = strlen(expression);
    for(i=0 ; i<lenght ; i++)
    {
        if(expression[i] == '\n')
            expression[i] = '\0';
    }
}
void cases(char entery[] , char Path_to_dir[] , int ans , int ansN)
{
    //---------------------------------------------------------------------------------------------------------------------------------
    time_t t_var;
    int i , number = 0;
    struct tm tim;
    struct dirent* filename = NULL;
    DIR* directory = NULL;
    FILE* log_file = NULL;
    char  *chrRes = NULL , fileNameContainer[SIZE] , destinationPath[SIZE] , newFileName[SIZE] , removeAns[3];
    //---------------------------------------------------------------------------------------------------------------------------------
    directory = opendir(Path_to_dir);
    log_file = fopen("logs.txt" , "a+");
        if(directory == NULL)//always good to check
        {
            perror("ERROR");
            exit(-1);
        }
        if(log_file == NULL)
        {
            perror("ERROR");
            exit(-1);
        }
        time(&t_var);
        tim = *localtime(&t_var);
        /*the folowing part maybe bad programming and there is a shorter way to do it by creating an array of ints where to store the lines numbers of mached
        words using telldir in the main function then use seekdir to go back to them but this will only work on windows so for the sake of compability ...*/
        /*-----------------------------the ugly part starts here-----------------------------------------------------------------------*/
        while((filename = readdir(directory)) != NULL)//reading the fileNameContainer while there is something to read
        {
            strcpy(fileNameContainer , filename->d_name);//copy the fileNameContainer name to fileNameContainer because its easier to deal with
            for(i=0 ; fileNameContainer[i] != '\0' ; i++)
                fileNameContainer[i] = tolower(fileNameContainer[i]);
            chrRes = strstr(fileNameContainer,entery);
            if(chrRes != NULL)
            {
                number++;
            }
            if(number == ansN)
                break;
        }
        /*------------------------then ends here-----------------------------------------------------------------------------------------*/
    switch(ans)
    {
        /*case the user wants to rename the file*/
        case 1:
            printf("what's the new file name ? : ");
            fgets(newFileName , sizeof(newFileName) , stdin);
            nEraser(newFileName);
	    strcpy(destinationPath , Path_to_dir);
            strcat(Path_to_dir , filename->d_name);
	    strcat(destinationPath , newFileName);
            if(!rename(Path_to_dir, destinationPath))
            {
                printf("the file %s (PATH : %s )was renamed successfuly , the new name is : %s\n" , filename->d_name , Path_to_dir , newFileName);
                fprintf(log_file , "[%2d:%2d:%2d] : RENAMED : %s -> %s\n" , tim.tm_hour , tim.tm_min , tim.tm_sec , filename->d_name , newFileName);
            }
            else
            {
                perror("ERROR");
                printf(" the renaming process didn't go well ...\n");
            }
            break;
            /*case the user wants to remove the file*/
        case 2:
            /*asking for confirmation*/
            printf("are you sure you want to remove the file : %s ? y/n \n" , filename->d_name);
            fgets(removeAns , sizeof(removeAns) , stdin);
            nEraser(removeAns);
            if(!strcmp(removeAns , "y") || !strcmp(removeAns , "Y"))
            {
                strcat(Path_to_dir , filename->d_name);
                fprintf(log_file , "[%2d:%2d:%2d] : REMOVED : %s\n" , tim.tm_hour , tim.tm_min , tim.tm_sec , filename->d_name);
                if(remove(Path_to_dir) == -1)
			perror("remove");
            }
            break;
        case 3:
            break;
        default :
            printf("please enter a valid answer");
    }
    fclose(log_file);
    if(closedir(directory) == -1)
        exit(-3);
}
