# Here

## What is this?

``Here`` or ``Libhere`` is a ``C-library`` which implements regular expressions in a simple and straightforward way.

"Here" is a sub-project from [``Hefesto``](https://github.com/rafael-santiago/hefesto) project and it can be understood
as ``He``festo's ``R``egular ``E``xpressions.

This library is not POSIX compliant because my main goal in this project is to keep the things simple and not bloated.

## How to build here?

In order to build "here" you need to use [Hefesto](https://github.com/rafael-santiago/hefesto.git).

After you had ``Hefesto`` installed on your system just type ``hefesto``. Being inside the libhere's ``src`` sub-directory. Something like:

```
root@moloko:~/here# cd src
root@moloko:~/here/src# hefesto
```

If all works a ".a" file will be within the ``src/lib`` sub-directory. Now you can use it to link the ``libhere`` against your projects.

## How to use libhere within my code?

Basically ``libhere`` exposes for you functions for matching and replacing data.

If you need to match something, in general you should do:

```c
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
    del_here_search_result_ctx(search_result);
}

del_here_search_program_ctx(search_program);

(...)
```

If you need to replace something you should do:

```c
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
```

From here everything is simple! ;)

Enjoy!
