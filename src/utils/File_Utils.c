#include <File_Utils.h>
#include <unistd.h>

char *GetPath(size_t size)
{
    char *path = NULL;
    ssize_t len;

    path = (char *)malloc(size);
    if (path == NULL)
    {
        perror("Erro ao alocar memória");
        return NULL;
    }

    len = (ssize_t)getcwd(path, size);

    if (len == -1)
    {
        perror("Erro ao obter o diretório atual");
        free(path);
        return NULL;
    }

    if (len == (ssize_t)(size - 1))
    {
        free(path);
        return GetPath(size * 2);
    }

    return path;
}

char *BuildFilePath(const char *basePath, const char *fileName)
{
    char *fullPath = (char *)malloc(256);
    if (fullPath == NULL)
    {
        perror("Erro ao alocar memória para caminho de arquivo");
        return NULL;
    }

    snprintf(fullPath, 256, "%s%s", basePath, fileName);

    return fullPath;
}