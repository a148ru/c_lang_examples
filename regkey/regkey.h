#include <strings.h>
#include <stdlib.h>

#define STRING_SIZE 100
#define MAX_KEYS 40

struct Key
{
    char key_name[STRING_SIZE];
    char key_value[STRING_SIZE];
};

/* глобальный на уровне файла массив, содержащий все разделы реестра */
static struct Key* key_list[MAX_KEYS];

/* Описатель раздела реестра */
typedef struct Key* RegKey;

/* Создать новый раздел реестра с именем key_name */
RegKey createKey(char* key_name);

/* Сохранить значение value в раздел с именем key */
void storeValue(RegKey key, char* value);

/* Сделать раздел доступным для чтения */
void publishKey(RegKey key);