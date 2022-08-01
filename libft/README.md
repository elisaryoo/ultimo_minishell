##Lista de funções

| Funções Libc | Funções adicionais | Funções de bônus | Funções Pessoais |
| ----------- |  ----------- |  ----------- | ----------- |
[ft_memset](#ft_memset) | [ft_substr](#ft_substr) | [ft_lstnew](#ft_lstnew) | [ft_islower](#ft_islower)
[ft_bzero](#ft_bzero) | [ft_strjoin](#ft_strjoin) | [ft_lstadd_front](#ft_lstadd_front) | [ft_isupper](#ft_isupper)
[ft_memcpy](#ft_memcpy) | [ft_strtrim](#ft_strjoin) | [ft_lstsize](#ft_lstsize) | [ft_isspace](#ft_isspace)
[ft_memccpy](#ft_memccpy) | [ft_split](#ft_split) | [ft_lstlast](#ft_lstlast) | [ft_strndup](#ft_strndup)
[ft_memmove](#ft_memmove) | [ft_itoa](#ft_itoa) | [ft_lstadd_back](#ft_lstadd_back) | [ft_strcdup](#ft_strcdup)
[ft_memchr](#ft_memchr) | [ft_strmapi](#ft_strmapi) | [ft_lstdelone](#ft_lstdelone) |
[ft_memcmp](#ft_memcmp) | [ft_putchar_fd](#ft_putchar_fd) | [ft_lstclear](#ft_lstclear) |
[ft_strlen](#ft_strlen) | [ft_putstr_fd](#ft_putstr_fd) | [ft_lstiter](#ft_lstiter) |
[ft_strdup](#ft_strdup) | [ft_putendl_fd](#ft_putendl_fd) | [ft_lstmap](#ft_lstmap) |
[ft_strcpy](#ft_strcpy) | [ft_putnbr_fd](#ft_putnbr_fd) | |
[ft_strlcpy](#ft_strlcpy) | | |
[ft_strcat](#ft_strcat) | | |
[ft_strlcat](#ft_strlcat) | | |
[ft_strchr](#ft_strchr) | | |
[ft_strrchr](#ft_strrchr) | | |
[ft_strstr](#ft_strstr) | | |
[ft_strnstr](#ft_strnstr) | | |
[ft_strcmp](#ft_strcmp) | | |
[ft_strncmp](#ft_strncmp) | | |
[ft_atoi](#ft_atoi) | | |
[ft_isalpha](#ft_isalpha) | | |
[ft_isdigit](#ft_isdigit) | | |
[ft_isalnum](#ft_isalnum) | | |
[ft_isascii](#ft_isascii) | | |
[ft_isprint](#ft_isprint) | | |
[ft_toupper](#ft_toupper) | | |
[ft_tolower](#ft_tolower) | | |
[ft_calloc](#ft_calloc) | | |

##[ft_memset](libft / ft_memset.c)

`void * ft_memset(void * s, int c, size_t len)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno | | |
| -----------| -----------| -----------| -----------| -----------|
Preencher com bytes "len" de "c" a memória de "s" | A string na qual operar | Valor c(convertido para um caractere sem sinal) | O número de bytes | Um ponteiro para a área de memória s

##[ft_bzero](libft / ft_bzero.c)

`void * ft_bzero(void * s, size_t n)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Apaga os dados nos "n" bytes da memória começando na localização apontada por "s" escrevendo zeros | A string na qual operar | O número de bytes | Nenhum |

 ##[ft_memcpy](libft / ft_memcpy.c)

`void * ft_memcpy(void * dst, const void * src, size_t n)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno | |
| ----------- | ----------- | ----------- | ----------- | -----------|  
| Copia n bytes da área de memória src para a memória de dst. As áreas de memória não devem se sobrepor. Use [ft_memmove](#ft_memmove) se as áreas de memória se sobrepõem. Área de memória dst | Área de memória src | O número de bytes | Um ponteiro para a área de memória dst |

 ##[ft_memccpy](libft / ft_memccpy.c)

`void * ft_memccpy(void * dst, const void * src, int c, size_t n)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Param. #4 | Valor de retorno | |
| ----------- | ----------- | ----------- | ----------- | ----------- | -----------|  
| Copia n bytes da área de memória src para a área de memória dst, parando quando o caractere c é encontrado ou depois que n caracteres são copiados, o que ocorrer primeiro. Se a cópia ocorrer entre objetos que se sobrepõem, o comportamento é indefinido. Área de memória dst | Área de memória src | Um personagem para pesquisar | Número de bytes que memccpy() copiou | Um ponteiro para o próximo caractere em dst após c, ou NULL se c não foi encontrado nos primeiros n bytes |

##[ft_memmove](libft / ft_memmove.c)

`void * ft_memmove(void * dst, const void * src, size_t len)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno | |
| ----------- | ----------- | ----------- | ----------- | -----------|  
| Copia len bytes da memória de src para dst. As memórias podem se sobrepor. Primeiro, os bytes em src são copiados em uma matriz temporária e, em seguida, em dst. Área de memória dst | Arco de ares de memória | O número de bytes | Um ponteiro para a área de memória dst |

 ##[ft_memchr](libft / ft_memchr.c)

`void * ft_memchr(const void * s, int c, size_t n)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno | |
| ----------- | ----------- | ----------- | ----------- | -----------|  
| Verifica os n bytes iniciais de s para a primeira instância de c | Área de memória s | Um personagem para pesquisar | O número de bytes | Um ponteiro para o byte correspondente ou NULL se o caractere não ocorrer na área de memória fornecida |

 ##[ft_memcmp](libft / ft_memcmp.c)

`void * ft_memcmp(void * dst, const void * src, size_t n)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno
| ----------- | ----------- | ----------- | ----------- | -----------|  
Compara a string de bytes s1 com a string de bytes s2 | Memory area s1 | Área de memória s2 | O número de bytes | <0 se s1 for menor que s2,> 0 se s1 for maior que s2, = 0 se s1 for igual a s2 |

##[ft_strlen](libft / ft_strlen.c)
`size_t ft_strlen(const char * s)`

| Descrição Param. #1 | Valores Retornados |
| ----------- | ----------- | -----------|  
| Calcula o comprimento da string apontada por s, excluindo o byte nulo final('\ 0') | A string a calcular | Número de caracteres na string apontada por s |

##[ft_strdup](libft / ft_strdup.c)
`char * ft_strdup(const char * s))`

| Descrição Param. #1 | Valores Retornados |
| ----------- | ----------- | -----------|  
| String duplicada s1. A memória para a nova string é obtida com malloc e pode ser liberada com free | A string a duplicar | Um ponteiro para a string duplicada. NULL se não houver memória suficiente disponível |

##[ft_strndup](libft / ft_strndup.c)

`char * ft_strndup(const char * s, size_t n)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Aloca uma quantidade específica de memória para copiar uma string | A string a ser copiada | A quantidade máxima de caracteres a serem copiados da string | Um ponteiro para a nova string |

##[ft_strcdup](libft / ft_strcdup.c)

`char * ft_strcdup(const char * s, int c)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Aloca uma quantidade específica de memória para copiar uma string até a ocorrência de c. Exemplo| ft_strcdup("Blue", 'u') -> "Bl" | A string a ser copiada antes de c | O personagem c | Um ponteiro para a nova string |

##[ft_strchr](libft / ft_strchr.c)

`char * ft_strchr(const char * s, int c)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Localiza a primeira ocorrência de 'c' na string apontada por 's'. O caractere nulo de terminação é considerado parte da string, portanto, se 'c' for '\ 0', localiza a terminação '\ 0' | Ponteiro para string | Personagem a ser localizada | Um ponteiro para a primeira ocorrência do caractere c na string ou NULL se o caractere não for encontrado | |

##[ft_strrchr](libft / ft_strrchr.c)

`char * ft_strrchr(const char * s, int c)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Localiza a última ocorrência de 'c' na string apontada por 's'. O caractere nulo de terminação é considerado parte da string, portanto, se 'c' for '\ 0', localiza a terminação '\ 0' | Ponteiro para string | Personagem a ser localizada | Um ponteiro para a última ocorrência do caractere c na string ou NULL se o caractere não for encontrado | |

##[ft_strcpy](libft / ft_strcpy.c)

`char * ft_strcpy(char * dst, const char * src)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Copie uma string, incluindo o byte nulo de terminação('\ 0') | Matriz de destino | | String a ser copiada | Um ponteiro para a string de destino dst |

##[ft_strlcpy](libft / ft_strlcpy.c)

`size_t ft_strlcpy(char * dst, const char * src, size_t dstsize)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno | |
| ----------- | ----------- | ----------- | ----------- | -----------|  
| Copia até dstsize - 1 caractere da string terminada em NUL src para dst, terminando em NUL o resultado | | Matriz de destino | | String a ser copiada | Número de caracteres a serem copiados do src | Comprimento total da string a ser criada(comprimento de src) |

##[ft_strcat](libft / ft_strcat.c)

`char * ft_strcpy(char * dst, const char * src)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Concatene duas strings(acrescente s2 a s1), incluindo o byte nulo de terminação('\ 0') | Matriz de destino | | String a ser anexada a dst | Um ponteiro para a string resultante dst |

##[ft_strlcat](libft / ft_strlcat.c)

`size_t ft_strlcat(char * dst, const char * src, size_t size)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno | |
| ----------- | ----------- | ----------- | ----------- | -----------|  
| Concatene a string src ao final de dst. Ele irá concatenar no máximo o tamanho - strlen(dst) - 1 bytes, finalizando o resultado em NUL | Matriz de destino | | String a ser anexada a dst | Número máximo de caracteres a serem acrescentados | O comprimento inicial de dst mais o comprimento de src |

##[ft_strstr](libft / ft_strstr.c)

`char * ft_strstr(const char * haystack, const char * needle)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Localize a substring. Encontra a primeira ocorrência da substring 'agulha' na string 'palheiro'. Os bytes nulos de terminação('\ 0') não são comparados | String a ser verificada | O pequeno fio a ser pesquisado no fio do palheiro | | Um ponteiro para o início da substring localizada. NULL se a substring não for encontrada. Se 'agulha' é uma corda vaziag, 'haystack' é retornado | |

##[ft_strnstr](libft / ft_strnstr.c)

`char * ft_strnstr(const char * haystack, const char * needle, size_t len)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno | |
| ----------- | ----------- | ----------- | ----------- | -----------|  
| Localize a substring, onde não mais do que caracteres 'len' são pesquisados. Encontra a primeira ocorrência da substring 'agulha' na string 'palheiro'. Os bytes nulos de terminação('\ 0') não são comparados. | String a ser verificada | A pequena string a ser pesquisada na string 'palheiro' | A quantidade máxima de caracteres a serem pesquisados ​​| Um ponteiro para o primeiro caractere da primeira ocorrência de pouco é retornado. NULL se a substring não for encontrada. Se 'agulha' é uma string vazia, 'palheiro' é retornado | |

##[ft_atoi](libft / ft_atoi.c)

`int ft_atoi(const char * str)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Converta uma string em um inteiro | | A string a ser convertida em int | O valor convertido | |

##[ft_isalpha](libft / ft_isalpha.c)

`int ft_isalpha(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Verifique se há um caractere alfabético, é equivalente a([ft_isupper](#ft_isupper)(c) ou [ft_islower](#ft_islower)(c)) | O personagem a ser testado | | 0 se o caractere for falso e 1 se o caractere for verdadeiro | |

##[ft_isdigit](libft / ft_isdigit.c)

`int ft_isdigit(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Verifique se há um dígito(0 a 9) | O personagem a ser testado | | 0 se o caractere for falso e 1 se o caractere for verdadeiro | |

##[ft_isalnum](libft / ft_isalnum.c)

`int ft_isalnum(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Verifique se há um caractere alfanumérico; é equivalente a([ft_isalpha](#ft_isalpha) ou [ft_isdigit](#ft_isdigit)) | O personagem a ser testado | | 0 se o caractere for falso e 1 se o caractere for verdadeiro | |

##[ft_isascii](libft / ft_isascii.c)

`int ft_isascii(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Verifica se há um caractere ASCII, que é qualquer caractere entre 0 e octal 0177, inclusive | O personagem a ser testado | | 0 se o caractere for falso e 1 se o caractere for verdadeiro | |

##[ft_isprint](libft / ft_isprint.c)

`int ft_isprint(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Verifica se há qualquer caractere imprimível, incluindo espaço | | O personagem a ser testado | | 0 se o caractere for falso e 1 se o caractere for verdadeiro | |

##[ft_toupper](libft / ft_toupper.c)

`int ft_toupper(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Se o caractere passado como argumento estiver em minúsculas, converta em maiúsculas | O personagem a ser convertido | | Se c for uma letra minúscula, retorna seu equivalente em maiúscula. Caso contrário, ele retorna c.|

##[ft_tolower](libft / ft_tolower.c)

`int ft_tolower(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Se o caractere passado como argumento for maiúsculo, converta para minúsculo | | O personagem a ser convertido | | Se c for uma letra maiúscula, retorna seu equivalente em minúsculas. Caso contrário, ele retorna c. |

##[ft_calloc](libft / ft_calloc.c)

`void * ft_calloc(size_t count, size_t size)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Aloca espaço suficiente para objetos de contagem que são bytes de tamanho de memória cada e retorna um ponteiro para a memória alocada. A memória alocada é preenchida com bytes de valor zero | | Número de elementos a serem atribuídos | Tamanho dos elementos | Um ponteiro para a memória alocada ou NULL se a solicitação falhar |

##[ft_substr]
`char * ft_substr(char const * s, unsigned int start, size_t len)`

| Descrição Param. #1 | Param. #2 | Param. #3 | Valor de retorno | |
| ----------- | ----------- | ----------- | ----------- | -----------|  
| Aloca(com malloc) e retorna uma substring da string fornecida no argumento. A substring começa no índice 'start' e tem tamanho máximo 'len' | A string a partir da qual cria a substring | O índice inicial da substring na string | O comprimento máximo da substring | A substring. NULL se a alocação falhar |

##[ft_strjoin]

`char * ft_strjoin(char const * s1, char const * s2)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Aloca(com malloc) e retorna uma nova string, resultado da concatenação de s1 e s2 | A string de prefixo | | A string de sufixo | | A nova string. NULL se a alocação falhar |

##[ft_strtrim]

`char * ft_strjoin(char const * s1, char const * s2)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Aloca(com malloc) e retorna uma cópia do stanel fornecido como argumento sem os caracteres especificados no argumento definido no início e no final da string | A string a ser aparada | O conjunto de referência de caracteres a aparar | A corda aparada. NULL se a alocação falhar |

##[ft_strsplit]

`char ** ft_split(char const * s, char c)`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Aloca(com malloc) e retorna uma matriz de strings obtida pela divisão de s usando o caractere 'c' como delimitador. A matriz deve ser encerrada por um ponteiro NULL | A string a ser dividida | O caractere delimitador | A matriz de novas strings resulta da divisão. NULL se a alocação falhar |

##[ft_strmapi]

`char * ft_strmapi(char const * s, char(* f)(unsigned int, char))`

| Descrição Param. #1 | Param. #2 | Valor de retorno | |
| ----------- | ----------- | ----------- | -----------|  
| Aplica a função f a cada caractere da string passada como argumento para criar uma nova string(com malloc) resultante de aplicações sucessivas de f | A string na qual iterar | A função a ser aplicada a cada personagem | A string criada a partir das aplicações sucessivas de f. Retorna NULL se a alocação falhar |

##[ft_atoi]

`char ft_itoa(int n)`

| Descrição Param. #1 | Valor de retorno \
| ----------- | ----------- | -----------|  
| Aloca(com malloc) e retorna uma string que representa o inteiro recebido como um argumento. Números negativos devem ser tratados | O inteiro a ser convertido | | A string que representa o inteiro. NULL se a alocação falhar. |










##[ft_islower](libft / ft_islower.c)

`int ft_islower(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Verifique se há um caractere minúsculo | | O personagem a ser testado | | 0 se o caractere for falso e 1 se o caractere for verdadeiro | |

##[ft_isupper](libft / ft_isupper.c)

`int ft_isupper(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Verifique se há um caractere maiúsculo | | O personagem a ser testado | | 0 se o caractere for falso e 1 se o caractere for verdadeiro | |

##[ft_isspace](libft / ft_isspace.c)

`int ft_isspace(int c)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
| Verifica se há caracteres de espaço em branco. São eles| espaço, alimentação de formulário('\ f'), nova linha('\ n'), retorno de carro('\ r'), guia horizontal('\ t') e guia vertical('\ v') . | O personagem a ser testado | | 0 se o caractere for falso e 1 se o caractere for verdadeiro | |











##ft_capitalize

`char * ft_capitalize(char * s)`

| Descrição Param. #1 | Valor de retorno | |
| ----------- | ----------- | -----------|  
|Coloca em maiúscula a primeira letra de cada palavra em uma string | A string para capitalizar | A nova string com palavras maiúsculas |
