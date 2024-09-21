#include "regkey.h"

RegKey createKey(char* key_name)
{
    RegKey newKey = calloc(1, sizeof(struct Key));
    strcpy(newKey->key_name, key_name);
    return newKey;
}

void storeValue(RegKey key, char* value)
{
    strcpy(key->key_value, value);
}

void publishKey(RegKey key)
{
    int i;
    for(i=0; i< MAX_KEYS;i++)
    {
        if(key_list[i] == NULL)
        {
            key_list[i] = key;
            return;
        }
    }
}