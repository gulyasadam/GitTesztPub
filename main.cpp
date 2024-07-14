void f()
{
    char arr[5];
    arr[10] = 3;
}

void f(int *p)
{
    *p = 3;
}

int main()
{
    int *p = 0;
    f(p);
    return 0;
}