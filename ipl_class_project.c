#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct team
{
    char name[50];
    char players[11][50];
    int num_players;
};

struct match
{
    char team1[50];
    char team2[50];
    char date[20];
};

int num_teams = 0;
struct team teams[20];
int num_matches = 0;
struct match matches[200];

void display_teams()
{
    printf("                               ----------------------------------------------------\n");
    printf("                                                  LISTS OF TEAMS\n");
    printf("                               ----------------------------------------------------\n");
    // printf("                               ----------------------------------------------------\n");

    for (int i = 0; i < num_teams; i++)
    {
        printf("NAME OF TEAM NO. %d IS %s\n\n", i + 1, teams[i].name); // FOR SHOWING THE NAMES OF THE TEAM
        printf(" PLAYERS OF THE TEAM  ::   \n");
        printf("\n");
        for (int j = 0; j < teams[i].num_players; j++)
        {
            printf("%d.  %s . ", j + 1, teams[i].players[j]); // FOR SHOWING THE PLAYES OF THE TEAM
            printf("\n");
        }
        printf("\n                               ----------------------------------------------------\n");
    }
}

void add_team()
{
    printf("\n\n********************************************************************************************************************************\n");

    printf("ENTER THE NAME OF THE NEW  TEAM    ::     ");
    scanf("%s", teams[num_teams].name); // FOR TAKING THE TEAM NAME AS INPUT
    printf("\n                               ----------------------------------------------------\n");

    printf("ENTER THE NUMBER OF PLAYES IN THE NEWLY ADDED TEAM  ::    ");
    scanf("%d", &teams[num_teams].num_players); // FOR TAKING THE NUMBER OF PLAYRES AS INPUT
    printf("\n                               ----------------------------------------------------\n");
    for (int i = 0; i < teams[num_teams].num_players; i++)
    {
        printf("ENTER THE NAME OF OF PLAYER %d ::  ", i + 1);
        scanf("%s", teams[num_teams].players[i]); // FOR TAKING THE PLAYERS NAME AS INPUT
    }
    num_teams++;
    printf("Team added successfully.\n");
    printf("\n\n********************************************************************************************************************************\n");
}

void delete_team()
{
    printf("\n                               ----------------------------------------------------\n");

    printf("ENTER THE NAME OF THE TEAM TO DELETE  ::   ");
    char team_name[50];
    scanf("%s", team_name); // FOR TAKING THE TEAM NAME AS STRING AS INPUT FOR DELETING
    int i;
    for (i = 0; i < num_teams; i++)
    {
        if (strcmp(teams[i].name, team_name) == 0)
        {
            break;
        }
    }
    if (i == num_teams)
    {
        printf("TEAM NOT FOUND.\n"); // IF THE INPUT DOESNOT MATCH ACCORDING TO THE EXISTING TEAMS
        return;
    }
    for (int j = i; j < num_teams - 1; j++)
    {
        teams[j] = teams[j + 1];
    }
    num_teams--;
    printf("Team deleted successfully.\n");
    printf("\n                               ----------------------------------------------------\n");
}

void update_team()
{
    printf("\n                               ----------------------------------------------------\n");

    printf("ENTER THE NAME OF THE TEAM TO UPDATE  :: ");
    char team_name[50];
    scanf("%s", team_name); // FOR TAKING INPUT WHICH TEAM DETAIS TO BE UPDATED
    printf("\n                               ----------------------------------------------------\n");

    int i;
    for (i = 0; i < num_teams; i++)
    {
        if (strcmp(teams[i].name, team_name) == 0)
        {
            break;
        }
    }
    if (i == num_teams)
    {
        printf("Team not found.\n");
        return;
    }
    printf("ENTER THE NEW NAME OF THE TEAM  ::    "); // FOR UPDATING THE NAME OF THE TEAM
    scanf("%s", teams[i].name);
    printf("\n                               ----------------------------------------------------\n");

    printf("ENTER NUMBER OF PLAYERS IN THE TEAM  ::  ");
    scanf("%d", &teams[i].num_players); // FOR UPDATING THE NUMBER OF PLAYERS OF THE TEAM

    printf("\n                               ----------------------------------------------------\n");
    for (int j = 0; j < teams[i].num_players; j++)
    {
        printf("ENTER THE NAME OF PLAYER %d : ", j + 1); // FOR UPDATING THE NAME OF THE PLAYERS OF THE TEAM
        scanf("%s", teams[i].players[j]);
    }
    printf("Team updated successfully.\n");
    printf("\n                               ----------------------------------------------------\n");
}

void generate_schedule()
{
    if (num_teams % 2 == 1)
    {
        strcpy(teams[num_teams].name, "");
        num_teams++;
    }
    int total_matches = (num_teams - 1) * 2;
    int match_index = 0;
    printf("\n                               ----------------------------------------------------\n");

    for (int i = 0; i < num_teams - 1; i++)
    {
        for (int j = i + 1; j < num_teams; j++)
        {
            if (strcmp(teams[i].name, "") == 0 || strcmp(teams[j].name, "") == 0)
                continue;
            strcpy(matches[match_index].team1, teams[i].name);
            strcpy(matches[match_index].team2, teams[j].name);
            printf("ENTER DATE FOR MATCH BETWEEN  %s AND %s (DD/MM/YYYY): ", teams[i].name, teams[j].name);
            scanf("%s", matches[match_index].date);
            match_index++;
        }
    }
    num_matches = match_index;
    printf("\n                               ----------------------------------------------------\n");
}
int main()
{
    do
    {
        printf("\n                               ----------------------------------------------------");

        printf("\n                                 This program is a type of IPL cricket simulator");

        printf("\n                               ----------------------------------------------------");
        printf("\n 1.Display all teams in IPL.");
        printf("\n 2.Add team.");
        printf("\n 3.Delete team.");
        printf("\n 4.Update team.");
        printf("\n 5.Generate schedule.");
        // printf("\n 6.Show schedule.");

        printf("\n\n********************************************************************************************************************************");
        printf("\n                               Choose any one of the above options according to yourself:");
        printf("\n\n********************************************************************************************************************************");
        printf("\n option selected :");

        int num;

        scanf("%d", &num);
        if (num > 5 && num < 1)
        {
            printf("Invalid Option.");
            return 0;
        }
        switch (num)
        {
        case 1:

            display_teams();
            break;
        case 2:

            add_team();
            break;
        case 3:

            delete_team();
            break;
        case 4:

            update_team();
            break;
        case 5:

            generate_schedule();
            break;

        default:
            printf("enter number between 1 to 5");
        }
    } while (1);

    return 0;
}