#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void listFilesAndDirs() {
    system("ls -l");
}

void createNewFile() {
    int choice;
    char filename[100];
    
    printf("Select file type:\n1- .c\n2- .sh\n3- .txt\nEnter choice: ");
    scanf("%d", &choice);
    
    printf("Enter file name (without extension): ");
    scanf("%s", filename);

    if (choice == 1)
        strcat(filename, ".c");
    else if (choice == 2)
        strcat(filename, ".sh");
    else if (choice == 3)
        strcat(filename, ".txt");
    else {
        printf("Invalid choice!\n");
        return;
    }

    FILE *fp = fopen(filename, "w");
    if (fp) {
        printf("File '%s' created successfully.\n", filename);
        fclose(fp);
    } else {
        printf("Failed to create file.\n");
    }
}

void deleteFile() {
    char filename[100];
    printf("Enter file name (with extension) to delete: ");
    scanf("%s", filename);
    
    if (remove(filename) == 0)
        printf("File '%s' deleted successfully.\n", filename);
    else
        printf("File not found.\n");
}

void renameFile() {
    char oldname[100], newname[100];
    printf("Enter current file name (with extension): ");
    scanf("%s", oldname);
    printf("Enter new file name (with extension): ");
    scanf("%s", newname);
    
    if (rename(oldname, newname) == 0)
        printf("File renamed to '%s'.\n", newname);
    else
        printf("File rename failed. Check if the file exists.\n");
}

void editFile() {
    char filename[100];
    printf("Enter file name (with extension) to edit: ");
    scanf("%s", filename);
    
    char command[150];
    snprintf(command, sizeof(command), "nano %s", filename);
    system(command);
}

void searchFile() {
    char filename[100];
    printf("Enter file name to search: ");
    scanf("%s", filename);

    char command[150];
    snprintf(command, sizeof(command), "find . -name \"%s\"", filename);
    system(command);
}

void fileDetails() {
    char filename[100];
    printf("Enter file name (with extension) to get details: ");
    scanf("%s", filename);

    char command[150];
    snprintf(command, sizeof(command), "stat %s", filename);
    system(command);
}

void viewFileContent() {
    char filename[100];
    printf("Enter file name (with extension) to view content: ");
    scanf("%s", filename);

    char command[150];
    snprintf(command, sizeof(command), "cat %s", filename);
    system(command);
}

void sortFileContent() {
    char filename[100];
    printf("Enter file name (with extension) to sort content: ");
    scanf("%s", filename);

    char command[150];
    snprintf(command, sizeof(command), "sort %s", filename);
    system(command);
}

void listDirectories() {
    system("ls -d */");
}

void countDirectories() {
    system("echo */ | wc -w");
}

void countFiles() {
    system("ls -l | grep -v '^d' | wc -l");
}

void sortFilesInDir() {
    system("ls | sort");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=================================================================\n");
        printf("--------------------- File Management System --------------------\n");
        printf("=================================================================\n");
        printf("1- List all Files and Directories\n");
        printf("2- Create New Files\n");
        printf("3- Delete Existing Files\n");
        printf("4- Rename Files\n");
        printf("5- Edit File Content\n");
        printf("6- Search Files\n");
        printf("7- Details of a Particular File\n");
        printf("8- View Content of File\n");
        printf("9- Sort File Content\n");
        printf("10- List only Directories\n");
        printf("11- Count Number of Directories\n");
        printf("12- Count Number of Files\n");
        printf("13- Sort Files in Directory\n");
        printf("0- Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: listFilesAndDirs(); break;
            case 2: createNewFile(); break;
            case 3: deleteFile(); break;
            case 4: renameFile(); break;
            case 5: editFile(); break;
            case 6: searchFile(); break;
            case 7: fileDetails(); break;
            case 8: viewFileContent(); break;
            case 9: sortFileContent(); break;
            case 10: listDirectories(); break;
            case 11: countDirectories(); break;
            case 12: countFiles(); break;
            case 13: sortFilesInDir(); break;
            case 0: printf("Exiting... Goodbye!\n"); return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}