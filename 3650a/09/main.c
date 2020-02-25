#include <stdio.h>

#include "list.c"
#include "tokenize.c"
#include "parse.c"
#include "ast.c"



int
main(int _ac, char* _av[])
{
    char line[100];
    while (1) {
        char* rv = fgets(line, 96, stdin);
        if (!rv) {
            break;
        }
        list* toks = tokenize(line);
        list* toks1 = reverse(toks);
        print_list(toks1);

        calc_ast* ast = parse(toks);
        print_ast(ast);

        /*
        printf(" = %d\n", ast_eval(ast));
        free_ast(ast);
        free_list(toks);
        */
    }

    return 0;


   //  char line[100];
   //  while (1) {
   //   printf("tokens$ ");
   //   fflush(stdout);
   //   line = read_line()
   //   if (that was EOF) {
   //      exit(0);
   //   }
   //   tokens = tokenize(line);
   //   foreach token in reverse(tokens):
   //     puts(token)
   // }
}
