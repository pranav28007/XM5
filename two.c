#include <stdio.h>
#include <string.h>

#define MAX_DIRS 10
#define MAX_SUBDIRS 10
#define MAX_FILES 20

// File Structure
struct File {
    char fname[30];
};

// Subdirectory Structure (Level 2)
struct SubDirectory {
    char subdir_name[30];
    struct File files[MAX_FILES];
    int fcount;
};

// Main Directory Structure (Level 1)
struct Directory {
    char dname[30];
    struct SubDirectory subdirs[MAX_SUBDIRS];
    int subcount;
};

int main() {
    struct Directory dir[MAX_DIRS];
    int dcount = 0;          // Number of main directories
    int choice, i, j, k;
    char dname[30], subname[30], fname[30];
    int found;

    printf("=== TWO LEVEL DIRECTORY SIMULATION ===\n");

    while (1) {
        printf("\n--- Menu ---\n");
        printf("1. Create Main Directory\n");
        printf("2. Create Subdirectory\n");
        printf("3. Create File\n");
        printf("4. Display All Directories and Files\n");
        printf("5. Search File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            // Case 1: Create Main Directory
            case 1:
                if (dcount >= MAX_DIRS) {
                    printf("Maximum directories limit reached!\n");
                    break;
                }
                printf("Enter Main Directory Name: ");
                scanf("%s", dname);
                strcpy(dir[dcount].dname, dname);
                dir[dcount].subcount = 0;
                dcount++;
                printf("Main Directory '%s' created successfully.\n", dname);
                break;

            // Case 2: Create Subdirectory
            case 2:
                printf("Enter Main Directory Name: ");
                scanf("%s", dname);
                found = 0;
                for (i = 0; i < dcount; i++) {
                    if (strcmp(dir[i].dname, dname) == 0) {
                        if (dir[i].subcount >= MAX_SUBDIRS) {
                            printf("Maximum subdirectories limit reached!\n");
                            break;
                        }
                        printf("Enter Subdirectory Name: ");
                        scanf("%s", subname);
                        strcpy(dir[i].subdirs[dir[i].subcount].subdir_name, subname);
                        dir[i].subdirs[dir[i].subcount].fcount = 0;
                        dir[i].subcount++;
                        printf("Subdirectory '%s' created in '%s'.\n", subname, dname);
                        found = 1;
                        break;
                    }
                }
                if (!found) printf("Main Directory not found.\n");
                break;

            // Case 3: Create File
            case 3:
                printf("Enter Main Directory Name: ");
                scanf("%s", dname);
                found = 0;
                for (i = 0; i < dcount; i++) {
                    if (strcmp(dir[i].dname, dname) == 0) {
                        printf("Enter Subdirectory Name: ");
                        scanf("%s", subname);
                        for (j = 0; j < dir[i].subcount; j++) {
                            if (strcmp(dir[i].subdirs[j].subdir_name, subname) == 0) {
                                if (dir[i].subdirs[j].fcount >= MAX_FILES) {
                                    printf("Maximum files limit reached!\n");
                                    break;
                                }
                                printf("Enter File Name: ");
                                scanf("%s", fname);
                                strcpy(dir[i].subdirs[j].files[dir[i].subdirs[j].fcount].fname, fname);
                                dir[i].subdirs[j].fcount++;
                                printf("File '%s' created successfully in %s/%s\n", fname, dname, subname);
                                found = 1;
                                break;
                            }
                        }
                        if (!found) printf("Subdirectory not found.\n");
                        found = 1;  // Main dir was found
                        break;
                    }
                }
                if (!found) printf("Main Directory not found.\n");
                break;

            // Case 4: Display
            case 4:
                printf("\n=== TWO LEVEL DIRECTORY STRUCTURE ===\n");
                if (dcount == 0) {
                    printf("No directories created yet.\n");
                    break;
                }
                for (i = 0; i < dcount; i++) {
                    printf("\nMain Directory: %s\n", dir[i].dname);
                    if (dir[i].subcount == 0) {
                        printf("  (No subdirectories)\n");
                        continue;
                    }
                    for (j = 0; j < dir[i].subcount; j++) {
                        printf("  └── Subdirectory: %s\n", dir[i].subdirs[j].subdir_name);
                        if (dir[i].subdirs[j].fcount == 0) {
                            printf("       (No files)\n");
                        } else {
                            for (k = 0; k < dir[i].subdirs[j].fcount; k++) {
                                printf("       └── File: %s\n", dir[i].subdirs[j].files[k].fname);
                            }
                        }
                    }
                }
                break;

            // Case 5: Search File
            case 5:
                printf("Enter File Name to Search: ");
                scanf("%s", fname);
                found = 0;
                for (i = 0; i < dcount; i++) {
                    for (j = 0; j < dir[i].subcount; j++) {
                        for (k = 0; k < dir[i].subdirs[j].fcount; k++) {
                            if (strcmp(dir[i].subdirs[j].files[k].fname, fname) == 0) {
                                printf("File '%s' found in: %s / %s\n",
                                       fname, dir[i].dname, dir[i].subdirs[j].subdir_name);
                                found = 1;
                            }
                        }
                    }
                }
                if (!found)
                    printf("File '%s' not found in any directory.\n", fname);
                break;

            // Case 6: Exit
            case 6:
                printf("Exiting program...\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

