#define ELEMENT_COUNT 10

int main(void)
{
    char *s1 = "abc";
    char *s2 = "abb";
    char *s3 = "abd";
    unsigned int nbr = 3;

    printf("strlen :\n");
    printf("%s = %d\n\n", "hello", strlen("hello"));
    
    printf("strcmp :\n");
    printf("%s == %s ? : %d\n\n", s1, s2, strcmp(s1, s2));

    printf("strncmp :\n");
    printf("%s == %s (%d char) ? : %d\n", s1, "abcde", nbr, strncmp(s1, "abcde", nbr));
    printf("%s == %s (%d char) ? : %d\n", s2, "abc", nbr, strncmp(s2, "abc", nbr));
    printf("%s == %s (%d char) ? : %d\n", s3, "abc", nbr, strncmp(s3, "abc", nbr));
    printf("compare the 0 first %d\n\n", strncmp("abc", "ehehe", 0));

    printf("strcasecmp :\n");
    printf("%s == %s ? : %d\n", "hey", "HEY", strcasecmp("hey", "HEY"));
    printf("%s == %s ? : %d\n", "hey", "hey", strcasecmp("hey", "hey"));
    printf("%s == %s ? : %d\n", "heyb", "HEYa", strcasecmp("heyb", "HEYa"));
    printf("%s == %s ? : %d\n\n", "heyb", "HEYa", strcasecmp("heya", "HEYb"));

    printf("strchr :\n");
    char c = 'h';
    printf("abcdefhello -> %c : %s\n", c, strchr("abcdefhello", c));
    printf("abcdefhello -> %c : %s\n", 'z', strchr("abcdefhello", 'z'));
    printf("abcdefhello -> %c : %s\n\n", 'a', strchr("abcdefhello", 'a'));

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
    printf("haystack = %s, needle = %s -> %s\n", haystack, "not", strstr(haystack, "not"));
    printf("haystack = %s, needle = %s -> %s\n", haystack, "NULL", strstr(haystack, ""));
    printf("haystack = %s, needle = %s -> %s\n\n", "NULL", "not", strstr("", "not"));
    printf("haystack = %s, needle = %s -> %s\n\n", "NULL", "NULL", strstr("", ""));
    
    printf("strpbrk :\n");
    char *big_str = "abcdefghi";
    printf("str = %s, ok = %s -> %s\n", big_str, "a", strpbrk(big_str, "a"));
    printf("str = %s, ok = %s -> %s\n", big_str, "azu", strpbrk(big_str, "azu"));
    printf("str = %s, ok = %s -> %s\n", big_str, "o", strpbrk(big_str, "o"));
    printf("str = %s, ok = %s -> %s\n\n", big_str, "jc", strpbrk(big_str, "jc"));

    printf("memset :\n");
    int array[5] = {54, 85, 20, 63, 21};
    unsigned int size = sizeof(int) * 5;
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
    // other test
    char DuplicateString[255] = "ok";
    memset(&DuplicateString,'*',5);
    DuplicateString[50] = 0;
    printf("DuplicateString = %s\n\n",DuplicateString);

    printf("memcpy :\n");
    char *dest = strdup("noooooooo please dont aaaaaaaa\n");
    char *src = strdup("hello i am overwriting you\n");
    printf("before :\n%s%s", src, dest);
    printf("after :\n%s%s", src, memcpy(dest, src, strlen(src)));
    dest = strdup("heya\n");
    src = strdup("test\n");
    printf("before :\n%s%s", src, dest);
    printf("after :\n%s%s\n", src, memcpy(dest, src, 5));

    printf("memmove :\n");
    int data[] = {20, 30, 40, 50, 60, 70, 80, 90, 100, 0};
    for(int i = 0; i < ELEMENT_COUNT; i++)
        printf("%d ", data[i]);
    printf("\n");
    void * source = (void *) data;
    void * destination = (void *) ( data + 1 );
    unsigned int sizet = ELEMENT_COUNT * sizeof( int );
    memmove( destination, source, sizet );
    data[0] = 10;
    for( int i=0; i<ELEMENT_COUNT; i++ )
        printf( "%d ", data[i] );
    printf("\n");
    return(0);
}