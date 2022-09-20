#include <stdio.h>
#include <string.h>

// Create a struct File which represents a file with the fields (id, name, size, data)
struct File {
    int id;
    char name[63];
    unsigned int size;
    char data[1024];
    char path[1024];
};

// Create a struct Directory which represents a directory with the fields (files, directories, nf, nd, path)
struct Directory {
    struct File files[256];
    struct Directory *directories[8];
    int nd;
    int nf;
    char path[2048];
};

// add to file(struct File* file, const char* str) which overwrites the file content with the new content.
void add_to_file(struct File *file, const char *str) {
    strcpy_s(file->data, strlen(str) * sizeof(char), str);
    file->size = strlen(file->data);
}

// not mentioned in the task
void add_dir(struct Directory *dir, struct Directory *dir_to_add) {
    dir->directories[dir->nd] = dir_to_add;
    dir->nd++;
}

// append to file(struct File* file, const char* str) which appends the new content to the end of the file.
void append_to_file(struct File *file, const char *str) {
    strcat_s(file->data, strlen(str) * sizeof(char), str);
}

// pwd file(struct File* file) prints to stdout the path of the file.
void pwd_file(struct File *file) {
    printf("%s\n", file->path);
}

// add file(struct File* file, struct Directory* dir) which adds a new file to the current directory
void add_file(struct File *file, struct Directory *dir) {
    dir->files[dir->nf] = *file;
    dir->nf++;
    strcpy_s(file->path, strlen(dir->path) * sizeof(char), dir->path);
    strcat_s(file->path, strlen("/") * sizeof(char), "/");
    strcat_s(file->path, strlen(file->name) * sizeof(char), file->name);
}

int main() {
    struct Directory root, home, bin;
    struct File bash, ex3_1, ex3_2;

    // Create the root directory (/) with two subdirectories home and bin
    add_dir(&root, &home);
    add_dir(&root, &bin);
    root.nd = 2;

    strcpy_s(root.path, strlen("/") * sizeof(char), "/");
    strcpy_s(bin.path, strlen("/bin") * sizeof(char), "/bin");
    strcpy_s(home.path, strlen("/home") * sizeof(char), "/home");

    // Add a file bash to the directory bin
    bash.id = 1;
    strcat_s(bash.name, strlen("bash") * sizeof(char), "bash");

    // Add two files ex3 1.c and ex3 2.c to the directory home.
    // The file ex3 1.c contains the code: “int printf(const char * format, ...);”
    // And the file ex3 2.c contains the code: “//This is a comment in C language”
    // Add the content “Bourne Again Shell!!” to the file bash
    ex3_1.id = 2;
    strcat_s(ex3_1.name, strlen("bash") * sizeof(char), "ex3_1.c");

    ex3_2.id = 3;
    strcat_s(ex3_2.name, strlen("bash") * sizeof(char), "ex3_2.c");

    add_to_file(&ex3_1, "int printf(const char * format, ...);");
    add_to_file(&ex3_2, "//This is a comment in C language");
    add_to_file(&bash, "Bourne Again Shell!!");
    add_file(&bash, &bin);
    add_file(&ex3_1, &home);
    add_file(&ex3_2, &home);

    // Append the content “int main(){printf(”Hello World!”)}” to the file ex3 1.c
    append_to_file(&ex3_1, "int main(){printf(”Hello World!”)}");

    pwd_file(&ex3_1);
    pwd_file(&ex3_2);
    pwd_file(&bash);

    return 0;
}
