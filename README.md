# Here

## What is this?

Here or Libhere is a C-library which implements regular expressions in a simple and straightforward way.

"Here" is a subproject from Hefesto project and it can be understood as *H*efesto's *R*egular *E*xpressions.

This library isn't posix compliant because my main goal in this project is to keep the things simple and not bloated.

## How to build here?

In order to build here you need to use [Hefesto](https://github.com/rafael-santiago/hefesto.git).

After you had Hefesto installed in your system just type "hefesto" being inside the libhere's "src" subdirectory, uhmm something like:

    root@moloko:~/here# cd src
    root@moloko:~/here/src# hefesto

If all works a ".a" file will be within "src/lib" subdirectory. Now you can use this to link libhere against your projects.

## How to use libhere within my code?

Basically libhere exposes to you functions to matching and replacing data.

If you need to match something, in general you can try:

    (...)

    #include <here.h>

    (...)

    here_search_program_ctx *search_program = NULL;
    here_search_result_ctx *search_result = NULL;
    char error_messages[4096];

    (...)

    search_program = here_compile(".*6655321.*", error_messages);

    if (search_program == NULL) {
        //  If you don't want to know details about compilation errors
        //  just pass NULL instead of a message buffer to here_compile()
        //  function.
        printf("Regex compile ERROR: %s\n", error_messages);
        exit(1);
    }

    search_result = here_match_string(user_data_buffer, search_program);

    if (here_matches(search_result)) {
        printf("Pattern found.\n");
    }

    del_here_search_program_ctx(search_program);

    (...)

If you need to replace something you can try:


    (...)

    #include <here.h>

    (...)

    here_search_program_ctx *search_program = NULL;
    here_search_result_ctx *search_result = NULL;
    char *output = NULL;
    size_t output_size = 0;
    int replacements = 0;

    (...)

    search_program = here_compile("6655321", NULL);

    if (search_program == NULL) {
        printf("The supplied regex has errors.\n");
        exit(1);
    }

    replacements = here_replace_string(user_data_buffer, search_program, "Alex", &output, &output_size);

    if (replacements > 0) {
        printf("%d replacements had done -> %s\n", replacements, output);
    }

    del_here_search_program_ctx(search_program);

    (...)

Enjoy!

Santiago

## O que é isso?

Here ou Libhere é uma biblioteca C que implementa expressões regulares de um jeito simples e direto.

"Here" é um subprojeto do projeto Hefesto e isso pode ser endentido como *H*efesto's *R*egular *E*xpressions.

Esta biblioteca não é posix porque meu principal objetivo neste projeto é manter as coisas simples e não inchadas.

## Como compilar here?

Para compilar esta lib você precisa de usar o [Hefesto](https://github.com/rafael-santiago/hefesto.git).

Depois de você ter o Hefesto instalado no seu sistema apenas digite "hefesto" estando dentro do subdiretório "src" da libhere, uhmm alguma coisa como:

    root@moloko:~/here# cd src
    root@moloko:~/here/src# hefesto

Se tudo funcionar um arquivo ".a" vai estar dentro do subdiretório "src/lib". Agora você pode usar isso para linkar a libhere com seus projetos.

## Como usar a libhere dentro do meu código?

Basicamente a libhere expõe para você funções para matching e replacing de dados.

Se você precisa buscar alguma coisa, em geral você pode tentar:

    (...)

    #include <here.h>

    (...)

    here_search_program_ctx *search_program = NULL;
    here_search_result_ctx *search_result = NULL;
    char error_messages[4096];

    (...)

    search_program = here_compile(".*6655321.*", error_messages);

    if (search_program == NULL) {
        //  Se você não quer saber detalhes sobre erros de compilação
        //  apenas passe NULL ao invés de um buffer de mensagem para
        //  a função here_compile().
        printf("Regex compile ERROR: %s\n", error_messages);
        exit(1);
    }

    search_result = here_match_string(user_data_buffer, search_program);

    if (here_matches(search_result)) {
        printf("Pattern found.\n");
    }

    del_here_search_program_ctx(search_program);

    (...)

Se você precisa substituir alguma coisa você pode tentar:

    (...)

    #include <here.h>

    (...)

    here_search_program_ctx *search_program = NULL;
    here_search_result_ctx *search_result = NULL;
    char *output = NULL;
    size_t output_size = 0;
    int replacements = 0;

    (...)

    search_program = here_compile("6655321", NULL);

    if (search_program == NULL) {
        printf("The supplied regex has errors.\n");
        exit(1);
    }

    replacements = here_replace_string(user_data_buffer, search_program, "Alex", &output, &output_size);

    if (replacements > 0) {
        printf("%d replacements had done -> %s\n", replacements, output);
    }

    del_here_search_program_ctx(search_program);

    (...)

Aproveite!

Santiago
