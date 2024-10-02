#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Date{
    int year;
    int month;
    int day;
};

struct Task{
    char name[20];
    char desc[30];
    char status[20];
    struct Date date;
};

struct Task tasks[100];
int tasksCounter = 3;

void getTasks(){
    printf("+--------------------------------------------------------------------------+\n");
    printf("|                            Liste Des Taches                              |\n");
    printf("+-----+----------------------+----------------------+----------------------+\n");
    for(int index = 0; index < tasksCounter; index ++){
        printf("|__Task %i\n", index);
        printf("|  |__Name : %s\n", tasks[index].name);
        printf("|  |__Descreption : %s\n", tasks[index].desc);
        printf("|  |__Date : %i/%i/%i\n", tasks[index].date.day, tasks[index].date.month, tasks[index].date.year);
        printf("|  |__Status : %s\n", tasks[index].status);
    }
}

void updateStatus(){
    system("cls");
    char name[20];
    printf("+--------------------+\n");
    printf("| Changer Le Status  |\n");
    printf("+--------------------+\n");
    printf("[+] Nom : ");
    scanf("%s", name);
    for (int i = 0; i < tasksCounter; i++) {
        if (strcmp(tasks[i].name, name) == 0) {
            printf("+-----------------+\n");
            printf("| Tache Trouvee   |\n");
            printf("+-----------------+\n");
            int newstatus;
            printf("[+] 1. To Do\n");
            printf("[+] 2. Doing \n");
            printf("[+] 3. Done\n");
            printf(">>> ");
            scanf("%i", &newstatus);
            switch(newstatus){
                case 1:
                strcpy(tasks[i].status, "To Do");
                break;
                case 2:
                strcpy(tasks[i].status, "Doing");
                break;
                case 3:
                strcpy(tasks[i].status, "Done");
                break;
                default:
                  printf("Command Not Found");
            }
            printf("+-----+----------------------+----------------------+----------------------+----------------------+\n");
            printf("| ID  |         Nom          |      Descreption     |         Date         |         Status       |\n");
            printf("+-----+----------------------+----------------------+----------------------+----------------------+\n");
            printf("| %-3d | %-20s | %-20s | %02d/%02d/%04d | %-20s |\n", i, tasks[i].name, tasks[i].desc, tasks[i].date.day, tasks[i].date.month, tasks[i].date.year, tasks[i].status);
            printf("+-----+----------------------+----------------------+----------------------+----------------------+\n");
            return;
        }
    }
    printf("| Tache Non Trouvee |\n");
}

int terminal() {
    system("title Systeme De Gestion De Taches");
    system("cls");
    int choice;
    while (1) {
        printf("+------------------------------------------+\n");
        printf("|     Systeme De Gestion Des Contacts      |\n");
        printf("+------------------------------------------+\n");
        printf("| 1 | Afficher Tous Les Taches             |\n");
        printf("| 2 | Changer Le Status                    |\n");
        printf("+------------------------------------------+\n");

        printf(">>> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getTasks();
                break;
            case 2:
                updateStatus();
                break;
            case 7:
                printf("[+] Fermeture En Cours...\n");
                printf("+------------------+\n");
                printf("| A la Prochaine ! |\n");
                printf("+------------------+\n");
                return 0;
            default:
                printf("+----------------------+\n");
                printf("| Commande Non Trouvee |\n");
                printf("+----------------------+\n");
        }
    }
}

int main() {
    tasks[0] = (struct Task){"Task1", "Description of Task 1", "To Do", {2024, 10, 2}};
    tasks[1] = (struct Task){"Task2", "Description of Task 2", "Doing", {2024, 10, 3}};
    tasks[2] = (struct Task){"Task3", "Description of Task 3", "Done", {2024, 10, 4}};
    
    terminal();
    return 0;
}
