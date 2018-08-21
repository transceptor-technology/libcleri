#include "expecting.h"


const char * re_to_str(uint32_t gid);


void expecting_str(cleri_grammar_t * grammar, const char * str)
{
    cleri_parse_t * pr = cleri_parse(grammar, str);
    const char * expect;
    buffer_t * expect_buf = buffer_create();
    //char expect_string[STRING_SIZE];
    int count = 0;
    long unsigned int len;

    while (pr->expect != NULL)
    {
        switch(pr->expect->cl_obj->tp)
        {
            case CLERI_TP_END_OF_STATEMENT:
                expect = "end_of_statement";
                break;

            case CLERI_TP_KEYWORD:
                expect = pr->expect->cl_obj->via.keyword->keyword;
                break;

            case CLERI_TP_TOKENS:
                expect = pr->expect->cl_obj->via.tokens->tokens;
                break;

            case CLERI_TP_TOKEN:
                expect = pr->expect->cl_obj->via.token->token;
                break;

            case CLERI_TP_REGEX:
                expect = re_to_str(pr->expect->cl_obj->gid);
                break;

            default:
                expect = "not found";
        }
        pr->expect = pr->expect->next; // takes choice.

        if (!count++)
        {
            len = buffer_printf(expect_buf, "%s", expect);
        }
        else if (pr->expect == NULL)
        {
            len += buffer_printf(expect_buf, " or %s.", expect);
        }
        else
        {
            len += buffer_printf(expect_buf, ", %s", expect);
        }
    }
    printf("Expecting: %s\n", expect_buf->buf);
    buffer_destroy(expect_buf);
    cleri_parse_free(pr);
}
