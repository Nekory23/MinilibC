#include <string.h>
#include <stdio.h>

void main(void)
{
    printf("strlen :\n");
    printf("len of %s = %d\n", "hello there", strlen("hello there"));
    printf("len of %s = %d\n", "hello\\n\\tthere", strlen("hello\n\tthere"));
    printf("len of %s = %d\n\n", "", strlen(""));

    printf("strcmp :\n");
    printf("%s == %s ? : %d\n", "hey", "hey", strcmp("hey", "hey"));
    printf("%s == %s ? : %d\n", "heyb", "heya", strcmp("heyb", "heya"));
    printf("%s == %s ? : %d\n\n", "heyb", "heya", strcmp("heya", "heyb"));

    printf("strncmp :\n");
    printf("%s == %s ? : %d\n", "hey", "hey", strncmp("heya", "heyaaaaa", 4));
    printf("%s == %s ? : %d\n", "heyb", "heya", strncmp("heyb", "heya", 4));
    printf("%s == %s ? : %d\n\n", "heyb", "heya", strncmp("heya", "heyb", 4));

    printf("strcasecmp :\n");
    printf("%s == %s ? : %d\n", "hey", "HEY", strcasecmp("hey", "HEY"));
    printf("%s == %s ? : %d\n", "hey", "hey", strcasecmp("hey", "hey"));
    printf("%s == %s ? : %d\n", "heyb", "HEYa", strcasecmp("heyb", "HEYa"));
    printf("%s == %s ? : %d\n\n", "heyb", "HEYa", strcasecmp("heya", "HEYb"));

    printf("strchr :\n");
    printf("abcdef -> %c : %s\n", 'a', strchr("abcdef", 'a'));
    printf("abcdef -> %c : %s\n", 'c', strchr("abcdef", 'c'));
    printf("abcdef -> %c : %s\n\n", 'z', strchr("abcdef", 'z'));

    printf("strcspn :\n");
    char *s = "hellothereyou";
    printf("strlen s = %d\n", strlen(s));
    printf("%s, ok = %s = %d\n", s, "u", strcspn(s, "u"));
    printf("%s, ok = %s = %d\n", s, "h", strcspn(s, "h"));
    printf("%s, ok = %s = %d\n", s, "z", strcspn(s, "z"));
    printf("%s, ok = %s = %d\n\n", s, "t", strcspn(s, "t"));

    printf("rindex :\n");
    char *str2 = "abcdefedcba";
    printf("%s -> %c : %s\n", str2, 'c', rindex(str2, 'c'));
    printf("%s -> %c : %s\n", str2, 'a', rindex(str2, 'a'));
    printf("%s -> %c : %s\n", str2, 'f', rindex(str2, 'f'));
    printf("%s -> %c : %s\n\n", str2, '\0', rindex(str2, '\0'));

    printf("strstr :\n");
    char *haystack = "this is a sentence to find a word";
    printf("haystack = %s, needle = %s -> %s\n", haystack, "t", strstr(haystack, "t"));
    printf("haystack = %s, needle = %s -> %s\n", haystack, "i", strstr(haystack, "i"));
    printf("haystack = %s, needle = %s -> %s\n", haystack, "this", strstr(haystack, "this"));
    printf("haystack = %s, needle = %s -> %s\n", haystack, "to", strstr(haystack, "to"));
    printf("haystack = %s, needle = %s -> %s\n", haystack, "word", strstr(haystack, "word"));
    printf("haystack = %s, needle = %s -> %s\n\n", haystack, "not", strstr(haystack, "not"));

    printf("strpbrk :\n");
    char *big_str = "abcdefghi";
    printf("str = %s, ok = %s -> %s\n", big_str, "a", strpbrk(big_str, "a"));
    printf("str = %s, ok = %s -> %s\n", big_str, "azu", strpbrk(big_str, "azu"));
    printf("str = %s, ok = %s -> %s\n", big_str, "o", strpbrk(big_str, "o"));
    printf("str = %s, ok = %s -> %s\n\n", big_str, "jc", strpbrk(big_str, "jc"));

    printf("memset :\n");
    int array[5] = {54, 85, 20, 63, 21};
    size_t size = sizeof(int) * 5;
    int length;
    printf("before :");
    for(length = 0; length < 5; length++)
        printf("%d ", array[length]);
    printf("\n");
    printf("after :");
    memset(array, 0, size);
    for(length = 0; length < 5; length++)
        printf("%d ", array[length]);
    printf("\n");
    
    char DuplicateString[255] = "ok";
    memset(&DuplicateString,'*',50);
    DuplicateString[50] = 0;
    printf("DuplicateString = %s\n\n",DuplicateString);

    printf("memcpy :\n");
    char *dest = strdup("noooooooo please dont aaaaaaaa\n");
    char *src = strdup("hello i am overwriting you\n");
    printf("before :\n%s%s", src, dest);
    printf("after :\n%s%s", src, memcpy(dest, src, strlen(src)));
}
