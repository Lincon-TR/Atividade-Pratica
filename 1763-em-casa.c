#define tam 26

bool IsNice ( char *s, int comeco, int fim ) {
    char lower[tam];
    char upper[tam];
    int qtdLower[tam];
    int qtdUpper[tam];

    for ( int i = 0; i < tam; i++ ) {
        lower[i] = 'a' + i;
        upper[i] = 'A' + i;
        qtdLower[i] = 0;
        qtdUpper[i] = 0;
    }

    for ( int i = comeco; i <= fim; i++ ) {
        for ( int j = 0; j < tam; j++ ) {
            if ( s[i] == lower[j] ) {
                qtdLower[j]++;
                break;
            }
            if ( s[i] == upper[j] ) {
                qtdUpper[j]++;
                break;
            }
        }
    }

    for ( int i = 0; i < tam; i++ ) {
        if ( ( qtdUpper[i] > 0 && qtdLower[i] == 0 ) || ( qtdUpper[i] == 0 && qtdLower[i] > 0 ) ) {
            return false;
        }
    }
    return true;
}

char* longestNiceSubstring(char* s) {
    int tamanho = strlen( s );
    int atual, comeco, fim;
    int maior = 0;
    int i, j;

    for ( i = 0; i < tamanho; i++ ) {
        for ( j = 0; j < tamanho; j++ ) {
            if ( IsNice ( s, i, j ) ) {
                atual = j - i + 1;
                if ( atual > maior ) {
                    maior = atual;
                    comeco = i;
                    fim = j;
                }
            }
        }
    }
    if ( maior == 0 ) {
        return "";
    }
    char *lns = ( char * )malloc( sizeof( char ) * maior + 1 );
    j = 0;
    for ( i = comeco; i <= fim; i++ ) {
        lns[j] = s[i];
        j++;
    }
    lns[j] = '\0';
    return lns;
}