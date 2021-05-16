#include <janet.h>
#include <stdio.h>

int loadTextFile(const char* fn, char* buf, int bufsize) {
    FILE* fp = fopen(fn, "rt");
    if (!fp) {
        return 1;
    }
    char* p = buf;
    for (;;) {
        int n = fread(p, 1, bufsize, fp);
        if (n == 0) {
            break;
        }
        bufsize -= n;
        p += n;
    }
    *p = '\0';
    return 0;
}

int main(int argc, const char *argv[]) {
    janet_init();
    JanetTable *env = janet_core_env(NULL);

    char buf[10 * 1024];
    if (!loadTextFile("geo3x3.janet", buf, 10 * 1024)) {
        janet_dostring(env, buf, "geo3x3", NULL);
    }
    janet_dostring(env, "(print (encode 35.65858 139.745433 14))", "main", NULL);

    janet_deinit();
    return 0;
}
