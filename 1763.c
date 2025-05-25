#define tam 26
char* longestNiceSubstring(char* s) {
    char lower[tam];
    char upper[tam];
    char clns[strlen(s)];
    char lns[strlen(s)];
    int k = 0;
    lns[0] = '\0';

    for (int i = 0; i < tam; i++) {
        lower[i] = 'a' + i;
    }
    for (int i = 0; i < tam; i++) {
        upper[i] = 'A' + i;
    }
    
    for (int i = 0; i < tam; i++) {
        for (int j = 0; j < strlen(s); j++) {
            if (upper[i] == s[j] || lower[i] == s[j]){
                clns[k] = s[j];
                k++;
            } else {
                clns[k] = '\0';
                k=0;
                if (strlen(clns) >= strlen(lns)) {
                     strcpy(lns, clns);
                }
            }
            
        }
    }

    if (strlen(lns) == 1) {
        return "";
    } else {
        return lns;
    }
    
}
// vai de a-z, A-Z
// vai de s[0] até o final
// se a letra for igual, guarda em clns[k] e k++;, se nao for k=0 e começa uma nova letra
//  se tamanho da atual for maior que o maior, maior recebe atual