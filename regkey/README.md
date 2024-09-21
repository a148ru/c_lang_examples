## Пример реестр


### API реестра
```c
/* Описатель раздела реестра */
typedef struct Key* RegKey;

/* Создать новый раздел реестра с именем key_name */
RegKey createKey(char* key_name);

/* Сохранить значение value в раздел с именем key */
void storeValue(RegKey key, char* value);

/* Сделать раздел доступным для чтения */
void publishKey(RegKey key);
```
