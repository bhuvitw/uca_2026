#include <stdio.h>
#include <stdbool.h>

void remove_comments(FILE *in, FILE *out) {
    int ch, next_ch;
    bool in_single_comment = false;
    bool in_multi_comment = false;
    bool in_string = false;
    bool in_char = false;

    while ((ch = fgetc(in)) != EOF) {
        // Handle single-line comment: // ...
        if (in_single_comment) {
            if (ch == '\n') {
                in_single_comment = false;
                fputc(ch, out); // Keep newline to preserve line numbers
            }
            continue;
        }

        // Handle multi-line comment: /* ... */
        if (in_multi_comment) {
            if (ch == '*') {
                next_ch = fgetc(in);
                if (next_ch == '/') {
                    in_multi_comment = false;
                } else if (next_ch != EOF) {
                    ungetc(next_ch, in);
                }
            }
            continue;
        }

        // Handle string literals: "..."
        if (in_string) {
            fputc(ch, out);
            if (ch == '\\') {
                // Handle escaped character inside string
                next_ch = fgetc(in);
                if (next_ch != EOF) {
                    fputc(next_ch, out);
                }
            } else if (ch == '"') {
                in_string = false;
            }
            continue;
        }

        // Handle character literals: '...'
        if (in_char) {
            fputc(ch, out);
            if (ch == '\\') {
                // Handle escaped character inside char literal
                next_ch = fgetc(in);
                if (next_ch != EOF) {
                    fputc(next_ch, out);
                }
            } else if (ch == '\'') {
                in_char = false;
            }
            continue;
        }

        // State: Outside comments, strings, and character constants
        if (ch == '"') {
            in_string = true;
            fputc(ch, out);
        } else if (ch == '\'') {
            in_char = true;
            fputc(ch, out);
        } else if (ch == '/') {
            next_ch = fgetc(in);
            if (next_ch == '/') {
                in_single_comment = true;
            } else if (next_ch == '*') {
                in_multi_comment = true;
            } else {
                fputc(ch, out);
                if (next_ch != EOF) {
                    ungetc(next_ch, in);
                }
            }
        } else {
            fputc(ch, out);
        }
    }
}

int main(void) {
    remove_comments(stdin, stdout);
    return 0;
}