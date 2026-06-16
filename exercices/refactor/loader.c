#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <mysql/mysql.h>

int main()
{
    int s, c;
    socklen_t l;
    struct sockaddr_in a, b;
    char buf[1024];
    float *f;
    MYSQL *m;
    char q[512];

    s = socket(AF_INET, SOCK_STREAM, 0);

    a.sin_family = AF_INET;
    a.sin_port = htons(1618);
    a.sin_addr.s_addr = INADDR_ANY;

    bind(s, (struct sockaddr*)&a, sizeof(a));

    listen(s, 5);

    m = mysql_init(NULL);
    mysql_real_connect(m, "localhost", "meteo", "abcd", "meteo", 0, NULL, 0);

    while(1)
    {
        l = sizeof(b);
        c = accept(s, (struct sockaddr*)&b, &l);

        read(c, buf, 1024);

        f = (float*)buf;

        float t = f[0];
        float h = f[1];
        float p = f[2];

        sprintf(q, "INSERT INTO data VALUES(%f,%f,%f)", t, h, p);

        mysql_query(m, q);

        printf("t=%f h=%f p=%f\n", t, h, p);

        close(c);
    }

    mysql_close(m);

    return 0;
}
