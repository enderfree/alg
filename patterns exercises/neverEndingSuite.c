int main()
{
    int n= 1;
    for(int i = 1; i < 6; ++i)
    {
        for(int limit = n + i; n < limit ; ++n) 
        {
            printf("%d ", n);
        }
        printf("\n");
    }

    return 0;
}