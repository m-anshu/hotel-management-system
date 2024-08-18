#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct customer
{
    int id;
    char password[50];
    char name[50];
    char number[11];
    int bill;
    struct customer *left;
    struct customer *right;
};

struct chef
{
    char Name[50];
    char password[50];
    int phno;
    int UID;
    struct chef *left;
    struct chef *right;
};

struct receptionist
{
    char Name[50];
    char password[50];
    int phno;
    int UID;
    struct receptionist *left;
    struct receptionist *right;
};

struct manager
{
    char Name[50];
    char password[50];
    int phno;
    int UID;
    struct manager *left;
    struct manager *right;
};

struct customer *cus = NULL;
struct chef *chf = NULL;
struct receptionist *rcp = NULL;
struct manager *mng = NULL;

struct customer *findUser(struct customer *cus, int id)
{
    while (cus != NULL)
    {
        if (id < cus->id)
        {
            cus = cus->left;
        }
        else if (id > cus->id)
        {
            cus = cus->right;
        }
        else
        {
            return cus; // User found
        }
    }
    return NULL; // User not found
}

/*int check_csv_for_phone_number(char* filename, char* phone_number) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        char* token = strtok(line, ",");
        if (strcmp(token, phone_number) == 0) {
            fclose(fp);
            return 1;
        }
    }

    fclose(fp);
    return 0;
}*/

/*int rooms[NUM_ROOMS] = {0};

int is_room_available(int room_number) {
    if (room_number < 1 || room_number > NUM_ROOMS) {
        printf("Error: invalid room number\n");
        return -1;
    }

    if (rooms[room_number - 1] == 0) {
        printf("Room %d is available\n", room_number);
        return 1;
    } else {
        printf("Room %d is already in use\n", room_number);
        return 0;
    }
}*/

struct customer *insert(struct customer *cus, int id, const char password[], const char name[], const char number[], int bill)
{
    if (cus == NULL)
    {
        struct customer *newNode = (struct customer *)malloc(sizeof(struct customer));
        newNode->id = id;
        strncpy(newNode->password, password, 50);
        strncpy(newNode->name, name, 50);
        strncpy(newNode->number, number, 11);
        newNode->bill = bill;
        newNode->left = newNode->right = NULL;
        return newNode;
    }

    if (id < cus->id)
    {
        cus->left = insert(cus->left, id, password, name, number, bill);
    }
    else if (id > cus->id)
    {
        cus->right = insert(cus->right, id, password, name, number, bill);
    }

    return cus;
}

struct chef *findChef(struct chef *chf, int UID)
{
    while (chf != NULL)
    {
        if (UID < chf->UID)
        {
            chf = chf->left;
        }
        else if (UID > chf->UID)
        {
            chf = chf->right;
        }
        else
        {
            return chf; // Chef found
        }
    }
    return NULL; // Chef not found
}

struct chef *insertChef(struct chef *chf, int UID, const char Name[], const char password[], int phno)
{
    if (chf == NULL)
    {
        struct chef *newChef = (struct chef *)malloc(sizeof(struct chef));
        newChef->UID = UID;
        strncpy(newChef->Name, Name, 50);
        strncpy(newChef->password, password, 50);
        newChef->phno = phno;
        newChef->left = newChef->right = NULL;
        return newChef;
    }

    if (UID < chf->UID)
    {
        chf->left = insertChef(chf->left, UID, Name, password, phno);
    }
    else if (UID > chf->UID)
    {
        chf->right = insertChef(chf->right, UID, Name, password, phno);
    }

    return chf;
}

struct receptionist *findReceptionist(struct receptionist *rcp, int UID)
{
    while (rcp != NULL)
    {
        if (UID < rcp->UID)
        {
            rcp = rcp->left;
        }
        else if (UID > rcp->UID)
        {
            rcp = rcp->right;
        }
        else
        {
            return rcp; // Receptionist found
        }
    }
    return NULL; // Receptionist not found
}

struct receptionist *insertReceptionist(struct receptionist *rcp, int UID, const char Name[], const char password[], int phno)
{
    if (rcp == NULL)
    {
        struct receptionist *newReceptionist = (struct receptionist *)malloc(sizeof(struct receptionist));
        newReceptionist->UID = UID;
        strncpy(newReceptionist->Name, Name, 50);
        strncpy(newReceptionist->password, password, 50);
        newReceptionist->phno = phno;
        newReceptionist->left = newReceptionist->right = NULL;
        return newReceptionist;
    }

    if (UID < rcp->UID)
    {
        rcp->left = insertReceptionist(rcp->left, UID, Name, password, phno);
    }
    else if (UID > rcp->UID)
    {
        rcp->right = insertReceptionist(rcp->right, UID, Name, password, phno);
    }

    return rcp;
}

struct manager *findManager(struct manager *mng, int UID)
{
    while (mng != NULL)
    {
        if (UID < mng->UID)
        {
            mng = mng->left;
        }
        else if (UID > mng->UID)
        {
            mng = mng->right;
        }
        else
        {
            return mng; // Manager found
        }
    }
    return NULL; // Manager not found
}

struct manager *insertManager(struct manager *mng, int UID, const char Name[], const char password[], int phno)
{
    if (mng == NULL)
    {
        struct manager *newManager = (struct manager *)malloc(sizeof(struct manager));
        newManager->UID = UID;
        strncpy(newManager->Name, Name, 50);
        strncpy(newManager->password, password, 50);
        newManager->phno = phno;
        newManager->left = newManager->right = NULL;
        return newManager;
    }

    if (UID < mng->UID)
    {
        mng->left = insertManager(mng->left, UID, Name, password, phno);
    }
    else if (UID > mng->UID)
    {
        mng->right = insertManager(mng->right, UID, Name, password, phno);
    }

    return mng;
}

void importfromcus(const char *filename, struct customer **cus)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        int id, bill;
        char password[50], name[50], number[11];
        if (sscanf(line, "%d,%49[^,],%49[^,],%10[^,],%d", &id, password, name, number, &bill) == 5)
        {
            *cus = insert(*cus, id, password, name, number, bill);
        }
        else
        {
            printf("Error parsing line: %s\n");
        }
    }

    fclose(file);
}

void importChefDataFromCSV(const char *filename, struct chef **chf)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        int UID, phno;
        char Name[50], password[50];
        if (sscanf(line, "%d,%49[^,],%49[^,],%d", &UID, Name, password, &phno) == 4)
        {
            *chf = insertChef(*chf, UID, Name, password, phno);
        }
        else
        {
            printf("Error parsing line: %s\n");
        }
    }

    fclose(file);
}

void importReceptionistDataFromCSV(const char *filename, struct receptionist **rcp)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        int UID, phno;
        char Name[50], password[50];
        if (sscanf(line, "%d,%49[^,],%49[^,],%d", &UID, Name, password, &phno) == 4)
        {
            *rcp = insertReceptionist(*rcp, UID, Name, password, phno);
        }
        else
        {
            printf("Error parsing line: %s\n");
        }
    }

    fclose(file);
}

void importManagerDataFromCSV(const char *filename, struct manager **mng)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Failed to open file.\n");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), file))
    {
        int UID, phno;
        char Name[50], password[50];
        if (sscanf(line, "%d,%49[^,],%49[^,],%d", &UID, Name, password, &phno) == 4)
        {
            *mng = insertManager(*mng, UID, Name, password, phno);
        }
        else
        {
            printf("Error parsing line: %s\n");
        }
    }

    fclose(file);
}
/*int rooms[NUM_ROOMS] = {0};

void get_booked_rooms(int* booked_rooms, int* num_booked_rooms) {
    int i;
    *num_booked_rooms = 0;
    for (i = 0; i < NUM_ROOMS; i++) {
        if (rooms[i] == 1) {
            booked_rooms[*num_booked_rooms] = i + 1;
            (*num_booked_rooms)++;
        }
    }
}*/

int authenticate(struct customer *root, int id, const char password[])
{
    while (root != NULL)
    {
        if (id < root->id)
        {
            root = root->left;
        }
        else if (id > root->id)
        {
            root = root->right;
        }
        else
        {
            if (strcmp(password, root->password) == 0)
            {
                return 1; // Authentication successful
            }
            return 0; // Password doesn't match
        }
    }
    return 0; // User not found
}

int authenticateChef(struct chef *chf, int UID, const char password[])
{
    while (chf != NULL)
    {
        if (UID < chf->UID)
        {
            chf = chf->left;
        }
        else if (UID > chf->UID)
        {
            chf = chf->right;
        }
        else
        {
            if (strcmp(password, chf->password) == 0)
            {
                return 1; // Authentication successful
            }
            return 0; // Password doesn't match
        }
    }
    return 0; // Chef not found
}

int authenticateReceptionist(struct receptionist *rcp, int UID, const char password[])
{
    while (rcp != NULL)
    {
        if (UID < rcp->UID)
        {
            rcp = rcp->left;
        }
        else if (UID > rcp->UID)
        {
            rcp = rcp->right;
        }
        else
        {
            if (strcmp(password, rcp->password) == 0)
            {
                return 1; // Authentication successful
            }
            return 0; // Password doesn't match
        }
    }
    return 0; // Receptionist not found
}

int authenticateManager(struct manager *mng, int UID, const char password[])
{
    while (mng != NULL)
    {
        if (UID < mng->UID)
        {
            mng = mng->left;
        }
        else if (UID > mng->UID)
        {
            mng = mng->right;
        }
        else
        {
            if (strcmp(password, mng->password) == 0)
            {
                return 1; // Authentication successful
            }
            return 0; // Password doesn't match
        }
    }
    return 0; // Manager not found
}
        

int aunthenticate_all(int UID, char pwd[50])
{
    system("cls");
    printf("--------------------------------------------------------------------\n");
    printf("                           PROFILE PAGE\n");
    printf("--------------------------------------------------------------------\n");
    if (UID / 10000 == 1)
    {
        importfromcus("customer1.csv", &cus);
        if (authenticate(cus, UID, pwd))
        {
            printf("Authentication successful.\nYour details:\n");
            struct customer *user = findUser(cus, UID);
            if (user != NULL)
            {
                printf("ID: %d\n", user->id);
                printf("Name: %s\n", user->name);
                printf("Number: %s\n", user->number);
                printf("Bill: %d\n", user->bill);
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else if (UID / 10000 == 2)
    {
        importChefDataFromCSV("chef.csv", &chf);

        if (authenticateChef(chf, UID, pwd))
        {
            printf("Authentication successful.\nYour details:\n");
            struct chef *user = findChef(chf, UID);
            if (user != NULL)
            {
                printf("UID: %d\n", user->UID);
                printf("Name: %s\n", user->Name);
                printf("Number: %d\n", user->phno);
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else if (UID / 10000 == 3)
    {
        importReceptionistDataFromCSV("receptionist.csv", &rcp);

        if (authenticateReceptionist(rcp, UID, pwd))
        {
            printf("Authentication successful.\nYour details:\n");
            struct receptionist *user = findReceptionist(rcp, UID);
            if (user != NULL)
            {
                printf("UID: %d\n", user->UID);
                printf("Name: %s\n", user->Name);
                printf("Number: %d\n", user->phno);
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 0;
        }
    }
    else if (UID / 10000 == 4)
    {

        importManagerDataFromCSV("manager.csv", &mng);
        if (authenticateManager(mng, UID, pwd))
        {
            printf("Authentication successful.\nYour details:\n");
            struct manager *user = findManager(mng, UID);
            if (user != NULL)
            {
                printf("UID: %d\n", user->UID);
                printf("Name: %s\n", user->Name);
                printf("Number: %d\n", user->phno);
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else
    return 0;
}

void Login(int UID, char pwd[])
{
    while (1)
    {
        system("cls");
        printf("------------------------------------------------------------------------------\n");
        printf("                    WELCOME TO HOTEL CASABLANCA\n");
        printf("------------------------------------------------------------------------------\n");
        printf("------------------------------------------------------------------------------\n");
        printf("                    HOTEL LOGIN PAGE\n");
        printf("------------------------------------------------------------------------------\n");
        int a;
        if (a == 1)
            printf("Failed to Authenticate. Please Try Again\n");
        printf("->Enter User ID\n");
        scanf("%d", &UID);
        printf("->Enter Password\n");
        scanf("%s", pwd); 

        if (!aunthenticate_all(UID, pwd))
        {
            a = 1;
            continue;
        }
        else
        {
            a = 0;
            break;
        }
    }
}

int main()
{
    int UID;
    char pwd[50];

    Login(UID, pwd);

    return 0;
}