nclude <stdio.h>
#include <time.h>

int main() {
    // 获取系统上电时间
    FILE *uptime_file = fopen("/proc/uptime", "r");
    if (uptime_file == NULL) {
        perror("Failed to open /proc/uptime");
        return 1;
    }

    double uptime_seconds;
    fscanf(uptime_file, "%lf", &uptime_seconds);
    fclose(uptime_file);

    // 将上电时间转换为秒和毫秒
    long seconds = (long)uptime_seconds;
    long milliseconds = (long)((uptime_seconds - seconds) * 1000);

    // 格式化时间戳字符串
    char time_str[64];
    snprintf(time_str, sizeof(time_str), "[%ld.%03ld] ", seconds, milliseconds);

    // 打印日志消息，包括上电时间戳
    printf("%s Your log message here\n", time_str);

    return 0;
}
