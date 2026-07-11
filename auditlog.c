#include <fcntl.h>
#include <unistd.h>

#define LOG_FILE "audit.log"
#define BUFFER_SIZE 4096

// Helper function to find the length of a null-terminated string
size_t mystrlen(const char *str) {
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Helper function to check string equality
int mystrcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

// Basic integer to string conversion using only write
void write_line_number(int num) {
    char buf[12];
    int i = 10;
    buf[11] = '\0';
    
    if (num == 0) {
        write(STDOUT_FILENO, "0", 1);
        return;
    }
    
    while (num > 0 && i >= 0) {
        buf[i--] = (num % 10) + '0';
        num /= 10;
    }
    write(STDOUT_FILENO, &buf[i + 1], 10 - i);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        write(STDERR_FILENO, "Usage: ./auditlog --add \"message\" or ./auditlog --view\n", 55);
        return 1;
    }

    if (mystrcmp(argv[1], "--add") == 0) {
        if (argc < 3) {
            write(STDERR_FILENO, "Error: Missing log message.\n", 28);
            return 1;
        }

        // Open file in Append mode, Create if not exists, Permissions: rw-r--r--
        int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);
        if (fd < 0) return 1;

        // Write message followed by newline character
        write(fd, argv[2], mystrlen(argv[2]));
        write(fd, "\n", 1);
        close(fd);

    } else if (mystrcmp(argv[1], "--view") == 0) {
        int fd = open(LOG_FILE, O_RDONLY);
        if (fd < 0) {
            // File doesn't exist yet, or can't be read safely
            return 0;
        }

        char buffer[BUFFER_SIZE];
        ssize_t bytes_read;
        int line_count = 1;
        int need_prefix = 1;

        while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
            for (ssize_t i = 0; i < bytes_read; i++) {
                if (need_prefix) {
                    write_line_number(line_count);
                    write(STDOUT_FILENO, ": ", 2);
                    need_prefix = 0;
                }
                
                write(STDOUT_FILENO, &buffer[i], 1);
                
                if (buffer[i] == '\n') {
                    line_count++;
                    need_prefix = 1;
                }
            }
        }
        close(fd);
    } else {
        write(STDERR_FILENO, "Unknown command.\n", 17);
        return 1;
    }

    return 0;
}