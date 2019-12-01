#include <regex.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // (([^:]+:){6}(([^:]+:[^:]+)|(.*\..*)))|((([^:]+:)*[^:]+)?::(([^:]+:)*[^:]+)?)(%.+)?

    regex_t re;
    regmatch_t pm;
    char inp[200]={};
    // char *p = "(^([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])[o]([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$)";
    char *p = "(^([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])[o]([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$)|(^[1-9][0-9]{0,8}$)";
        // |([1-3][0-9]{9})|(4[0-1][0-9]{8})|(42[0-8][0-9]{7})|(429[0-3][0-9]{6})|(4294[0-8][0-9]{5})|(42949[0-5][0-9]{4})|(429496[0-6][0-9]{3})|(4294967[0-1][0-9]{2})|(42949672[0-8][0-9])|(429496729[0-5])";
    /*
    "(^([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])[o]([0-9]{1,4}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])) |
    ([1-9][0-9]{0,8}) |
    ([1-3][0-9]{9})|
    (4[0-1][0-9]{8})|
    (42[0-8][0-9]{7})|
    (429[0-3][0-9]{6})|(4294[0-8][0-9]{5})|(42949[0-5][0-9]{4})|(429496[0-6][0-9]{3})|(4294967[0-1][0-9]{2})|(42949672[0-8][0-9])|(429496729[0-5])";
*/

    if (0 != regcomp(&re, p, REG_EXTENDED))
    {
        printf("Erro in compiling");
        return 0;
    }

    while(1)
    {
        int a;
        printf("Enter input: ");
        scanf("%s", inp);

        a = regexec(&re, inp, 0, NULL, 0);
        printf("\n first match at %d:%s\n", a, (a==0)?"Matched":"Not matched");
    }

    return 0;
}